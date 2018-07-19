//
//  ADMobGenNativeLoader.h
//  ADMobGenAdapter
//
//  Created by 曹飞 on 2018/7/17.
//

#import <Foundation/Foundation.h>

@interface ADMobGenNativeLoader : NSObject

+ (NSArray<NSString *> *)allPlatforms;

+ (void)registPlatformClass:(Class)klass forSdkName:(NSString *)sdkName;

+ (Class)platformClassForSdkName:(NSString *)sdkName;

@end
