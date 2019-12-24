//
//  ADMobGenUnifiedNativeCallBack.h
//  ADMobGenAdapter
//
//  Created by 陶冶明 on 2019/11/6.
//

#import <Foundation/Foundation.h>
#import "ADMobUnifiedNativeAdViewProtocol.h"
#import "ADMobUnifiedNativeAdDataObject.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ADMobGenUnifiedNativeCallBack <NSObject>

- (void)unifiedNativeSuccessToLoadCallBack:(id)sourceAd unifiedNativeAdViews:(NSArray<UIView<ADMobUnifiedNativeAdViewProtocol>*> *)adViews;

- (void)unifiedNativeFailToLoadCallBack:(id)sourceAd error:(NSError *)error;

- (void)unifiedNativeExposureCallBack:(id)sourceAd exposureTracked:(BOOL)exposureTracked;

- (void)unifiedNativeClickedCallBack:(id)sourceAd clickedTracked:(BOOL)clickedTracked;

@end

NS_ASSUME_NONNULL_END
