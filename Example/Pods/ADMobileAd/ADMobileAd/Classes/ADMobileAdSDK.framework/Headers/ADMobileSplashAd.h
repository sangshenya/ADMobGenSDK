//
//  ADMobileSplashAd.h
//  ADMobileAdSDK
//
//  Created by 陈坤 on 2019/3/7.
//

#import <Foundation/Foundation.h>
@class ADMobGenSplashConfig;

NS_ASSUME_NONNULL_BEGIN

@interface ADMobileSplashAd : NSObject

- (BOOL)loadAndShowWithConfig:(ADMobGenSplashConfig *)config;

@end

NS_ASSUME_NONNULL_END
