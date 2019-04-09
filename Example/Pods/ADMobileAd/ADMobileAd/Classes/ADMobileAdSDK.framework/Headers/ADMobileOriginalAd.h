//
//  ADMobileOriginalAd.h
//  ADMobileAdSDK
//
//  Created by 陈坤 on 2019/3/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ADMobGenOriginalAdConfig;

@interface ADMobileOriginalAd : NSObject

- (instancetype)initWithConfig:(ADMobGenOriginalAdConfig *)config;

- (BOOL)loadAd:(NSNumber *)count;

@end

NS_ASSUME_NONNULL_END
