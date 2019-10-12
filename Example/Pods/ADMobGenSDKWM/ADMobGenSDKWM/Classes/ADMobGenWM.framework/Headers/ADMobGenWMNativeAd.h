//
//  ADMobGenWMNativeAd.h
//  ADMobGenWM
//
//  Created by kaifa on 2018/8/7.
//

#import <Foundation/Foundation.h>

@class ADMobGenNativeConfig;

@interface ADMobGenWMNativeAd : NSObject

- (instancetype)initWithConfig:(ADMobGenNativeConfig *)config;

- (BOOL)loadAd:(NSNumber *)count;

@end
