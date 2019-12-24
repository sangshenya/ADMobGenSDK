//
//  ADMobGenSplashSkipView.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/6/29.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ADMobGenSplashSkipView : UIView

@property (nonatomic, copy) void (^skipClicked)(void);

/**
 采用该方法初始化, 内部布局已做好, 无序设置frame
 */
+ (instancetype)sharedSkipView;

/**
 跳过视图在父视图中的中心点, 已适配iPhone X
 */
- (CGPoint)centerPointInContainer;

/**
 设置视图是否可以点击, 默认YES
 */
- (void)setClickEnabled:(BOOL)enabled;

/**
 设置跳过视图的剩余时间
 */
- (void)setLifeTime:(NSInteger)lifeTime;

@end
