//
//  ADMobGenRewardvodAd.h
//  ADMobGenSDK
//
//  Created by 陈坤 on 2018/12/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ADMobGenRewardvodAdDelegate;

@interface ADMobGenRewardvodAd : NSObject

/*
 viewControllerForPresentingModalView
 详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *controller;

/**
 代理回调
 */
@property (nonatomic, weak) id<ADMobGenRewardvodAdDelegate> delegate;

/**
 加载激励视频广告
 */
- (void)loadVideoAd;

/**
 加载激励视频广告
 
 @param index 广告位序号，默认为0，不同的页面使用，可以传如不同的序号
 */
- (void)loadVideoAdIndex:(NSInteger)index;

/**
 激励视频广告是否准备好
 */
- (BOOL)rewardvodAdIsReady;

/**
 激励视频广告物料是否有效
 */
- (BOOL)rewardvodAdIsValid;

/**
 展示激励视频广告
 */
- (void)showRewardvodAd;

@end

@protocol ADMobGenRewardvodAdDelegate <NSObject>

/**
 广告数据加载成功回调
 
 @param rewardvodAd 广告实例
 */
- (void)admg_rewardvodAdLoadSuccessCallBack:(ADMobGenRewardvodAd *)rewardvodAd;
/**
 视频数据下载成功回调，已经下载过的视频会直接回调
 
 @param rewardvodAd 广告实例
 */
- (void)admg_rewardvodAdVideoLoadSuccessCallBack:(ADMobGenRewardvodAd *)rewardvodAd;
/**
 视频播放页即将展示回调
 
 @param rewardvodAd 广告实例
 */
- (void)admg_rewardvodAdWillVisibleCallBack:(ADMobGenRewardvodAd *)rewardvodAd;
/**
 视频广告曝光回调
 
 @param rewardvodAd 广告实例
 */
- (void)admg_rewardvodAdDidVisibleCallBack:(ADMobGenRewardvodAd *)rewardvodAd;
/**
 视频播放页关闭回调
 
 @param rewardvodAd 广告实例
 */
- (void)admg_rewardvodAdDidCloseCallBack:(ADMobGenRewardvodAd *)rewardvodAd;
/**
 视频广告信息点击回调
 
 @param rewardvodAd 广告实例
 */
- (void)admg_rewardvodAdDidClickCallBack:(ADMobGenRewardvodAd *)rewardvodAd;
/**
 视频广告视频播放完成
 
 @param rewardvodAd 广告实例
 */
- (void)admg_rewardvodAdDidPlayFinishCallBack:(ADMobGenRewardvodAd *)rewardvodAd;

/**
 视频广告视频达到奖励条件
 
 @param rewardvodAd 广告实例
 */
- (void)admg_rewardvodAdDidRewardEffective:(ADMobGenRewardvodAd *)rewardvodAd;

/**
 视频广告各种错误信息回调
 
 @param rewardvodAd 广告实例
 @param error 具体错误信息
 */
- (void)admg_rewardvodAdFailToLoadCallBack:(ADMobGenRewardvodAd *)rewardvodAd error:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
