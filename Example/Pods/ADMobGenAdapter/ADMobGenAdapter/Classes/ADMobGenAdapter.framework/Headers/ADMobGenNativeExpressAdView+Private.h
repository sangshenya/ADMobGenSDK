//
//  ADMobGenNativeExpressAdView+Private.h
//  ADMobGenAdapter
//
//  Created by 曹飞 on 2018/7/13.
//

#import "ADMobGenNativeExpressAdView.h"

@protocol ADMobGenNativeExpressProtocol;

@interface ADMobGenNativeExpressAdView ()

@property (nonatomic, strong, readonly) UIView<ADMobGenNativeExpressProtocol> *adView;

- (instancetype)initWithAdView:(UIView<ADMobGenNativeExpressProtocol> *)adView DEPRECATED_MSG_ATTRIBUTE("Donot has webViewType");

- (instancetype)initWithAdView:(UIView<ADMobGenNativeExpressProtocol> *)adView webViewType:(BOOL)webViewType;

- (void)setClickTracked;
- (BOOL)getClickTracked;

- (void)setExposureTracked;
- (BOOL)getExposureTracked;

@end

