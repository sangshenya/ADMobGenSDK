//
//  ADMobNetworkClient.h
//  ADMobSDK_Code
//
//  Created by 曹飞 on 2018/6/20.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ADMobURLRequestSerialization.h"
#import "ADMobURLResponseSerialization.h"

@interface ADMobNetworkClient : NSObject

/// 基础URL, 调用GET,POST方法传入的URL会跟他以"relativeToURL:"拼接
@property (nonatomic, readonly, strong) NSURL *baseURL;
/// 请求任务队列
@property (nonatomic, readonly, strong) NSOperationQueue *operationQueue;

/// 请求转换器, 根据传入参数, 解析出正确的NSURLRequest
@property (nonatomic, strong) ADMobURLRequestSerialization *requestSerializer;
/// 响应转换器, 根据需求, 把response转成对应的responseObject
@property (nonatomic, strong) ADMobURLResponseSerialization *responseSerializer;

/**
 指定初始化方法, 申明为单例或者全局对象,否则会被释放

 @param baseURL 基础URL
 @return 网络请求对象
 */
- (instancetype)initWithBaseURL:(NSURL *)baseURL;

/**
 GET请求

 @param URLString 请求URL
 @param parameters 参数
 @param success 成功回调
 @param failure 失败回调
 */
- (void)GET:(NSString *)URLString
 parameters:(id)parameters
    success:(void (^)(NSURLSessionDataTask *task, id responseObject))success
    failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;

/**
 GET请求(可定制NSURLRequest)

 @param URLString 请求URL
 @param parameters 参数
 @param requestSerializer 请求转换器
 @param success 成功回调
 @param failure 失败回调
 */
- (void)GET:(NSString *)URLString
 parameters:(id)parameters
requestSerializer:(ADMobURLRequestSerialization *)requestSerializer
    success:(void (^)(NSURLSessionDataTask *task, id responseObject))success
    failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;

/**
 GET请求(可定制NSURLRequest,也可定制response解析)

 @param URLString 请求URL
 @param parameters 参数
 @param requestSerializer 请求转换器
 @param responseSerializer 响应转换器
 @param success 成功回调
 @param failure 失败回调
 */
- (void)GET:(NSString *)URLString
 parameters:(id)parameters
requestSerializer:(ADMobURLRequestSerialization *)requestSerializer
responseSerializer:(ADMobURLResponseSerialization *)responseSerializer
    success:(void (^)(NSURLSessionDataTask *task, id responseObject))success
    failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;

/**
 POST请求
 
 @param URLString 请求URL
 @param parameters 参数
 @param success 成功回调
 @param failure 失败回调
 */
- (void)POST:(NSString *)URLString
  parameters:(id)parameters
     success:(void (^)(NSURLSessionDataTask *task, id responseObject))success
     failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;

/**
 POST请求(可定制NSURLRequest)
 
 @param URLString 请求URL
 @param parameters 参数
 @param requestSerializer 请求转换器
 @param success 成功回调
 @param failure 失败回调
 */
- (void)POST:(NSString *)URLString
  parameters:(id)parameters 
requestSerializer:(ADMobURLRequestSerialization *)requestSerializer
     success:(void (^)(NSURLSessionDataTask *task, id responseObject))success
     failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;

/**
 POST请求(可定制NSURLRequest,也可定制response解析)
 
 @param URLString 请求URL
 @param parameters 参数
 @param requestSerializer 请求转换器
 @param responseSerializer 响应转换器
 @param success 成功回调
 @param failure 失败回调
 */
- (void)POST:(NSString *)URLString
  parameters:(id)parameters
requestSerializer:(ADMobURLRequestSerialization *)requestSerializer
responseSerializer:(ADMobURLResponseSerialization *)responseSerializer
     success:(void (^)(NSURLSessionDataTask *task, id responseObject))success
     failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;

@end
