//
//  WMAppInfo.h
//  WMAdSDK
//
//  Created by chenren on 10/05/2017.
//  Copyright © 2017 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WMActionServiceDefine.h"


@interface WMAppInfo : NSObject <WMActionAppModel, NSCoding>

// 应用名称
@property (nonatomic, copy) NSString *appName;

@property (nonatomic, copy) NSString *appid;

// 应用下载URL，应用下载必须
@property (nonatomic, copy) NSString *downloadURL;

// 应用app的评分，默认为0
@property (nonatomic, assign) NSInteger appScore;

// 下载量或使用人数
@property (nonatomic, assign) NSInteger userNumber;

/// 广告星级
@property (nonatomic, assign) int score;

///评分人数
@property (nonatomic, assign) int commentNum;

- (instancetype)initWithDictionary:(NSDictionary *)dict error:(NSError * __autoreleasing *)error;

@end

