//
//  ADMobGenBannerConfig.h
//  ADMobGenAdapter
//
//  Created by 曹飞 on 2018/7/13.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, ADMobGenBannerAdSize) {
    ADMobGenBannerAdSizeNormal = 0,//640:100
    ADMobGenBannerAdSize600_150 = 1,//600:150
    ADMobGenBannerAdSize690_388 = 2,//690:388
    ADMobGenBannerAdSize600_400 = 3,//600:400
    ADMobGenBannerAdSize600_260 = 4,//600:260
};

@protocol ADMobGenBannerAdCallBack;

@interface ADMobGenBannerConfig : NSObject

@property (nonatomic, readonly, copy) NSString *appId;
@property (nonatomic, readonly, copy) NSString *posId;
@property (nonatomic, readonly, assign) BOOL displayType;
@property (nonatomic, readonly, assign) BOOL trunType;
@property (nonatomic, readonly, assign) ADMobGenBannerAdSize bannerSize;
@property (nonatomic, readonly, weak) UIViewController *viewController;
@property (nonatomic, readonly, weak) id<ADMobGenBannerAdCallBack> callback;

+ (instancetype)configWithappId:(NSString *)appId
                          posId:(NSString *)posId
                    displayType:(BOOL)displayType
                 viewController:(UIViewController *)viewController
                       callback:(id<ADMobGenBannerAdCallBack>)callback DEPRECATED_MSG_ATTRIBUTE("Donot has trunType");

+ (instancetype)configWithappId:(NSString *)appId
                          posId:(NSString *)posId
                    displayType:(BOOL)displayType
                       trunType:(BOOL)trunType
                 viewController:(UIViewController *)viewController
                       callback:(id<ADMobGenBannerAdCallBack>)callback DEPRECATED_MSG_ATTRIBUTE("Donot has bannerSize");

+ (instancetype)configWithappId:(NSString *)appId
                          posId:(NSString *)posId
                    displayType:(BOOL)displayType
                       trunType:(BOOL)trunType
                     bannerSize:(ADMobGenBannerAdSize)bannerSize
                 viewController:(UIViewController *)viewController
                       callback:(id<ADMobGenBannerAdCallBack>)callback;

@end
