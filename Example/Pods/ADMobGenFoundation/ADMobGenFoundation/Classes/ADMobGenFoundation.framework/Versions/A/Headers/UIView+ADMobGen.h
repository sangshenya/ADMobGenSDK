//
//  UIView+ADMobGen.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/7/5.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (ADMobGen)

/**
 Returns the view's view controller (may be nil).
 */
@property (nullable, nonatomic, readonly) UIViewController *admg_viewController;

@property (nonatomic, readonly, assign) BOOL admg_inScreen;

@end
