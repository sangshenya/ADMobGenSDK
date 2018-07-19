//
//  ADMobURLRequestSerialization.h
//  ADMobSDK_Code
//
//  Created by 曹飞 on 2018/6/20.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 取自"AFNetworking"的"AFURLRequestSerialization"

@interface ADMobURLRequestSerialization : NSObject

+ (instancetype)serializer;

/**
 Whether created requests can use the device’s cellular radio (if present). `YES` by default.
 
 @see NSMutableURLRequest -setAllowsCellularAccess:
 */
@property (nonatomic, assign) BOOL allowsCellularAccess;

/**
 The cache policy of created requests. `NSURLRequestUseProtocolCachePolicy` by default.
 
 @see NSMutableURLRequest -setCachePolicy:
 */
@property (nonatomic, assign) NSURLRequestCachePolicy cachePolicy;

/**
 Whether created requests should use the default cookie handling. `YES` by default.
 
 @see NSMutableURLRequest -setHTTPShouldHandleCookies:
 */
@property (nonatomic, assign) BOOL HTTPShouldHandleCookies;

/**
 Whether created requests can continue transmitting data before receiving a response from an earlier transmission. `NO` by default
 
 @see NSMutableURLRequest -setHTTPShouldUsePipelining:
 */
@property (nonatomic, assign) BOOL HTTPShouldUsePipelining;

/**
 The network service type for created requests. `NSURLNetworkServiceTypeDefault` by default.
 
 @see NSMutableURLRequest -setNetworkServiceType:
 */
@property (nonatomic, assign) NSURLRequestNetworkServiceType networkServiceType;

/**
 The timeout interval, in seconds, for created requests. The default timeout interval is 60 seconds.
 
 @see NSMutableURLRequest -setTimeoutInterval:
 */
@property (nonatomic, assign) NSTimeInterval timeoutInterval;

///---------------------------------------
/// @name Configuring HTTP Request Headers
///---------------------------------------

@property (nonatomic, readonly, strong) NSDictionary<NSString *, NSString *> *HTTPRequestHeaders;

- (void)setValue:(NSString *)value forHTTPHeaderField:(NSString *)field;

///-------------------------------
/// @name Creating Request Objects
///-------------------------------

- (NSMutableURLRequest *)requestWithMethod:(NSString *)method
                                 URLString:(NSString *)URLString
                                parameters:(id)parameters
                                     error:(NSError *__autoreleasing *)error;

@end

NS_ASSUME_NONNULL_END
