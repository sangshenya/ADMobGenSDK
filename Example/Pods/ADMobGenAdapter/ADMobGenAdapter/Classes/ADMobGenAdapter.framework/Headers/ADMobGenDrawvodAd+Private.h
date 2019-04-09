//
//  ADMobGenDrawvodAd+Private.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/3/8.
//

#import "ADMobGenDrawvodAd.h"

@class ADMobGenDrawvodProtocol;

NS_ASSUME_NONNULL_BEGIN

@interface ADMobGenDrawvodAd ()

- (instancetype)initWithDrawvodAdView:(UIView<ADMobGenDrawvodProtocol> *)drawvodAdView;

- (void)setClickTracked;
- (BOOL)getClickTracked;

- (void)setExposureTracked;
- (BOOL)getExposureTracked;

@end

NS_ASSUME_NONNULL_END
