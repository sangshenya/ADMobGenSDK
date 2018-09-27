//
//  ADMobGenViewController.m
//  ADMobGenSDK
//
//  Created by 1594717129@qq.com on 07/19/2018.
//  Copyright (c) 2018 1594717129@qq.com. All rights reserved.
//

#import "ADMobGenViewController.h"
#import <ADMobGenSDK/ADMobGenSplashAd.h>
#import <ADMobGenSDK/ADMobGenBannerView.h>
#import "ADMobGenExpressViewController.h"

//// 机型UI适配宏
//#define kIPhoneX (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone && ([UIScreen mainScreen].bounds.size.width == 375.0 && [UIScreen mainScreen].bounds.size.height == 812.0))

@interface ADMobGenViewController () <ADMobGenBannerViewDelegate,ADMobGenSplashAdDelegate> {
    ADMobGenSplashAd *_splashAd;
    ADMobGenBannerView *_bannerView;
}

@end

@implementation ADMobGenViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    UIButton *btn = [UIButton new];
    btn.backgroundColor = [UIColor redColor];
    btn.frame = CGRectMake(0, 64, 100, 100);
    [btn setTitle:@"开屏" forState:UIControlStateNormal];
    [btn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [self.view addSubview:btn];
    [btn addTarget:self action:@selector(test) forControlEvents:UIControlEventTouchUpInside];
    
    UIButton *btn2 = [UIButton new];
    btn2.backgroundColor = [UIColor redColor];
    btn2.frame = CGRectMake(0, 120+64, 100, 100);
    [btn2 setTitle:@"banner" forState:UIControlStateNormal];
    [btn2 setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [self.view addSubview:btn2];
    [btn2 addTarget:self action:@selector(test2) forControlEvents:UIControlEventTouchUpInside];
    
    UIButton *btn3 = [UIButton new];
    btn3.backgroundColor = [UIColor redColor];
    btn3.frame = CGRectMake(0, 240+64, 100, 100);
    [btn3 setTitle:@"原生模板" forState:UIControlStateNormal];
    [btn3 setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [self.view  addSubview:btn3];
    [btn3 addTarget:self action:@selector(test3) forControlEvents:UIControlEventTouchUpInside];
    
    [self test3];
}


- (void)test {
    // 1 初始化
    _splashAd = [[ADMobGenSplashAd alloc] init];
    
    // 2 设置默认启动图(一般设置启动图的平铺颜色为背景颜色，使得视觉效果更加平滑)
    _splashAd.backgroundColor = [UIColor yellowColor];
    
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
    [_splashAd loadAndShowInWindow:window withBottomView:view];
}

#pragma mark - Banner

- (void)test2 {
    if (_bannerView) {
        [_bannerView removeFromSuperview];
        _bannerView = nil;
    }
    
    // 1 初始化banner视图
    _bannerView = [[ADMobGenBannerView alloc] init];
    _bannerView.delegate = self;
    _bannerView.backgroundColor = [UIColor redColor];
    
    // 2 添加到父视图上
    CGFloat height = [UIScreen mainScreen].bounds.size.width * (5 / 32.0);
    CGFloat width = [UIScreen mainScreen].bounds.size.width;
    _bannerView.frame = CGRectMake(0, [UIScreen mainScreen].bounds.size.height  - height, width, height);
    [self.view addSubview:_bannerView];
    
    // 3 加载并显示广告 注意: 请确保banner视图显示在屏幕内的时候,调用load方法
    [_bannerView loadWithError:nil];
}

- (void)test3 {
    ADMobGenExpressViewController *vc = [ADMobGenExpressViewController new];
    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];;
    [self presentViewController:nav animated:YES completion:nil];
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

#pragma mark - ADMobGenBannerViewDelegate
- (void)admg_bannerViewDidReceived:(ADMobGenBannerView *)bannerView{
    NSLog(@"load banner success");
}

- (void)admg_bannerViewFailToReceived:(ADMobGenBannerView *)bannerView error:(NSError *)error{
    if (error) {
        //请求失败时，将banner视图的高度置为0，就不会出现空白区域
        CGRect rect = _bannerView.frame;
        _bannerView.frame = CGRectMake(rect.origin.x, rect.origin.y, rect.size.width, 0);
    }
}


@end
