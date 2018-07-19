//
//  UIApplication+ADMobGen.h
//  ADMobGenSDK_Code
//
//  Created by 曹飞 on 2018/6/28.
//  Copyright © 2018年 曹飞. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIApplication (ADMobGen)

/// app是否是盗版(不是从app store下载的)
@property (nonatomic, readonly) BOOL admg_isPirated;

/// app是否正在被调试
@property (nonatomic, readonly) BOOL admg_isBeingDebugged;

/// 应用版本
@property (nonatomic, readonly) NSString *admg_appVersion;

/// 包名
@property (nonatomic, readonly) NSString *admg_appBundleId;

/// "Documents"在沙盒中文件夹路径
@property (nonatomic, readonly) NSURL *admg_documentsURL;
@property (nonatomic, readonly) NSString *admg_documentsPath;

/// "Caches"在沙盒中文件夹路径
@property (nonatomic, readonly) NSURL *admg_cachesURL;
@property (nonatomic, readonly) NSString *admg_cachesPath;

/// "Library"在沙盒中文件夹路径
@property (nonatomic, readonly) NSURL *admg_libraryURL;
@property (nonatomic, readonly) NSString *admg_libraryPath;

/// 应用当前展示的控制器
@property (nonatomic, readonly, strong) UIViewController *admg_viewController;

@end
