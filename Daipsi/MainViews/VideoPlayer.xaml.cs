using Daipsi.Models;
using MediaManager;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Daipsi.MainViews
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class VideoPlayer : ContentPage
    {
        public VideoPlayer()
        {
            InitializeComponent();
        }

        public static CoursesVideos courseitem = new CoursesVideos(); // course subject selection
        public static Bookmarkdata bookmarkitem = new Bookmarkdata(); // bookmark selection 
        public string videourishare = null;
        public string videonameshare = null;
        protected override async void OnAppearing()
        {
            try
            {
                loadingbox.IsVisible = true;
                loadingimage.IsVisible = true;
                videoloading.IsVisible = true;
                CrossMediaManager.Current.ClearQueueOnPlay=true;
                if (courseitem.Id != null) // subject item not null
                {
                    Bookmarkdata checkforbookmark = (await App.MobileService.GetTable<Bookmarkdata>().Where(q => q.CourseVideoId == courseitem.Id).Where(u => u.UserId ==App.logineduser.Id).ToListAsync()).FirstOrDefault();
                    if (checkforbookmark != null)
                    {
                        bookmarked.IsVisible = true;
                        bookmarkedoornot.IsVisible = false;
                    }

                    videouri.Source = new Uri(courseitem.VideoLink +".mp4");
                    
                    
                    await CrossMediaManager.Current.Play(courseitem.VideoLink);
                    CrossMediaManager.Current.Notification.ShowNavigationControls = false;
                    CrossMediaManager.Current.Notification.ShowPlayPauseControls = true;
                    

                    videourishare = courseitem.VideoLink;
                    videonameshare = courseitem.VideoName;
                    Descriptionname.Text = courseitem.VideoDescription;
                    Coursename.Text = courseitem.NameOfCourse;
                    Videoname.Text = courseitem.VideoName;
                    Subjectname.Text = courseitem.SubjectName;
                    DateUploaded.Text = courseitem.DateUploaded;
                    
                    if(CrossMediaManager.Current.IsBuffering() == false)
                    {
                        videoloading.IsVisible = false;
                    }
                    loadingimage.IsVisible = false;
                    loadingbox.IsVisible = false;

                }
                if(courseitem.Id is null)
                {
                    bookmarked.IsVisible = true;
                    bookmarkedoornot.IsVisible = false;

                    var bookmark_Data = (await App.MobileService.GetTable<CoursesVideos>().Where(u => u.Id == bookmarkitem.CourseVideoId).ToListAsync()).FirstOrDefault();
                    videouri.Source = new Uri(bookmark_Data.VideoLink+".mp4");
                    
                    await CrossMediaManager.Current.Play(bookmark_Data.VideoLink);
                    CrossMediaManager.Current.Notification.ShowNavigationControls = false;
                    CrossMediaManager.Current.Notification.ShowPlayPauseControls = true;
                    
                    Coursename.Text = bookmark_Data.NameOfCourse;
                    Videoname.Text = bookmark_Data.VideoName;
                    Subjectname.Text = bookmark_Data.SubjectName;
                    DateUploaded.Text = bookmark_Data.DateUploaded;
                    Descriptionname.Text = bookmark_Data.VideoDescription;
                    videourishare = bookmark_Data.VideoLink;
                    videonameshare = bookmark_Data.VideoName;
                    loadingimage.IsVisible = false;
                    loadingbox.IsVisible = false;
                }
              


            }
            catch (HttpRequestException)
            {
                await DisplayAlert("No Internet Connection", "There was no internet connection found!","Ok");
                await Navigation.PopModalAsync(true);
            }
            catch (TaskCanceledException ex)
            {
                await DisplayAlert("Task Not Completed", "Some Background loading task were not completed succesfully ! "+ex.CancellationToken, "Ok");
                await Navigation.PopModalAsync(true);
            }
            catch (Exception  exc)
            {
                await DisplayAlert("Error Video Player", "There was an error in page!"+exc.ToString(), "Try Again!");
                await Navigation.PopModalAsync(true);
            }
            

            base.OnAppearing();
        }
        protected override void OnDisappearing()
        {
            base.OnDisappearing();
            loadingimage.IsVisible = false;
            loadingbox.IsVisible = false;

        }
        protected override bool OnBackButtonPressed()
        {
            CrossMediaManager.Current.Stop() ;
            return base.OnBackButtonPressed();
        }

        private async void backbuttontext_Clicked(object sender, EventArgs e)
        {
            await Navigation.PopModalAsync(true);
            await CrossMediaManager.Current.Stop();
            Navigation.RemovePage(new VideoPlayer());
        }

        private async void bookmarkedoornot_Clicked(object sender, EventArgs e)
        {

            try
            {
                bookmarkedoornot.IsVisible = false;
                bookmarked.IsVisible = true;

                Bookmarkdata Addbookmark = new Bookmarkdata()
                {
                    CourseVideoId = courseitem.Id,
                    UserId = App.logineduser.Id,
                    UserEmailId = App.logineduser.EmailId,
                    DateBookmarked = DateTime.Now.ToLocalTime().ToString(),
                    DateUploaded = courseitem.DateUploaded,
                    SubjectName = courseitem.SubjectName,
                    VideoName = courseitem.VideoName,
                    VideoDescription=courseitem.VideoDescription,
                    VideoThumbnail=courseitem.VideoThumbnail,
                    Downloaded = "yes"
                };

                await App.MobileService.GetTable<Bookmarkdata>().InsertAsync(Addbookmark);
                
                await DisplayAlert("Bookmark Added! ", "The Bookmarked video has been Added to your page", "Ok");
                
            }
            catch (HttpRequestException)
            {
                await DisplayAlert("No Internet Connection", "There was no internet connection found!", "Ok");
                await Navigation.PopModalAsync(true);
            }
            catch (Exception)
            {
                await DisplayAlert("Error Video Player", "There was an error in page!", "Try Again!");
                await Navigation.PopModalAsync(true);
            }
            
            
        }

        private async void bookmarked_Clicked(object sender, EventArgs e)
        {
            if (bookmarkitem.Id != null)
            {

                try
                {
                    bookmarkedoornot.IsVisible = true;
                    bookmarked.IsVisible = false;
                    await App.MobileService.GetTable<Bookmarkdata>().DeleteAsync(bookmarkitem);
                    await DisplayAlert("Removed Successfully", "Your Video has been removed", "Ok");

                }
                catch (HttpRequestException)
                {
                    await DisplayAlert("No Internet Connection", "There was no internet connection found!", "Ok");
                    await Navigation.PopModalAsync(true);
                }
                catch (Exception ecc)
                {
                    await DisplayAlert("Error Video Player", "There was an error in page! as " + ecc.Message+"   "+ecc.Source, "Try Again!");
                    await Navigation.PopModalAsync(true);
                }
            }
            else
            {
                try
                {
                    bookmarkedoornot.IsVisible = true;
                    bookmarked.IsVisible = false;
                    var bookmarkusingcoure = (await App.MobileService.GetTable<Bookmarkdata>().Where(u => u.CourseVideoId == courseitem.Id).Where(q => q.UserId == App.logineduser.Id).ToListAsync()).FirstOrDefault();

                  
                    await App.MobileService.GetTable<Bookmarkdata>().DeleteAsync(bookmarkusingcoure);
                    await DisplayAlert("Removed Successfully", "Your Video has been removed", "Ok");

                }
                catch (HttpRequestException)
                {
                    await DisplayAlert("No Internet Connection", "There was no internet connection found!", "Ok");
                    await Navigation.PopModalAsync(true);
                }
                catch (Exception ecc)
                {
                    await DisplayAlert("Error Video Player", "There was an error in page! as " + ecc.Message, "Try Again!");
                    await Navigation.PopModalAsync(true);
                }
            }
        }
        
        private async void fullscreenvideo_Clicked(object sender, EventArgs e)
        {
            FullScreenVideo.showcourseitem.VideoName = videonameshare;
            FullScreenVideo.showcourseitem.VideoLink = videourishare;
            await Navigation.PushModalAsync(new FullScreenVideo(),true);
        }
        
    }
}