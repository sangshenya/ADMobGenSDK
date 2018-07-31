//
//  ADMobMCSplashAd.h
//  ADMobGenMCAd
//
//  Created by 曹飞 on 2018/7/26.
//

#import <Foundation/Foundation.h>

@class ADMobGenSplashConfig;

@interface ADMobMCSplashAd : NSObject

- (BOOL)loadAndShowWithConfig:(ADMobGenSplashConfig *)config;

@end
