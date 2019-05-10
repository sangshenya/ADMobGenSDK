//
//  ADMobGenSplashAdViewController.m
//  ADMobGenSDK_Example
//
//  Created by 陈坤 on 2018/12/25.
//  Copyright © 2018 1594717129@qq.com. All rights reserved.
//

#import "ADMobGenSplashAdViewController.h"
#import <ADMobGenSDK/ADMobGenSplashAd.h>
#import <ADMobGenFoundation/ADMobGenSDKMacros.h>

@interface ADMobGenSplashAdViewController ()<ADMobGenSplashAdDelegate>{
    ADMobGenSplashAd *_splashAd;
}

@end

@implementation ADMobGenSplashAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    UIBarButtonItem *itemLeft = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemCancel target:self action:@selector(onCancelClicked:)];
    self.navigationItem.leftBarButtonItem = itemLeft;
    
    UIButton *btn = [UIButton new];
    btn.backgroundColor = [UIColor orangeColor];
    btn.layer.cornerRadius = 20;
    btn.frame = CGRectMake((kADMGScreenWidth -150)/2, kADMGTopBarHeight + 100, 150, 40);
    [btn setTitle:@"开屏" forState:UIControlStateNormal];
    [btn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [self.view addSubview:btn];
    [btn addTarget:self action:@selector(test) forControlEvents:UIControlEventTouchUpInside];
}

- (void)test {
    // 1 初始化
    _splashAd = [[ADMobGenSplashAd alloc] init];
    
    // 2 设置默认启动图
    _splashAd.backgroundColor = [UIColor redColor];
    _splashAd.delegate = self;
    
    // 3 设置底部logo视图, 高度不能超过屏幕的25%, 建议: 开屏的广告图片默认640 / 960比例（刘海屏是特例）
    CGFloat bottomViewHeight = [UIScreen mainScreen].bounds.size.height * 0.25;
    UIView *view = [[UIView alloc] init];
    view.backgroundColor = [UIColor purpleColor];
    view.frame = CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, bottomViewHeight);
    
    // 4 展示
    UIWindow *window = [UIApplication sharedApplication].delegate.window;
    [_splashAd loadAndShowInWindow:window withBottomView:view];
}

- (void)onCancelClicked:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}


#pragma mark - SplashAdDelegate
- (void)admg_splashAdSuccessToPresentScreen:(ADMobGenSplashAd *)splashAd{
    
}

- (void)admg_splashAd:(ADMobGenSplashAd *)splash failToPresentScreen:(NSError *)error{
    _splashAd = nil;
}

- (void)admg_splashAdClosed:(ADMobGenSplashAd *)splashAd{
    _splashAd = nil;
}

@end
