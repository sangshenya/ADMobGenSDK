//
//  ADMobileMixOriginalAd.h
//  ADMobileAdSDK
//
//  Created by 陶冶明 on 2019/9/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ADMobGenMixOriginalAdConfig;

@interface ADMobileMixOriginalAd : NSObject

- (instancetype)initWithConfig:(ADMobGenMixOriginalAdConfig *)config;

- (BOOL)loadAd:(NSNumber *)count;

@end

NS_ASSUME_NONNULL_END

