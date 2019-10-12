//
//  ADMobileRewardvodAd.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/8/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ADMobGenRewardvodConfig;

@interface ADMobileRewardvodAd : NSObject

- (instancetype)initWithConfig:(ADMobGenRewardvodConfig *)config;

- (BOOL)rewardvodAdIsValid;

- (BOOL)rewardvodAdIsReady;

- (BOOL)showFromRootViewController;

@end

NS_ASSUME_NONNULL_END
