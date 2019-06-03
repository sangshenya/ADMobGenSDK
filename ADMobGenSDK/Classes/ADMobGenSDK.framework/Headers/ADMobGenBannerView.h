//
//  ADMobGenBannerView.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/6/28.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ADMobGenAdapter/ADMobGenBannerConfig.h>

@protocol ADMobGenBannerViewDelegate;

@interface ADMobGenBannerView : UIView

/**
 代理回调
 */
@property (nonatomic, weak) id<ADMobGenBannerViewDelegate> delegate;



- (id)new NS_UNAVAILABLE;
- (id)init NS_UNAVAILABLE;
/*
 初始化bannerView
 @param size 期望的banner广告尺寸比例，默认为640:100
 */
- (instancetype)initWithFrame:(CGRect)frame withBannerSize:(ADMobGenBannerAdSize)bannerSize;

/*
 初始化bannerView
 @param size 期望的banner广告尺寸比例，默认为640:100
 @param bannerIndex 广告位序号，默认为0，不同的页面使用，可以传如不同的序号
 */
- (instancetype)initWithFrame:(CGRect)frame withBannerSize:(ADMobGenBannerAdSize)bannerSize withBannerIndex:(NSInteger)bannerIndex;

/*
 初始化bannerView
 @param size 期望的banner广告尺寸比例，默认为640:100
 @param bannerIndex 广告位序号，默认为0，不同的页面使用，可以传如不同的序号
 @param gdtBanner 是否为广点通2.0，默认为NO不支持广点通2.0
 */
- (instancetype)initWithFrame:(CGRect)frame withBannerSize:(ADMobGenBannerAdSize)bannerSize withBannerIndex:(NSInteger)bannerIndex withGdtBanner:(BOOL)gdtBanner;

/*
 初始化bannerView
 @param size 期望的banner广告尺寸比例，默认为640:100
 @param bannerIndex 广告位序号，默认为0，不同的页面使用，可以传如不同的序号
 @param gdtBanner 是否为广点通2.0，默认为NO不支持广点通2.0
 @param rootViewController
 */
- (instancetype)initWithFrame:(CGRect)frame withBannerSize:(ADMobGenBannerAdSize)bannerSize withBannerIndex:(NSInteger)bannerIndex withGdtBanner:(BOOL)gdtBanner withViewController:(UIViewController *)rootViewController NS_DESIGNATED_INITIALIZER;


/**
 加载并显示广告
 @warning 请确保banner视图显示在屏幕内的时候,调用load方法
 */
- (void)loadWithError:(NSError *__autoreleasing *)error;

/**
 banner广告关闭按钮是否隐藏
 
 @param isHidden 默认为NO，不隐藏
 */
- (void)closeButtonHidden:(BOOL)isHidden;

@end

@protocol ADMobGenBannerViewDelegate <NSObject>

/**
 广告获取成功
 
 @param bannerView banner实例
 */
- (void)admg_bannerViewDidReceived:(ADMobGenBannerView *)bannerView;

/**
 广告拉取失败
 
 @param bannerView banner实例
 @param error 错误描述
 */
- (void)admg_bannerViewFailToReceived:(ADMobGenBannerView *)bannerView error:(NSError *)error;

/**
 广告点击
 
 @param bannerView 广告实例
 */
- (void)admg_bannerViewClicked:(ADMobGenBannerView *)bannerView;

/**
 广告关闭
 
 @param bannerView 广告实例
 */
- (void)admg_bannerViewClose:(ADMobGenBannerView *)bannerView;

@end
