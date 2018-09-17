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
    ADMobGenNativeAdTypeNormal = 0,//图文，默认为图文，目前仅支持图片尺寸为1280×720
    ADMobGenNativeAdTypePic,//纯图片
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
                       callback:(id<ADMobGenNativeExpressAdCallBack>)callback;

@end
