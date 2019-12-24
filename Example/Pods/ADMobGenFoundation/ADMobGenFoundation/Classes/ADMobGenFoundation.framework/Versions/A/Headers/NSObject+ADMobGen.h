//
//  NSObject+ADMobGen.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/6/28.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (ADMobGen)

+ (BOOL)admg_swizzleInstanceMethod:(SEL)originalSel with:(SEL)newSel;

+ (BOOL)admg_swizzleClassMethod:(SEL)originalSel with:(SEL)newSel;

- (NSDictionary *)admg_toDic;

- (id)admg_PerformSelector:(SEL)action withObject:(id)object, ...NS_REQUIRES_NIL_TERMINATION;

- (NSData *)admg_serializationToJsonDataWithError:(NSError **)error;

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
