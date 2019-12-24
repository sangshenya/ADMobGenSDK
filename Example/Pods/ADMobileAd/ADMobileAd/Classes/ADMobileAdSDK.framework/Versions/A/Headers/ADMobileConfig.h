//
//  ADMobileConfig.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/10/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ADMobGenInitializeConfig;

@interface ADMobileConfig : NSObject

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
