//
//  ADMobWMSplashAd.h
//  ADMobGenWM
//
//  Created by 陈坤 on 2018/10/12.
//

#import <Foundation/Foundation.h>
@class ADMobGenSplashConfig;
NS_ASSUME_NONNULL_BEGIN

@interface ADMobWMSplashAd : NSObject

- (BOOL)loadAndShowWithConfig:(ADMobGenSplashConfig *)config;

@end

NS_ASSUME_NONNULL_END
