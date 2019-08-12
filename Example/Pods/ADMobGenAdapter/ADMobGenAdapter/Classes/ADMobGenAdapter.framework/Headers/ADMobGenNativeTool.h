//
//  ADMobGenNativeTool.h
//  ADMobGenAdapter
//
//  Created by kaifa on 2018/8/13.
//

#import <Foundation/Foundation.h>
#import "ADMobGenNativeExpressCommon.h"

@interface ADMobGenHtmlColor : NSObject

- (instancetype)initWithString:(NSString *)colorString;

- (instancetype)initWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;

- (NSString *)getColorString;

- (UIColor *)getColor;

@end

@interface ADMobGenNativeTool : NSObject

+ (instancetype)sharedInstance;

+ (NSString *)getHtmlStringWithAdType:(ADMobGenNativeAdType)adType;

/**
 配置信息流广告样式
 
 @param htmlString 信息流广告样式，所有的都自定义
 @param adType 配置的信息流广告类型
 */
+ (void)setHtmlString:(NSString *)htmlString adType:(ADMobGenNativeAdType)adType;

/**
 配置.gdtmo标签
 
 @param mainEdge 整体上左下右的间隙，只对left(默认:(10, 16, 10, 16))/right(默认:(10, 16, 10, 16))/three(默认:(10, 16, 10, 16))/double(默认:(0, 16, 8, 16))起作用
 @param isDefult 是否使用默认间隙和背景颜色
 @param mainColor 整体背景颜色，默认为#ffffff
 @param adType 配置的信息流广告类型，目前只支持left/right/three/double
 */
+ (void)setHtmlHeadMainEdge:(UIEdgeInsets)mainEdge mainBackgroundColor:(ADMobGenHtmlColor *)mainColor defult:(BOOL)isDefult adType:(ADMobGenNativeAdType)adType;

/**
 配置.t.image标签
 
 @param imageEdge 图片的上左下右的间隙，目前只支持nomal(默认:(10, 16, 10, 16))/center(默认:(8, 16, 10, 16))
 @param isDefult 是否使用默认间隙
 @param adType 配置的信息流广告类型，目前只支持nomal/center
 */
+ (void)setHtmlImageEdge:(UIEdgeInsets)imageEdge defult:(BOOL)isDefult adType:(ADMobGenNativeAdType)adType;

/**
 配置广告字样加标题，.vda便签
 
 @param titleColor 标题颜色，默认为#999999;双图双文默认#666666
 @param titleFont 标题字体大小，默认为12;双图双文默认14
 @param titlePaddingRight 标题右边距，默认为30;双图双文无效
 @param bottomEdge 与底部间隙，默认值left、right为(0, 10, 0, 0)、three为(10, 0, 0, 0)、其他为(0, 16, 10, 16);双图双文中是与顶部的间隙，默认值为(10，16，16，16)
 @param adType 信息流广告类型
 @param isDefult 是否使用默认样式
 */
+ (void)setHtmlForBottomWithTitleColor:(ADMobGenHtmlColor *)titleColor titleFont:(NSInteger)titleFont titlePaddingRight:(CGFloat)titlePaddingRight bottomEdge:(UIEdgeInsets)bottomEdge adType:(ADMobGenNativeAdType)adType defult:(BOOL)isDefult;

/**
 配置广告字样，.vda .icon-ad便签，不适用于双图双文
 
 @param adFont 广告字体大小，默认为10
 @param adColor 广告颜色，默认为#ffffff
 @param backgroundColor 背景颜色，默认为#cccccc
 @param borderRadius 边框圆角大小，默认为2
 @param adEdge 文字与边框间隙，默认为(0, 4, 0, 4)
 @param rightSpace 与标题的右边距，默认为6
 @param borderWidth 边框大小，默认为0
 @param borderColor  边框颜色，默认为#ffffff
 @param lineHeight 容器高度，默认为18
 @param adType 信息流广告类型
 @param isDefult 是否使用默认样式
 */
+ (void)setHtmlForIconAdWithAdFont:(NSInteger)adFont adColor:(ADMobGenHtmlColor *)adColor backgroundColor:(ADMobGenHtmlColor *)backgroundColor borderRadius:(CGFloat)borderRadius adEdge:(UIEdgeInsets)adEdge rightSpace:(CGFloat)rightSpace borderWidth:(CGFloat)borderWidth borderColor:(ADMobGenHtmlColor *)borderColor lineHeight:(CGFloat)lineHeight adType:(ADMobGenNativeAdType)adType defult:(BOOL)isDefult;

/**
 配置广告描述，.description便签
 
 @param descColor 描述颜色，默认为#666666,双图双文默认为#333333
 @param descFont 描述字体大小，默认为14
 @param descEdge 描述边距，normal(0, 16, 8, 16)、center(10, 16, 0, 16)、left(0, 10, 0, 0)、right(0, 10, 0, 0)、three(0, 0, 8, 0)、双图双文(0, 16, 8, 16)
 @param adType 信息流广告类型
 @param isDefult 是否使用默认样式
 */

+ (void)setHtmlForDescriptionWithDescColor:(ADMobGenHtmlColor *)descColor descFont:(NSInteger)descFont descEdge:(UIEdgeInsets)descEdge adType:(ADMobGenNativeAdType)adType defult:(BOOL)isDefult;

+ (NSString *)htmlStringWithMainImageurl:(NSString *)imageurl
                                   title:(NSString *)title
                                subTitle:(NSString *)subTitle
                                  adType:(ADMobGenNativeAdType)adType
                                platform:(ADMobGenNativeAdPlatform)platform DEPRECATED_MSG_ATTRIBUTE("Donot has imageUrlArray");

+ (NSString *)htmlStringWithMainImageurlArray:(NSArray *)imageUrlArray
                                   title:(NSString *)title
                                subTitle:(NSString *)subTitle
                                  adType:(ADMobGenNativeAdType)adType
                                platform:(ADMobGenNativeAdPlatform)platform;




@end
