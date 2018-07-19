//
//  ADMobGenSDKConfig+Private.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/6/28.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import "ADMobGenSDKConfig.h"
#import "ADMobGenConfigModel.h"

@interface ADMobGenSDKConfig ()

/// SDK的启动Id
@property (nonatomic, copy) NSString *appId;
/// SDK的配置信息
@property (nonatomic, strong) ADMobGenConfigModel *sdkInfo;
/// SDK是否初始化成功
@property (nonatomic, assign) BOOL initSuccess;
/// 调试模式
@property (nonatomic, readonly, assign) BOOL debugMode;

+ (instancetype)sharedConfig;

/**
 是否可以抓包
 */
- (BOOL)flagTrue;

@end
