//
//  ADMobGenUnifiedNativeAdConfig.h
//  ADMobGenAdapter
//
//  Created by 陶冶明 on 2019/11/6.
//

#import <Foundation/Foundation.h>
#import "ADMobGenUnifiedNativeCallBack.h"

NS_ASSUME_NONNULL_BEGIN

@interface ADMobGenUnifiedNativeAdConfig : NSObject

/**
 平台的应用id
 */
@property (nonatomic, readonly, copy) NSString *appId;

/**
 平台的广告位id
 */
@property (nonatomic, readonly, copy) NSString *posId;

/**
 广告生命周期回调
 */
@property (nonatomic, readonly, weak) id<ADMobGenUnifiedNativeCallBack> callback;

/**
 
 */
@property (nonatomic, readonly, assign) BOOL trunType;

/**
 
 */
@property (nonatomic, readonly, assign) BOOL rewardType;

/**
 点击广告需要跳转的控制器
 */
@property (nonatomic, readonly, weak) UIViewController *viewController;

+ (instancetype)configWithAppId:(NSString *)appId
                          posId:(NSString *)posId
                       trunType:(BOOL)trunType
                     rewardType:(BOOL)rewardType
                 viewController:(UIViewController *)viewController
                       callback:(id<ADMobGenUnifiedNativeCallBack>)callback;

@end

NS_ASSUME_NONNULL_END
