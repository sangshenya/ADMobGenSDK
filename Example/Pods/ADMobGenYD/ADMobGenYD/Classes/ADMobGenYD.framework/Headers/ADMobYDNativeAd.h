//
//  ADMobYDNativeAd.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/7/4.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * 展现上报: https://dsp-impr2.youdao.com
 * 点击上报: https://dsp-click.youdao.com/clk/request.s
 * 有道的展现上报会在调用retrieveAdViewWithError后,过1-2s时间上报
 */

@class ADMobGenNativeConfig;

@interface ADMobYDNativeAd : NSObject

- (instancetype)initWithConfig:(ADMobGenNativeConfig *)config;

- (BOOL)loadAd:(NSNumber *)count;

@end
