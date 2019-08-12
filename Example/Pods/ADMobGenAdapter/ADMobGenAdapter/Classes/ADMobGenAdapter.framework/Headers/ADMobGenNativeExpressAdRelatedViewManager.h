//
//  ADMobGenNativeExpressAdRelatedViewManager.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/6/15.
//

#import <Foundation/Foundation.h>
#import "ADMobGenNativeTool.h"

#define kTopSpace 10

//文字之间的间隙
#define kAdOrTestSpace 8

//左图右文、右图左文图片宽高
#define kLeftRightImageWidth 111
#define kLeftRightImageHeight 74

//广告字样label大小
#define kAdWidth 32
#define kAdHeight 18

//关闭按钮
#define kNormalCloseWidth 18
#define kBigCloseWidth 20

//logo
#define kAdLogoScale 0.4
#define kLogoScale 0.72

NS_ASSUME_NONNULL_BEGIN


@interface ADMobGenNativeExpressAdRelated : NSObject

/**
 整体上左下右的间隙，只对left/right起作用
 */
@property (nonatomic, assign) UIEdgeInsets mainEdgeInsets;
/**
 图片的上左下右的间隙,nomal/center
 */
@property (nonatomic, assign) UIEdgeInsets imageEdgeInsets;
/**
 整体背景颜色
 */
@property (nonatomic, strong) UIColor *mainColor;
/**
 标题颜色
 */
@property (nonatomic, strong) UIColor *titleColor;
/**
 标题字体大小
 */
@property (nonatomic, strong) UIFont *titleFont;
/**
 标题右边距
 */
@property (nonatomic, assign) CGFloat titlePaddingRight;
/**
 与底部间隙
 */
@property (nonatomic, assign) UIEdgeInsets bottomEdgeInsets;
/**
 广告字样的颜色
 */
@property (nonatomic, strong) UIColor *adColor;
/**
 广告字样的字体大小
 */
@property (nonatomic, strong) UIFont *adFont;
/**
 广告容器的背景颜色
 */
@property (nonatomic, strong) UIColor *adBgColor;
/**
 广告容器的圆角大小
 */
@property (nonatomic, assign) CGFloat adBdRadius;
/**
 广告文字与容器的间隙
 */
@property (nonatomic, assign) UIEdgeInsets adEdgeInsets;
/**
 与标题的右边距
 */
@property (nonatomic, assign) CGFloat rightSpace;
/**
 广告容器边框大小
 */
@property (nonatomic, assign) CGFloat adBdWidth;
/**
 广告容器边框颜色
 */
@property (nonatomic, strong) UIColor *bdColor;
/**
 广告容器高度
 */
@property (nonatomic, assign) CGFloat adHeight;
/**
 描述颜色
 */
@property (nonatomic, strong) UIColor *descColor;
/**
 描述字体大小
 */
@property (nonatomic, strong) UIFont *descFont;
/**
 描述间隙
 */
@property (nonatomic, assign) UIEdgeInsets descEdgeInsets;


@end

@interface ADMobGenNativeExpressAdRelatedViewManager : NSObject

+ (instancetype)sharedInstance;

- (void)setMainEdge:(UIEdgeInsets)mainEdge mainBgColor:(ADMobGenHtmlColor *)bgColor adType:(ADMobGenNativeAdType)adType defult:(BOOL)isDefult;

- (void)setImageEdge:(UIEdgeInsets)imageEdge adType:(ADMobGenNativeAdType)adType defult:(BOOL)isDefult;

- (void)setTitleColor:(ADMobGenHtmlColor *)titleColor titleFont:(NSInteger)titleFont titlePaddingRight:(CGFloat)titlePaddingRight bottomEdge:(UIEdgeInsets)bottomEdge adType:(ADMobGenNativeAdType)adType defult:(BOOL)isDefult;

- (void)setAdFont:(NSInteger)adFont adColor:(ADMobGenHtmlColor *)adColor backgroundColor:(ADMobGenHtmlColor *)backgroundColor borderRadius:(CGFloat)borderRadius adEdge:(UIEdgeInsets)adEdge rightSpace:(CGFloat)rightSpace borderWidth:(CGFloat)borderWidth borderColor:(ADMobGenHtmlColor *)borderColor lineHeight:(CGFloat)lineHeight adType:(ADMobGenNativeAdType)adType defult:(BOOL)isDefult;

- (void)setDescColor:(ADMobGenHtmlColor *)descColor descFont:(NSInteger)descFont descEdge:(UIEdgeInsets)descEdge adType:(ADMobGenNativeAdType)adType defult:(BOOL)isDefult;

- (void)setAdDes:(NSString *)adDes adTitle:(NSString *)adTitle normalSize:(CGSize)normalSize adType:(ADMobGenNativeAdType)adType;

- (ADMobGenNativeExpressAdRelated *)getRelatedViewWithAdType:(ADMobGenNativeAdType)adType;

@end

NS_ASSUME_NONNULL_END
