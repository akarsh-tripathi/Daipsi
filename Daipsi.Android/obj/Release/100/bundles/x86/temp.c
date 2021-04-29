/* This source code was produced by mkbundle, do not edit */

#ifndef NULL
#define NULL (void *)0
#endif

typedef struct {
	const char *name;
	const unsigned char *data;
	const unsigned int size;
} MonoBundledAssembly;

#define MONO_AOT_MODE_NORMAL 1
#define MONO_AOT_MODE_FULL 3
#define MONO_AOT_MODE_LLVMONLY 4
#ifndef __MKBUNDLE_API_H
#define __MKBUNDLE_API_H

#ifdef __cplusplus
using namespace xamarin::android;
#endif

typedef struct BundleMonoAPI
{
	void (*mono_register_bundled_assemblies) (const MonoBundledAssembly **assemblies);
	void (*mono_register_config_for_assembly) (const char* assembly_name, const char* config_xml);
	void (*mono_jit_set_aot_mode) (int mode);
	void (*mono_aot_register_module) (void** aot_info);
	void (*mono_config_parse_memory) (const char *buffer);
	void (*mono_register_machine_config) (const char *config_xml);
} BundleMonoAPI;

#if ANDROID
#include <stdarg.h>
#include <android/log.h>

#ifdef __cplusplus
[[maybe_unused]]
#endif
static void
mkbundle_log_error (const char *format, ...)
{
	va_list ap;

	va_start (ap, format);
	__android_log_vprint (ANDROID_LOG_ERROR, "mkbundle", format, ap);
	va_end (ap);
}
#endif // ANDROID
#endif // __MKBUNDLE_API_H
#define USE_COMPRESSED_ASSEMBLY

typedef struct _compressed_data {
	MonoBundledAssembly assembly;
	int compressed_size;
} CompressedAssembly;

extern const unsigned char assembly_data_System_Threading_Tasks_Extensions_dll [];
static CompressedAssembly assembly_bundle_System_Threading_Tasks_Extensions_dll = {{"System.Threading.Tasks.Extensions.dll", assembly_data_System_Threading_Tasks_Extensions_dll, 14216}, 7747};
extern const unsigned char assembly_data_System_Net_Http_dll [];
static CompressedAssembly assembly_bundle_System_Net_Http_dll = {{"System.Net.Http.dll", assembly_data_System_Net_Http_dll, 219136}, 92409};
extern const unsigned char assembly_data_Java_Interop_dll [];
static CompressedAssembly assembly_bundle_Java_Interop_dll = {{"Java.Interop.dll", assembly_data_Java_Interop_dll, 164864}, 55574};
extern const unsigned char assembly_data_Mono_Android_dll [];
static CompressedAssembly assembly_bundle_Mono_Android_dll = {{"Mono.Android.dll", assembly_data_Mono_Android_dll, 2147840}, 550342};
extern const unsigned char assembly_data_mscorlib_dll [];
static CompressedAssembly assembly_bundle_mscorlib_dll = {{"mscorlib.dll", assembly_data_mscorlib_dll, 2186240}, 787801};
extern const unsigned char assembly_data_System_Buffers_dll [];
static CompressedAssembly assembly_bundle_System_Buffers_dll = {{"System.Buffers.dll", assembly_data_System_Buffers_dll, 13704}, 7555};
extern const unsigned char assembly_data_System_Core_dll [];
static CompressedAssembly assembly_bundle_System_Core_dll = {{"System.Core.dll", assembly_data_System_Core_dll, 456704}, 180536};
extern const unsigned char assembly_data_System_dll [];
static CompressedAssembly assembly_bundle_System_dll = {{"System.dll", assembly_data_System_dll, 890368}, 367321};
extern const unsigned char assembly_data_System_Numerics_dll [];
static CompressedAssembly assembly_bundle_System_Numerics_dll = {{"System.Numerics.dll", assembly_data_System_Numerics_dll, 38912}, 18067};
extern const unsigned char assembly_data_System_Runtime_CompilerServices_Unsafe_dll [];
static CompressedAssembly assembly_bundle_System_Runtime_CompilerServices_Unsafe_dll = {{"System.Runtime.CompilerServices.Unsafe.dll", assembly_data_System_Runtime_CompilerServices_Unsafe_dll, 7680}, 2726};
extern const unsigned char assembly_data_System_Runtime_Serialization_dll [];
static CompressedAssembly assembly_bundle_System_Runtime_Serialization_dll = {{"System.Runtime.Serialization.dll", assembly_data_System_Runtime_Serialization_dll, 419328}, 156340};
extern const unsigned char assembly_data_System_Xml_dll [];
static CompressedAssembly assembly_bundle_System_Xml_dll = {{"System.Xml.dll", assembly_data_System_Xml_dll, 1397760}, 483053};
extern const unsigned char assembly_data_System_Xml_Linq_dll [];
static CompressedAssembly assembly_bundle_System_Xml_Linq_dll = {{"System.Xml.Linq.dll", assembly_data_System_Xml_Linq_dll, 66560}, 27765};
extern const unsigned char assembly_data_Xamarin_Android_Arch_Core_Common_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Arch_Core_Common_dll = {{"Xamarin.Android.Arch.Core.Common.dll", assembly_data_Xamarin_Android_Arch_Core_Common_dll, 5120}, 2048};
extern const unsigned char assembly_data_Xamarin_Android_Arch_Core_Runtime_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Arch_Core_Runtime_dll = {{"Xamarin.Android.Arch.Core.Runtime.dll", assembly_data_Xamarin_Android_Arch_Core_Runtime_dll, 5120}, 2022};
extern const unsigned char assembly_data_Xamarin_Android_Arch_Lifecycle_Common_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Arch_Lifecycle_Common_dll = {{"Xamarin.Android.Arch.Lifecycle.Common.dll", assembly_data_Xamarin_Android_Arch_Lifecycle_Common_dll, 5120}, 2040};
extern const unsigned char assembly_data_Xamarin_Android_Arch_Lifecycle_LiveData_Core_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Arch_Lifecycle_LiveData_Core_dll = {{"Xamarin.Android.Arch.Lifecycle.LiveData.Core.dll", assembly_data_Xamarin_Android_Arch_Lifecycle_LiveData_Core_dll, 5120}, 2074};
extern const unsigned char assembly_data_Xamarin_Android_Arch_Lifecycle_LiveData_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Arch_Lifecycle_LiveData_dll = {{"Xamarin.Android.Arch.Lifecycle.LiveData.dll", assembly_data_Xamarin_Android_Arch_Lifecycle_LiveData_dll, 5632}, 2072};
extern const unsigned char assembly_data_Xamarin_Android_Arch_Lifecycle_Runtime_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Arch_Lifecycle_Runtime_dll = {{"Xamarin.Android.Arch.Lifecycle.Runtime.dll", assembly_data_Xamarin_Android_Arch_Lifecycle_Runtime_dll, 5120}, 2043};
extern const unsigned char assembly_data_Xamarin_Android_Arch_Lifecycle_ViewModel_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Arch_Lifecycle_ViewModel_dll = {{"Xamarin.Android.Arch.Lifecycle.ViewModel.dll", assembly_data_Xamarin_Android_Arch_Lifecycle_ViewModel_dll, 5120}, 2050};
extern const unsigned char assembly_data_Xamarin_Android_Support_Annotations_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Support_Annotations_dll = {{"Xamarin.Android.Support.Annotations.dll", assembly_data_Xamarin_Android_Support_Annotations_dll, 5632}, 2205};
extern const unsigned char assembly_data_Xamarin_Android_Support_AsyncLayoutInflater_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Support_AsyncLayoutInflater_dll = {{"Xamarin.Android.Support.AsyncLayoutInflater.dll", assembly_data_Xamarin_Android_Support_AsyncLayoutInflater_dll, 5120}, 2054};
extern const unsigned char assembly_data_Xamarin_Android_Support_Collections_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Support_Collections_dll = {{"Xamarin.Android.Support.Collections.dll", assembly_data_Xamarin_Android_Support_Collections_dll, 5120}, 2027};
extern const unsigned char assembly_data_Xamarin_Android_Support_Compat_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Support_Compat_dll = {{"Xamarin.Android.Support.Compat.dll", assembly_data_Xamarin_Android_Support_Compat_dll, 9216}, 3054};
extern const unsigned char assembly_data_Xamarin_Android_Support_CoordinaterLayout_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Support_CoordinaterLayout_dll = {{"Xamarin.Android.Support.CoordinaterLayout.dll", assembly_data_Xamarin_Android_Support_CoordinaterLayout_dll, 5632}, 2105};
extern const unsigned char assembly_data_Xamarin_Android_Support_Core_UI_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Support_Core_UI_dll = {{"Xamarin.Android.Support.Core.UI.dll", assembly_data_Xamarin_Android_Support_Core_UI_dll, 5632}, 2182};
extern const unsigned char assembly_data_Xamarin_Android_Support_Core_Utils_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Support_Core_Utils_dll = {{"Xamarin.Android.Support.Core.Utils.dll", assembly_data_Xamarin_Android_Support_Core_Utils_dll, 5632}, 2116};
extern const unsigned char assembly_data_Xamarin_Android_Support_CursorAdapter_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Support_CursorAdapter_dll = {{"Xamarin.Android.Support.CursorAdapter.dll", assembly_data_Xamarin_Android_Support_CursorAdapter_dll, 5120}, 2052};
extern const unsigned char assembly_data_Xamarin_Android_Support_CustomTabs_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Support_CustomTabs_dll = {{"Xamarin.Android.Support.CustomTabs.dll", assembly_data_Xamarin_Android_Support_CustomTabs_dll, 9728}, 2756};
extern const unsigned char assembly_data_Xamarin_Android_Support_CustomView_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Support_CustomView_dll = {{"Xamarin.Android.Support.CustomView.dll", assembly_data_Xamarin_Android_Support_CustomView_dll, 5632}, 2077};
extern const unsigned char assembly_data_Xamarin_Android_Support_DocumentFile_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Support_DocumentFile_dll = {{"Xamarin.Android.Support.DocumentFile.dll", assembly_data_Xamarin_Android_Support_DocumentFile_dll, 5120}, 2037};
extern const unsigned char assembly_data_Xamarin_Android_Support_DrawerLayout_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Support_DrawerLayout_dll = {{"Xamarin.Android.Support.DrawerLayout.dll", assembly_data_Xamarin_Android_Support_DrawerLayout_dll, 5632}, 2074};
extern const unsigned char assembly_data_Xamarin_Android_Support_Interpolator_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Support_Interpolator_dll = {{"Xamarin.Android.Support.Interpolator.dll", assembly_data_Xamarin_Android_Support_Interpolator_dll, 5120}, 2031};
extern const unsigned char assembly_data_Xamarin_Android_Support_Loader_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Support_Loader_dll = {{"Xamarin.Android.Support.Loader.dll", assembly_data_Xamarin_Android_Support_Loader_dll, 5120}, 2043};
extern const unsigned char assembly_data_Xamarin_Android_Support_LocalBroadcastManager_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Support_LocalBroadcastManager_dll = {{"Xamarin.Android.Support.LocalBroadcastManager.dll", assembly_data_Xamarin_Android_Support_LocalBroadcastManager_dll, 5120}, 2061};
extern const unsigned char assembly_data_Xamarin_Android_Support_Print_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Support_Print_dll = {{"Xamarin.Android.Support.Print.dll", assembly_data_Xamarin_Android_Support_Print_dll, 5120}, 2017};
extern const unsigned char assembly_data_Xamarin_Android_Support_SlidingPaneLayout_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Support_SlidingPaneLayout_dll = {{"Xamarin.Android.Support.SlidingPaneLayout.dll", assembly_data_Xamarin_Android_Support_SlidingPaneLayout_dll, 5632}, 2069};
extern const unsigned char assembly_data_Xamarin_Android_Support_SwipeRefreshLayout_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Support_SwipeRefreshLayout_dll = {{"Xamarin.Android.Support.SwipeRefreshLayout.dll", assembly_data_Xamarin_Android_Support_SwipeRefreshLayout_dll, 5120}, 2065};
extern const unsigned char assembly_data_Xamarin_Android_Support_VersionedParcelable_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Support_VersionedParcelable_dll = {{"Xamarin.Android.Support.VersionedParcelable.dll", assembly_data_Xamarin_Android_Support_VersionedParcelable_dll, 6656}, 2307};
extern const unsigned char assembly_data_Xamarin_Android_Support_ViewPager_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Android_Support_ViewPager_dll = {{"Xamarin.Android.Support.ViewPager.dll", assembly_data_Xamarin_Android_Support_ViewPager_dll, 5632}, 2058};
extern const unsigned char assembly_data_Xamarin_AndroidX_Annotation_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_Annotation_dll = {{"Xamarin.AndroidX.Annotation.dll", assembly_data_Xamarin_AndroidX_Annotation_dll, 6144}, 2324};
extern const unsigned char assembly_data_Xamarin_AndroidX_AppCompat_AppCompatResources_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_AppCompat_AppCompatResources_dll = {{"Xamarin.AndroidX.AppCompat.AppCompatResources.dll", assembly_data_Xamarin_AndroidX_AppCompat_AppCompatResources_dll, 19456}, 6230};
extern const unsigned char assembly_data_Xamarin_AndroidX_AppCompat_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_AppCompat_dll = {{"Xamarin.AndroidX.AppCompat.dll", assembly_data_Xamarin_AndroidX_AppCompat_dll, 481280}, 106053};
extern const unsigned char assembly_data_Xamarin_AndroidX_Arch_Core_Common_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_Arch_Core_Common_dll = {{"Xamarin.AndroidX.Arch.Core.Common.dll", assembly_data_Xamarin_AndroidX_Arch_Core_Common_dll, 6656}, 2421};
extern const unsigned char assembly_data_Xamarin_AndroidX_Arch_Core_Runtime_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_Arch_Core_Runtime_dll = {{"Xamarin.AndroidX.Arch.Core.Runtime.dll", assembly_data_Xamarin_AndroidX_Arch_Core_Runtime_dll, 6144}, 2365};
extern const unsigned char assembly_data_Xamarin_AndroidX_AsyncLayoutInflater_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_AsyncLayoutInflater_dll = {{"Xamarin.AndroidX.AsyncLayoutInflater.dll", assembly_data_Xamarin_AndroidX_AsyncLayoutInflater_dll, 6144}, 2311};
extern const unsigned char assembly_data_Xamarin_AndroidX_Browser_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_Browser_dll = {{"Xamarin.AndroidX.Browser.dll", assembly_data_Xamarin_AndroidX_Browser_dll, 68096}, 17039};
extern const unsigned char assembly_data_Xamarin_AndroidX_CardView_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_CardView_dll = {{"Xamarin.AndroidX.CardView.dll", assembly_data_Xamarin_AndroidX_CardView_dll, 18432}, 6362};
extern const unsigned char assembly_data_Xamarin_AndroidX_Collection_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_Collection_dll = {{"Xamarin.AndroidX.Collection.dll", assembly_data_Xamarin_AndroidX_Collection_dll, 6656}, 2431};
extern const unsigned char assembly_data_Xamarin_AndroidX_CoordinatorLayout_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_CoordinatorLayout_dll = {{"Xamarin.AndroidX.CoordinatorLayout.dll", assembly_data_Xamarin_AndroidX_CoordinatorLayout_dll, 78848}, 16529};
extern const unsigned char assembly_data_Xamarin_AndroidX_Core_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_Core_dll = {{"Xamarin.AndroidX.Core.dll", assembly_data_Xamarin_AndroidX_Core_dll, 683520}, 144482};
extern const unsigned char assembly_data_Xamarin_AndroidX_CursorAdapter_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_CursorAdapter_dll = {{"Xamarin.AndroidX.CursorAdapter.dll", assembly_data_Xamarin_AndroidX_CursorAdapter_dll, 6656}, 2376};
extern const unsigned char assembly_data_Xamarin_AndroidX_CustomView_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_CustomView_dll = {{"Xamarin.AndroidX.CustomView.dll", assembly_data_Xamarin_AndroidX_CustomView_dll, 10240}, 4211};
extern const unsigned char assembly_data_Xamarin_AndroidX_DocumentFile_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_DocumentFile_dll = {{"Xamarin.AndroidX.DocumentFile.dll", assembly_data_Xamarin_AndroidX_DocumentFile_dll, 6144}, 2293};
extern const unsigned char assembly_data_Xamarin_AndroidX_DrawerLayout_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_DrawerLayout_dll = {{"Xamarin.AndroidX.DrawerLayout.dll", assembly_data_Xamarin_AndroidX_DrawerLayout_dll, 45056}, 13519};
extern const unsigned char assembly_data_Xamarin_AndroidX_Fragment_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_Fragment_dll = {{"Xamarin.AndroidX.Fragment.dll", assembly_data_Xamarin_AndroidX_Fragment_dll, 162816}, 38189};
extern const unsigned char assembly_data_Xamarin_AndroidX_Interpolator_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_Interpolator_dll = {{"Xamarin.AndroidX.Interpolator.dll", assembly_data_Xamarin_AndroidX_Interpolator_dll, 6656}, 2398};
extern const unsigned char assembly_data_Xamarin_AndroidX_Legacy_Support_Core_UI_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_Legacy_Support_Core_UI_dll = {{"Xamarin.AndroidX.Legacy.Support.Core.UI.dll", assembly_data_Xamarin_AndroidX_Legacy_Support_Core_UI_dll, 16896}, 5930};
extern const unsigned char assembly_data_Xamarin_AndroidX_Legacy_Support_Core_Utils_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_Legacy_Support_Core_Utils_dll = {{"Xamarin.AndroidX.Legacy.Support.Core.Utils.dll", assembly_data_Xamarin_AndroidX_Legacy_Support_Core_Utils_dll, 6144}, 2348};
extern const unsigned char assembly_data_Xamarin_AndroidX_Lifecycle_Common_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_Lifecycle_Common_dll = {{"Xamarin.AndroidX.Lifecycle.Common.dll", assembly_data_Xamarin_AndroidX_Lifecycle_Common_dll, 16384}, 6096};
extern const unsigned char assembly_data_Xamarin_AndroidX_Lifecycle_LiveData_Core_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_Lifecycle_LiveData_Core_dll = {{"Xamarin.AndroidX.Lifecycle.LiveData.Core.dll", assembly_data_Xamarin_AndroidX_Lifecycle_LiveData_Core_dll, 16896}, 6211};
extern const unsigned char assembly_data_Xamarin_AndroidX_Lifecycle_LiveData_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_Lifecycle_LiveData_dll = {{"Xamarin.AndroidX.Lifecycle.LiveData.dll", assembly_data_Xamarin_AndroidX_Lifecycle_LiveData_dll, 6144}, 2379};
extern const unsigned char assembly_data_Xamarin_AndroidX_Lifecycle_Runtime_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_Lifecycle_Runtime_dll = {{"Xamarin.AndroidX.Lifecycle.Runtime.dll", assembly_data_Xamarin_AndroidX_Lifecycle_Runtime_dll, 6144}, 2339};
extern const unsigned char assembly_data_Xamarin_AndroidX_Lifecycle_ViewModel_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_Lifecycle_ViewModel_dll = {{"Xamarin.AndroidX.Lifecycle.ViewModel.dll", assembly_data_Xamarin_AndroidX_Lifecycle_ViewModel_dll, 18432}, 6292};
extern const unsigned char assembly_data_Xamarin_AndroidX_Loader_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_Loader_dll = {{"Xamarin.AndroidX.Loader.dll", assembly_data_Xamarin_AndroidX_Loader_dll, 37888}, 11530};
extern const unsigned char assembly_data_Xamarin_AndroidX_LocalBroadcastManager_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_LocalBroadcastManager_dll = {{"Xamarin.AndroidX.LocalBroadcastManager.dll", assembly_data_Xamarin_AndroidX_LocalBroadcastManager_dll, 6144}, 2330};
extern const unsigned char assembly_data_Xamarin_AndroidX_Media_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_Media_dll = {{"Xamarin.AndroidX.Media.dll", assembly_data_Xamarin_AndroidX_Media_dll, 220160}, 52018};
extern const unsigned char assembly_data_Xamarin_AndroidX_Print_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_Print_dll = {{"Xamarin.AndroidX.Print.dll", assembly_data_Xamarin_AndroidX_Print_dll, 5632}, 2242};
extern const unsigned char assembly_data_Xamarin_AndroidX_RecyclerView_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_RecyclerView_dll = {{"Xamarin.AndroidX.RecyclerView.dll", assembly_data_Xamarin_AndroidX_RecyclerView_dll, 418816}, 86774};
extern const unsigned char assembly_data_Xamarin_AndroidX_SlidingPaneLayout_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_SlidingPaneLayout_dll = {{"Xamarin.AndroidX.SlidingPaneLayout.dll", assembly_data_Xamarin_AndroidX_SlidingPaneLayout_dll, 6656}, 2398};
extern const unsigned char assembly_data_Xamarin_AndroidX_SwipeRefreshLayout_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_SwipeRefreshLayout_dll = {{"Xamarin.AndroidX.SwipeRefreshLayout.dll", assembly_data_Xamarin_AndroidX_SwipeRefreshLayout_dll, 40960}, 12491};
extern const unsigned char assembly_data_Xamarin_AndroidX_Transition_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_Transition_dll = {{"Xamarin.AndroidX.Transition.dll", assembly_data_Xamarin_AndroidX_Transition_dll, 9728}, 2839};
extern const unsigned char assembly_data_Xamarin_AndroidX_VectorDrawable_Animated_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_VectorDrawable_Animated_dll = {{"Xamarin.AndroidX.VectorDrawable.Animated.dll", assembly_data_Xamarin_AndroidX_VectorDrawable_Animated_dll, 7680}, 2509};
extern const unsigned char assembly_data_Xamarin_AndroidX_VectorDrawable_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_VectorDrawable_dll = {{"Xamarin.AndroidX.VectorDrawable.dll", assembly_data_Xamarin_AndroidX_VectorDrawable_dll, 6656}, 2364};
extern const unsigned char assembly_data_Xamarin_AndroidX_VersionedParcelable_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_VersionedParcelable_dll = {{"Xamarin.AndroidX.VersionedParcelable.dll", assembly_data_Xamarin_AndroidX_VersionedParcelable_dll, 11264}, 4374};
extern const unsigned char assembly_data_Xamarin_AndroidX_ViewPager_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_ViewPager_dll = {{"Xamarin.AndroidX.ViewPager.dll", assembly_data_Xamarin_AndroidX_ViewPager_dll, 59392}, 16707};
extern const unsigned char assembly_data_Xamarin_Google_Android_Material_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Google_Android_Material_dll = {{"Xamarin.Google.Android.Material.dll", assembly_data_Xamarin_Google_Android_Material_dll, 281088}, 61948};
extern const unsigned char assembly_data_System_Data_dll [];
static CompressedAssembly assembly_bundle_System_Data_dll = {{"System.Data.dll", assembly_data_System_Data_dll, 748032}, 260541};
extern const unsigned char assembly_data_System_Drawing_Common_dll [];
static CompressedAssembly assembly_bundle_System_Drawing_Common_dll = {{"System.Drawing.Common.dll", assembly_data_System_Drawing_Common_dll, 26112}, 12325};
extern const unsigned char assembly_data_System_Web_Services_dll [];
static CompressedAssembly assembly_bundle_System_Web_Services_dll = {{"System.Web.Services.dll", assembly_data_System_Web_Services_dll, 38912}, 11428};
extern const unsigned char assembly_data_Mono_Security_dll [];
static CompressedAssembly assembly_bundle_Mono_Security_dll = {{"Mono.Security.dll", assembly_data_Mono_Security_dll, 121856}, 53005};
extern const unsigned char assembly_data_System_ServiceModel_Internals_dll [];
static CompressedAssembly assembly_bundle_System_ServiceModel_Internals_dll = {{"System.ServiceModel.Internals.dll", assembly_data_System_ServiceModel_Internals_dll, 55808}, 21140};
extern const unsigned char assembly_data_Azure_Core_dll [];
static CompressedAssembly assembly_bundle_Azure_Core_dll = {{"Azure.Core.dll", assembly_data_Azure_Core_dll, 142848}, 61957};
extern const unsigned char assembly_data_Azure_Storage_Blobs_dll [];
static CompressedAssembly assembly_bundle_Azure_Storage_Blobs_dll = {{"Azure.Storage.Blobs.dll", assembly_data_Azure_Storage_Blobs_dll, 891392}, 280723};
extern const unsigned char assembly_data_Azure_Storage_Common_dll [];
static CompressedAssembly assembly_bundle_Azure_Storage_Common_dll = {{"Azure.Storage.Common.dll", assembly_data_Azure_Storage_Common_dll, 69120}, 29546};
extern const unsigned char assembly_data_Daipsi_dll [];
static CompressedAssembly assembly_bundle_Daipsi_dll = {{"Daipsi.dll", assembly_data_Daipsi_dll, 165376}, 49139};
extern const unsigned char assembly_data_ExoPlayer_Core_dll [];
static CompressedAssembly assembly_bundle_ExoPlayer_Core_dll = {{"ExoPlayer.Core.dll", assembly_data_ExoPlayer_Core_dll, 2651136}, 568049};
extern const unsigned char assembly_data_ExoPlayer_Dash_dll [];
static CompressedAssembly assembly_bundle_ExoPlayer_Dash_dll = {{"ExoPlayer.Dash.dll", assembly_data_ExoPlayer_Dash_dll, 218624}, 48225};
extern const unsigned char assembly_data_ExoPlayer_dll [];
static CompressedAssembly assembly_bundle_ExoPlayer_dll = {{"ExoPlayer.dll", assembly_data_ExoPlayer_dll, 7168}, 3482};
extern const unsigned char assembly_data_ExoPlayer_Ext_MediaSession_dll [];
static CompressedAssembly assembly_bundle_ExoPlayer_Ext_MediaSession_dll = {{"ExoPlayer.Ext.MediaSession.dll", assembly_data_ExoPlayer_Ext_MediaSession_dll, 95232}, 21535};
extern const unsigned char assembly_data_ExoPlayer_Hls_dll [];
static CompressedAssembly assembly_bundle_ExoPlayer_Hls_dll = {{"ExoPlayer.Hls.dll", assembly_data_ExoPlayer_Hls_dll, 136704}, 34503};
extern const unsigned char assembly_data_ExoPlayer_SmoothStreaming_dll [];
static CompressedAssembly assembly_bundle_ExoPlayer_SmoothStreaming_dll = {{"ExoPlayer.SmoothStreaming.dll", assembly_data_ExoPlayer_SmoothStreaming_dll, 73728}, 18974};
extern const unsigned char assembly_data_ExoPlayer_UI_dll [];
static CompressedAssembly assembly_bundle_ExoPlayer_UI_dll = {{"ExoPlayer.UI.dll", assembly_data_ExoPlayer_UI_dll, 191488}, 49967};
extern const unsigned char assembly_data_FFImageLoading_dll [];
static CompressedAssembly assembly_bundle_FFImageLoading_dll = {{"FFImageLoading.dll", assembly_data_FFImageLoading_dll, 185856}, 79363};
extern const unsigned char assembly_data_FFImageLoading_Forms_dll [];
static CompressedAssembly assembly_bundle_FFImageLoading_Forms_dll = {{"FFImageLoading.Forms.dll", assembly_data_FFImageLoading_Forms_dll, 33280}, 13813};
extern const unsigned char assembly_data_FFImageLoading_Forms_Platform_dll [];
static CompressedAssembly assembly_bundle_FFImageLoading_Forms_Platform_dll = {{"FFImageLoading.Forms.Platform.dll", assembly_data_FFImageLoading_Forms_Platform_dll, 30208}, 13134};
extern const unsigned char assembly_data_FFImageLoading_Platform_dll [];
static CompressedAssembly assembly_bundle_FFImageLoading_Platform_dll = {{"FFImageLoading.Platform.dll", assembly_data_FFImageLoading_Platform_dll, 91136}, 40361};
extern const unsigned char assembly_data_FormsViewGroup_dll [];
static CompressedAssembly assembly_bundle_FormsViewGroup_dll = {{"FormsViewGroup.dll", assembly_data_FormsViewGroup_dll, 15360}, 5879};
extern const unsigned char assembly_data_ImageCircle_Forms_Plugin_dll [];
static CompressedAssembly assembly_bundle_ImageCircle_Forms_Plugin_dll = {{"ImageCircle.Forms.Plugin.dll", assembly_data_ImageCircle_Forms_Plugin_dll, 9216}, 4246};
extern const unsigned char assembly_data_MediaManager_dll [];
static CompressedAssembly assembly_bundle_MediaManager_dll = {{"MediaManager.dll", assembly_data_MediaManager_dll, 190464}, 74848};
extern const unsigned char assembly_data_MediaManager_Forms_dll [];
static CompressedAssembly assembly_bundle_MediaManager_Forms_dll = {{"MediaManager.Forms.dll", assembly_data_MediaManager_Forms_dll, 153600}, 50561};
extern const unsigned char assembly_data_Microsoft_Azure_Mobile_Client_dll [];
static CompressedAssembly assembly_bundle_Microsoft_Azure_Mobile_Client_dll = {{"Microsoft.Azure.Mobile.Client.dll", assembly_data_Microsoft_Azure_Mobile_Client_dll, 345472}, 137829};
extern const unsigned char assembly_data_Microsoft_Bcl_AsyncInterfaces_dll [];
static CompressedAssembly assembly_bundle_Microsoft_Bcl_AsyncInterfaces_dll = {{"Microsoft.Bcl.AsyncInterfaces.dll", assembly_data_Microsoft_Bcl_AsyncInterfaces_dll, 5120}, 1953};
extern const unsigned char assembly_data_Newtonsoft_Json_dll [];
static CompressedAssembly assembly_bundle_Newtonsoft_Json_dll = {{"Newtonsoft.Json.dll", assembly_data_Newtonsoft_Json_dll, 682496}, 254508};
extern const unsigned char assembly_data_PCLCrypto_dll [];
static CompressedAssembly assembly_bundle_PCLCrypto_dll = {{"PCLCrypto.dll", assembly_data_PCLCrypto_dll, 57344}, 25148};
extern const unsigned char assembly_data_PInvoke_BCrypt_dll [];
static CompressedAssembly assembly_bundle_PInvoke_BCrypt_dll = {{"PInvoke.BCrypt.dll", assembly_data_PInvoke_BCrypt_dll, 31744}, 12913};
extern const unsigned char assembly_data_PInvoke_Kernel32_dll [];
static CompressedAssembly assembly_bundle_PInvoke_Kernel32_dll = {{"PInvoke.Kernel32.dll", assembly_data_PInvoke_Kernel32_dll, 17408}, 7878};
extern const unsigned char assembly_data_PInvoke_NCrypt_dll [];
static CompressedAssembly assembly_bundle_PInvoke_NCrypt_dll = {{"PInvoke.NCrypt.dll", assembly_data_PInvoke_NCrypt_dll, 31744}, 12870};
extern const unsigned char assembly_data_PInvoke_Windows_Core_dll [];
static CompressedAssembly assembly_bundle_PInvoke_Windows_Core_dll = {{"PInvoke.Windows.Core.dll", assembly_data_PInvoke_Windows_Core_dll, 235520}, 77812};
extern const unsigned char assembly_data_Plugin_Connectivity_Abstractions_dll [];
static CompressedAssembly assembly_bundle_Plugin_Connectivity_Abstractions_dll = {{"Plugin.Connectivity.Abstractions.dll", assembly_data_Plugin_Connectivity_Abstractions_dll, 7680}, 2845};
extern const unsigned char assembly_data_Plugin_Connectivity_dll [];
static CompressedAssembly assembly_bundle_Plugin_Connectivity_dll = {{"Plugin.Connectivity.dll", assembly_data_Plugin_Connectivity_dll, 17408}, 7819};
extern const unsigned char assembly_data_Plugin_Media_dll [];
static CompressedAssembly assembly_bundle_Plugin_Media_dll = {{"Plugin.Media.dll", assembly_data_Plugin_Media_dll, 65536}, 28324};
extern const unsigned char assembly_data_System_Diagnostics_DiagnosticSource_dll [];
static CompressedAssembly assembly_bundle_System_Diagnostics_DiagnosticSource_dll = {{"System.Diagnostics.DiagnosticSource.dll", assembly_data_System_Diagnostics_DiagnosticSource_dll, 39424}, 17426};
extern const unsigned char assembly_data_System_Text_Encodings_Web_dll [];
static CompressedAssembly assembly_bundle_System_Text_Encodings_Web_dll = {{"System.Text.Encodings.Web.dll", assembly_data_System_Text_Encodings_Web_dll, 48128}, 18198};
extern const unsigned char assembly_data_System_Text_Json_dll [];
static CompressedAssembly assembly_bundle_System_Text_Json_dll = {{"System.Text.Json.dll", assembly_data_System_Text_Json_dll, 284160}, 100316};
extern const unsigned char assembly_data_Validation_dll [];
static CompressedAssembly assembly_bundle_Validation_dll = {{"Validation.dll", assembly_data_Validation_dll, 13824}, 6034};
extern const unsigned char assembly_data_Xamarin_AndroidX_Activity_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_Activity_dll = {{"Xamarin.AndroidX.Activity.dll", assembly_data_Xamarin_AndroidX_Activity_dll, 18944}, 6690};
extern const unsigned char assembly_data_Xamarin_AndroidX_Lifecycle_ViewModelSavedState_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_Lifecycle_ViewModelSavedState_dll = {{"Xamarin.AndroidX.Lifecycle.ViewModelSavedState.dll", assembly_data_Xamarin_AndroidX_Lifecycle_ViewModelSavedState_dll, 6144}, 2349};
extern const unsigned char assembly_data_Xamarin_AndroidX_SavedState_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_SavedState_dll = {{"Xamarin.AndroidX.SavedState.dll", assembly_data_Xamarin_AndroidX_SavedState_dll, 13824}, 5335};
extern const unsigned char assembly_data_Xamarin_AndroidX_ViewPager2_dll [];
static CompressedAssembly assembly_bundle_Xamarin_AndroidX_ViewPager2_dll = {{"Xamarin.AndroidX.ViewPager2.dll", assembly_data_Xamarin_AndroidX_ViewPager2_dll, 7168}, 2577};
extern const unsigned char assembly_data_Xamarin_CommunityToolkit_dll [];
static CompressedAssembly assembly_bundle_Xamarin_CommunityToolkit_dll = {{"Xamarin.CommunityToolkit.dll", assembly_data_Xamarin_CommunityToolkit_dll, 326656}, 113141};
extern const unsigned char assembly_data_Xamarin_Essentials_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Essentials_dll = {{"Xamarin.Essentials.dll", assembly_data_Xamarin_Essentials_dll, 67584}, 30729};
extern const unsigned char assembly_data_Xamarin_Forms_Core_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Forms_Core_dll = {{"Xamarin.Forms.Core.dll", assembly_data_Xamarin_Forms_Core_dll, 1203200}, 443062};
extern const unsigned char assembly_data_Xamarin_Forms_PancakeView_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Forms_PancakeView_dll = {{"Xamarin.Forms.PancakeView.dll", assembly_data_Xamarin_Forms_PancakeView_dll, 152064}, 51279};
extern const unsigned char assembly_data_Xamarin_Forms_Platform_Android_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Forms_Platform_Android_dll = {{"Xamarin.Forms.Platform.Android.dll", assembly_data_Xamarin_Forms_Platform_Android_dll, 847360}, 335780};
extern const unsigned char assembly_data_Xamarin_Forms_Platform_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Forms_Platform_dll = {{"Xamarin.Forms.Platform.dll", assembly_data_Xamarin_Forms_Platform_dll, 170496}, 50329};
extern const unsigned char assembly_data_Xamarin_Forms_Xaml_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Forms_Xaml_dll = {{"Xamarin.Forms.Xaml.dll", assembly_data_Xamarin_Forms_Xaml_dll, 103424}, 44540};
extern const unsigned char assembly_data_Xamarin_Google_Guava_ListenableFuture_dll [];
static CompressedAssembly assembly_bundle_Xamarin_Google_Guava_ListenableFuture_dll = {{"Xamarin.Google.Guava.ListenableFuture.dll", assembly_data_Xamarin_Google_Guava_ListenableFuture_dll, 18072}, 9268};
extern const unsigned char assembly_data_Daipsi_Android_dll [];
static CompressedAssembly assembly_bundle_Daipsi_Android_dll = {{"Daipsi.Android.dll", assembly_data_Daipsi_Android_dll, 1172992}, 750783};

static const CompressedAssembly *compressed [] = {
	&assembly_bundle_System_Threading_Tasks_Extensions_dll,
	&assembly_bundle_System_Net_Http_dll,
	&assembly_bundle_Java_Interop_dll,
	&assembly_bundle_Mono_Android_dll,
	&assembly_bundle_mscorlib_dll,
	&assembly_bundle_System_Buffers_dll,
	&assembly_bundle_System_Core_dll,
	&assembly_bundle_System_dll,
	&assembly_bundle_System_Numerics_dll,
	&assembly_bundle_System_Runtime_CompilerServices_Unsafe_dll,
	&assembly_bundle_System_Runtime_Serialization_dll,
	&assembly_bundle_System_Xml_dll,
	&assembly_bundle_System_Xml_Linq_dll,
	&assembly_bundle_Xamarin_Android_Arch_Core_Common_dll,
	&assembly_bundle_Xamarin_Android_Arch_Core_Runtime_dll,
	&assembly_bundle_Xamarin_Android_Arch_Lifecycle_Common_dll,
	&assembly_bundle_Xamarin_Android_Arch_Lifecycle_LiveData_Core_dll,
	&assembly_bundle_Xamarin_Android_Arch_Lifecycle_LiveData_dll,
	&assembly_bundle_Xamarin_Android_Arch_Lifecycle_Runtime_dll,
	&assembly_bundle_Xamarin_Android_Arch_Lifecycle_ViewModel_dll,
	&assembly_bundle_Xamarin_Android_Support_Annotations_dll,
	&assembly_bundle_Xamarin_Android_Support_AsyncLayoutInflater_dll,
	&assembly_bundle_Xamarin_Android_Support_Collections_dll,
	&assembly_bundle_Xamarin_Android_Support_Compat_dll,
	&assembly_bundle_Xamarin_Android_Support_CoordinaterLayout_dll,
	&assembly_bundle_Xamarin_Android_Support_Core_UI_dll,
	&assembly_bundle_Xamarin_Android_Support_Core_Utils_dll,
	&assembly_bundle_Xamarin_Android_Support_CursorAdapter_dll,
	&assembly_bundle_Xamarin_Android_Support_CustomTabs_dll,
	&assembly_bundle_Xamarin_Android_Support_CustomView_dll,
	&assembly_bundle_Xamarin_Android_Support_DocumentFile_dll,
	&assembly_bundle_Xamarin_Android_Support_DrawerLayout_dll,
	&assembly_bundle_Xamarin_Android_Support_Interpolator_dll,
	&assembly_bundle_Xamarin_Android_Support_Loader_dll,
	&assembly_bundle_Xamarin_Android_Support_LocalBroadcastManager_dll,
	&assembly_bundle_Xamarin_Android_Support_Print_dll,
	&assembly_bundle_Xamarin_Android_Support_SlidingPaneLayout_dll,
	&assembly_bundle_Xamarin_Android_Support_SwipeRefreshLayout_dll,
	&assembly_bundle_Xamarin_Android_Support_VersionedParcelable_dll,
	&assembly_bundle_Xamarin_Android_Support_ViewPager_dll,
	&assembly_bundle_Xamarin_AndroidX_Annotation_dll,
	&assembly_bundle_Xamarin_AndroidX_AppCompat_AppCompatResources_dll,
	&assembly_bundle_Xamarin_AndroidX_AppCompat_dll,
	&assembly_bundle_Xamarin_AndroidX_Arch_Core_Common_dll,
	&assembly_bundle_Xamarin_AndroidX_Arch_Core_Runtime_dll,
	&assembly_bundle_Xamarin_AndroidX_AsyncLayoutInflater_dll,
	&assembly_bundle_Xamarin_AndroidX_Browser_dll,
	&assembly_bundle_Xamarin_AndroidX_CardView_dll,
	&assembly_bundle_Xamarin_AndroidX_Collection_dll,
	&assembly_bundle_Xamarin_AndroidX_CoordinatorLayout_dll,
	&assembly_bundle_Xamarin_AndroidX_Core_dll,
	&assembly_bundle_Xamarin_AndroidX_CursorAdapter_dll,
	&assembly_bundle_Xamarin_AndroidX_CustomView_dll,
	&assembly_bundle_Xamarin_AndroidX_DocumentFile_dll,
	&assembly_bundle_Xamarin_AndroidX_DrawerLayout_dll,
	&assembly_bundle_Xamarin_AndroidX_Fragment_dll,
	&assembly_bundle_Xamarin_AndroidX_Interpolator_dll,
	&assembly_bundle_Xamarin_AndroidX_Legacy_Support_Core_UI_dll,
	&assembly_bundle_Xamarin_AndroidX_Legacy_Support_Core_Utils_dll,
	&assembly_bundle_Xamarin_AndroidX_Lifecycle_Common_dll,
	&assembly_bundle_Xamarin_AndroidX_Lifecycle_LiveData_Core_dll,
	&assembly_bundle_Xamarin_AndroidX_Lifecycle_LiveData_dll,
	&assembly_bundle_Xamarin_AndroidX_Lifecycle_Runtime_dll,
	&assembly_bundle_Xamarin_AndroidX_Lifecycle_ViewModel_dll,
	&assembly_bundle_Xamarin_AndroidX_Loader_dll,
	&assembly_bundle_Xamarin_AndroidX_LocalBroadcastManager_dll,
	&assembly_bundle_Xamarin_AndroidX_Media_dll,
	&assembly_bundle_Xamarin_AndroidX_Print_dll,
	&assembly_bundle_Xamarin_AndroidX_RecyclerView_dll,
	&assembly_bundle_Xamarin_AndroidX_SlidingPaneLayout_dll,
	&assembly_bundle_Xamarin_AndroidX_SwipeRefreshLayout_dll,
	&assembly_bundle_Xamarin_AndroidX_Transition_dll,
	&assembly_bundle_Xamarin_AndroidX_VectorDrawable_Animated_dll,
	&assembly_bundle_Xamarin_AndroidX_VectorDrawable_dll,
	&assembly_bundle_Xamarin_AndroidX_VersionedParcelable_dll,
	&assembly_bundle_Xamarin_AndroidX_ViewPager_dll,
	&assembly_bundle_Xamarin_Google_Android_Material_dll,
	&assembly_bundle_System_Data_dll,
	&assembly_bundle_System_Drawing_Common_dll,
	&assembly_bundle_System_Web_Services_dll,
	&assembly_bundle_Mono_Security_dll,
	&assembly_bundle_System_ServiceModel_Internals_dll,
	&assembly_bundle_Azure_Core_dll,
	&assembly_bundle_Azure_Storage_Blobs_dll,
	&assembly_bundle_Azure_Storage_Common_dll,
	&assembly_bundle_Daipsi_dll,
	&assembly_bundle_ExoPlayer_Core_dll,
	&assembly_bundle_ExoPlayer_Dash_dll,
	&assembly_bundle_ExoPlayer_dll,
	&assembly_bundle_ExoPlayer_Ext_MediaSession_dll,
	&assembly_bundle_ExoPlayer_Hls_dll,
	&assembly_bundle_ExoPlayer_SmoothStreaming_dll,
	&assembly_bundle_ExoPlayer_UI_dll,
	&assembly_bundle_FFImageLoading_dll,
	&assembly_bundle_FFImageLoading_Forms_dll,
	&assembly_bundle_FFImageLoading_Forms_Platform_dll,
	&assembly_bundle_FFImageLoading_Platform_dll,
	&assembly_bundle_FormsViewGroup_dll,
	&assembly_bundle_ImageCircle_Forms_Plugin_dll,
	&assembly_bundle_MediaManager_dll,
	&assembly_bundle_MediaManager_Forms_dll,
	&assembly_bundle_Microsoft_Azure_Mobile_Client_dll,
	&assembly_bundle_Microsoft_Bcl_AsyncInterfaces_dll,
	&assembly_bundle_Newtonsoft_Json_dll,
	&assembly_bundle_PCLCrypto_dll,
	&assembly_bundle_PInvoke_BCrypt_dll,
	&assembly_bundle_PInvoke_Kernel32_dll,
	&assembly_bundle_PInvoke_NCrypt_dll,
	&assembly_bundle_PInvoke_Windows_Core_dll,
	&assembly_bundle_Plugin_Connectivity_Abstractions_dll,
	&assembly_bundle_Plugin_Connectivity_dll,
	&assembly_bundle_Plugin_Media_dll,
	&assembly_bundle_System_Diagnostics_DiagnosticSource_dll,
	&assembly_bundle_System_Text_Encodings_Web_dll,
	&assembly_bundle_System_Text_Json_dll,
	&assembly_bundle_Validation_dll,
	&assembly_bundle_Xamarin_AndroidX_Activity_dll,
	&assembly_bundle_Xamarin_AndroidX_Lifecycle_ViewModelSavedState_dll,
	&assembly_bundle_Xamarin_AndroidX_SavedState_dll,
	&assembly_bundle_Xamarin_AndroidX_ViewPager2_dll,
	&assembly_bundle_Xamarin_CommunityToolkit_dll,
	&assembly_bundle_Xamarin_Essentials_dll,
	&assembly_bundle_Xamarin_Forms_Core_dll,
	&assembly_bundle_Xamarin_Forms_PancakeView_dll,
	&assembly_bundle_Xamarin_Forms_Platform_Android_dll,
	&assembly_bundle_Xamarin_Forms_Platform_dll,
	&assembly_bundle_Xamarin_Forms_Xaml_dll,
	&assembly_bundle_Xamarin_Google_Guava_ListenableFuture_dll,
	&assembly_bundle_Daipsi_Android_dll,
	NULL
};

/* -*- C -*- */
#include <stdlib.h>

static BundleMonoAPI mono_api;

void initialize_mono_api (const BundleMonoAPI *info)
{
	if (info == NULL) {
		mkbundle_log_error ("mkbundle: missing Mono API info\n");
		exit (1);
	}

	mono_api.mono_register_bundled_assemblies = info->mono_register_bundled_assemblies;
	mono_api.mono_register_config_for_assembly = info->mono_register_config_for_assembly;
	mono_api.mono_jit_set_aot_mode = info->mono_jit_set_aot_mode;
	mono_api.mono_aot_register_module = info->mono_aot_register_module;
	mono_api.mono_config_parse_memory = info->mono_config_parse_memory;
	mono_api.mono_register_machine_config = info->mono_register_machine_config;
}

#ifdef USE_COMPRESSED_ASSEMBLY

static int
validate_api_pointer (const char *name, void *ptr)
{
	if (ptr != NULL)
		return 0;

	mkbundle_log_error ("mkbundle: Mono API pointer '%s' missing\n", name);
	return 1;
}

static void
validate_api_struct ()
{
	int missing = 0;

	missing += validate_api_pointer ("mono_register_bundled_assemblies", mono_api.mono_register_bundled_assemblies);
	missing += validate_api_pointer ("mono_register_config_for_assembly", mono_api.mono_register_config_for_assembly);
	missing += validate_api_pointer ("mono_jit_set_aot_mode", mono_api.mono_jit_set_aot_mode);
	missing += validate_api_pointer ("mono_aot_register_module", mono_api.mono_aot_register_module);
	missing += validate_api_pointer ("mono_config_parse_memory", mono_api.mono_config_parse_memory);
	missing += validate_api_pointer ("mono_register_machine_config", mono_api.mono_register_machine_config);

	if (missing <= 0)
		return;

	mkbundle_log_error ("mkbundle: bundle not initialized properly, %d Mono API pointers are missing\n", missing);
	exit (1);
}

static void
init_default_mono_api_struct ()
{
#ifdef USE_DEFAULT_MONO_API_STRUCT
	mono_api.mono_register_bundled_assemblies = mono_register_bundled_assemblies;
	mono_api.mono_register_config_for_assembly = mono_register_config_for_assembly;
	mono_api.mono_jit_set_aot_mode = mono_jit_set_aot_mode;
	mono_api.mono_aot_register_module = mono_aot_register_module;
	mono_api.mono_config_parse_memory = mono_config_parse_memory;
	mono_api.mono_register_machine_config = mono_register_machine_config;
#endif // USE_DEFAULT_MONO_API_STRUCT
}

#endif

#ifndef USE_COMPRESSED_ASSEMBLY

static void install_aot_modules (void) {

	mono_api.mono_jit_set_aot_mode (MONO_AOT_MODE_NORMAL);

}

#endif

static char *image_name = "System.Threading.Tasks.Extensions.dll";

static void install_dll_config_files (void) {

}

static const char *config_dir = NULL;
static MonoBundledAssembly **bundled;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>

static int
my_inflate (const Byte *compr, uLong compr_len, Byte *uncompr, uLong uncompr_len)
{
	int err;
	z_stream stream;

	memset (&stream, 0, sizeof (z_stream));
	stream.next_in = (Byte *) compr;
	stream.avail_in = (uInt) compr_len;

	// http://www.zlib.net/manual.html
	err = inflateInit2 (&stream, 16+MAX_WBITS);
	if (err != Z_OK)
		return 1;

	for (;;) {
		stream.next_out = uncompr;
		stream.avail_out = (uInt) uncompr_len;
		err = inflate (&stream, Z_NO_FLUSH);
		if (err == Z_STREAM_END) break;
		if (err != Z_OK) {
			printf ("%d\n", err);
			return 2;
		}
	}

	err = inflateEnd (&stream);
	if (err != Z_OK)
		return 3;

	if (stream.total_out != uncompr_len)
		return 4;
	
	return 0;
}

void mono_mkbundle_init ()
{
	CompressedAssembly **ptr;
	MonoBundledAssembly **bundled_ptr;
	Bytef *buffer;
	int nbundles;

	init_default_mono_api_struct ();
	validate_api_struct ();
	install_dll_config_files ();

	ptr = (CompressedAssembly **) compressed;
	nbundles = 0;
	while (*ptr++ != NULL)
		nbundles++;

	bundled = (MonoBundledAssembly **) malloc (sizeof (MonoBundledAssembly *) * (nbundles + 1));
	if (bundled == NULL) {
		// May fail...
		mkbundle_log_error ("mkbundle: out of memory");
		exit (1);
	}

	bundled_ptr = bundled;
	ptr = (CompressedAssembly **) compressed;
	while (*ptr != NULL) {
		uLong real_size;
		uLongf zsize;
		int result;
		MonoBundledAssembly *current;

		real_size = (*ptr)->assembly.size;
		zsize = (*ptr)->compressed_size;
		buffer = (Bytef *) malloc (real_size);
		result = my_inflate ((*ptr)->assembly.data, zsize, buffer, real_size);
		if (result != 0) {
			fprintf (stderr, "mkbundle: Error %d decompressing data for %s\n", result, (*ptr)->assembly.name);
			exit (1);
		}
		(*ptr)->assembly.data = buffer;
		current = (MonoBundledAssembly *) malloc (sizeof (MonoBundledAssembly));
		memcpy (current, *ptr, sizeof (MonoBundledAssembly));
		current->name = (*ptr)->assembly.name;
		*bundled_ptr = current;
		bundled_ptr++;
		ptr++;
	}
	*bundled_ptr = NULL;
	mono_api.mono_register_bundled_assemblies((const MonoBundledAssembly **) bundled);
}
