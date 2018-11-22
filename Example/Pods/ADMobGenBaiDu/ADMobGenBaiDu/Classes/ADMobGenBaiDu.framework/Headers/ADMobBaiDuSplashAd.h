//
//  ADMobBaiDuSplashAd.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/6/27.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * 展现上报: https://mobads-logs.baidu.com || https://wn.pos.baidu.com
 * 点击上报: https://mobads-logs.baidu.com 不确定
 */

@class ADMobGenSplashConfig;

@interface ADMobBaiDuSplashAd : NSObject

- (BOOL)loadAndShowWithConfig:(ADMobGenSplashConfig *)config;

@end
