//
//  ADMobGenSDKGzipUtils.h
//  ADMobGenFoundation
//
//  Created by 陈坤 on 2019/2/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ADMobGenSDKGzipUtils : NSObject

+ (NSData *)admg_gzipData:(NSData *)gzipData;
+ (NSData *)admg_ungzipData:(NSData *)unGzipData;

@end

NS_ASSUME_NONNULL_END
