//
//  ADMobGenMixOriginalAdConfig.h
//  ADMobGenAdapter
//
//  Created by 陶冶明 on 2019/9/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ADMobGenMixOriginalCallBack;

@interface ADMobGenMixOriginalAdConfig : NSObject

/**
 平台的应用id
 */
@property (nonatomic, readonly, copy) NSString *appId;

/**
 是否是请求开屏广告
 */
@property (nonatomic, assign) BOOL isSpalsh;

/**
 平台的广告位id
 */
@property (nonatomic, readonly, copy) NSString *posId;

/**
 广告生命周期回调
 */
@property (nonatomic, readonly, weak) id<ADMobGenMixOriginalCallBack> callback;

/**
 
 */
@property (nonatomic, readonly, assign) BOOL trunType;

/**
 
 */
@property (nonatomic, readonly, assign) BOOL rewardType;

+ (instancetype)configWithAppId:(NSString *)appId
                          posId:(NSString *)posId
                       trunType:(BOOL)trunType
                       callback:(id<ADMobGenMixOriginalCallBack>)callback DEPRECATED_MSG_ATTRIBUTE("Donot has rewardType");

+ (instancetype)configWithAppId:(NSString *)appId
                          posId:(NSString *)posId
                       trunType:(BOOL)trunType
                     rewardType:(BOOL)rewardType
                       callback:(id<ADMobGenMixOriginalCallBack>)callback;

@end

NS_ASSUME_NONNULL_END
