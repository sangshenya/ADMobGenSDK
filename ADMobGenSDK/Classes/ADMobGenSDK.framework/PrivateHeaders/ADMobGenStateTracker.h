//
//  ADMobGenStateTracker.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/7/5.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 广告追踪上报类
 
 请求上报
 展现上报
 点击上报
 错误状态
 */
@interface ADMobGenStateTracker : NSObject

@property (nonatomic, readonly, copy) NSString *sdkName;
@property (nonatomic, readonly, copy) NSString *adType;
@property (nonatomic, readonly, assign) int show;

- (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithWithSdkName:(NSString *)sdkName
                             adType:(NSString *)adType
                               show:(int)show NS_DESIGNATED_INITIALIZER;

- (void)sendRequestReport;

- (void)sendDisplayReport;

- (void)sendClickReport;

- (void)sendErrorReport:(NSError *)error;

@end
