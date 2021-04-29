using Daipsi.AdminViews;
using Daipsi.MainViews;
using Daipsi.Models;
using Microsoft.WindowsAzure.MobileServices;
using System;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Daipsi
{
    public partial class App : Application
    {
        public App()
        {
            InitializeComponent();

            MainPage = new NavigationPage(new MainPage());
        }

        public static MobileServiceClient MobileService= new MobileServiceClient("https://daipsiebat1.azurewebsites.net");
        public static Userbook logineduser = new Userbook();
        protected override void OnStart()
        {
        }

        protected override void OnSleep()
        {
        }

        protected override void OnResume()
        {
        }
    }
}
