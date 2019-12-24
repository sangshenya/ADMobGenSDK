//
//  ADMobGenTimerTool.h
//  ADMobGenFoundation
//
//  Created by 陈坤 on 2019/10/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ADMobGenTimerTool : NSObject

- (instancetype)initStartWithTimeRefresh:(NSInteger)timeRefresh;

- (void)stop;

@end

FOUNDATION_EXTERN NSNotificationName const kADMobGenTimerRefreshCallBackNotification;

NS_ASSUME_NONNULL_END


