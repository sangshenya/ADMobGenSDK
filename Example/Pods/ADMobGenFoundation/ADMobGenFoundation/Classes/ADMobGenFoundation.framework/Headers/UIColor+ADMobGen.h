//
//  UIColor+ADMobGen.h
//  ADMobGenFoundation
//
//  Created by 陈坤 on 2018/10/24.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (ADMobGen)
/**
 图片转颜色
 @param image 图片
 @param newSize 背景的大小
 */
+ (UIColor *)getColorWithImage:(UIImage *)image withNewSize:(CGSize)newSize;

/**
 十六进制数转颜色
 @param hexString 十六进制数
 */
+ (nullable UIColor *)colorWithHexString:(NSString *)hexString;

/**
 十六进制数转颜色
 @param hexString 十六进制数
 @param alphaComponent 透明度 0~1
 */
+ (nullable UIColor *)colorWithHexString:(NSString *)hexString alphaComponent:(CGFloat)alphaComponent;

@end

NS_ASSUME_NONNULL_END
