//
//  ADMobGenSDKConfig+Private.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/6/28.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import "ADMobGenSDKConfig.h"
#import "ADMobGenConfigModel.h"

#define ADLog(format, ...) printf("%s\n",[[NSString stringWithFormat:(format), ##__VA_ARGS__] UTF8String] )

@interface ADMobGenSDKConfig ()

/// SDK的启动Id
@property (nonatomic, copy) NSString *appId;
/// SDK的配置信息
@property (nonatomic, strong) ADMobGenConfigModel *sdkInfo;
/// SDK是否初始化成功
@property (nonatomic, assign) BOOL initSuccess;
/// 调试模式
@property (nonatomic, readonly, assign) BOOL debugMode;
// 打印信息
@property (nonatomic, readonly, assign) BOOL logInfo;
// 开发模式
@property (nonatomic, readonly, assign) ADMobGenLogLevel logLevel;

+ (instancetype)sharedConfig;

/**
 是否可以抓包
 */
- (BOOL)flagTrue;

/**
 设置调试参数
 需要在 'initWithAppId' 之前调用

 @param arg 字典类型
 */
- (void)setDebugConfig:(id)arg;


/**
 获取所有SDK版本号
 */
+ (NSDictionary *)getAllSDKVersion;

@end
