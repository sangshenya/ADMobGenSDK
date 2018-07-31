//
//  ADMobYDBannerAd.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/7/2.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ADMobGenBannerConfig;

@interface ADMobYDBannerAd : NSObject

- (id)requestViewWithConfig:(ADMobGenBannerConfig *)config;

- (BOOL)loadAndShowWithError:(NSError *__autoreleasing *)error;

@end
