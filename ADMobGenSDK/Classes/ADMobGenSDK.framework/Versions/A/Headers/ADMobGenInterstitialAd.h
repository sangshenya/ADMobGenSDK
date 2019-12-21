//
//  ADMobGenInterstitialAd.h
//  ADMobGenSDK
//
//  Created by 陶冶明 on 2019/11/8.
//

#import <Foundation/Foundation.h>
#import <ADMobGenAdapter/ADMobGenInterstitialAdConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class ADMobGenInterstitialAd;

@protocol ADMobGenInterstitialAdDelegate <NSObject>

/**
 ADMobGenInterstitialAd请求成功回调
 
 @param interstitialAd 插屏广告实例对象
*/
- (void)admg_interstitialSuccedToLoad:(ADMobGenInterstitialAd *)interstitialAd;

/**
 ADMobGenInterstitialAd请求失败回调

 @param interstitialAd 插屏广告实例对象
 @param error 失败原因
*/
- (void)admg_interstitialFailedToLoad:(ADMobGenInterstitialAd *)interstitialAd error:(NSError *_Nullable)error;

/**
 ADMobGenInterstitialAd展示在屏幕内回调

 @param interstitialAd 插屏广告实例对象
*/
- (void)admg_interstitialDidPresent:(ADMobGenInterstitialAd *)interstitialAd;

/**
 ADMobGenInterstitialAd点击回调

 @param interstitialAd 插屏广告实例对象
*/
- (void)admg_interstitialDidClick:(ADMobGenInterstitialAd *)interstitialAd;

/**
 ADMobGenInterstitialAd关闭回调

 @param interstitialAd 插屏广告实例对象
*/
- (void)admg_interstitialDidClose:(ADMobGenInterstitialAd *)interstitialAd;

/**
 广告展示
 
 @param interstitialAd 广告实例
 */
- (void)admg_interstitialExposure:(ADMobGenInterstitialAd *)interstitialAd;

@end

@interface ADMobGenInterstitialAd : NSObject

/**
 代理回调
*/
@property (nonatomic, weak) id<ADMobGenInterstitialAdDelegate> delegate;

- (id)new NS_UNAVAILABLE;
- (id)init NS_UNAVAILABLE;

/*
 初始化ADMobGenInterstitialAd
 @param viewController 开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 @param index 请求的广告位序号
*/
- (instancetype)initWithViewController:(nullable UIViewController *)viewController index:(NSInteger)index;

/*
 初始化ADMobGenInterstitialAd
 @param viewController 开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 @param index 请求的广告位序号
 @param ratio 设置广告的大小，广告比例(只影响穿山甲广告) 默认为1:1，size 300x300
*/
- (instancetype)initWithViewController:(nullable UIViewController *)viewController index:(NSInteger)index adSize:(CGSize)adSize aspectRatio:(ADMobGenInterstitialAdAspectRatio)ratio NS_DESIGNATED_INITIALIZER;

/**
 加载广告
*/
- (void)load;

/**
 展示广告
*/
- (void)show;

@end

NS_ASSUME_NONNULL_END
