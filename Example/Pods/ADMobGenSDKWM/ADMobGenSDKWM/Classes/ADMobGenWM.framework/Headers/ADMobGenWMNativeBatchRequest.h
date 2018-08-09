//
//  ADMobGenWMNativeBatchRequest.h
//  ADMobGenWM
//
//  Created by kaifa on 2018/8/7.
//

#import <Foundation/Foundation.h>

@class WMNativeAd;

@protocol ADMobGenWMNativeBatchRequestDelegate <NSObject>

@optional
- (void)mcNativeExpressAdSuccessToLoadCallBack:(id)sourceAd dataArray:(NSArray<__kindof WMNativeAd *> *)dataArray;

- (void)mcNativeExpressAdFailToLoadCallBack:(id)sourceAd error:(NSError *)error;

- (void)mcNativeExpressAdClicked:(WMNativeAd *)nativeAd;

- (void)mcNativeEcpressADExposure:(WMNativeAd *)nativeAd;

@end

@interface ADMobGenWMNativeBatchRequest : NSObject

@property (nonatomic, weak) id<ADMobGenWMNativeBatchRequestDelegate> delegate;

- (void)load:(int)count posId:(NSString *)posId;

@end
