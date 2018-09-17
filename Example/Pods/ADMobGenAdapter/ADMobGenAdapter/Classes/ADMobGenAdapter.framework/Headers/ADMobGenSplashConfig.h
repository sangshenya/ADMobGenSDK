//
//  ADMobGenSplashConfig.h
//  ADMobGenAdapter
//
//  Created by 曹飞 on 2018/7/12.
//

#import <Foundation/Foundation.h>

@protocol ADMobGenSplashAdCallBack;

@interface ADMobGenSplashConfig : NSObject

@property (nonatomic, readonly, strong) UIView *contentView;
@property (nonatomic, readonly, strong) UIView *bottomView;
@property (nonatomic, readonly, copy) UIColor *backgroundColor;
@property (nonatomic, readonly, copy) NSString *appId;
@property (nonatomic, readonly, copy) NSString *posId;
@property (nonatomic, readonly, assign) BOOL displayType;
@property (nonatomic, readonly, assign) BOOL trunType;
@property (nonatomic, readonly, weak) UIViewController *viewController;
@property (nonatomic, readonly, weak) id<ADMobGenSplashAdCallBack> callback;

+ (instancetype)configWithContentView:(UIView *)contentView
                           bottomView:(UIView *)bottomView
                      backgroundColor:(UIColor *)backgroundColor
                                appId:(NSString *)appId
                                posId:(NSString *)posId
                          displayType:(BOOL)displayType
                       viewController:(UIViewController *)viewController
                             callBack:(id<ADMobGenSplashAdCallBack>)callBack DEPRECATED_MSG_ATTRIBUTE("Donot has displayType");

+ (instancetype)configWithContentView:(UIView *)contentView
                           bottomView:(UIView *)bottomView
                      backgroundColor:(UIColor *)backgroundColor
                                appId:(NSString *)appId
                                posId:(NSString *)posId
                          displayType:(BOOL)displayType
                             trunType:(BOOL)trunType
                       viewController:(UIViewController *)viewController
                             callBack:(id<ADMobGenSplashAdCallBack>)callBack;

@end
