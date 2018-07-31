//
//  ADMobMCBannerAd.h
//  ADMobGenMCAd
//
//  Created by 曹飞 on 2018/7/26.
//

#import <Foundation/Foundation.h>

@class ADMobGenBannerConfig;

@interface ADMobMCBannerAd : NSObject

- (id)requestViewWithConfig:(ADMobGenBannerConfig *)config;

- (BOOL)loadAndShowWithError:(NSError *__autoreleasing *)error;

@end
