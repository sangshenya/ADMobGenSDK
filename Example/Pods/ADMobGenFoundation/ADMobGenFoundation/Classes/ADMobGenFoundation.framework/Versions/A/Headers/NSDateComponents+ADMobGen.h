//
//  NSDateComponents+ADMobGen.h
//  ADMobGenFoundation
//
//  Created by 陈坤 on 2020/1/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDateComponents (ADMobGen)

+ (NSDateComponents *)admg_dateComponentsFromDate:(NSDate *)date;

@end

NS_ASSUME_NONNULL_END
