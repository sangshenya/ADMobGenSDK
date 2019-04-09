//
//  ADMobGenWMOriginalAd.h
//  ADMobGenWM
//
//  Created by 陈坤 on 2019/1/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ADMobGenOriginalAdConfig;

@interface ADMobGenWMOriginalAd : NSObject

- (instancetype)initWithConfig:(ADMobGenOriginalAdConfig *)config;

- (BOOL)loadAd:(NSNumber *)count;

@end

NS_ASSUME_NONNULL_END
