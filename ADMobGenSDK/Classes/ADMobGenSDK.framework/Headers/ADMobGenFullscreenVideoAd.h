//
//  ADMobGenFullscreenVideoAd.h
//  ADMobGenSDK
//
//  Created by 陶冶明 on 2020/3/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ADMobGenFullscreenVideoAd;

@protocol ADMobGenFullscreenVideoAdDelegate <NSObject>

/**
 ADMobGenFullscreenVideoAd请求成功回调
 
 @param fullscreenVideoAd 全屏视频广告实例对象
*/
- (void)admg_fullscreenVideoSuccedToLoad:(ADMobGenFullscreenVideoAd *)fullscreenVideoAd;

/**
 ADMobGenFullscreenVideoAd视频加载成功回调
 
 @param fullscreenVideoAd 全屏视频广告实例对象
*/
- (void)admg_fullscreenSuccessToLoadVideo:(ADMobGenFullscreenVideoAd *)fullscreenVideoAd;

/**
 ADMobGenFullscreenVideoAd请求失败回调

 @param fullscreenVideoAd 全屏视频广告实例对象
 @param error 失败原因
*/
- (void)admg_fullscreenVideoFailedToLoad:(ADMobGenFullscreenVideoAd *)fullscreenVideoAd error:(NSError *_Nullable)error;

/**
 ADMobGenFullscreenVideoAd展示在屏幕内回调

 @param fullscreenVideoAd 全屏视频广告实例对象
*/
- (void)admg_fullscreenVideoDidPresent:(ADMobGenFullscreenVideoAd *)fullscreenVideoAd;

/**
 ADMobGenFullscreenVideoAd展示失败回调

 @param fullscreenVideoAd 全屏视频广告实例对象
 @param error 失败原因
*/
- (void)admg_fullscreenVideoFailToPresent:(ADMobGenFullscreenVideoAd *)fullscreenVideoAd error:(NSError *)error;

/**
 ADMobGenFullscreenVideoAd点击回调

 @param fullscreenVideoAd 全屏视频广告实例对象
*/
- (void)admg_fullscreenVideoDidClick:(ADMobGenFullscreenVideoAd *)fullscreenVideoAd;

/**
 ADMobGenFullscreenVideoAd关闭回调

 @param fullscreenVideoAd 全屏视频广告实例对象
*/
- (void)admg_fullscreenVideoDidClose:(ADMobGenFullscreenVideoAd *)fullscreenVideoAd;

/**
 ADMobGenFullscreenVideoAd展示回调
 
 @param fullscreenVideoAd 广告实例
 */
- (void)admg_fullscreenVideoExposure:(ADMobGenFullscreenVideoAd *)fullscreenVideoAd;

/**
ADMobGenFullscreenVideoAd播放完成回调

 @param fullscreenVideoAd 广告实例
 @param error 失败原因（如果为nil，则是单纯的播放完成）
*/
- (void)admg_fullscreenVideoPlayComplete:(ADMobGenFullscreenVideoAd *)fullscreenVideoAd didFailed:(NSError *_Nullable)error;

@end

@interface ADMobGenFullscreenVideoAd : NSObject

/**
 代理回调
*/
@property (nonatomic, weak) id<ADMobGenFullscreenVideoAdDelegate> delegate;

- (id)new NS_UNAVAILABLE;
- (id)init NS_UNAVAILABLE;

/*
 初始化ADMobGenFullscreenVideoAd
 @param viewController 开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 @param index 请求的广告位序号
*/
- (instancetype)initWithViewController:(UIViewController *)viewController index:(NSInteger)index;

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
