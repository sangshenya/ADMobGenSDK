//
//  ADMobGenNativeExpressAdView+Private.h
//  ADMobGenAdapter
//
//  Created by 曹飞 on 2018/7/13.
//

#import "ADMobGenNativeExpressAdView.h"

@class ADMobGenNativeAdData;
@class ADMobGenNativeConfig;
@protocol ADMobGenNativeExpressAdViewDelegate;

@interface ADMobGenNativeExpressAdView ()

@property (nonatomic, readonly, strong) ADMobGenNativeAdData *adData;
@property (nonatomic, readonly, strong) ADMobGenNativeConfig *config;
@property (nonatomic, weak) id<ADMobGenNativeExpressAdViewDelegate> delegate;

- (instancetype)initWithAdData:(ADMobGenNativeAdData *)adData config:(ADMobGenNativeConfig *)config;

@end


@protocol ADMobGenNativeExpressAdViewDelegate <NSObject>

@optional
- (void)nativeExpressAdViewRenderSuccessAction:(ADMobGenNativeExpressAdView *)expressAdView;
- (void)nativeExpressAdViewRenderFailAction:(ADMobGenNativeExpressAdView *)expressAdView;
- (void)nativeExpressAdViewExposureAction:(ADMobGenNativeExpressAdView *)expressAdView;
- (void)nativeExpressAdViewClickedAction:(ADMobGenNativeExpressAdView *)expressAdView;

@end
