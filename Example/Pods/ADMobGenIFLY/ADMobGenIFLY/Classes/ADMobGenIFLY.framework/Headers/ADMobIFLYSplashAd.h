//
//  ADMobIFLYSplashAd.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/6/28.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class ADMobGenSplashConfig;

@interface ADMobIFLYSplashAd : NSObject

- (BOOL)loadAndShowWithConfig:(ADMobGenSplashConfig *)config;

@end
