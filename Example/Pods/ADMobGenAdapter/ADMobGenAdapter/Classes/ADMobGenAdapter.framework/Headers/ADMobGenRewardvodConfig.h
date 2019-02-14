//
//  ADMobGenRewardvodConfig.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2018/12/20.
//

#import <Foundation/Foundation.h>

@protocol ADMobGenRewardvodCallBack;

NS_ASSUME_NONNULL_BEGIN

@interface ADMobGenRewardvodConfig : NSObject

@property (nonatomic, readonly, copy) NSString *appId;
@property (nonatomic, readonly, copy) NSString *posId;
@property (nonatomic, readonly, assign) BOOL trunType;
@property (nonatomic, readonly, assign) BOOL isSupportLandscape;
@property (nonatomic, readonly, weak) UIViewController *viewController;
@property (nonatomic, readonly, weak) id<ADMobGenRewardvodCallBack> callback;

+ (instancetype)configWithappId:(NSString *)appId
                          posId:(NSString *)posId
                       trunType:(BOOL)trunType
             isSupportLandscape:(BOOL)isSupportLandscape
                 viewController:(UIViewController *)viewController
                       callback:(id<ADMobGenRewardvodCallBack>)callback;

@end

NS_ASSUME_NONNULL_END
