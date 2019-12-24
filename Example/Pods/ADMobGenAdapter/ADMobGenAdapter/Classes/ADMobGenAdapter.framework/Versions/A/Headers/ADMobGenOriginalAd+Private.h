//
//  ADMobGenNativeAd+Private.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/1/4.
//

#import "ADMobGenOriginalAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface ADMobGenOriginalAd ()

@property (nonatomic, strong, readonly) id<ADMobGenOriginalProtocol> originalAd;

//
- (instancetype)initWithOriginalAd:(id<ADMobGenOriginalProtocol>)originalAd;

- (void)setClickTracked;
- (BOOL)getClickTracked;

- (void)setExposureTracked;
- (BOOL)getExposureTracked;

@end

NS_ASSUME_NONNULL_END
