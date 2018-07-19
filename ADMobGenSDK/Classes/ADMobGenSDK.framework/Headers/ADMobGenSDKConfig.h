//
//  ADMobGenSDKConfig.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/6/27.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ADMobGenSDKConfig : NSObject

/**
 注册SDK

 @param appId 给定的唯一appid
 @param completion 启动完成回调
 */
+ (void)initWithAppId:(NSString *)appId completionBlock:(void (^)(NSError *error))completion;

/**
 是否打开调试模式, 默认 NO

 @param debugMode 调试模式
 */
+ (void)setDebugMode:(id)debugMode;

@end
