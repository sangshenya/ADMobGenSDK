//
//  ADMobGenSDKUtils.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/7/7.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ADMobGenSDKUtils : NSObject

/**
 是否开启网络代理
 */
+ (BOOL)hasAgent;

/**
 md5 加密
 */
+ (NSString *)md5:(NSString *)string;

/**
 是否含有中文
 */
+ (BOOL)containsChinese:(NSString *)string;

@end
