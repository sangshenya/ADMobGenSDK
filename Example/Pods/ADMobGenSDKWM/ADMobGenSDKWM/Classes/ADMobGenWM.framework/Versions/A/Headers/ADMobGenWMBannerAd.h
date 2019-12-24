//
//  ADMobGenWMBannerAd.h
//  ADMobGenWMSDK-ADMobGenWMSDK
//
//  Created by kaifa on 2018/8/6.
//

#import <Foundation/Foundation.h>

@class ADMobGenBannerConfig;

@interface ADMobGenWMBannerAd : NSObject

- (id)requestViewWithConfig:(ADMobGenBannerConfig *)config;

- (BOOL)loadAndShowWithError:(NSError *__autoreleasing *)error;

@end
