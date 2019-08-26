//
//  ADMobGenMTGSplashAd.h
//  ADMobGenMTG
//
//  Created by 陈坤 on 2019/3/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ADMobGenSplashConfig;

@interface ADMobGenMTGSplashAd : NSObject

- (BOOL)loadAndShowWithConfig:(ADMobGenSplashConfig *)config;
    
@end

NS_ASSUME_NONNULL_END
