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
#import <ADMobGenFoundation/UIColor+ADMobGen.h>
#import <GDTMobSDK/GDTSDKConfig.h>
#import <ADMobileAdSDK/ADMobileAdSDK.h>
#import <ADMobGenAdapter/ADMobGenNativeTool.h>
#import <BUAdSDK/BUAdSDKManager.h>

@interface ADMobGenAppDelegate ()<ADMobGenSplashAdDelegate>{
    ADMobGenSplashAd *_splashAd;
}
@end

@implementation ADMobGenAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    //测试Debug包需要，一般情况下不开启,需要时会另行通知
    //[ADMobGenSDKConfig setDebugMode:@(YES)];
    //日志等级输出
    
    [ADMobGenSDKConfig setLogLevel:ADMobGenLogLevelError];
    [ADMobGenSDKConfig initWithAppId:@"2938412" completionBlock:^(NSError *error) {
        if (error) {
            // SDK启动失败
            NSLog(@"SDK启动失败:%@",error.localizedDescription);
        }
    }];
   
    // 调整信息流模板广告样式
    [ADMobGenNativeTool setHtmlString:@"<style>    @charset \"utf-8\";    body,    div,    html,    img {        padding: 0;        margin: 0    }    .clearfix:after,    .clearfix:before {        content: \".\";        display: block;        height: 0;        font-size: 0;        visibility: hidden;    }    .clearfix:after {        clear: both    }    .clearfix {        zoom: 1    }    .gdtmo {        background: #fff;        padding: 8px 9px;    }    .mo_tb {        font-size: 14px;        line-height: 1.5;        box-sizing: border-box;        font-family: Roboto-Regular, Arial, sans-serif;        display: -webkit-box;    }    .mo_tb * {        box-sizing: border-box    }    .image {        position: relative;        display: block;        width: 128;    }    .image .logo {        position: absolute; width: 25px;      height: 18px;        background-size: auto 18px;background-repeat:no-repeat;background-position:right;        bottom: 0;        right: 0;        background-image: url(%@)    }    .vda { line-height:18px;       color: #AAA;        padding-right: 30px;        white-space: nowrap;        overflow: hidden;        text-overflow: ellipsis;        font-size: 12px;        margin: 0 10px 0px 0px;        position: absolute;        left: 0;        bottom: 0;        box-size: border-box;        width: 100%%;    }    .vda .icon-ad {        font-size: 10px;        float: left;        color: #AAA;        background: rgb(170,170,170,0.08);        border-radius: 2px;        padding: 0 4px;        margin-right: 4px; border: solid 1px rgb(151,151,151,0.24); line-height: 16px;}    .description {        color: #333;        overflow: hidden;        text-overflow: ellipsis;        display: -webkit-box;        -webkit-line-clamp: 2;        -webkit-box-orient: vertical;        word-break: break-all;        font-size: 14px;    }    .t .description {        margin: 0 10px 0px 0px    }    .b .description {        margin: 0px 10px 0px    }    img {        display: block;        width: 100%%    }    .gdtmo img {        background: #ccc url(%@) no-repeat center;        background-size: 100%% 100%%;    }    .content {        -webkit-box-flex: 1;        position: relative;        padding-left: 8px;    }    .box {        position: absolute;        height: 100%%;        width: 100%%;    }</style><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\"><div class=\"gdtmo mo_tb t clearfix\" id=\"tpbt\" onclick=\"contentClicked()\">    <div class=\"image\"><img            src=\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAMAAAACAQMAAACnuvRZAAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAK7OHOkAAAADUExURUxpcU3H2DoAAAABdFJOUwBA5thmAAAADElEQVQI12NgYGAAAAAEAAEnNCcKAAAAAElFTkSuQmCC\"            alt=\"\"/>        <div class=\"logo\"></div>    </div>    <div class=\"content\">        <div class=\"box\">            <div class=\"description\">%@</div>            <div class=\"vda\"><span class=\"icon-ad\">广告</span><span class=\"title\">%@</span></div>        </div>    </div></div><script>function contentClicked() {    window.webkit.messageHandlers.onClick.postMessage({});}</script>" adType:ADMobGenNativeAdTypeLeftPic];
    
    /*
     一定要导入ADMob平台，否则会导致崩溃
     */
    
    //打开GPS定位
    [ADMobGenSDKConfig setGpsOn];
    
    //获取SDK版本号
    NSString *sdkVersion = [ADMobGenSDKConfig getSDKVersion];
    NSLog(@"ADMobGenSDKVersion:%@",sdkVersion);
    
    SEL select = NSSelectorFromString(@"getAllSDKVersion");
    if ([ADMobGenSDKConfig respondsToSelector:select]) {
    NSDictionary *dict = [ADMobGenSDKConfig performSelector:select];
    NSLog(@"ADMobGenSDKConfig:%@",dict);
    }
    
    // [ADMobileAdSDK sharedInstance].barItemTintColor = [UIColor blackColor];
    // [ADMobileAdSDK sharedInstance].barTintColor = [UIColor whiteColor];
    
    // 状态栏为白色
    // [UIApplication sharedApplication].statusBarStyle =  UIStatusBarStyleLightContent;
    
    // 状态栏为黑色
    // [UIApplication sharedApplication].statusBarStyle =  UIStatusBarStyleDefault;
    
    
    self.window = [[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];
    self.window.backgroundColor = [UIColor whiteColor];
    
    ADMobGenViewController *vc = [[ADMobGenViewController alloc]init];
    UINavigationController *nav = [[UINavigationController alloc]initWithRootViewController:vc];
    self.window.rootViewController = nav;
    
    [self.window makeKeyAndVisible];
    //当你在rootViewController中有去模态弹出其他的控制器的话，可能会出现广告加载不出的情况（广点通广告无法加载）
    [self loadSplash];
    
    
    
    return YES;
}

- (void)loadSplash{
    //注意：当你在控制器中加载开屏时，请勿在viewWillAppear中加载开屏，该方法会调用多次，使得展示多次开屏广告，在viewDidLoad中加载开屏广告的时候，如果该控制器没有用导航栏承载，会出现无法展示广告，却走了加载成功的回调方法
    // 1 初始化
    _splashAd = [[ADMobGenSplashAd alloc] init];
    
    // 2 设置默认启动图(一般设置启动图的平铺颜色为背景颜色，使得视觉效果更加平滑)
    UIImage *image = [UIImage imageNamed:@"750x1334.png"];
    NSLog(@"hhhhhhh%@",image);
    UIColor *color = [UIColor admg_getColorWithImage:image withNewSize:[UIScreen mainScreen].bounds.size];
    _splashAd.backgroundColor = color;
    
    _splashAd.delegate = self;
    
    // 3 设置底部logo视图, 高度不能超过屏幕的25%, 除刘海屏以外建议: 开屏的广告图片默认640 / 960比例，如果是刘海屏注意bottomViewHeight不能超过屏幕的25%
    CGFloat bottomViewHeight;
    if (kIPhoneX) {
        bottomViewHeight = [UIScreen mainScreen].bounds.size.height * 0.25;
    } else {
        bottomViewHeight = [UIScreen mainScreen].bounds.size.height - ([UIScreen mainScreen].bounds.size.width * 960 / 640.0);
    }
//
    NSLog(@"%f",bottomViewHeight);
//    bottomViewHeight = 105;
    
    UIView *bottomView = [[UIView alloc] init];
    bottomView.backgroundColor = [UIColor whiteColor];
    bottomView.frame = CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, bottomViewHeight);
    UIImageView *logoImageView = [[UIImageView alloc]initWithImage:[UIImage imageNamed:@"ADMob_Logo.png"]];
    logoImageView.frame = CGRectMake(([UIScreen mainScreen].bounds.size.width-135)/2, (bottomViewHeight-46)/2, 135, 46);
    [bottomView addSubview:logoImageView];
    
    // 4 展示
    UIWindow *window = [UIApplication sharedApplication].delegate.window;
    [_splashAd loadAndShowInWindow:window withBottomView:bottomView];
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
//千万不要在点击回调中将开屏广告对象置空，否则广点通下载类落地页无法关闭，头条广告会停留在屏幕上无法关闭
- (void)admg_splashAdClicked:(ADMobGenSplashAd *)splashAd{
    
//    _splashAd = nil;
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
