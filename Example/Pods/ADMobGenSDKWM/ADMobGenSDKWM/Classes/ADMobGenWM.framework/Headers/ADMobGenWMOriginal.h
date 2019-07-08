//
//  ADMobGenWMOriginal.h
//  ADMobGenWM
//
//  Created by 陈坤 on 2019/1/5.
//

#import <Foundation/Foundation.h>
#import <ADMobGenAdapter/ADMobGenOriginalProtocol.h>

@class BUNativeAd;

NS_ASSUME_NONNULL_BEGIN

@interface ADMobGenWMOriginal : NSObject<ADMobGenOriginalProtocol>

@property (nonatomic, strong, readonly) BUNativeAd *nativeAd;

- (instancetype)initWithNativeAd:(BUNativeAd *)nativeAd;

@end

NS_ASSUME_NONNULL_END
