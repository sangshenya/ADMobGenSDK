//
//  ADMobUnifiedNativeAdDataObject.h
//  ADMobGenSDK
//
//  Created by 陶冶明 on 2019/11/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ADMobUnifiedNativeAdDataObject : NSObject

/**
 标题
 */
@property (nonatomic, copy, nullable) NSString *title;

/**
 描述
 */
@property (nonatomic, copy, nullable) NSString *desc;

/**
 封面大图
 */
@property (nonatomic, copy, nullable) NSString *imageUrl;

/**
 图片列表
 */
@property (nonatomic, copy, nullable) NSArray<NSString *> *imageUrlAry;

/**
 icon图片url(不同平台的差异导致，需要同时判断一下iconImageUrl和iconImage)
 */
@property (nonatomic, copy, nullable) NSString *iconImageUrl;

/**
 icon图片
 */
@property (nonatomic, strong, nullable) UIImage *iconImage;

/**
 是否需要显示多媒体View（包括但不限于：视频素材、没有图片素材）
 */
@property (nonatomic, assign) BOOL shouldShowMediaView;

/**
 原始对象
 */
@property (nonatomic, strong, nullable) id nativeData;

@end

NS_ASSUME_NONNULL_END
