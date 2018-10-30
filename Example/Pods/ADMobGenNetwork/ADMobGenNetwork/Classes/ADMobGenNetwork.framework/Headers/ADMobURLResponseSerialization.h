//
//  ADMobURLResponseSerialization.h
//  ADMobSDK_Code
//
//  Created by 曹飞 on 2018/6/20.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ADMobURLResponseSerializationType) {
    ADMobURLResponseSerializationHTTP = 0,
    ADMobURLResponseSerializationJSON,
    ADMobURLResponseSerializationXMLParse,
};

/// 取自"AFNetworking"的"AFURLResponseSerialization"

@interface ADMobURLResponseSerialization : NSObject

+ (instancetype)serializer;

///-----------------------------------------
/// @name Configuring Response Serialization
///-----------------------------------------

/**
 The acceptable HTTP status codes for responses. When non-`nil`, responses with status codes not contained by the set will result in an error during validation.
 
 See http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html
 */
@property (nonatomic, copy) NSIndexSet *acceptableStatusCodes;

/**
 The acceptable MIME types for responses. When non-`nil`, responses with a `Content-Type` with MIME types that do not intersect with the set will result in an error during validation.
 */
@property (nonatomic, copy) NSSet <NSString *> *acceptableContentTypes;

/**
 default is 'ADMobURLResponseSerializationJSON'
 */
@property (nonatomic, assign) ADMobURLResponseSerializationType serializationType;

/**
 Validates the specified response and data.
 
 In its base implementation, this method checks for an acceptable status code and content type. Subclasses may wish to add other domain-specific checks.
 
 @param response The response to be validated.
 @param data The data associated with the response.
 @param error The error that occurred while attempting to validate the response.
 
 @return `YES` if the response is valid, otherwise `NO`.
 */
- (BOOL)validateResponse:(NSHTTPURLResponse *)response
                    data:(NSData *)data
                   error:(NSError *__autoreleasing *)error;

#pragma mark -

- (id)responseObjectForResponse:(NSURLResponse *)response
                           data:(NSData *)data
                          error:(NSError *__autoreleasing *)error;

@end

FOUNDATION_EXPORT NSString * const ADMobURLResponseSerializationErrorDomain;
