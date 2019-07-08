//
//  ADMobGenNativeExpressProtocol.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/3/11.
//

#import <Foundation/Foundation.h>
#import "ADMobGenNativeExpressCommon.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ADMobGenNativeExpressProtocol <NSObject>

//渲染方法
- (void)render;

//获取视图高度
- (CGSize)contentSize;

@optional
// 期望size
- (CGSize)expectSize;

// 类型
- (ADMobGenNativeAdType)adType;

// 平台类型
- (ADMobGenNativeAdPlatform)adPlatform;

@end

NS_ASSUME_NONNULL_END
