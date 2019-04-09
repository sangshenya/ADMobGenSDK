//
//  ADMobGenDrawvodAd.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/3/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ADMobGenDrawvodProtocol;

@interface ADMobGenDrawvodAd : NSObject

/**
 Draw 视频播放视图， 需要主动添加到 View
 */
@property (nonatomic, strong, readonly, nullable) UIView<ADMobGenDrawvodProtocol> *drawvodView;

/**
 广告标题
 */
@property (nonatomic, copy, readonly, nullable) NSString *title;

/**
 广告描述
 */
@property (nonatomic, copy, readonly, nullable) NSString *content;

/**
 广告icon
 */
@property (nonatomic, copy, readonly, nullable) NSString *iconImageUrl;

/**
 adLabel 推广标签懒加载， 需要主动添加到 View
 */
@property (nonatomic, strong, readonly, nullable) UILabel *adLabel;

/**
 logoImageView 广告标识，需要主动添加到 View
 */
@property (nonatomic, strong, readonly, nullable) UIImageView *logoImageView;
/**
 logoADImageView 广告+广告标识，需要主动添加到 View
 */
@property (nonatomic, strong, readonly, nullable) UIImageView *logoADImageView;


/**
 注册可点击视图，当选择自定义样式时，需要调用该方法
 @param containerView 注册Draw视频广告的容器视图，必传参数
 @param clickViews 注册创意按钮，可选参数
 @note 同一nativeAd对象请勿重复注册同一视图
 */
- (void)registContainerView:(__kindof UIView *)containerView withClickViews:(NSArray<__kindof UIView *> *_Nullable)clickViews;

/// 广告类解除和view的绑定
- (void)unregisterView;

@end

NS_ASSUME_NONNULL_END
