//
//  WKWebView+ADMobGen.m
//  ADMobGenSDK_Example
//
//  Created by 陈坤 on 2019/8/12.
//  Copyright © 2019 1594717129@qq.com. All rights reserved.
//

#import "WKWebView+ADMobGen.h"
#import <objc/runtime.h>

@implementation WKWebView (ADMobGen)

+ (void)load {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        Class class = [self class];
        // @selector(viewWillDisappear:)
        SEL originalSels[] = {@selector(layoutSubviews)};
        for (int i = 0; i < sizeof(originalSels) / sizeof(SEL); i ++) {
            SEL originalSelector1 = originalSels[i];
            SEL swizzledSelector1 = NSSelectorFromString([@"admg_" stringByAppendingString:NSStringFromSelector(originalSelector1)]);
            
            Method originalMethod1 = class_getInstanceMethod(class, originalSelector1);
            Method swizzledMethod1 = class_getInstanceMethod(class, swizzledSelector1);
            
            BOOL didAddMethod =
            class_addMethod(class,
                            originalSelector1,
                            method_getImplementation(swizzledMethod1),
                            method_getTypeEncoding(swizzledMethod1));
            
            if (didAddMethod) {
                class_replaceMethod(class,
                                    swizzledSelector1,
                                    method_getImplementation(originalMethod1),
                                    method_getTypeEncoding(originalMethod1));
                
            } else {
                method_exchangeImplementations(originalMethod1, swizzledMethod1);
            }
        }
    });
}

- (void)admg_layoutSubviews{
    [self admg_layoutSubviews];
    if (@available(iOS 11.0, *)) {
        self.scrollView.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
    } else {
        // Fallback on earlier versions
    }
}

@end
