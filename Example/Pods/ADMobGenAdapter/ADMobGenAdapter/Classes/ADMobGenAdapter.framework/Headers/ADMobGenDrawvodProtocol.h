//
//  ADMobGenDrawvodProtocol.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/3/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ADMobGenDrawvodProtocol <NSObject>

@optional

- (NSString *)title;

- (NSString *)desc;

- (NSString *)iconImageUrl;

- (id)getDrawvodAd;

- (NSString *)drawvodAdClass;

- (UILabel *)adLabel;

- (UIImageView *)logoImageView;

- (UIImageView *)logoADImageView;

/**
 定义原生广告视图中，注册可点击视图
 @param containerView 注册原生广告的容器视图，必传参数
 @param clickViews 注册创意按钮，可选参数
 @note 同一nativeAd对象请勿重复注册同一视图
 */
- (void)registContainerView:(__kindof UIView *)containerView withClickViews:(NSArray<__kindof UIView *> *_Nullable)clickViews;

/// 广告类解除和view的绑定
- (void)unregisterView;

@end

NS_ASSUME_NONNULL_END
