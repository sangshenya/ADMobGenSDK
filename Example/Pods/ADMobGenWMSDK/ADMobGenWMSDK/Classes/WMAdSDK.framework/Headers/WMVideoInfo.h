//
//  WMVideoInfo.h
//  WMAdSDK
//
//  Created by gdp on 2017/12/10.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface WMVideoInfo : NSObject<NSCoding>

// 视频占位图高度
@property (nonatomic, assign) NSInteger coverHeight;

// 视频占位图宽度
@property (nonatomic, assign) NSInteger coverWidth;

// 视频占位图链接
@property (nonatomic, copy) NSString *coverUrl;

// 视频解析度
@property (nonatomic, copy) NSString *resolution;

// 视频文件大小
@property (nonatomic, assign) NSInteger size;

// 视频时长
@property (nonatomic, assign) NSInteger videoDuration;

// 视频地址
@property (nonatomic, copy) NSString *videoUrl;

// 记录已播放时间，用于续播
@property (nonatomic, assign) CGFloat playedSeconds;

// endcard 落地页地址
@property (nonatomic, copy) NSString *endcard;

- (instancetype)initWithDictionary:(NSDictionary *)dict error:(NSError * __autoreleasing *)error;

@end
