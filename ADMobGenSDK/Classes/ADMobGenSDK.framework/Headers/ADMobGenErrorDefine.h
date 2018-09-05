//
//  ADMobGenErrorDefine.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/6/27.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#ifndef ADMobGenErrorDefine_h
#define ADMobGenErrorDefine_h

typedef enum : NSInteger {
    ADMG_SDK_INIT_FAIL = 1001, // SDK初始化失败
    ADMG_SDK_APPID_NIL = 1002, //appId为空
    ADMG_SDK_PACKAGE_ERROR = 1003,//包名和appId不对应
    ADMG_SDK_CONFIG_EMPTY = 1004,//请求配置为空
} ADMobGenErrorCode;

static NSError * ADMobGenError(NSErrorDomain domain, NSInteger code, NSString *localizedDescription) {
    NSDictionary *userInfo = nil;
    if (localizedDescription && localizedDescription.length > 0) {
        userInfo = @{NSLocalizedDescriptionKey : localizedDescription};
    }
    return [[NSError alloc] initWithDomain:domain code:code userInfo:userInfo];
}

#endif /* ADMobGenErrorDefine_h */
