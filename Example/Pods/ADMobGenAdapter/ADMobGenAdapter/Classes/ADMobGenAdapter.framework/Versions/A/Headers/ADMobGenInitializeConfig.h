//
//  ADMobGenInitializeConfig.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/10/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ADMobGenInitializeConfig : NSObject
/**
 平台的应用id
 */
@property (nonatomic, readonly, copy) NSString *appId;

@property (nonatomic, readonly, assign) BOOL trunType;


+ (instancetype)configWithAppId:(NSString *)appId DEPRECATED_MSG_ATTRIBUTE("Donot has trunType");

+ (instancetype)configWithAppId:(NSString *)appId trunType:(BOOL)trunType;

@end

NS_ASSUME_NONNULL_END
