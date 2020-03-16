//
//  NSDate+ADMobGen.h
//  ADMobGenFoundation
//
//  Created by 陈坤 on 2020/1/8.
//
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDate (ADMobGen)

@property (nonatomic, assign, readonly) NSInteger admg_year;
@property (nonatomic, assign, readonly) NSInteger admg_month;
@property (nonatomic, assign, readonly) NSInteger admg_day;
@property (nonatomic, assign, readonly) NSInteger admg_hour;
@property (nonatomic, assign, readonly) NSInteger admg_minute;
@property (nonatomic, assign, readonly) NSInteger admg_seconds;
@property (nonatomic, assign, readonly) NSInteger admg_weekday;

+ (NSDate *)admg_dateWithDateString:(NSString *)dateString;

+(NSDate *)admg_dateWithFormat_yyyy_MM_dd_HH_mm_ss_string:(NSString *)string;
+(NSDate *)admg_dateWithFormat_yyyy_MM_dd_HH_mm_string:(NSString *)string;
+(NSDate *)admg_dateWithFormat_yyyy_MM_dd_HH_string:(NSString *)string;
+(NSDate *)admg_dateWithFormat_yyyy_MM_dd_string:(NSString *)string;
+(NSDate *)admg_dateWithFormat_yyyy_MM_string:(NSString *)string;

@end

NS_ASSUME_NONNULL_END
