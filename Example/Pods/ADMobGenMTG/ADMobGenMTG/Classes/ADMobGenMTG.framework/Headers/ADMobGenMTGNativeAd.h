//
//  ADMobGenMTGNativeAd.h
//  ADMobGenMTG
//
//  Created by kaifa on 2018/8/17.
//

#import <Foundation/Foundation.h>

@class ADMobGenNativeConfig;

@interface ADMobGenMTGNativeAd : NSObject

- (instancetype)initWithConfig:(ADMobGenNativeConfig *)config;

- (BOOL)loadAd:(NSNumber *)count;

@end
