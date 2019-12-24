//
//  ADMobUnifiedNativeAdViewProtocol.h
//  ADMobGenAdapter
//
//  Created by 陶冶明 on 2019/11/6.
//

#import <Foundation/Foundation.h>
@class ADMobUnifiedNativeAdDataObject;

NS_ASSUME_NONNULL_BEGIN

@protocol ADMobUnifiedNativeAdViewProtocol <NSObject>

@required
/**
 视频播放视图
 */
- (UIView *)admg_mediaViewForWidth:(CGFloat)width;

/**
 广告的对象
 */
- (ADMobUnifiedNativeAdDataObject *)admg_dataObject;

/**
 广告标识符
 */
- (UIImage *)logoImageWithText:(BOOL)on;

/**
 注册广告视图
 */
- (void)admg_regist;

@end

NS_ASSUME_NONNULL_END
