//
//  ADMobileNativeAd.h
//  ADMobileAdSDK
//
//  Created by 陈坤 on 2019/3/8.
//

#import <Foundation/Foundation.h>

@class ADMobGenNativeConfig;

NS_ASSUME_NONNULL_BEGIN

@interface ADMobileNativeAd : NSObject

- (instancetype)initWithConfig:(ADMobGenNativeConfig *)config;

- (BOOL)loadAd:(NSNumber *)count;

@end

NS_ASSUME_NONNULL_END
