//
//  ADMobGenRewardVideoAd.h
//  ADMobGenGDT
//
//  Created by 陈坤 on 2018/12/20.
//

#import <Foundation/Foundation.h>

@class ADMobGenRewardvodConfig;

NS_ASSUME_NONNULL_BEGIN

@interface ADMobGenGDTRewardVideoAd : NSObject

- (instancetype)initWithConfig:(ADMobGenRewardvodConfig *)config;

- (BOOL)rewardvodAdIsReady;

- (BOOL)rewardvodAdIsValid;

- (BOOL)showFromRootViewController;

@end

NS_ASSUME_NONNULL_END
