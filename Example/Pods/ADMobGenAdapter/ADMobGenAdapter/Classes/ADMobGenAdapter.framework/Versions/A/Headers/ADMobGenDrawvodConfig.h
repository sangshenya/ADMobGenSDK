//
//  ADMobGenDrawvodConfig.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/3/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ADMobGenDrawvodCallBack;

@interface ADMobGenDrawvodConfig : NSObject

/**
 平台的应用id
 */
@property (nonatomic, readonly, copy) NSString *appId;
/**
 平台的广告位id
 */
@property (nonatomic, readonly, copy) NSString *posId;
/**
 是否自定义样式，默认为NO
 */
@property (nonatomic, readonly, assign) BOOL isCustomStyles;
/**
 用来展示的视图控制器
 */
@property (nonatomic, readonly, weak) UIViewController *viewController;
/**
 广告生命周期回调
 */
@property (nonatomic, readonly, weak) id<ADMobGenDrawvodCallBack> callback;


+ (instancetype)configWithAppId:(NSString *)appId
                          posId:(NSString *)posId
              isCustomStyles:(BOOL)isCustomStyles
                 viewController:(UIViewController *)viewController
                       callback:(id<ADMobGenDrawvodCallBack>)callback;

@end

NS_ASSUME_NONNULL_END
