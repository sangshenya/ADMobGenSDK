//
//  ADMobGenNativCallBack.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/1/4.
//

#import <Foundation/Foundation.h>

@class ADMobGenOriginalAd;

NS_ASSUME_NONNULL_BEGIN

@protocol ADMobGenOriginalCallBack <NSObject>

- (void)originalSuccessToLoadCallBack:(id)sourceAd originalAds:(NSArray<ADMobGenOriginalAd *> *)originalAds;

- (void)originalFailToLoadCallBack:(id)sourceAd error:(NSError *)error;

- (void)originalExposureCallBack:(id)sourceAd exposureTracked:(BOOL)exposureTracked;

- (void)originalClickedCallBack:(id)sourceAd clickedTracked:(BOOL)clickedTracked;

@end

NS_ASSUME_NONNULL_END
