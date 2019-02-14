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

+ (instancetype)configWithAppId:(NSString *)appId
                          posId:(NSString *)posId
                       trunType:(BOOL)trunType
                       callback:(id<ADMobGenOriginalCallBack>)callback;

@end

NS_ASSUME_NONNULL_END
