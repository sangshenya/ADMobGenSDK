//
//  ADMobGenWMDrawvodAd.h
//  ADMobGenWM
//
//  Created by 陈坤 on 2019/3/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ADMobGenDrawvodConfig;

@interface ADMobGenWMDrawvodAd : NSObject

- (instancetype)initWithConfig:(ADMobGenDrawvodConfig *)config;

- (BOOL)loadAd:(NSNumber *)count;

@end

NS_ASSUME_NONNULL_END
