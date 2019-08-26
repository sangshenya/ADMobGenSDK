//
//  ADMobGenMTGBannerAd.h
//  ADMobGenMTG
//
//  Created by 陈坤 on 2019/3/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ADMobGenBannerConfig;

@interface ADMobGenMTGBannerAd : NSObject
    
- (id)requestViewWithConfig:(ADMobGenBannerConfig *)config;
    
- (BOOL)loadAndShowWithError:(NSError *__autoreleasing *)error;

@end

NS_ASSUME_NONNULL_END
