//
//  ADMobGenNativeExpressShowAd.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/7/5.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ADMobGenNativeExpressShowAd : NSObject

+ (instancetype)sharedInstance;

- (void)startWithDangerSdkName:(NSString *)sdkName;

@end
