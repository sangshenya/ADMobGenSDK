//
//  ADMobGenInitializeLoader.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/10/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ADMobGenInitializeLoader : NSObject

+ (NSArray<NSString *> *)allPlatforms;

+ (void)registPlatformClass:(Class)klass forSdkName:(NSString *)sdkName;

+ (Class)platformClassForSdkName:(NSString *)sdkName;

@end

NS_ASSUME_NONNULL_END
