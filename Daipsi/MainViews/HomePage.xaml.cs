using Azure.Storage.Blobs;
using Daipsi.AdminViews;
using Daipsi.Models;
using Daipsi.SignInUp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Essentials;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Daipsi.MainViews
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class HomePage : ContentPage
    {
        

        public HomePage()
        {
            InitializeComponent();
            
        }

        // Declaring of public variables
        public string coursename = "JEE";

        protected async override void OnAppearing()
        {
            try
            {

                //Handling the user data
                Mainpage_Username.Text = "Hi, " + App.logineduser.FullName.ToString();

                if (App.logineduser.ProfilePic == null)
                {
                    swipe_Userprofile.Source = ImageSource.FromFile("sampleuser.png");
                    Mainpage_Userprofilepic.Source = ImageSource.FromFile("sampleuser.png");
                }
                else
                {
                    swipe_Userprofile.Source = ImageSource.FromUri(new Uri(App.logineduser.ProfilePic));
                    Mainpage_Userprofilepic.Source = ImageSource.FromUri(new Uri(App.logineduser.ProfilePic));
                }


                if (App.logineduser.EmailId == "kshitijchaudhary175@gmail.com" || App.logineduser.EmailId=="akarshtripathi02@gmail.com")
                {
                    AdminPanel.IsVisible = true;
                    slidemenu_Usertype.Text = "ADMIN";
                }
                else
                {
                    //Handling the slide user data
                    slidemenu_Usertype.Text = "Student";
                }
                slidemenu_Username.Text = App.logineduser.FullName.ToString();



                DataRequest();
                
            }
            catch (HttpRequestException)
            {
                await DisplayAlert("No Internet Connection", "There is no active Internet Connection! ", "Try Again");
            }
            catch(InvalidCastException inex)
            {
                await DisplayAlert("Critical invalid ex Error", "We have encountered a serious error "+inex.ToString(), "Ok");
            }
            catch (Exception)
            {
                await DisplayAlert("Critical Error","We have encountered a serious error !","Ok");
            }
           
            base.OnAppearing();
        }

        void DataRequest()
        {
            MainThread.BeginInvokeOnMainThread(async () =>
            {
                var courses = await App.MobileService.GetTable<Courses>().ToListAsync();
                var videosdata = await App.MobileService.GetTable<CoursesVideos>().Where(c => c.NameOfCourse == coursename).ToListAsync();
                var bookmarkslistdata = await App.MobileService.GetTable<Bookmarkdata>().Where(p => p.UserId == App.logineduser.Id).ToListAsync();


                // Handling the list of courses
                CoursesCollectionView.ItemsSource = courses;

                // Handling the videos of Courses

                Subjects_CollectionView.ItemsSource = videosdata;

                //Handling the bookmarks of user

                Bookmarks_COllectionView.ItemsSource = bookmarkslistdata;
            }
            );



        }


        // Handling the SwipeView Animations

        private async void OpenAnimation()
        {
            
            swipepancake.CornerRadius = 20;
            await Swipegrid.ScaleTo(0.9, 300, Easing.SinOut);
            swipeclosebox.IsVisible = true;
        }
        private async void CloseAnimation()
        {
            await Swipegrid.ScaleTo(1, 200, Easing.SinOut);
            swipepancake.CornerRadius = 0;
            
            swipeclosebox.IsVisible = false;
        }
        private void MainSwipe_SwipeStarted(Object sender, SwipeStartedEventArgs e)
        {
            OpenAnimation();
        }
        private void MainSwipe_SwipeEnded(object sender, SwipeEndedEventArgs e)
        {
            if (!e.IsOpen)
                CloseAnimation();
            

        }


        // To close the opened swipe
        private void TapGestureRecognizer_Tapped(object sender, EventArgs e)
        {

            MainSwipe.Close(true);
            CloseAnimation();
            
        }
        private async void AdminPanel_Clicked(object sender, EventArgs e)
        {
            await Navigation.PushAsync(new VideoUpload(), true);
        }
        private void SwipeHome_Clicked(object sender, EventArgs e)
        {
            CloseAnimation();
        }


        // Refreshing the elements
        private void RefreshView_Refreshing(object sender, EventArgs e)
        {
            Refreshview.IsRefreshing = true;
            OnAppearing();
            Refreshview.IsRefreshing = false;
        }


        // Adding Functionality to the Collection views
        private async void SwipeExplore_Clicked(object sender, EventArgs e)
        {
            await Navigation.PushAsync(new UnderDev());
        }

        private void CoursesCollectionView_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

            var current = CoursesCollectionView.SelectedItem as Courses;
            coursename = current.NameOfCourse;
            CoursesCollectionView.BackgroundColor = Color.Transparent;
            DataRequest();
        }
        private object item;
        private async void Subjects_CollectionView_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            item =Subjects_CollectionView.SelectedItem;
            VideoPlayer.courseitem = item as CoursesVideos;
            await Navigation.PushModalAsync(new VideoPlayer() , true);
            
        }
        private async void Bookmarks_COllectionView_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            item = Bookmarks_COllectionView.SelectedItem;
            VideoPlayer.bookmarkitem = item as Bookmarkdata;
            
            await Navigation.PushModalAsync(new VideoPlayer(), true);
            
        }
        
        // Adding the swipe out functionality
        private async void SwipeLogout_Clicked(object sender, EventArgs e)
        {
            
            await Navigation.PushAsync(new MainPage(), true);
            SecureStorage.RemoveAll();
            App.Current.MainPage = new NavigationPage(new MainPage());
            
        }

    }
}