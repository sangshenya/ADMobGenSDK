//
//  ADMobMCNativeAd.h
//  ADMobGenMCAd
//
//  Created by 曹飞 on 2018/7/26.
//

#import <Foundation/Foundation.h>

@class ADMobGenNativeConfig;

@interface ADMobMCNativeAd : NSObject

- (instancetype)initWithConfig:(ADMobGenNativeConfig *)config;

- (BOOL)loadAd:(NSNumber *)count;

@end
