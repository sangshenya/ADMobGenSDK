//
//  ADMobGenSDKConfig.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/6/27.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ADMobGenLogLevel) {
    ADMobGenLogLevelNone = 0,
    ADMobGenLogLevelError = 1,
    ADMobGenLogLevelDebug = 2
};

@interface ADMobGenSDKConfig : NSObject

/**
 注册SDK
 
 @param appId 给定的唯一appid
 @param completion 启动完成回调
 */
+ (void)initWithAppId:(NSString *)appId completionBlock:(void (^)(NSError *error))completion;

/**
 是否打开调试模式, 默认 NO
 需要在 'initWithAppId' 之前调用
 
 @param debugMode 调试模式
 */
+ (void)setDebugMode:(id)debugMode;

/**
 打开GPS定位, 默认关闭
 */
+ (void)setGpsOn;

/**
 配置开发模式
 @param logLevel 默认 ADMobGenLogLevelNone
 */
+ (void)setLogLevel:(ADMobGenLogLevel)logLevel;

/**
 SDK Version
 */
+ (NSString *)getSDKVersion;

@end
