//
//  ADMobGenNativeExpressAdView.h
//  ADMobGenAdapter
//
//  Created by 曹飞 on 2018/7/13.
//

#import <UIKit/UIKit.h>

@interface ADMobGenNativeExpressAdView : UIView

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
