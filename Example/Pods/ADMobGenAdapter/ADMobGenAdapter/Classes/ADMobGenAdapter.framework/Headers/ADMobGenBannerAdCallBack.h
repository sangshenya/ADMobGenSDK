//
//  ADMobGenBannerAdCallBack.h
//  ADMobGenAdapter
//
//  Created by 曹飞 on 2018/7/13.
//

#import <Foundation/Foundation.h>

@protocol ADMobGenBannerAdCallBack <NSObject>

- (void)bannerViewDidReceivedCallBack:(id)bannerAd;

- (void)bannerViewFailToReceivedCallBack:(id)bannerAd error:(NSError *)error;

- (void)bannerViewClickedCallBack:(id)bannerAd tracked:(BOOL)tracked;

- (void)bannerViewExposureCallBack:(id)bannerAd tracked:(BOOL)tracked;

@end
