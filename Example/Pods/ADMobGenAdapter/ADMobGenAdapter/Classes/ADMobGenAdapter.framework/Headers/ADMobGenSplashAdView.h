//
//  ADMobGenSplashAdView.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/6/29.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ADMobGenSplashSkipView.h"

@interface ADMobGenSplashAdView : UIView

/**
 开屏图片填充视图
 */
@property (nonatomic, readonly, strong) UIImageView *spContainerView;

/**
 跳过按钮, 默认可以点击,查看 "ADMobGenSplashSkipView" 类
 */
@property (nonatomic, readonly, strong) ADMobGenSplashSkipView *skipView;

/**
 默认的启动页
 */
@property (nonatomic, readonly, strong) UIImageView *defaultImgv;

/**
 底部Logo视图
 */
@property (nonatomic, readonly, strong) UIView *bottomView;

#pragma mark - Action

/**
 设置广告内容点击回调事件
 */
- (void)setAdClicked:(void (^)(void))clickBlock;

/**
 展现开屏视图

 @param view 父视图
 @param skipViewHidden 跳过按钮是否隐藏
 @param bottomView 底部logo视图
 @param backgroundColor 默认启动页
 */
- (void)showInView:(UIView *)view
    skipViewHidden:(BOOL)skipViewHidden
        bottomView:(UIView *)bottomView
   backgroundColor:(UIColor *)backgroundColor;

/**
 移除默认启动页

 @param animated 动画
 */
- (void)removeDefaultImgvAnimated:(BOOL)animated;

#pragma mark - Timer

/**
 倒计时, 默认为nil, 调用 'setCountDown: completion:' 后生成, 需要在合适的时候销毁
 */
@property (nonatomic, strong) NSTimer *countDownTimer;

/**
 开始倒计时

 @param lifeTime 倒计时生命周期
 @param completion 结束回调
 */
- (void)setCountDown:(NSInteger)lifeTime completion:(void (^)(void))completion;

@end
