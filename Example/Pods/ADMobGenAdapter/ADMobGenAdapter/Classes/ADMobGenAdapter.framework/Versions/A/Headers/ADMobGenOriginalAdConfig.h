//
//  ADMobGenNativeAdConfig.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/1/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ADMobGenOriginalCallBack;

@interface ADMobGenOriginalAdConfig : NSObject

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
@property (nonatomic, readonly, weak) id<ADMobGenOriginalCallBack> callback;

/**
 
 */
@property (nonatomic, readonly, assign) BOOL trunType;

/**
 
 */
@property (nonatomic, readonly, assign) BOOL rewardType;

+ (instancetype)configWithAppId:(NSString *)appId
                          posId:(NSString *)posId
                       trunType:(BOOL)trunType
                       callback:(id<ADMobGenOriginalCallBack>)callback DEPRECATED_MSG_ATTRIBUTE("Donot has rewardType");

+ (instancetype)configWithAppId:(NSString *)appId
                          posId:(NSString *)posId
                       trunType:(BOOL)trunType
                     rewardType:(BOOL)rewardType
                       callback:(id<ADMobGenOriginalCallBack>)callback;

@end

NS_ASSUME_NONNULL_END
