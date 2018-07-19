//
//  ADMobGenNativeAdData.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/7/3.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface ADMobGenNativeAdData : NSObject

// 详细消息,用web渲染
@property (nonatomic, copy) NSString *mainImgUrl;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *describe;

@property (nonatomic, strong) UIView *templetView; // 模板视图, 用给定的模板直接渲染
@property (nonatomic, copy) void (^renderBlock)(UIView *renderView);

@property (nonatomic, strong) UIView *actionView; // 作用视图, 特殊情况下,可用来响应事件

- (void)setClickTracked;
- (BOOL)getClickTracked;

- (void)setExposureTracked;
- (BOOL)getExposureTracked;

@end
