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

#pragma mark - Get
@property (nonatomic, readonly, strong) ADMobGenNativeAdData *adData; // 渲染资源
@property (nonatomic, readonly, strong) ADMobGenNativeConfig *config; // 广告配置

#pragma mark - Set
@property (nonatomic, weak) id<ADMobGenNativeExpressAdViewDelegate> delegate; // 视图生命周期回调
@property (nonatomic, assign) CGFloat impressRatio; // 展现比例, 范围0 ~ 1, 默认是0.5

- (instancetype)initWithAdData:(ADMobGenNativeAdData *)adData config:(ADMobGenNativeConfig *)config NS_DESIGNATED_INITIALIZER;


- (instancetype)new NS_UNAVAILABLE;

- (instancetype)init NS_UNAVAILABLE;

@end


@protocol ADMobGenNativeExpressAdViewDelegate <NSObject>

@optional
- (void)nativeExpressAdViewRenderSuccessAction:(ADMobGenNativeExpressAdView *)expressAdView;
- (void)nativeExpressAdViewRenderFailAction:(ADMobGenNativeExpressAdView *)expressAdView;
- (void)nativeExpressAdViewExposureAction:(ADMobGenNativeExpressAdView *)expressAdView;
- (void)nativeExpressAdViewClickedAction:(ADMobGenNativeExpressAdView *)expressAdView;

@end
