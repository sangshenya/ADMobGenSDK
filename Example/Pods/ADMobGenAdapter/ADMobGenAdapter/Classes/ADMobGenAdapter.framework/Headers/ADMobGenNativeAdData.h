//
//  ADMobGenNativeAdData.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/7/3.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface ADMobGenNativeAdData : NSObject

// 详细消息,用web渲染
/**
 *　图片资源,0.7.0及以后版本不推荐使用,适配图片资源类型的不同
 */
@property (nonatomic, copy) NSString *mainImgUrl DEPRECATED_MSG_ATTRIBUTE("use mainImage instead");
/**
 *　图片资源,0.7.0及以后新增
 */
@property (nonatomic, strong) id mainImage;//web图片资源

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *describe;

@end
