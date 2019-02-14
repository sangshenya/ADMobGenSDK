//
//  ADMobNetworkErrorDefine.h
//  ADMobSDK_Code
//
//  Created by 曹飞 on 2018/6/26.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#ifndef ADMobNetworkErrorDefine_h
#define ADMobNetworkErrorDefine_h

#define kADMobGenNetworkSDKVersion @"0.3.4"

typedef enum : NSInteger {
    ADM_NETWORK_REQUEST_SERIALIZETION_ERROR = 1001, // 请求对象解析失败
    ADM_NETWORK_REQUEST_OPERATION_CANCELED = 1002, // 请求被取消
    ADM_NETWORK_RESPONSE_SERIALIZETION_ERROR = 1003, // 响应解析失败
} ADMobNetworkErrorCode;


static NSError * ADMobNetworkError(NSErrorDomain domain, NSInteger code, NSString *localizedDescription) {
    NSDictionary *userInfo = nil;
    if (localizedDescription && localizedDescription.length > 0) {
        userInfo = @{NSLocalizedDescriptionKey : localizedDescription};
    }
    return [[NSError alloc] initWithDomain:domain code:code userInfo:userInfo];
}


#endif /* ADMobNetworkErrorDefine_h */
