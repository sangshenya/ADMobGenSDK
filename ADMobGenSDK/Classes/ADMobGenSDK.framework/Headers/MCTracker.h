//
//  MCTracker.h
//  MCTracker
//
//  Created by 曹飞 on 2018/1/23.
//  Copyright © 2018年 Hangzhou Mo Chu Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MCTracker : NSObject

/**
 开始追踪用户行为, 该方法内部只会调用一次逻辑,多次调用无效

 @param serviceDomain 指定上报域名
 @param provingBlock SDK校验成功
 */
+ (void)startTrackerWithServiceDomain:(NSString *)serviceDomain provingSuccess:(void (^)(BOOL success))provingBlock;

/**
 SDK是否校验成功

 @return 校验成功
 */
+ (BOOL)provingSuccess;

/**
 设备唯一标识, SDK校验成功才可以正确获取到

 @return 唯一标识
 */
+ (long)machineId;

@end
