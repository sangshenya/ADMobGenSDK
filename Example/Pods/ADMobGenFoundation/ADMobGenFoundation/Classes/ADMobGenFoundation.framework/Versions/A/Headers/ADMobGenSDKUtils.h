//
//  ADMobGenSDKUtils.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/7/7.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>

NSString * KADMGDateString(NSDate *date, NSString *format);

@interface ADMobGenSDKUtils : NSObject

/**
 是否开启网络代理
 */
+ (BOOL)hasAgent;

/**
 md5 加密
 */
+ (NSString *)md5:(NSString *)string;

/**NSString * KADMGDateString(NSDate *date, NSString *format);
 是否含有中文
 */
+ (BOOL)containsChinese:(NSString *)string;

@end
