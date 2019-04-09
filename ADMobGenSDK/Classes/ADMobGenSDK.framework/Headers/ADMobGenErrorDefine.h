//
//  ADMobGenErrorDefine.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/6/27.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#ifndef ADMobGenErrorDefine_h
#define ADMobGenErrorDefine_h

typedef enum : NSInteger {
    ADMG_SDK_INIT_FAIL = 1001, // SDK初始化失败
    ADMG_SDK_APPID_NIL = 1002, //appId为空
    ADMG_SDK_PACKAGE_ERROR = 1003,//包名和appId不对应
    ADMG_SDK_CONFIG_EMPTY = 1004,//请求配置为空
    ADMG_SDK_LOADTIMEOUT  = -9995,//请求超时
    ADMG_SDK_LOAD_FAIL = -9996,//获取广告失败
    ADMG_SDK_PRATFORM_EMPTY = -9997,//未获取到加载广告的平台，可能一下原因 1、第一次启动未获取到配置信息；2、运营未配置广告
    ADMG_SDK_POSID_EMPTY = -9998,//未获取到需要展示的广告位ID
    ADMG_SDK_LANDSCAPE_NOTLOADSPLASH = -9999,//横屏不加载开屏广告
    //视频相关错误
    ADMG_SDK_VIDEO_LOADFAIL = 5001,//初始化失败
    
    
    
} ADMobGenErrorCode;

static NSError * ADMobGenError(NSErrorDomain domain, NSInteger code, NSString *localizedDescription) {
    NSDictionary *userInfo = nil;
    if (localizedDescription && localizedDescription.length > 0) {
        userInfo = @{NSLocalizedDescriptionKey : localizedDescription};
    }
    return [[NSError alloc] initWithDomain:domain code:code userInfo:userInfo];
}

#endif /* ADMobGenErrorDefine_h */
