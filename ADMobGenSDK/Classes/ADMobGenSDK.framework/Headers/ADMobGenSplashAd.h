//
//  ADMobGenSplashAd.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/6/27.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol ADMobGenSplashAdDelegate;


@interface ADMobGenSplashAd : NSObject

/**
 代理回调
 */
@property (nonatomic, weak) id<ADMobGenSplashAdDelegate> delegate;

/**
 开屏的默认背景色,或者启动页
 */
@property (nonatomic, copy) UIColor *backgroundColor;

/**
 加载并展示到window中
 
 @param window window
 @param bottomView 底部logo视图, 高度不能超过屏幕的25%, 建议: 开屏的广告图片默认640 / 960比例, 可以用 screenHeight - screenWidth * (960 / 640.0) 得出bottomview的高度（iPhone X不适用）
 */
- (void)loadAndShowInWindow:(UIWindow *)window withBottomView:(UIView *)bottomView;

@end

@protocol ADMobGenSplashAdDelegate <NSObject>

/**
 开屏展现成功
 
 @param splashAd 开屏实例
 */
- (void)admg_splashAdSuccessToPresentScreen:(ADMobGenSplashAd *)splashAd;

/**
 开屏展现失败
 
 @param splash 开屏实例
 @param error 错误描述
 */
- (void)admg_splashAd:(ADMobGenSplashAd *)splash failToPresentScreen:(NSError *)error;

/**
 开屏广告点击
 
 @param splashAd 开屏实例
 */
- (void)admg_splashAdClicked:(ADMobGenSplashAd *)splashAd;

/**
 开屏被关闭
 
 @param splashAd 开屏实例
 */
- (void)admg_splashAdClosed:(ADMobGenSplashAd *)splashAd;

@end
