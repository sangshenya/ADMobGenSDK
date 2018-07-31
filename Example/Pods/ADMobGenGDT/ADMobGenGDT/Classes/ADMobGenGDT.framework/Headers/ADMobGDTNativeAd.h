//
//  ADMobGDTNativeAd.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/7/2.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * 展现上报: http://v.gdt.qq.com/gdt_stats.fcg
 * 点击上报: http://c.gdt.qq.com/gdt_mclick.fcg
 */
@class ADMobGenNativeConfig;

@interface ADMobGDTNativeAd : NSObject

- (instancetype)initWithConfig:(ADMobGenNativeConfig *)config;

- (BOOL)loadAd:(NSNumber *)count;

@end
