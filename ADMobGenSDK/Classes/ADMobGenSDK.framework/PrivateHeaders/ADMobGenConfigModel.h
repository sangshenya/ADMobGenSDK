//
//  ADMobGenConfigModel.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/6/28.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ADMobGenPlatformPosIdModel : NSObject

@property (nonatomic, copy) NSString *banner;
@property (nonatomic, copy) NSString *flow;
@property (nonatomic, copy) NSString *startup;

- (instancetype)initModelWithJson:(NSDictionary *)json;

@end


@interface ADMobGenPlatformConfigModel : NSObject

@property (nonatomic, copy) NSString *sdkName;
@property (nonatomic, copy) NSString *appid;
@property (nonatomic, strong) ADMobGenPlatformPosIdModel *posidList;

+ (NSArray<ADMobGenPlatformConfigModel *> *)modelsWithArray:(NSArray<NSDictionary *> *)array verify:(BOOL)verify;

@end


@interface ADMobGenAdInvokeConfigModel : NSObject

@property (nonatomic, strong) NSArray<NSString *> *banner;
@property (nonatomic, strong) NSArray<NSString *> *startup;
@property (nonatomic, strong) NSArray<NSString *> *flow;

- (instancetype)initModelWithJson:(NSDictionary *)json verify:(BOOL)verify;

@end


@interface ADMobGenConfigModel : NSObject

@property (nonatomic, strong) ADMobGenAdInvokeConfigModel *display;
@property (nonatomic, strong) ADMobGenAdInvokeConfigModel *show;
@property (nonatomic, strong) NSArray<ADMobGenPlatformConfigModel *> *sdkList;

/**
 根据json转成model

 @param json json列表
 @param verify 是否需要校验平台有效性
 */
+ (instancetype)modelWithJson:(NSDictionary *)json verify:(BOOL)verify;

/**
 根据SDK的APPID, 从缓存中取对应的配置

 @param appId 唯一Id
 @param verify 验证SDK中各平台是否兼容
 */
+ (instancetype)modelFromCacheByAppId:(NSString *)appId verify:(BOOL)verify;

/**
 根据当前SDK的APPID,存储到本地缓存中, 支持存储空配置

 @param json 配置信息
 @param appId 唯一Id
 @return 是否存储成功
 */
+ (BOOL)persistenceToCache:(NSDictionary *)json appId:(NSString *)appId;

/**
 配置是否有效, sdkList不能为nil, 同时display和show中的各项配置也不能全为nil
 */
- (BOOL)validation;

@end
