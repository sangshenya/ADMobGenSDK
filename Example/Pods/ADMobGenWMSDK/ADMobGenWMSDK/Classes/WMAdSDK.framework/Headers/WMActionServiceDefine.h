//
//  WMActionServiceDefine.h
//  WMAdSDK
//
//  Created by carl on 2017/8/8.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

@class WMDeepLink;
@class WMAppInfo;
@class WMVideoInfo;

typedef NS_ENUM(NSInteger, WMAdDownloadActionType) {
    WMAdDownloadActionType_OpenUrl,
    WMAdDownloadActionType_FallBackUrl,
    WMAdDownloadActionType_DownloadUrl,
    WMAdDownloadActionType_UnKnown
};

/** 初始化成功回调 */
typedef void (^SuccessCallback)(void);
/** 初始化失败回调 */
typedef void (^FailedCallback)(NSError *error,NSString *failMessage);

@protocol WMActionWebModel <NSObject>
// 创意的落地页URL
@property (nonatomic, copy) NSString *targetURL;
@end

@protocol WMActionPhoneModel <NSObject>
// 广告类型为电话时，电话号码必须
@property (nonatomic, copy) NSString *phone;

@end

@protocol WMActionDeepLinkModel <NSObject>
// 广告类型为电话时，电话号码必须
@property (nonatomic, strong) WMDeepLink *deepLink;

@end

@protocol WMActionAppModel <NSObject>
// 应用名称
@property (nonatomic, copy) NSString *appName;

@property (nonatomic, copy) NSString *appid;

// 应用下载URL，应用下载必须
@property (nonatomic, copy) NSString *downloadURL;

@end

@protocol WMActionVideoModel <NSObject>

@property (nonatomic, copy) NSString *AdTitle;
@property (nonatomic, copy) NSString *buttonText;

@optional
// 区分明暗投
@property (nonatomic, assign) NSInteger unionSpecial;

// 落地页链接
@property (nonatomic, copy) NSString *targetURL;

@property (nonatomic, strong) WMAppInfo *appInfo;

@property (nonatomic, strong) WMVideoInfo *videoInfo;

@end

