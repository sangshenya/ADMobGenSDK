//
//  ADMobGenUnifiedNativeAd.h
//  ADMobGenSDK
//
//  Created by 陶冶明 on 2019/11/5.
//

#import <Foundation/Foundation.h>
#import <ADMobGenAdapter/ADMobUnifiedNativeAdDataObject.h>
#import <ADMobGenAdapter/ADMobUnifiedNativeAdViewProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class ADMobGenUnifiedNativeAd;

@protocol ADMobGenUnifiedNativeAdDelegate <NSObject>

/**
 ADMobGenUnifiedNativeAd请求成功
 
 @param unifiedNativeAd 自渲染广告实例对象
 @param nativeAdViewAry 自渲染广告视图数组
 */
- (void)admg_unifiedNativeSuccessToLoad:(ADMobGenUnifiedNativeAd *)unifiedNativeAd viewArray:(NSArray<UIView<ADMobUnifiedNativeAdViewProtocol>*> *)nativeAdViewAry;

/**
 ADMobGenUnifiedNativeAd请求失败
 
 @param unifiedNativeAd 自渲染广告实例对象
 @param error 失败原因
 */
- (void)admg_unifiedNativeFailToLoad:(ADMobGenUnifiedNativeAd *)unifiedNativeAd error:(NSError *)error;

/**
 ADMobGenUnifiedNativeAd被点击
 
 @param unifiedNativeAdView 被点击的原生广告
 */
- (void)admg_unifiedNativeClicked:(ADMobGenUnifiedNativeAd *)unifiedNativeAd view:(UIView<ADMobUnifiedNativeAdViewProtocol>*)unifiedNativeAdView;

/**
 ADMobGenUnifiedNativeAd展示
 
 @param unifiedNativeAd 广告实例
 @param unifiedNativeAdView 广告模板
 */
- (void)admg_unifiedNativeExposure:(ADMobGenUnifiedNativeAd *)unifiedNativeAd view:(UIView<ADMobUnifiedNativeAdViewProtocol>*)unifiedNativeAdView;

@end

@interface ADMobGenUnifiedNativeAd : NSObject

- (id)new NS_UNAVAILABLE;
- (id)init NS_UNAVAILABLE;

/**
 ADMobGenUnifiedNativeAd初始化接口

 @param viewController 开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 @param index 广告位序号，默认为0
*/
- (instancetype)initWithViewController:(nullable UIViewController *)viewController index:(NSInteger)index NS_DESIGNATED_INITIALIZER;

/**
 加载广告

 @param count 拉取几条广告,建议区间 1~4, 超过可能无法拉取到
*/
- (void)load:(int)count;

/**
 代理回调
*/
@property (nonatomic, weak) id<ADMobGenUnifiedNativeAdDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
