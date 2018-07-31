//
//  ADMobIFLYNativeAd.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/7/4.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * 点击上报: http://bj.imp.voiceads.cn/a/click? || http://rtb.voiceads.cn/click?
 * 展现上报: http://bj.imp.voiceads.cn/a/impress? || http://rtb.voiceads.cn/view?
 */

@class ADMobGenNativeConfig;

@interface ADMobIFLYNativeAd : NSObject

- (instancetype)initWithConfig:(ADMobGenNativeConfig *)config;

- (BOOL)loadAd:(NSNumber *)count;

@end
