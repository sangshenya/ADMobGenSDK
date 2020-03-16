//
//  ADMobGenWMConfig.h
//  ADMobGenWM
//
//  Created by 陈坤 on 2018/10/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ADMobGenInitializeConfig;

@interface ADMobGenWMConfig : NSObject

/**
 SDK Version
 */
+ (NSString *)getSDKVersion;

/**
SDK 初始化
*/
- (void)initializeSDK:(ADMobGenInitializeConfig *)config;

@end

NS_ASSUME_NONNULL_END
