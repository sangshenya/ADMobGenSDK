//
//  ADMobGenMTGRewardvodAd.h
//  ADMobGenMTG
//
//  Created by 陈坤 on 2019/3/28.
//

#import <Foundation/Foundation.h>

@class ADMobGenRewardvodConfig;

NS_ASSUME_NONNULL_BEGIN

@interface ADMobGenMTGRewardvodAd : NSObject

- (instancetype)initWithConfig:(ADMobGenRewardvodConfig *)config;

- (BOOL)rewardvodAdIsReady;

- (BOOL)rewardvodAdIsValid;
    
- (BOOL)showFromRootViewController;
    
    
@end

NS_ASSUME_NONNULL_END
