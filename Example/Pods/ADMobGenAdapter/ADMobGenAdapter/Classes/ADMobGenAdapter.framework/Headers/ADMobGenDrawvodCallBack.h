//
//  ADMobGenDrawvodCallBack.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/3/8.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ADMobGenDrawPlayerState) {
    ADMobGenDrawPlayerStateInitial = 0,//初始化状态
    ADMobGenDrawPlayerStateBuffering = 1,//缓冲中
    ADMobGenDrawPlayerStatePlaying = 2,//播放中
    ADMobGenDrawPlayerStatePaused = 3,//播放暂停
    ADMobGenDrawPlayerStateStopped = 4,//播放停止
    ADMobGenDrawPlayerStateError = 5,//播放出错
};

@class ADMobGenDrawvodAd;

NS_ASSUME_NONNULL_BEGIN

@protocol ADMobGenDrawvodCallBack <NSObject>

- (void)drawvodAdSuccessToLoadCallBack:(id)sourceAd views:(NSArray<__kindof ADMobGenDrawvodAd *> *)drawAdArray;

- (void)drawvodAdFailToLoadCallBack:(id)sourceAd error:(NSError *)error;

- (void)drawvodAdCallBack:(ADMobGenDrawvodAd *)drawvodAd stateDidChanged:(ADMobGenDrawPlayerState)playerState;

- (void)drawvodAdCallBack:(ADMobGenDrawvodAd *)drawvodAd didLoadFailWithError:(NSError *)error;

- (void)drawvodAdDidPlayFinishCallBack:(ADMobGenDrawvodAd *)drawvodAd;

- (void)drawvodAdDidClickCallBack:(ADMobGenDrawvodAd *)drawvodAd clickedTracked:(BOOL)clickTracked;

- (void)drawvodAdDidExposureCallBack:(ADMobGenDrawvodAd *)drawvodAd exposureTracked:(BOOL)exposureTracked;

@end

NS_ASSUME_NONNULL_END
