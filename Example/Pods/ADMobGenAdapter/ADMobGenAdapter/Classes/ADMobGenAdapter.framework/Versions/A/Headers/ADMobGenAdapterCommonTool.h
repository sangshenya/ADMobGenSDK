//
//  ADMobGenAdapterCommonTool.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/10/24.
//

#import <Foundation/Foundation.h>
#import "ADMobGenAdapterCommon.h"

NS_ASSUME_NONNULL_BEGIN

@interface ADMobGenAdapterCommonTool : NSObject

+ (UIImage *)getBundleImageWithImageName:(NSString *)imageName;

+ (UIImage *)getBundleLogoWithAdLabel:(BOOL)hasAdLabel platform:(ADMobGenAdPlatform)platform;

@end

NS_ASSUME_NONNULL_END
