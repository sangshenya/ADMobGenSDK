//
//  ADMobIFLYBannerAd.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/7/2.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class ADMobGenBannerConfig;

@interface ADMobIFLYBannerAd : NSObject

- (id)requestViewWithConfig:(ADMobGenBannerConfig *)config;

- (BOOL)loadAndShowWithError:(NSError *__autoreleasing *)error;

@end
