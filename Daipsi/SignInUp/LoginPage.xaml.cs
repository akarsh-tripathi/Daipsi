using Daipsi.MainViews;
using Daipsi.Models;
using Microsoft.WindowsAzure.MobileServices;
using Plugin.Connectivity;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net.Http;
using System.Security.Cryptography;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using Xamarin.Essentials;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Daipsi.SignInUp
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class LoginPage : ContentPage
    {
        public LoginPage()
        {
            InitializeComponent();
        }
        protected override async void OnAppearing()
        {
            try
            {
                var courses = await App.MobileService.GetTable<Courses>().ToListAsync();
                
                registerclasscourse.ItemsSource = courses;
                var oauthToken1 = await SecureStorage.GetAsync("loginid");
                var oauthToken2 = await SecureStorage.GetAsync("loginpass");
                
                if (oauthToken1 != null)
                {
                    remebered.IsVisible = true;
                    rememberstack.IsVisible = false;
                    loginusername.Text = oauthToken1;
                    loginusername.IsReadOnly = true;
                    loginpassword.Text = oauthToken2;
                    loginpassword.IsReadOnly = true;
                    deletecred.IsVisible = true;
                }
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
        // Decrypt And Encrypt
        private string Decrypt(string cipherText, string key)
        {
            string EncryptionKey = key;
            byte[] cipherBytes = Convert.FromBase64String(cipherText);
            using (Aes encryptor = Aes.Create())
            {
                Rfc2898DeriveBytes pdb = new Rfc2898DeriveBytes(EncryptionKey, new byte[] { 0x49, 0x76, 0x61, 0x6e, 0x20, 0x4d, 0x65, 0x64, 0x76, 0x65, 0x64, 0x65, 0x76 });
                encryptor.Key = pdb.GetBytes(32);
                encryptor.IV = pdb.GetBytes(16);
                using (MemoryStream ms = new MemoryStream())
                {
                    using (CryptoStream cs = new CryptoStream(ms, encryptor.CreateDecryptor(), CryptoStreamMode.Write))
                    {
                        cs.Write(cipherBytes, 0, cipherBytes.Length);
                        cs.Close();
                    }
                    cipherText = Encoding.Unicode.GetString(ms.ToArray());
                }
            }
            return cipherText;
        }
        private string Encrypt(string clearText, string key)
        {
            string EncryptionKey = key;
            byte[] clearBytes = Encoding.Unicode.GetBytes(clearText);
            using (Aes encryptor = Aes.Create())
            {
                Rfc2898DeriveBytes pdb = new Rfc2898DeriveBytes(EncryptionKey, new byte[] { 0x49, 0x76, 0x61, 0x6e, 0x20, 0x4d, 0x65, 0x64, 0x76, 0x65, 0x64, 0x65, 0x76 });
                encryptor.Key = pdb.GetBytes(32);
                encryptor.IV = pdb.GetBytes(16);
                using (MemoryStream ms = new MemoryStream())
                {
                    using (CryptoStream cs = new CryptoStream(ms, encryptor.CreateEncryptor(), CryptoStreamMode.Write))
                    {
                        cs.Write(clearBytes, 0, clearBytes.Length);
                        cs.Close();
                    }
                    clearText = Convert.ToBase64String(ms.ToArray());
                }
            }
            return clearText;
        }


        //
        private void passshow_Clicked(object sender, EventArgs e)
        {
            seepass.Source = ImageSource.FromFile("passwordhide.png");
            loginpassword.IsPassword = false;
        }

        private void LoginNav_Clicked(object sender, EventArgs e)
        {
            RegisterNav.TextColor = Color.Gray;
            LoginNav.TextColor = Color.Black;
            registerstack.IsVisible = false;
            loginstack.IsVisible = true;
        }

        private void RegisterNav_Clicked(object sender, EventArgs e)
        {
            RegisterNav.TextColor = Color.Black;
            LoginNav.TextColor = Color.Gray;
            registerstack.IsVisible = true;
            loginstack.IsVisible = false;
        }

        private void regreseepass_Clicked(object sender, EventArgs e)
        {
            regreseepass.Source = ImageSource.FromFile("passwordhide.png");
            registerconfpassword.IsPassword = false;
        }

        private void regseepass_Clicked(object sender, EventArgs e)
        {

            regseepass.Source = ImageSource.FromFile("passwordhide.png");
            registerpassword.IsPassword = false;
            
        }

        private async void Registerbutton_Clicked(object sender, EventArgs e)
        {
            loadingimage.IsVisible = true;
            bool fullnamecheck = string.IsNullOrWhiteSpace(registerfullname.Text);
            bool emailcheck = string.IsNullOrWhiteSpace(registerusername.Text);
            bool passwordcheck = string.IsNullOrWhiteSpace(registerpassword.Text);
            bool confpasswordcheck = string.IsNullOrWhiteSpace(registerconfpassword.Text);
            //bool agecheck = string.IsNullOrWhiteSpace(registerage.SelectedItem.ToString());
            bool phonecheck = string.IsNullOrWhiteSpace(registerphoneno.Text);
            
            if (fullnamecheck || emailcheck || passwordcheck || confpasswordcheck || phonecheck)
            {
                await DisplayAlert("Fields are empty !", "Please fill all the required fields to continue....", "Ok");
                loadingimage.IsVisible = false;
                return;
            }
            if (registerpassword.Text != registerconfpassword.Text)
            {
                await DisplayAlert("Passwords Don't Match!", "Your Passwords are not same....", "Ok");
                loadingimage.IsVisible = false;
                return;
            }
            var regexItempass = @"^(?=.*[A-Za-z])(?=.*\d)(?=.*[$@$!%*#?&])[A-Za-z\d$@$!%*#?&]{8,}$";
            var regexitememail=
                @"^(?("")("".+?(?<!\\)""@)|(([0-9a-z]((\.(?!\.))|[-!#\$%&'\*\+/=\?\^`\{\}\|~\w])*)(?<=[0-9a-z])@))" +
                @"(?(\[)(\[(\d{1,3}\.){3}\d{1,3}\])|(([0-9a-z][-\w]*[0-9a-z]*\.)+[a-z0-9][\-a-z0-9]{0,22}[a-z0-9]))$";
            if (!Regex.IsMatch(registerusername.Text,regexitememail))
            {
                await DisplayAlert("Not An Email", "The entered email is not correct.. Try Again!!", "Ok");
                registerusername.Text = string.Empty;
                loadingimage.IsVisible = false;
                return;
            }
            if (!Regex.IsMatch(registerpassword.Text,regexItempass))
            {
                await DisplayAlert("Use A Strong Password!", "The entered is not secure.. Try Again!! (Use One Lowercase, One UpperCase, One Special Character and should be more than 8 Characters to make it secure)", "Ok");
                loadingimage.IsVisible = false;
                return;
            }
            try
            {
                // key generation 

                Random random = new Random();
                string randomNumber = random.Next().ToString();
                
                string ecndeckey = "EXP"+registerfullname.Text.ToUpper()+registerphoneno.Text+"@"+randomNumber+"ARD";
                
                var userexistcheck = await App.MobileService.GetTable<Userbook>().Where(u => u.EmailId == registerusername.Text).Where(n => n.PhoneNo == registerphoneno.Text).ToListAsync();
                if (userexistcheck.Count !=0)
                {
                    await DisplayAlert("Email or Phone Already Exist!", "You have already registered with your same Phone or Email Id", "Ok");
                    loadingimage.IsVisible = false;
                    return;
                }
                var classorcourse = registerclasscourse.SelectedItem as Courses;
                Userbook userdatatoupload = new Userbook()
                {
                    FullName = registerfullname.Text,
                    Age = registerage.SelectedItem.ToString(),
                    EmailId = registerusername.Text.ToLower(),
                    Password = Encrypt(registerpassword.Text,ecndeckey),
                    PhoneNo = registerphoneno.Text,
                    ClassOrCourse = classorcourse.NameOfCourse,
                    DateRegisterd = DateTime.Today.ToShortDateString(),
                    EncryptionKey = ecndeckey

                };
                await App.MobileService.GetTable<Userbook>().InsertAsync(userdatatoupload);
                await DisplayAlert("Succesfully Registered! ", "Your Account has been saved succesfully", "Ok");
               
                var logineduserreg = (await App.MobileService.GetTable<Userbook>().Where(u => u.EmailId == registerusername.Text).ToListAsync()).FirstOrDefault();
                App.logineduser = logineduserreg; 
                loadingimage.IsVisible = false;
                await Navigation.PushModalAsync(new HomePage(), true);
                Application.Current.MainPage = new NavigationPage(new HomePage());
                
            }
            catch(HttpRequestException)
            {
                await DisplayAlert("No Internet Connection!", "Sorry, You don't have a internet connection... Try Again !", "Ok");
                loginpassword.IsVisible = false;
                await Navigation.PopModalAsync(true);
            }
            
	        catch (MobileServiceInvalidOperationException excep)
                {
                    loadingimage.IsVisible = false;
            	    await DisplayAlert("Something Happened!", "There was and Error occoured, the next prompt would be displaying the details of the error. Kimdly mail us the screen shot", "OK","Cancel");
                    await DisplayAlert("Error!", excep.ToString(), "Okay");
                    await Navigation.PopModalAsync(true);
            }
            catch (Exception ex)
            {
                await DisplayAlert("Some Error Occoured!", "Sorry, There was an internal error... Trying Again...." +ex.Message, "Ok");
                loadingimage.IsVisible = false;
                await Navigation.PopModalAsync(true);
            }
        }
        
        private async void LoginButton_Clicked(object sender, EventArgs e)
        {
            var oauthToken1 = await SecureStorage.GetAsync("loginid");
            var oauthToken2 = await SecureStorage.GetAsync("loginpass");
            if ( oauthToken1 != null)
            {
                seepass.IsVisible = false;
                rememberstack.IsVisible = false;
                loginusername.Text = oauthToken1;
                loginpassword.Text = oauthToken2;
                
            }
            
            loadingimage.IsVisible = true;
            bool usernamenull = String.IsNullOrEmpty(loginusername.Text);
            bool passwordnull = String.IsNullOrEmpty(loginpassword.Text);
            if(usernamenull|| passwordnull)
            {
                await DisplayAlert("Fields are Empty!", "Some Fields are empty, please fill them and try again...", "Ok");
                loadingimage.IsVisible = false;
                return;
            }
            try
            {
                var userbook = (await App.MobileService.GetTable<Userbook>().Where(u => u.EmailId == loginusername.Text).ToListAsync()).FirstOrDefault();
                if (userbook != null)
                {
                    string decrypted_passw = Decrypt(userbook.Password, userbook.EncryptionKey);
                    if (decrypted_passw != loginpassword.Text)
                    {
                        await DisplayAlert("Incorrect Password", "Sorry, Your password was wrong!", "Ok");
                        loadingimage.IsVisible = false;
                        return;
                    }

                    App.logineduser = userbook;
                    if (rememberme_checkbox.IsChecked == true)
                    {
                        try
                        {
                            await SecureStorage.SetAsync("loginid", loginusername.Text);
                            await SecureStorage.SetAsync("loginpass", decrypted_passw);
                        }
                        catch(Exception)
                        {
                            await DisplayAlert("Can't Save Login!", "This could be due to permission not given or an error occoured on our side", "Ok");
                        }
                        
                    }
                    await Navigation.PushModalAsync(new HomePage(), true);
                    App.Current.MainPage = new NavigationPage(new HomePage());
                    loadingimage.IsVisible = false;
                }
                else
                {
                    await DisplayAlert("No Records Found!", "Sorry, We couldnt find you Try Again!", "Ok");
                    loadingimage.IsVisible = false;
                    loginusername.Text=String.Empty;
		            loginpassword.Text=String.Empty;	
                }
            }
            catch(NullReferenceException ne)
            {
                await DisplayAlert("Null Reference Exception !", "This was a Null Exception " + ne.TargetSite, "Try Again");
                loadingimage.IsVisible = false;
                await Navigation.PopModalAsync(true);

            }
            catch(HttpRequestException)
            {
                await DisplayAlert("No Internet Connection", "Could Not Access Internet", "Ok");
                loadingimage.IsVisible = false;
                await Navigation.PopModalAsync(true);
            }
        }

        private async void BackButton_Clicked(object sender, EventArgs e)
        {
            await Navigation.PopModalAsync(true);
        }

        private async void forgetpass_Clicked(object sender, EventArgs e)
        {
            string action = await DisplayActionSheet("Change your password via", "Cancel", null, "Email", "Phone");
            if (action == "Email")
            {
                try
                {
                    var message = new EmailMessage
                    {
                        Subject = App.logineduser.FullName + ": I want to change my password ",
                        Body = "I am " + App.logineduser.FullName + " with id " + App.logineduser.Id + " and Email Id" + App.logineduser.EmailId + " want to change my password ...",
                        To = new List<string>
                    {
                        "developer@exploitblizzard.co","info@exploitblizzard.co","kshitijchaudhary175@gmail.com","daipsi175@gmail.com"
                    }

                    };
                    await Email.ComposeAsync(message);
                }
                catch (FeatureNotSupportedException)
                {
                    await DisplayAlert("Device Error", " Email is not supported on this device", "Ok");
                }
                catch (HttpRequestException)
                {
                    await DisplayAlert("Connection Error", "There is no active internet connection! Please try again later ", "Ok");
                }
                catch (Exception ex)
                {
                    await DisplayAlert("Error", " Some exception Occoured:" + ex.Message, "Ok");
                }
            }
            if(action == "Phone")
            {
                try
                {
                    PhoneDialer.Open("+91 8368729506");
                }
                catch (ArgumentNullException )
                {
                    // Number was null or white space
                }
                catch (FeatureNotSupportedException )
                {
                    await DisplayAlert("Feature not supported", "Your device don't support phone dialers", "Ok");
                }
                catch (Exception )
                {
                    await DisplayAlert("Some Error Occoured", "Dont worry it is under control", "Ok");
                }
            }
        }

        private async void deletecred_Clicked(object sender, EventArgs e)
        {
            SecureStorage.RemoveAll();
            deletecred.IsVisible = true;
            await DisplayAlert("Task successful", "Your Credentials have been successfully deleted ! Login Again", "Ok");
            await Navigation.PopModalAsync(true);
        }
    }
}