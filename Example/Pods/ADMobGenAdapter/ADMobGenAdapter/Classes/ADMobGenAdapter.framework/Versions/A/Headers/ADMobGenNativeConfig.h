//
//  ADMobGenNativeConfig.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/7/2.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ADMobGenNativeExpressCommon.h"
#import "ADMobGenAdapterCommon.h"

@protocol ADMobGenNativeExpressAdCallBack;

@interface ADMobGenNativeConfig : NSObject

/**
 平台的应用id
 */
@property (nonatomic, readonly, copy) NSString * _Nullable appId;

/**
 平台的广告位id
 */
@property (nonatomic, readonly, copy) NSString * _Nullable posId;

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
@property (nonatomic, readonly, weak) UIViewController * _Nullable viewController;

/**
 广告生命周期回调
 */
@property (nonatomic, readonly, weak) id<ADMobGenNativeExpressAdCallBack> _Nullable callback;

/**
 广告渲染类型
 */
@property (nonatomic, readonly, assign) ADMobGenNativeAdType nativeAdType;

/**
 广告平台类型
 */
@property (nonatomic, readonly, assign) ADMobGenAdPlatform platformType;

/**
 
 */
@property (nonatomic, readonly, assign) BOOL trunType;

/**
 
 */
@property (nonatomic, readonly, assign) BOOL rewardType;

/**
 隐藏关闭按钮
 */
@property (nonatomic, readonly, assign) BOOL hiddenCloseButton;

/**
 头条模板类型
 */
@property (nonatomic, readonly, assign) BOOL buNativeExpressType;

/**
 构造方法
 */
+ (instancetype _Nullable )configWithAppId:(NSString *_Nullable)appId
                                     posId:(NSString *_Nullable)posId
                     expectSize:(CGSize)expectSize
                    displayType:(BOOL)displayType
                            viewController:(UIViewController *_Nullable)viewController
                                  callback:(id<ADMobGenNativeExpressAdCallBack>_Nullable)callback DEPRECATED_MSG_ATTRIBUTE("Donot has nativeAdType");

+ (instancetype _Nullable )configWithAppId:(NSString *_Nullable)appId
                                     posId:(NSString *_Nullable)posId
                     expectSize:(CGSize)expectSize
                    displayType:(BOOL)displayType
                   nativeAdType:(ADMobGenNativeAdType)nativeAdType
                            viewController:(UIViewController *_Nullable)viewController
                                  callback:(id<ADMobGenNativeExpressAdCallBack>_Nullable)callback DEPRECATED_MSG_ATTRIBUTE("Donot has trunType");

+ (instancetype _Nullable )configWithAppId:(NSString *_Nullable)appId
                          posId:(NSString *_Nullable)posId
                     expectSize:(CGSize)expectSize
                    displayType:(BOOL)displayType
                       trunType:(BOOL)trunType
                   nativeAdType:(ADMobGenNativeAdType)nativeAdType
                 viewController:(UIViewController *_Nullable)viewController
                       callback:(id<ADMobGenNativeExpressAdCallBack>_Nullable)callback DEPRECATED_MSG_ATTRIBUTE("Donot has platformType");

+ (instancetype _Nullable )configWithAppId:(NSString *_Nullable)appId
                          posId:(NSString *_Nullable)posId
                     expectSize:(CGSize)expectSize
                    displayType:(BOOL)displayType
                       trunType:(BOOL)trunType
                   nativeAdType:(ADMobGenNativeAdType)nativeAdType
                   platformType:(ADMobGenAdPlatform)platformType
                 viewController:(UIViewController *_Nullable)viewController
                       callback:(id<ADMobGenNativeExpressAdCallBack>_Nullable)callback DEPRECATED_MSG_ATTRIBUTE("Donot has hiddenCloseButton");

+ (instancetype _Nullable )configWithAppId:(NSString *_Nullable)appId
                          posId:(NSString *_Nullable)posId
                     expectSize:(CGSize)expectSize
                    displayType:(BOOL)displayType
                       trunType:(BOOL)trunType
              hiddenCloseButton:(BOOL)hiddenCloseButton
                   nativeAdType:(ADMobGenNativeAdType)nativeAdType
                   platformType:(ADMobGenAdPlatform)platformType
                 viewController:(UIViewController *_Nullable)viewController
                       callback:(id<ADMobGenNativeExpressAdCallBack>_Nullable)callback DEPRECATED_MSG_ATTRIBUTE("Donot has rewardType");

+ (instancetype _Nullable )configWithAppId:(NSString *_Nullable)appId
                                     posId:(NSString *_Nullable)posId
                     expectSize:(CGSize)expectSize
                    displayType:(BOOL)displayType
                       trunType:(BOOL)trunType
                     rewardType:(BOOL)rewardType
              hiddenCloseButton:(BOOL)hiddenCloseButton
                   nativeAdType:(ADMobGenNativeAdType)nativeAdType
                   platformType:(ADMobGenAdPlatform)platformType
                            viewController:(UIViewController *_Nullable)viewController
                                  callback:(id<ADMobGenNativeExpressAdCallBack>_Nullable)callback DEPRECATED_MSG_ATTRIBUTE("Donot has buNativeExpressType");

+ (instancetype _Nullable )configWithAppId:(NSString *_Nullable)appId
                                     posId:(NSString *_Nullable)posId
                                expectSize:(CGSize)expectSize
                               displayType:(BOOL)displayType
                                  trunType:(BOOL)trunType
                                rewardType:(BOOL)rewardType
                         hiddenCloseButton:(BOOL)hiddenCloseButton
                       buNativeExpressType:(BOOL)buNativeExpressType
                              nativeAdType:(ADMobGenNativeAdType)nativeAdType
                              platformType:(ADMobGenAdPlatform)platformType
                            viewController:(UIViewController *_Nullable)viewController
                                  callback:(id<ADMobGenNativeExpressAdCallBack>_Nullable)callback;

@end
