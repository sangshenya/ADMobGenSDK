//
//  ADMobGenSplashAdCallBack.h
//  ADMobGenAdapter
//
//  Created by 曹飞 on 2018/7/12.
//

#import <Foundation/Foundation.h>

@protocol ADMobGenSplashAdCallBack <NSObject>

- (void)splashAdSuccessToPresentCallBack:(id)splashAd;

- (void)splashAdFailToPresentCallBack:(id)splashAd error:(NSError *)error;

- (void)splashAdExposureCallBack:(id)splashAd tracked:(BOOL)tracked;

- (void)splashAdClickedCallBack:(id)splashAd tracked:(BOOL)tracked;

- (void)splashAdClosedCallBack:(id)splashAd;

@end
