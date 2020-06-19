//
//  ADMobGenMixAdManager.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/9/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ADMobGenMixAdType) {
    ADMobGenMixAdTypeUnknown = 0, // 未知
    ADMobGenMixAdTypeNormal = 1, // 普通广告
    ADMobGenMixAdTypeReward = 2, // 激励视频
};

@class ADMobGenMixAdManager;

@protocol ADMobGenMixAdManagerDelegate <NSObject>

// 广告加载成功
- (void)admg_mixAdSuccessToLoad:(ADMobGenMixAdManager *)manager;
// 广告加载失败
- (void)admg_mixAdFailToLoad:(ADMobGenMixAdManager *)manager error:(NSError *)error;
// 广告被点击
- (void)admg_mixAdClicked:(ADMobGenMixAdManager *)manager;
// 广告奖励达成
- (void)admg_mixAdRewardEffective:(ADMobGenMixAdManager *)manager;
// 广告视图被关闭
- (void)admg_mixAdClosed:(ADMobGenMixAdManager *)manager;
// 广告视图展示
- (void)admg_mixAdExposure:(ADMobGenMixAdManager *)manager;

@end

@interface ADMobGenMixAdManager : NSObject

- (void)loadAd;

- (instancetype)initWithIndex:(NSInteger)index;

@property (nonatomic, copy) NSString *bottomLabel;

@property (nonatomic, copy) NSString *buttonLabel;
// 在admg_mixAdSuccessToLoad被调用之后才可以获取具体数值
@property (nonatomic, assign, readonly) ADMobGenMixAdType adType;

@property (nonatomic, weak) id<ADMobGenMixAdManagerDelegate> delegate;

/**
 头条的激励视频模板广告
 
 @param buRewardvodType 头条19年11月28日自渲染代码位新建入口关闭，之后新增的激励视频广告位都需要设置为YES，不导入头条SDK请忽略
 */
- (void)setBuRewardvodType:(BOOL)buRewardvodType;

@end

NS_ASSUME_NONNULL_END
