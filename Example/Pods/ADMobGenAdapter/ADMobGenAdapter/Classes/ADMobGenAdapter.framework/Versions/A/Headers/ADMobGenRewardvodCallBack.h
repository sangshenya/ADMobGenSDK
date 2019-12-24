//
//  ADMobGenRewardvodCallBack.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2018/12/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ADMobGenRewardvodCallBack <NSObject>
//ad加载成功
- (void)rewardvodAdLoadSuccessCallBack:(id)rewardvodAd;
//video加载成功
- (void)rewardvodAdVideoLoadSuccessCallBack:(id)rewardvodAd;
//即将展示
- (void)rewardvodAdWillVisibleCallBack:(id)rewardvodAd;
//已经展现
- (void)rewardvodAdDidVisibleCallBack:(id)rewardvodAd tracked:(BOOL)tracked;
//广告已经关闭
- (void)rewardvodAdDidCloseCallBack:(id)rewardvodAd;
//广告已经点击
- (void)rewardvodAdDidClickCallBack:(id)rewardvodAd tracked:(BOOL)tracked;
//广告播放完成
- (void)rewardvodAdDidPlayFinishCallBack:(id)rewardvodAd;
//广告播放达到激励条件
- (void)rewardVodAdDidRewardEffectiveCallBack:(id)rewardvodAd;
//广告播放中发生错误
- (void)rewardvodAdFailToLoadCallBack:(id)rewardvodAd error:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
