//
//  MCAdSDK.h
//  MCAdSDK
//
//  Created by 曹飞 on 2017/7/31.
//  Copyright © 2017年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MCAdNative.h"

NS_ASSUME_NONNULL_BEGIN

@interface MCAdSDK : NSObject

@property (nonatomic, copy, readonly) NSString *appId;
@property (nonatomic, copy, readonly) NSString *token;

/**
 Returns the shared MCAdSDK instance
 
 @return the instance of MCAdSDK
 */
+ (instancetype)sharedInstance;

/**
 Initialize the sdk. This must be called before any other API for the SDK used.
 
 @param appId the appid
 @param token the token
 */
+ (void)initSdkWithAppId:(nonnull NSString *)appId token:(nonnull NSString *)token DEPRECATED_MSG_ATTRIBUTE("Donot has turn");

/**
 Initialize the sdk. This must be called before any other API for the SDK used.
 
 @param appId the appid
 @param token the token
 @param turn request back or not
 */
+ (void)initSdkWithAppId:(nonnull NSString *)appId token:(nonnull NSString *)token withTurn:(BOOL)turn;

/**
 Get the SDK version
 */
+ (NSString *)getSDKVersion;

@end


@interface MCAdSDK (UI)

/// To tint the bar's subItems color
@property (nonatomic, strong) UIColor *barItemTintColor;
/// To tint the bar's background
@property (nonatomic, strong) UIColor *barTintColor;
/// the bar's right or left items font
@property (nonatomic, strong) UIFont *barItemFont;
/// the bar's Title font
@property (nonatomic, strong) UIFont *barTitleFont;

@end


@interface MCAdSDK (DeviceSetting)

/**
 Open the location permissions, We will use it for advertising necessary parameters
 */
+ (void)requestCoreLocationServer;

@end

NS_ASSUME_NONNULL_END
