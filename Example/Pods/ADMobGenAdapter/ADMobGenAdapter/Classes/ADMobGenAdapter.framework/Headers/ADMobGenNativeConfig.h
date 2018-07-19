//
//  ADMobGenNativeConfig.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/7/2.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

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
 构造方法
 */
+ (instancetype)configWithAppId:(NSString *)appId
                          posId:(NSString *)posId
                     expectSize:(CGSize)expectSize
                    displayType:(BOOL)displayType
                 viewController:(UIViewController *)viewController
                       callback:(id<ADMobGenNativeExpressAdCallBack>)callback;

@end
