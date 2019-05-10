//
//  ADMobGenBannerViewController.m
//  ADMobGenSDK_Example
//
//  Created by 陈坤 on 2018/12/25.
//  Copyright © 2018 1594717129@qq.com. All rights reserved.
//

#import "ADMobGenBannerViewController.h"
#import <ADMobGenSDK/ADMobGenBannerView.h>
#import <ADMobGenFoundation/ADMobGenSDKMacros.h>

@interface ADMobGenBannerViewController ()<ADMobGenBannerViewDelegate>{
    
    ADMobGenBannerView *_bannerView;
}

@end

@implementation ADMobGenBannerViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    UIBarButtonItem *itemLeft = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemCancel target:self action:@selector(onCancelClicked:)];
    self.navigationItem.leftBarButtonItem = itemLeft;
    
    UIButton *btn2 = [UIButton new];
    btn2.backgroundColor = [UIColor orangeColor];
    btn2.layer.cornerRadius = 20;
    btn2.frame = CGRectMake((kADMGScreenWidth -150)/2, kADMGTopBarHeight + 100, 150, 40);
    [btn2 setTitle:@"banner" forState:UIControlStateNormal];
    [btn2 setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [self.view addSubview:btn2];
    [btn2 addTarget:self action:@selector(test2) forControlEvents:UIControlEventTouchUpInside];
}

- (void)onCancelClicked:(id)sender {
    [self.navigationController dismissViewControllerAnimated:YES completion:nil];
}

#pragma mark - Banner

- (void)test2 {
    if (_bannerView) {
        [_bannerView removeFromSuperview];
        _bannerView = nil;
    }
    
    // 1 初始化banner视图
    _bannerView = [[ADMobGenBannerView alloc] initWithFrame:CGRectZero withBannerSize:ADMobGenBannerAdSize600_150 withBannerIndex:0];
    _bannerView.delegate = self;
    _bannerView.backgroundColor = [UIColor redColor];
    
    // 2 添加到父视图上
    CGFloat height = [UIScreen mainScreen].bounds.size.width/4;
    CGFloat width = [UIScreen mainScreen].bounds.size.width;
    _bannerView.frame = CGRectMake(0, [UIScreen mainScreen].bounds.size.height  - height, width, height);
    [self.view addSubview:_bannerView];
    
    // 3 隐藏关闭按钮，默认显示关闭按钮
    [_bannerView closeButtonHidden:YES];
    
    // 4 加载并显示广告 注意: 请确保banner视图显示在屏幕内的时候,调用load方法
    //    [_bannerView loadWithError:nil];
    [_bannerView loadWithError:nil];
}

#pragma mark - ADMobGenBannerViewDelegate

/**
 广告获取成功
 
 @param bannerView banner实例
 */
- (void)admg_bannerViewDidReceived:(ADMobGenBannerView *)bannerView{
    
}

/**
 广告拉取失败
 
 @param bannerView banner实例
 @param error 错误描述
 */
- (void)admg_bannerViewFailToReceived:(ADMobGenBannerView *)bannerView error:(NSError *)error{
    
}

/**
 广告点击
 
 @param bannerView 广告实例
 */
- (void)admg_bannerViewClicked:(ADMobGenBannerView *)bannerView{
    
}

/**
 广告关闭
 
 @param bannerView 广告实例
 */
- (void)admg_bannerViewClose:(ADMobGenBannerView *)bannerView{
    
}


@end
