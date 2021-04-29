using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;
using Daipsi.Models;
using Xamarin.CommunityToolkit.Core;
using MediaManager;

namespace Daipsi.MainViews
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class FullScreenVideo : ContentPage
    {
        public static CoursesVideos showcourseitem = new CoursesVideos();
        public FullScreenVideo()
        {
            InitializeComponent();
            videouri.Source = MediaSource.FromUri(showcourseitem.VideoLink);
            CrossMediaManager.Current.Play(showcourseitem.VideoLink);
        }
        protected override void OnAppearing()
        {
            
            
            loadingimage.IsVisible = false;
           
            base.OnAppearing();
        }
        protected override void OnDisappearing()
        {
            base.OnDisappearing();
            
        }
    }
}