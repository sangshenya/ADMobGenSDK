//
//  ADMobNetworkClient+GenSingleton.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/6/26.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import "ADMobNetworkClient.h"

@interface ADMobNetworkClient (GenSingleton)

+ (instancetype)admg_sharedClient;

@end
