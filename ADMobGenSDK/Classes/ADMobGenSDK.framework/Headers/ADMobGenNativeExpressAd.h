//
//  ADMobGenNativeExpressAd.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/7/2.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ADMobGenAdapter/ADMobGenNativeConfig.h>

@class ADMobGenNativeExpressAdView;
@protocol ADMobGenNativeExpressAdDelegate;

@interface ADMobGenNativeExpressAd : NSObject

/*
 viewControllerForPresentingModalView
 详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;

/**
 代理回调
 */
@property (nonatomic, weak) id<ADMobGenNativeExpressAdDelegate> delegate;

- (id)new NS_UNAVAILABLE;
- (id)init NS_UNAVAILABLE;

/**
 指定的构造方法

 @param size 期望的广告大小,高度自适应
 */
- (id)initWithSize:(CGSize)size NS_DESIGNATED_INITIALIZER;

/**
 加载广告

 @param count 拉取几条广告,建议区间 1~5, 超过可能无法拉取到
 */
- (void)load:(int)count;

/**
 设置原生广告类型
 
 @param nativeAdType 广告渲染的样式，默认为图文
 */
- (void)setNativeAdType:(ADMobGenNativeAdType)nativeAdType;

@end


@protocol ADMobGenNativeExpressAdDelegate <NSObject>

/**
 广告模板请求成功

 @param nativeExpressAd 广告实例
 @param views 广告模板集合
 */
- (void)admg_nativeExpressAdSucessToLoad:(ADMobGenNativeExpressAd *)nativeExpressAd views:(NSArray<__kindof ADMobGenNativeExpressAdView *> *)views;

/**
 广告模板请求失败

 @param nativeExpressAd 广告实例
 @param error 请求错误描述
 */
- (void)admg_nativeExpressAdFailToLoad:(ADMobGenNativeExpressAd *)nativeExpressAd error:(NSError *)error;

/**
 广告模板渲染成功
 如在列表中,可在此会调用刷新列表,重新调整高度

 @param nativeExpressAdView 广告模板
 */
- (void)admg_nativeExpressAdViewRenderSuccess:(ADMobGenNativeExpressAdView *)nativeExpressAdView;

/**
 广告模板渲染失败

 @param nativeExpressAdView 广告模板
 */
- (void)admg_nativeExpressAdViewRenderFail:(ADMobGenNativeExpressAdView *)nativeExpressAdView;

/**
 广告模板被点击

 @param nativeExpressAdView 广告模板
 */
- (void)admg_nativeExpressAdViewClicked:(ADMobGenNativeExpressAdView *)nativeExpressAdView;

/**
 视频广告模板播放状态更换
 
 @param nativeExpressAdView 广告模板
 */
- (void)admg_nativeExpressVideoAdView:(ADMobGenNativeExpressAdView *)nativeExpressAdView stateDidChanged:(ADMobGenPlayerState)playerState;

@end
