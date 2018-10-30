//
//  ADMobGenBannerShowAd.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/7/6.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ADMobGenBannerShowAd : NSObject

+ (instancetype)sharedInstance;

- (void)startWithDangerSdkName:(NSString *)sdkName;

@end
