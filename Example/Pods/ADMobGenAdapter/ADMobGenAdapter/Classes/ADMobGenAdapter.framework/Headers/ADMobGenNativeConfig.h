//
//  ADMobGenNativeConfig.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/7/2.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, ADMobGenNativeAdType) {
    ADMobGenNativeAdTypeNormal = 0,//上图下文，默认为图文，图片尺寸为16：9
    ADMobGenNativeAdTypePic,//纯图片16：9
    ADMobGenNativeAdTypeRightPic,//右图左文3：2
    ADMobGenNativeAdTypeLeftPic,//左图右文3：2
    ADMobGenNativeAdTypeCenterPic,//上文下图16：9
    ADMobGenNativeAdTypeVerticalPic,//竖版纯图3：2
};

typedef NS_ENUM(NSUInteger, ADMobGenNativeAdPlatform) {
    ADMobGenNativeAdPlatformGDT = 0,//广点通
    ADMobGenNativeAdPlatformWM,//头条
    ADMobGenNativeAdPlatformBaidu,//百度
    ADMobGenNativeAdPlatformADMob,//ADMob
    ADMobGenNativeAdPlatformNone,//之前版本
};


@protocol ADMobGenNativeExpressAdCallBack;

@interface ADMobGenNativeConfig : NSObject

/**
 平台的应用id
 */
@property (nonatomic, readonly, copy) NSString *appId;

/**
 平台的广告位id
 */
@property (nonatomic, readonly, copy) NSString *posId;

/**
 对模板广告的期望大小
 */
@property (nonatomic, readonly, assign) CGSize expectSize;

/**
 广告类型
 */
@property (nonatomic, readonly, assign) BOOL displayType;

/**
 用来展示的视图控制器
 */
@property (nonatomic, readonly, weak) UIViewController *viewController;

/**
 广告生命周期回调
 */
@property (nonatomic, readonly, weak) id<ADMobGenNativeExpressAdCallBack> callback;

/**
 广告渲染类型
 */
@property (nonatomic, readonly, assign) ADMobGenNativeAdType nativeAdType;

/**
 广告平台类型
 */
@property (nonatomic, readonly, assign) ADMobGenNativeAdPlatform platformType;

/**
 
 */
@property (nonatomic, readonly, assign) BOOL trunType;

/**
 构造方法
 */
+ (instancetype)configWithAppId:(NSString *)appId
                          posId:(NSString *)posId
                     expectSize:(CGSize)expectSize
                    displayType:(BOOL)displayType
                 viewController:(UIViewController *)viewController
                       callback:(id<ADMobGenNativeExpressAdCallBack>)callback DEPRECATED_MSG_ATTRIBUTE("Donot has nativeAdType");

+ (instancetype)configWithAppId:(NSString *)appId
                          posId:(NSString *)posId
                     expectSize:(CGSize)expectSize
                    displayType:(BOOL)displayType
                   nativeAdType:(ADMobGenNativeAdType)nativeAdType
                 viewController:(UIViewController *)viewController
                       callback:(id<ADMobGenNativeExpressAdCallBack>)callback DEPRECATED_MSG_ATTRIBUTE("Donot has trunType");

+ (instancetype)configWithAppId:(NSString *)appId
                          posId:(NSString *)posId
                     expectSize:(CGSize)expectSize
                    displayType:(BOOL)displayType
                       trunType:(BOOL)trunType
                   nativeAdType:(ADMobGenNativeAdType)nativeAdType
                 viewController:(UIViewController *)viewController
                       callback:(id<ADMobGenNativeExpressAdCallBack>)callback DEPRECATED_MSG_ATTRIBUTE("Donot has platformType");

+ (instancetype)configWithAppId:(NSString *)appId
                          posId:(NSString *)posId
                     expectSize:(CGSize)expectSize
                    displayType:(BOOL)displayType
                       trunType:(BOOL)trunType
                   nativeAdType:(ADMobGenNativeAdType)nativeAdType
                   platformType:(ADMobGenNativeAdPlatform)platformType
                 viewController:(UIViewController *)viewController
                       callback:(id<ADMobGenNativeExpressAdCallBack>)callback;

@end
