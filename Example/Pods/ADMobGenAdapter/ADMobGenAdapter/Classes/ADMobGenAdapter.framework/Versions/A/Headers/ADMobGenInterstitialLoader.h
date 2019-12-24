//
//  ADMobGenInterstitialLoader.h
//  Pods
//
//  Created by 陶冶明 on 2019/11/8.
//

#import <Foundation/Foundation.h>
@protocol ADMobGenInterstitialProtocol;

NS_ASSUME_NONNULL_BEGIN

@interface ADMobGenInterstitialLoader : NSObject

+ (NSArray<NSString *> *)allPlatforms;

+ (void)registPlatformClass:(Class<ADMobGenInterstitialProtocol>)klass forSdkName:(NSString *)sdkName;

+ (Class<ADMobGenInterstitialProtocol>)platformClassForSdkName:(NSString *)sdkName;

@end

NS_ASSUME_NONNULL_END
