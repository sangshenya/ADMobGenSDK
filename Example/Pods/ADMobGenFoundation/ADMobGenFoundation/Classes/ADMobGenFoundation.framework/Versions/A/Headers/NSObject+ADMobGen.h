//
//  NSObject+ADMobGen.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/6/28.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (ADMobGen)

- (NSDictionary *)admg_toDic;

@end


@interface NSArray (ADMobGen)

- (id)admg_objectOrNilAtIndex:(NSUInteger)index;

@end


@interface NSDictionary (ADMobGen)

- (id)admg_objectOrNilForKey:(id)key;

@end


@interface NSMutableDictionary (ADMobGen)

- (void)admg_setValidValue:(id)value forKey:(id<NSCopying>)key;

@end
