//
//  ADMobGenInterstitialAdConfig.h
//  ADMobGenAdapter
//
//  Created by 陶冶明 on 2019/11/8.
//

#import <Foundation/Foundation.h>
@protocol ADMobGenInterstitialCallBack;

typedef NS_ENUM(NSUInteger, ADMobGenInterstitialAdAspectRatio) {
    ADMobGenInterstitialAdAspectRatioDefault,
    ADMobGenInterstitialAdAspectRatio3_2,
    ADMobGenInterstitialAdAspectRatio1_1,
    ADMobGenInterstitialAdAspectRatio2_3,
};

NS_ASSUME_NONNULL_BEGIN

@interface ADMobGenInterstitialAdConfig : NSObject

/**
 平台的应用id
 */
@property (nonatomic, readonly, copy) NSString *appId;

/**
 平台的广告位id
 */
@property (nonatomic, readonly, copy) NSString *posId;

/**
 广告生命周期回调
 */
@property (nonatomic, readonly, weak) id<ADMobGenInterstitialCallBack> callback;

/**
 
 */
@property (nonatomic, readonly, assign) BOOL trunType;

/**
 
 */
@property (nonatomic, readonly, assign) BOOL rewardType;

/**
 长宽比,长/宽
 */
@property (nonatomic, readonly, assign) ADMobGenInterstitialAdAspectRatio aspectRatio;

@property (nonatomic, readonly, assign) CGSize adSize;

/**
 点击广告需要跳转的控制器
 */
@property (nonatomic, readonly, weak) UIViewController *viewController;

+ (instancetype)configWithAppId:(NSString *)appId
                          posId:(NSString *)posId
                       trunType:(BOOL)trunType
                     rewardType:(BOOL)rewardType
                 viewController:(UIViewController *)viewController
                    aspectRatio:(ADMobGenInterstitialAdAspectRatio)aspectRatio
                         adSize:(CGSize)adSize
                       callback:(id<ADMobGenInterstitialCallBack>)callback;

@end

NS_ASSUME_NONNULL_END
