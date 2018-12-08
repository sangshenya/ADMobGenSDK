//
//  ADMobGenSDKMacros.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/6/28.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#ifndef ADMobGenSDKMacros_h
#define ADMobGenSDKMacros_h

#import <UIKit/UIKit.h>

#define kADMobGenFoundationSDKVersion @"0.4.0"

// 字符串是否为空
#define kADMGStringIsEmpty(str) ([str isKindOfClass:[NSNull class]] || str == nil || ![str isKindOfClass:[NSString class]] || [str length] < 1 ? YES : NO)
// 数组是否为空
#define kADMGArrayIsEmpty(array) (array == nil || [array isKindOfClass:[NSNull class]] || ![array isKindOfClass:[NSArray class]] || array.count == 0)
// 字典是否为空
#define kADMGDictIsEmpty(dict) (dict == nil || [dict isKindOfClass:[NSNull class]] || ![dict isKindOfClass:[NSDictionary class]] || dict.allKeys.count == 0)
// 对象是否为空
#define kADMGObjectIsEmpty(_object) (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))

#ifdef DEBUG
#define NSLog(...) NSLog(__VA_ARGS__)
#else
#define NSLog(...)
#endif

static inline CGSize ADMobGenScreenSize(void) {
    static CGSize size;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        size = [UIScreen mainScreen].bounds.size;
        if (size.height < size.width) {
            CGFloat tmp = size.height;
            size.height = size.width;
            size.width = tmp;
        }
    });
    return size;
}

static inline CGFloat ADMobGenScreenScale(void) {
    static CGFloat scale;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        scale = [UIScreen mainScreen].scale;
    });
    return scale;
}


// main screen's scale (portrait)
#ifndef kADMGScreenScale
#define kADMGScreenScale ADMobGenScreenScale();
#endif

// main screen's size (portrait)
#ifndef kADMGScreenSize
#define kADMGScreenSize ADMobGenScreenSize();
#endif

// main screen's width (portrait)
#ifndef kADMGScreenWidth
#define kADMGScreenWidth ADMobGenScreenSize().width
#endif

// main screen's height (portrait)
#ifndef kADMGScreenHeight
#define kADMGScreenHeight ADMobGenScreenSize().height
#endif

//机型适配
#define kADMGIPhoneX (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone && kADMGScreenWidth == 375.0 && kADMGScreenHeight == 812.0)
#define kADMGIPhoneXS (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone && kADMGScreenWidth == 375.0 && kADMGScreenHeight == 812.0)
#define kADMGIphoneXR (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone && kADMGScreenWidth == 375.0 && kADMGScreenHeight == 812.0 && ADMobGenScreenScale() == 2)

#define kADMGIphoneXS_MAX (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone && kADMGScreenWidth == 414.0 && kADMGScreenHeight == 896.0 && ADMobGenScreenScale() == 3)

#define kADMGCurveScreen (kADMGIPhoneX || kADMGIPhoneXS || kADMGIphoneXR || kADMGIphoneXS_MAX) // 刘海屏幕

#define kADMGStatusBarHeight (kADMGCurveScreen ? 44 : 20)
#define kADMGNavBarHeight 44
#define kADMGTopBarHeight (kADMGStatusBarHeight + kADMGNavBarHeight)
#define kADMGTabBarHeight (kADMGCurveScreen ? 83 : 49)

#endif /* ADMobGenSDKMacros_h */
