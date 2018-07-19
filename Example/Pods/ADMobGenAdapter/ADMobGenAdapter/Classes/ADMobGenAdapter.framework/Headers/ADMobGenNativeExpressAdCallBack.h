//
//  ADMobGenNativeExpressAdCallBack.h
//  ADMobGenAdapter
//
//  Created by 曹飞 on 2018/7/13.
//

#import <Foundation/Foundation.h>

@class ADMobGenNativeExpressAdView;

@protocol ADMobGenNativeExpressAdCallBack <NSObject>

- (void)nativeExpressAdSuccessToLoadCallBack:(id)sourceAd views:(NSArray<__kindof ADMobGenNativeExpressAdView *> *)views;

- (void)nativeExpressAdFailToLoadCallBack:(id)sourceAd error:(NSError *)error;

- (void)nativeExpressAdViewRenderSuccessCallBack:(id)sourceAd view:(ADMobGenNativeExpressAdView *)nativeExpressAdView;

- (void)nativeExpressAdViewRenderFailCallBack:(id)sourceAd view:(ADMobGenNativeExpressAdView *)nativeExpressAdView;

- (void)nativeExpressAdViewExposureCallBack:(id)sourceAd view:(ADMobGenNativeExpressAdView *)nativeExpressAdView exposureTracked:(BOOL)exposureTracked;

- (void)nativeExpressAdViewClickedCallBack:(id)sourceAd view:(ADMobGenNativeExpressAdView *)nativeExpressAdView clickedTracked:(BOOL)clickTracked;

@end
