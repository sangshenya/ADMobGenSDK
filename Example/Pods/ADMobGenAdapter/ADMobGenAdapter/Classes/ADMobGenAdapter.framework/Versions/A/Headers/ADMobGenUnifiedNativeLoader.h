//
//  ADMobGenUnifiedNativeLoader.h
//  ADMobGenAdapter
//
//  Created by 陶冶明 on 2019/11/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ADMobGenUnifiedNativeLoader : NSObject

+ (NSArray<NSString *> *)allPlatforms;

+ (void)registPlatformClass:(Class)klass forSdkName:(NSString *)sdkName;

+ (Class)platformClassForSdkName:(NSString *)sdkName;

@end

NS_ASSUME_NONNULL_END
