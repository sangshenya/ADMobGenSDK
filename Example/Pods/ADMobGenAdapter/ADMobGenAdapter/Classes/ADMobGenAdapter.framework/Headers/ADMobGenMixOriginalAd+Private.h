//
//  ADMobGenMixOriginalAd+Private.h
//  ADMobGenAdapter
//
//  Created by 陶冶明 on 2019/9/23.
//

#import "ADMobGenMixOriginalAd.h"

@interface ADMobGenMixOriginalAd ()

@property (nonatomic, strong, readonly) id<ADMobGenMixOriginalProtocol> originalAd;

//
- (instancetype)initWithOriginalAd:(id<ADMobGenMixOriginalProtocol>)originalAd;

- (void)setClickTracked;
- (BOOL)getClickTracked;

- (void)setExposureTracked;
- (BOOL)getExposureTracked;

@end

