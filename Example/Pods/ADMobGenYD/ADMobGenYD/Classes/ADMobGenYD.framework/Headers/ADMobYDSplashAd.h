//
//  ADMobYDSplashAd.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/6/27.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 有道的展现上报会在调用retrieveAdViewWithError后,过1-2s时间上报
 */
@class ADMobGenSplashConfig;

@interface ADMobYDSplashAd : NSObject

- (BOOL)loadAndShowWithConfig:(ADMobGenSplashConfig *)config;

@end
