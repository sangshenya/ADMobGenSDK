//
//  ADMobGenInterstitialCallBack.h
//  Pods
//
//  Created by 陶冶明 on 2019/11/8.
//

#import <Foundation/Foundation.h>
@class ADMobGenInterstitialAdConfig;

NS_ASSUME_NONNULL_BEGIN

@protocol ADMobGenInterstitialCallBack <NSObject>

@optional

- (void)interstitialSuccessToLoadCallBack:(id)sourceAd;

- (void)interstitialFailToLoadCallBack:(id)sourceAd error:(nullable NSError *)error;

- (void)interstitialFailToPresentCallBack:(id)sourceAd error:(nullable NSError *)error;

- (void)interstitialDidPresentCallBack:(id)sourceAd;

- (void)interstitialDidExposureCallBack:(id)sourceAd exposureTracked:(BOOL)exposureTracked;

- (void)interstitialDidClickCallBack:(id)sourceAd clickedTracked:(BOOL)clickedTracked;;

- (void)interstitialDidCloseCallBack:(id)sourceAd;

@end

@protocol ADMobGenInterstitialProtocol <NSObject>

@required

- (void)load;

- (void)show;

- (instancetype)initWithConfig:(ADMobGenInterstitialAdConfig *)config;

@end

NS_ASSUME_NONNULL_END
