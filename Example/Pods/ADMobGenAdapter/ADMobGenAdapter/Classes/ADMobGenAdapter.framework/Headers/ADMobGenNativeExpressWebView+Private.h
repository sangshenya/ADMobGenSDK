//
//  ADMobGenNativeExpressWebView+Private.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/3/11.
//

#import "ADMobGenNativeExpressWebView.h"

@class ADMobGenNativeAdData;
@protocol ADMobGenNativeExpressWebViewDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface ADMobGenNativeExpressWebView ()

@property (nonatomic, weak) id<ADMobGenNativeExpressWebViewDelegate> delegate;

@property (nonatomic, strong, readonly) ADMobGenNativeAdData *adData;
@property (nonatomic, assign, readonly) CGSize normalSize;
@property (nonatomic, assign, readonly) ADMobGenNativeToolPlatform platform;
@property (nonatomic, assign, readonly) ADMobGenNativeToolType type;
@property (nonatomic, assign, readonly) BOOL hideCloseButton;

- (instancetype)initWithAdData:(ADMobGenNativeAdData *)adData expectSize:(CGSize)expectSize adType:(ADMobGenNativeToolType)adType adPlatform:(ADMobGenNativeToolPlatform)platform hide:(BOOL)hideCloseButton;

@property (nonatomic, strong) UIView *actionView;

@property (nonatomic, strong) UIButton *closeButton;

@end

@protocol ADMobGenNativeExpressWebViewDelegate <NSObject>

- (void)nativeExpressWebViewRenderSuccess:(ADMobGenNativeExpressWebView *)webView;

- (void)nativeExpressWebViewRenderFiled:(ADMobGenNativeExpressWebView *)webView;

- (void)nativeExpressWebViewDidClicked:(ADMobGenNativeExpressWebView *)webView;

- (void)nativeExpressWebViewDidClosed:(ADMobGenNativeExpressWebView *)webView;

@end

NS_ASSUME_NONNULL_END
