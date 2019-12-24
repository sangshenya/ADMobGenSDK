//
//  ADMobGenMixOriginalCallBack.h
//  ADMobGenAdapter
//
//  Created by 陶冶明 on 2019/9/23.
//

#import <Foundation/Foundation.h>

@class ADMobGenMixOriginalAd;

NS_ASSUME_NONNULL_BEGIN

@protocol ADMobGenMixOriginalCallBack <NSObject>

- (void)mixOriginalSuccessToLoadCallBack:(id)sourceAd originalAds:(NSArray<ADMobGenMixOriginalAd *> *)originalAds;

- (void)mixOriginalFailToLoadCallBack:(id)sourceAd error:(NSError *)error;

- (void)mixOriginalExposureCallBack:(id)sourceAd exposureTracked:(BOOL)exposureTracked;

- (void)mixOriginalClickedCallBack:(id)sourceAd clickedTracked:(BOOL)clickedTracked;

@end

NS_ASSUME_NONNULL_END
