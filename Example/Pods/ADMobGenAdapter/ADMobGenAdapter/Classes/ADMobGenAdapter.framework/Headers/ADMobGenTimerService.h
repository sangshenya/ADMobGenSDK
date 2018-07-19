//
//  ADMobGenTimerService.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/7/4.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ADMobGenTimer : NSObject

+ (ADMobGenTimer *)timerWithTimeInterval:(NSTimeInterval)interval
                                         target:(id)target
                                       selector:(SEL)selector
                                        repeats:(BOOL)repeats;

- (instancetype)initWithFireTime:(NSTimeInterval)start
                        interval:(NSTimeInterval)interval
                          target:(id)target
                        selector:(SEL)selector
                         repeats:(BOOL)repeats NS_DESIGNATED_INITIALIZER;

@property (readonly) BOOL repeats;
@property (readonly) NSTimeInterval timeInterval;
@property (readonly, getter=isValid) BOOL valid;

- (void)invalidate;

- (void)fire;

@end

@interface ADMobGenTimerService : NSObject

+ (void)start;

@end

FOUNDATION_EXTERN NSNotificationName const kADMobGenTimerCallBackNotification;
