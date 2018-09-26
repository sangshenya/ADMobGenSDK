//
//  ADMobGenAppDelegate.m
//  ADMobGenSDK
//
//  Created by 1594717129@qq.com on 07/19/2018.
//  Copyright (c) 2018 1594717129@qq.com. All rights reserved.
//

#import "ADMobGenAppDelegate.h"
#import <ADMobGenSDK/ADMobGenSDKConfig.h>
#import <ADMobGenSDK/ADMobGenSplashAd.h>
#import "ADMobGenViewController.h"

@interface ADMobGenAppDelegate ()<ADMobGenSplashAdDelegate>{
    ADMobGenSplashAd *_splashAd;
}
@end

@implementation ADMobGenAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    //默认为ADMobGenLogLevelNone
//    [ADMobGenSDKConfig setLogLevel:ADMobGenLogLevelDebug];
    [ADMobGenSDKConfig initWithAppId:@"2938412" completionBlock:^(NSError *error) {
        if (error) {
            // SDK启动失败
        }
    }];
    
    [ADMobGenSDKConfig setGpsOn];
    
    self.window = [[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];
    self.window.backgroundColor = [UIColor whiteColor];
    
    ADMobGenViewController *vc = [[ADMobGenViewController alloc]init];
    UINavigationController *nav = [[UINavigationController alloc]initWithRootViewController:vc];
    self.window.rootViewController = nav;
    
    [self.window makeKeyAndVisible];
    
    return YES;
}

- (void)loadSplash{
    // 1 初始化
    _splashAd = [[ADMobGenSplashAd alloc] init];
    
    // 2 设置默认启动图(一般设置启动图的平铺颜色为背景颜色，使得视觉效果更加平滑)
    _splashAd.backgroundColor = [UIColor yellowColor];
//    UIImage *backgroundImage = [self imageResize:[UIImage imageNamed:@"750×1334"] andResizeTo:[UIScreen mainScreen].bounds.size];
//    _splashAd.backgroundColor = [UIColor colorWithPatternImage:backgroundImage];
    
    _splashAd.delegate = self;
    
    // 3 设置底部logo视图, 高度不能超过屏幕的25%, 除iPhoneX以外建议: 开屏的广告图片默认640 / 960比例，如果是iPhoneX注意bottomViewHeight不能超过屏幕的25%
    CGFloat bottomViewHeight;
    if (kIPhoneX) {
        bottomViewHeight = [UIScreen mainScreen].bounds.size.height * 0.25;
    } else {
        bottomViewHeight = [UIScreen mainScreen].bounds.size.height - [UIScreen mainScreen].bounds.size.width * (960 / 640.0);
    }
    
    UIView *view = [[UIView alloc] init];
    view.backgroundColor = [UIColor purpleColor];
    view.frame = CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, bottomViewHeight);
    
    // 4 展示
    UIWindow *window = [UIApplication sharedApplication].delegate.window;
    [_splashAd loadAndShowInWindow:window withBottomView:nil];
}

- (UIImage *)imageResize:(UIImage*)img andResizeTo:(CGSize)newSize
{
    CGFloat scale = [[UIScreen mainScreen] scale];
    UIGraphicsBeginImageContextWithOptions(newSize, NO, scale);
    [img drawInRect:CGRectMake(0,0,newSize.width,newSize.height)];
    UIImage* newImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return newImage;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

#pragma mark - ADMobGenSplashAdDelegate
- (void)admg_splashAdSuccessToPresentScreen:(ADMobGenSplashAd *)splashAd{
    
}

- (void)admg_splashAd:(ADMobGenSplashAd *)splash failToPresentScreen:(NSError *)error{
    _splashAd = nil;
    if (error) {
        //NSLog(@"");ADMobGenLogLevelError自动打印错误信息，也可打印error查看
    }
}

- (void)admg_splashAdClosed:(ADMobGenSplashAd *)splashAd{
    _splashAd = nil;
}

@end
