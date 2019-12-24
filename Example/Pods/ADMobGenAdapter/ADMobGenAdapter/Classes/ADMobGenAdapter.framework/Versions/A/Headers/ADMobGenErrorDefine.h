//
//  ADMobGenErrorDefine.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/8/7.
//

#ifndef ADMobGenErrorDefine_h
#define ADMobGenErrorDefine_h

typedef enum : NSInteger {
    ADMG_SDK_SPLASH_LOADTIMEOUT = 10000, //splash广告获取超时
    ADMG_SDK_LANDSCAPE_NOTLOADSPLASH = 10001, //横屏不加载开屏广告
    ADMG_SDK_BANNER_LOADTIMEOUT = 10020, //banner广告获取超时
    ADMG_SDK_NATIVEEXPRESS_LOADTIMEOUT = 10040, //native express广告获取超时
    ADMG_SDK_REWARDVOD_LOADTIMEOUT = 10060, //reward video广告获取超时
    ADMG_SDK_ORIGINAL_LOADTIMEOUT = 10080, //original广告获取超时
    ADMG_SDK_NATIVEUNIFIED_LOADTIMEOUT = 10100, //NativeUnified广告获取超时
    ADMG_SDK_DRAWVOD_LOADTIMEOUT = 10120, //drawvod广告获取超时
    ADMG_SDK_INTERSTITIAL_LOADTIMEOUT = 10140, //interstitial广告获取超时
    ADMG_SDK_JS_VERSION = 10161, //js广告SDK版本错误
    ADMG_SDK_MIX_LOADTIMEOUT = 10180, //mix广告获取超时
    ADMG_SDK_INIT_FAIL = 10200, //SDK初始化失败
    ADMG_SDK_APPID_NIL = 10201, //appId为空
    ADMG_SDK_PACKAGE_ERROR = 10202, //包名和appId不对应
    ADMG_SDK_CONFIG_EMPTY = 10203, //请求配置为空
    ADMG_SDK_PRATFORM_EMPTY = 10204, //未获取到加载广告的平台，可能一下原因 1、第一次启动未获取到配置信息；2、运营未配置广告
    ADMG_SDK_POSID_EMPTY = 10205, //未获取到需要展示的广告位ID
    ADMG_SDK_VIDEO_INITFAIL = 10206, //播放器初始化失败
    ADMG_SDK_VIDEO_UNKNOWN = 10207, //视频资源出现未知错误
    ADMG_SDK_VIDEO_ITEMPLAYFAIL = 10208, //视频playitem播放失败
    
    ADMG_ADMOB_SPLASH_ARGUMENTEMPTY = 11000, //admobile spalsh广告参数错误
    ADMG_ADMOB_SPLASH_IMAGEEMPTY = 11001, //admobile spalsh广告图片为空
    ADMG_ADMOB_BANNER_EMPTYIMAGE = 11020, //admobile banner广告图片为空
    ADMG_ADMOB_BANNER_ARGUMENTEMPTY = 11021, //admobile banner广告参数错误
    ADMG_ADMOB_REWARDVOD_LOAD_FAIL = 11060, //admobile reward video广告加载失败
    ADMG_ADMOB_ORIGINAL_ARGUMENTEMPTY = 11080, //admobile original广告参数错误
    ADMG_ADMOB_UNIFIEDNATIVE_ARGUMENTEMPTY = 11100, //admobile unified native广告参数错误
    ADMG_ADMOB_INTERSTITIAL_LANDSCAPE = 11140, //admobile interstitial不支持横屏
    ADMG_ADMOB_MIX_RENDER_ERROR = 11180, //admobile mix广告渲染失败
    ADMG_ADMOB_MIX_ARGUMENTEMPTY = 11181, //admobile mix广告参数错误
    ADMG_ADMOB_VIDEO_LOAD_ERROR = 11200, //admobile 视频加载失败
    ADMG_ADMOB_NATIVE_EMPTY = 11201, //admobile native广告为空
    ADMG_ADMOB_NATIVE_TYPE_ERROR = 11202, //admobile native类型错误
    ADMG_ADMOB_NATIVE_ARGUMENTEMPTY = 11203, //admobile native广告参数错误
    ADMG_ADMOB_NATIVE_IMAGEEMPTY = 11204, //admobile native广告图片为空
    ADMG_ADMOB_VIDEO_CLEAN_ERROR = 11205, //admobile video缓存清理失败
    ADMG_ADMOB_VIDEO_WRITE_ERROR = 11206, //admobile video写入失败
    ADMG_ADMOB_VIDEO_READ_ERROR = 11207, //admobile video读取失败
    
    
    ADMG_WM_BANNER_OUTSCREEN = 40020, //wm banner广告初始化时在屏幕外
    
    ADMG_INMOBI_BANNER_OUTSCREEN = 50020, //inmobi banner广告初始化时在屏幕外
    ADMG_INMOBI_BANNER_FAILED = 50021, //inmobi banner广告获取失败
    ADMG_INMOBI_NATIVEEXPRESS_UNSUPPORTTYPE = 50040, //inmobi native express广告类型不支持
    ADMG_INMOBI_NATIVEEXPRESS_EMPTY = 50041, //inmobi native express广告为空
    ADMG_INMOBI_NATIVE_EMPTY = 50200, //inmobi native广告为空
    
    ADMG_MTG_SPLASH_RENDER_ERROR = 60000, //MTG splash广告渲染失败
    ADMG_MTG_BANNER_REDER_ERROR = 60020, //MTG banner广告渲染失败
    ADMG_MTG_NATIVE_EMPTY = 60200, //MTG native广告为空
    
    ADMG_GOOGLE_NATIVEEXPRESS_UNSUPPORTTYPE = 70040, //google native express广告类型不支持
    ADMG_GOOGLE_NATIVEEXPRESS_EMPTY = 70041, //google native express广告为空
    ADMG_GOOGLE_NATIVE_EMPTY = 70200, //google native广告为空
    
    ADMG_MGTV_SPLASH_LOAD_FAIL = 80000, //MGTV splash广告获取失败
    ADMG_MGTV_BANNER_RENDER_ERROR = 80020, //MGTV banner广告渲染失败
    ADMG_MGTV_BANNER_LOAD_FAIL = 80021, //MGTV banner广告获取失败
    
} ADMobGenErrorCode;

#define ADMobErrorDomain @"com.admobile.error"

NSError *ADMobGenError(NSErrorDomain domain, NSInteger code, NSString *localizedDescription);

#endif /* ADMobGenErrorDefine_h */
