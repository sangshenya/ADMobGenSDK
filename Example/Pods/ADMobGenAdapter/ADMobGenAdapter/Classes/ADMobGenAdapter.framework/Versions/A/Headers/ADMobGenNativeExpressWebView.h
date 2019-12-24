//
//  ADMobGenNativeExpressWebView.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/3/11.
//

#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

@class ADMobGenNativeConfig;

@interface ADMobGenNativeExpressWebView : UIView

/**
 * [必选]
 * 原生模板广告渲染
 */
- (void)render;

/**
 * 模板高度,一开始根据ADMobGenNativeExpressAd传入的size决定
 * render成功后, 会根据具体的内容返回正确的尺寸
 */
- (CGSize)contentSize;
@end

NS_ASSUME_NONNULL_END
