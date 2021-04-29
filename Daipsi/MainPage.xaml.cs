using Daipsi.SignInUp;
using Plugin.Connectivity;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Essentials;
using Xamarin.Forms;

namespace Daipsi
{
    public partial class MainPage : ContentPage
    {
        public MainPage()
        {
            InitializeComponent();
        }

        private async void EB_Clicked(object sender, EventArgs e)
        {
            var uri = new Uri("https://www.exploitblizzard.co");

            if (CrossConnectivity.Current.IsConnected)
            {
                try
                {
                    await Browser.OpenAsync(uri, new BrowserLaunchOptions
                    {
                        LaunchMode = BrowserLaunchMode.SystemPreferred,
                        TitleMode = BrowserTitleMode.Show,
                        PreferredToolbarColor = Color.Black,
                        PreferredControlColor = Color.FromHex("06FE01")
                    });
                }
                catch (NullReferenceException ee)
                {
                    await DisplayAlert("Error!", "Something Bad Appeared, Retrying....", "Ok");
                    await DisplayAlert("Error Code", ee.ToString(), "OK");
                }
            }
            else
            {
                await DisplayAlert("No Internet Connection!", "Try Connecting to an internet connection....", "Ok");
            }
        }

        private async void Logo_Clicked(object sender, EventArgs e)
        {
            
            try
            {
                
                HapticFeedback.Perform(HapticFeedbackType.Click);
            }
            catch (FeatureNotSupportedException )
            {
                            
            }
            catch (Exception )
            {
                
            }
            await Logo.ScaleTo(0.85, 100);
            await Logo.ScaleTo(1, 100);
            await Navigation.PushModalAsync(new LoginPage(), true);
        }
        
    }
}
