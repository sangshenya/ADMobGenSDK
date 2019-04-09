//
//  UIDevice+ADMobGen.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/6/28.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIDevice (ADMobGen)

#pragma mark - Device Information

// 系统版本号 (e.g. 8.0)
+ (double)admg_systemVersion;

// 运营商识别码 (e.g. "46001"), 获取失败返回nil
+ (NSString *)admg_imsi;

// 网络类型 (e.g. "4G"), 获取失败返回nil
+ (NSString *)admg_networkType;

// idfa广告标识符,获取失败返回nil
+ (NSString *)admg_idfa;

@property (nonatomic, readonly) BOOL admg_isSimulator;

@end

#ifndef kSystemVersion
#define kSystemVersion [UIDevice admg_systemVersion]
#endif

#ifndef kiOS7Later
#define kiOS7Later (kSystemVersion >= 7)
#endif

#ifndef kiOS8Later
#define kiOS8Later (kSystemVersion >= 8)
#endif

#ifndef kiOS9Later
#define kiOS9Later (kSystemVersion >= 9)
#endif

#ifndef kiOS10Later
#define kiOS10Later (kSystemVersion >= 10)
#endif

#ifndef kiOS11Later
#define kiOS11Later (kSystemVersion >= 11)
#endif

#ifndef kiOS12Later
#define kiOS12Later (kSystemVersion >= 12)
#endif
