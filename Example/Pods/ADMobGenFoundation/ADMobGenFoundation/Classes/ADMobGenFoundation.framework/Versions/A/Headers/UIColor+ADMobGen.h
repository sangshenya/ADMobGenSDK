//
//  UIColor+ADMobGen.h
//  ADMobGenFoundation
//
//  Created by 陈坤 on 2018/10/24.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ADMGGradientType) {
    ADMGGradientFromTopToBottom = 1,            //从上到下
    ADMGGradientFromLeftToRight,                //从做到右
    ADMGGradientFromLeftTopToRightBottom,       //从上到下
    ADMGGradientFromLeftBottomToRightTop        //从上到下
};

@interface UIColor (ADMobGen)
/**
 图片转颜色
 @param image   图片
 @param newSize 背景的大小
 */
+ (UIColor *)admg_getColorWithImage:(UIImage *)image withNewSize:(CGSize)newSize;

/**
 十六进制数转颜色
 @param hexString 十六进制数
 */
+ (nullable UIColor *)admg_colorWithHexString:(NSString *)hexString;

/**
 十六进制数转颜色
 @param hexString      十六进制数
 @param alphaComponent 透明度 0~1
 */
+ (nullable UIColor *)admg_colorWithHexString:(NSString *)hexString alphaComponent:(CGFloat)alphaComponent;

/**
 *  根据给定的颜色，生成渐变色的颜色
 *  @param size           视图的大小
 *  @param colors         渐变颜色的数组
 *  @param percents       渐变颜色的占比数组
 *  @param gradientType   渐变色的类型
 */
+ (UIColor *)admg_getGradientWithSize:(CGSize)size gradientColors:(NSArray *)colors percentage:(NSArray *)percents gradientType:(ADMGGradientType)gradientType;

@end

NS_ASSUME_NONNULL_END
