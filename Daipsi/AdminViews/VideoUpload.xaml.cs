using Azure.Storage.Blobs;
using Daipsi.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Essentials;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Daipsi.AdminViews
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class VideoUpload : ContentPage
    {

        public string thumbnailuri;
        public string videouploaduri;
        public VideoUpload()
        {
            InitializeComponent();
            
        }
        protected override async void OnAppearing()
        {
            try
            {
                var courses = await App.MobileService.GetTable<Courses>().ToListAsync();
                CoursePicker.ItemsSource = courses;
            }
            catch (HttpRequestException)
            {
                await DisplayAlert("No Internet Connection", "There was no active Internet Connection", "Ok");
            }
            catch (Exception)
            {
                await DisplayAlert("Exception Occoured !", "Some Error Occoured !", "Ok");
            }
            base.OnAppearing();
        }

        // Handling the cases of Uploading the Thumbnail
        private async void ThumbnailUpload_Clicked(object sender, EventArgs e)
        {
            try
            {            
                loadingimage.IsVisible = true;

                var thumbnailfile = await FilePicker.PickAsync(new PickOptions
                {
                    FileTypes = FilePickerFileType.Images,
                    PickerTitle = "Pick The Thumbnail Image"
                    
                    
                    
                });
                
                
                if (thumbnailfile == null)
                {
                    await DisplayAlert("No File Was Chosen", "You Didn't Chose A File", "Ok");
                    thumbnailuploaddone.IsVisible = false;
                    loadingimage.IsVisible = false;
                    return;
                }
                var stream = await thumbnailfile.OpenReadAsync();
                uploadthumbnailtostorage(stream);
                
            }
            catch (HttpRequestException)
            {
                await DisplayAlert("No Internet Connection", "There was no active Internet Connection", "Ok");
                loadingimage.IsVisible = false;
            }
            catch (Exception)
            {
                await DisplayAlert("Exception Occoured !", "Some Error Occoured !", "Ok");
                loadingimage.IsVisible = false;
            }
            
        }

        private async void uploadthumbnailtostorage(System.IO.Stream stream)
        {
            
            try
            {
                thumbnailuri = "";
                loadingimage.IsVisible = true;
                BlobContainerClient container = new BlobContainerClient("DefaultEndpointsProtocol=https;AccountName=daipsiebat;AccountKey=5mSpwWLLqgziOx4XJYMXXijPMUcJ5wpARWM9x6t9CwmWQixaM+9O8n9DpChVYbgLLEib7olSMSCIjUt45FjedQ==;EndpointSuffix=core.windows.net", "videothumbnailscontainer");
                await container.CreateIfNotExistsAsync();
                try
                {
                    if (VideoName.Text == null)
                    {
                        await DisplayAlert("VideoName missing", "Enter the Video Name first to upload!", "Ok");
                        return;
                    }
                    Random random = new Random();
                    
                    var blobname = VideoName.Text + "Thumbnail"+DateTime.Today.ToString()+random.Next(200027);
                    BlobClient blob = container.GetBlobClient(blobname.Replace(" ",string.Empty));
                    System.Threading.Tasks.Task task = new Task(async () =>
                    { 
                       await blob.UploadAsync(stream);
                    });
                    loadingimage.IsVisible = true;
                    task.Start();
                    task.Wait();


                    if (task.IsCompleted)
                    {
                        task.Dispose();
                        thumbnailuploaddone.IsVisible = true;
                        thumbnailuri = blob.Uri.OriginalString.ToString();
                        Thumbnaildelete.IsVisible = true;
                        loadingimage.IsVisible = false;
                    }
                    else
                    {
                        await DisplayAlert("Thumbnail Not Uploaded", "Try Again!", "True");
                        loadingimage.IsVisible = false;
                    }

                }
                catch (Exception)
                {
                    await DisplayAlert("Error In Uploading", "The selected file name already exist, Please change the resource name!", "ok");
                    loadingimage.IsVisible = false;
                }
                loadingimage.IsVisible = false;
            }
            catch (HttpRequestException)
            {
                await DisplayAlert("No Internet Connection", "There was no active Internet Connection", "Ok");
                loadingimage.IsVisible = false;
            }
            catch (Exception)
            {
                await DisplayAlert("Exception Occoured !", "Some Error Occoured !", "Ok");
                loadingimage.IsVisible = false;
            }

        }
        private async void Thumbnaildelete_Clicked(object sender, EventArgs e)
        {
            thumbnailuri = "";
            await DisplayAlert("Thumbnail Deleted","Your File was Deleted Upload a new one","Ok");
            Thumbnaildelete.IsVisible = false;
            thumbnailuploaddone.IsVisible = false;
        }

        // Hanlding Video Uploadation
        private async void VideoUpload_Clicked(object sender, EventArgs e)
        {
            
            try
            {
                loadingimage.IsVisible = true;
                var thumbnailfile = await FilePicker.PickAsync(new PickOptions
                {
                    FileTypes = FilePickerFileType.Videos,
                    PickerTitle = "Pick The Course Video"
                });
                if (thumbnailfile == null)
                {
                    await DisplayAlert("No File Was Chosen", "You Didn't Chose A File", "Ok");
                    videouploaddone.IsVisible = false;
                    loadingimage.IsVisible = false;
                    return;
                }
                var stream = await thumbnailfile.OpenReadAsync();
                uploadvideotostorage(stream);
                
                
            }
            catch (HttpRequestException)
            {
                await DisplayAlert("No Internet Connection", "There was no active Internet Connection", "Ok");
                loadingimage.IsVisible = false;
            }
            catch (Exception)
            {
                await DisplayAlert("Exception Occoured !", "Some Error Occoured !", "Ok");
                loadingimage.IsVisible = false;
            }
            
        }
        private async void uploadvideotostorage(System.IO.Stream stream)
        {
            
            try
            {
                videouploaduri = "";
                loadingimage.IsVisible = true;
                BlobContainerClient container = new BlobContainerClient("DefaultEndpointsProtocol=https;AccountName=daipsiebat;AccountKey=5mSpwWLLqgziOx4XJYMXXijPMUcJ5wpARWM9x6t9CwmWQixaM+9O8n9DpChVYbgLLEib7olSMSCIjUt45FjedQ==;EndpointSuffix=core.windows.net", "subjectsvideoscontainer");
                await container.CreateIfNotExistsAsync();
                try
                    
                {
                    if (VideoName.Text == null)
                    {
                        await DisplayAlert("VideoName missing", "Enter the Video Name first to upload!", "Ok");
                        return;
                    }
                    Random random = new Random();
                    
                    var blobname = VideoName.Text + "Video"+DateTime.Today.ToString()+ random.Next(200098);
                    BlobClient blob = container.GetBlobClient(blobname.Replace(" ",string.Empty));
                    System.Threading.Tasks.Task task = new Task(async () =>
                    {
                        
                        await blob.UploadAsync(stream);
                    });
                    task.Start();
                    loadingimage.IsVisible = true;
                    task.Wait();

                    if (task.IsCompleted)
                    {
                        task.Dispose();
                        videouploaddone.IsVisible = true;
                        videouploaduri = blob.Uri.OriginalString.ToString();
                        loadingimage.IsVisible = false;
                        videouploaddone.IsVisible = true;
                        Videodelete.IsVisible = true;

                    }
                    else
                    {
                        await DisplayAlert("Video not uploaded", "Video isn't uploaded succesfully!", "Ok");
                        loadingimage.IsVisible = false;
                    }
                    

                }
                catch (Exception)
                {
                    await DisplayAlert("Error In Uploading", "The selected file name already exist, Please change the resource name!", "ok");
                    loadingimage.IsVisible = false;
                }
                loadingimage.IsVisible = false;
            }
            catch (HttpRequestException)
            {
                await DisplayAlert("No Internet Connection", "There was no active Internet Connection", "Ok");

                loadingimage.IsVisible = false;
            }
            catch (Exception)
            {
                await DisplayAlert("Exception Occoured !", "Some Error Occoured !", "Ok");
                loadingimage.IsVisible = false;
            }

        }

        private async void Videodelete_Clicked(object sender, EventArgs e)
        {
            videouploaduri = "";
            await DisplayAlert("Video Deleted", "Your File was Deleted Upload a new one", "Ok");
            Videodelete.IsVisible = false;
            videouploaddone.IsVisible = false;
        }
        private async void BackButtonimg_Clicked(object sender, EventArgs e)
        {
            await Navigation.PopAsync(true);
        }

        private async void backbutton_Clicked(object sender, EventArgs e)
        {
            await Navigation.PopAsync(true);
        }

        private async void Uploadbutton_Clicked(object sender, EventArgs e)
        {
            loadingimage.IsVisible = true;
            if (CheckValidation.IsChecked == true)
            { 
                if(Videodelete.IsVisible && Thumbnaildelete.IsVisible == true)
                {
                    try
                    {
                        var coursename = CoursePicker.SelectedItem as Courses;
                        var courseupload = new CoursesVideos()
                        {
                            NameOfCourse = coursename.NameOfCourse,
                            SubjectName = Subjectname.Text,
                            DateUploaded = Datepicker.Date.ToString("dd/MM/yyyy"),
                            VideoName = VideoName.Text,
                            VideoThumbnail = thumbnailuri.ToString(),
                            VideoLink = videouploaduri.ToString(),
                            VideoDescription = VideoDesc.Text
                        };
                        Uploadbutton.BackgroundColor = Color.Blue;
                        await App.MobileService.GetTable<CoursesVideos>().InsertAsync(courseupload);
                        Uploadbutton.BackgroundColor = Color.Black;
                        await DisplayAlert("Succesfully Uploaded", "The video course has been uploaded successfully !!!", "Ok");
                        loadingimage.IsVisible = false;
                        await Navigation.PopToRootAsync(true);
                    }
                    catch (HttpRequestException)
                    {
                        await DisplayAlert("No Internet Connection", "There was no internet connection", "Try Again");
                        loadingimage.IsVisible = false;
                    }
                    catch (Exception)
                    {
                        await DisplayAlert("Error", "There was and exception occoured or U didnt provide whole material !", "Try Again");
                        loadingimage.IsVisible = false;
                    }
                }
                else
                {
                    await DisplayAlert("Not Uploaded", " Wait Some files we not Uploaded Succesfully!","Ok");
                    return;
                }
                
            }
            else
            {
                await DisplayAlert("Validate ?", "Tick the box to upload the contents !", "Ok");
                loadingimage.IsVisible = false;
                return;
            }
        }

    }
}