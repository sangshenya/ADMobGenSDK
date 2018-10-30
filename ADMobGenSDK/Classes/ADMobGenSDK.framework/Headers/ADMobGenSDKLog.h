//
//  ADMobGenSDKLog.h
//  ADMobGenSDK
//
//  Created by 陈坤 on 2018/9/4.
//

#import <Foundation/Foundation.h>

/**
 *  自定义error Log，可配置开关（用于替换NSLog）
 */
#define ADMobGenELog(format,...) ECustomLog(format,##__VA_ARGS__)

#define ADMobGenDLog(format,...) DCustomLog(format,##__VA_ARGS__)

#define ADMobGenLog(format,...) ACustomLog(format,##__VA_ARGS__)
/**
 *  自定义Log
 *  @param format       Log内容
 *  @param ...          个数可变的Log参数
 */
void ECustomLog(NSString *format, ...);

void DCustomLog(NSString *format, ...);

void ACustomLog(NSString *format, ...);

@interface ADMobGenSDKLog : NSObject

@end
