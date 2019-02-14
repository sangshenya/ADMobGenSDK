//
//  ADMobGenNativeProtocol.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/1/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ADMobGenOriginalProtocol <NSObject>

- (NSString *)title;

- (NSString *)desc;

- (NSArray<NSString *> *)imageUrlArray;

- (id)getOriginalAd;

- (NSString *)originalAdClass;

/**
 定义原生广告视图中，注册可点击视图
 @param containerView 注册原生广告的容器视图，必传参数
 @param clickViews 注册创意按钮，可选参数
 @note 同一nativeAd对象请勿重复注册同一视图
 */
- (void)registContainerView:(__kindof UIView *)containerView withClickViews:(NSArray<__kindof UIView *> *_Nullable)clickViews;

/// 广告类解除和view的绑定
- (void)unregisterView;

// 广告位展示落地页通过rootviewController进行跳转，必传参数，跳转方式分为pushViewController和presentViewController两种方式
- (void)rootViewController:(UIViewController *)rootViewController;


@end

NS_ASSUME_NONNULL_END
