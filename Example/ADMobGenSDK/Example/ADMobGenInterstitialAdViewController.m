//
//  ADMobGenInterstitialAdViewController.m
//  ADMobGenSDK_Example
//
//  Created by 陈坤 on 2019/12/24.
//  Copyright © 2019 1594717129@qq.com. All rights reserved.
//

#import "ADMobGenInterstitialAdViewController.h"
#import <ADMobGenSDK/ADMobGenInterstitialAd.h>

@interface ADMobGenInterstitialAdViewController ()<ADMobGenInterstitialAdDelegate>

@property (nonatomic, strong) ADMobGenInterstitialAd *interstitialAd;

@end

@implementation ADMobGenInterstitialAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)loadInterstitialAd{
    // 1、初始化 ADMobGenInterstitialAd，adSize为期望size，默认为CGSizeMake(300, 300)
    self.interstitialAd = [[ADMobGenInterstitialAd alloc]initWithViewController:self index:0 adSize:CGSizeMake(300, 300) aspectRatio:ADMobGenInterstitialAdAspectRatioDefault];
    // 2、加载 ADMobGenInterstitialAd 广告
    [self.interstitialAd load];
}

- (void)showInterstitialAd{
    // 3、展示 ADMobGenInterstitialAd 广告
    [self.interstitialAd show];
}

#pragma mark - ADMobGenInterstitialAdDelegate
/**
 ADMobGenInterstitialAd请求成功回调
 
 @param interstitialAd 插屏广告实例对象
*/
- (void)admg_interstitialSuccedToLoad:(ADMobGenInterstitialAd *)interstitialAd{
    // 推荐在该回调之后展示插屏广告
    dispatch_async(dispatch_get_main_queue(), ^{
        [self showInterstitialAd];
    });
}

/**
 ADMobGenInterstitialAd请求失败回调

 @param interstitialAd 插屏广告实例对象
 @param error 失败原因
*/
- (void)admg_interstitialFailedToLoad:(ADMobGenInterstitialAd *)interstitialAd error:(NSError *_Nullable)error{
    
}

/**
 ADMobGenInterstitialAd展示在屏幕内回调

 @param interstitialAd 插屏广告实例对象
*/
- (void)admg_interstitialDidPresent:(ADMobGenInterstitialAd *)interstitialAd{
    
}

/**
 ADMobGenInterstitialAd点击回调

 @param interstitialAd 插屏广告实例对象
*/
- (void)admg_interstitialDidClick:(ADMobGenInterstitialAd *)interstitialAd{
    
}

/**
 ADMobGenInterstitialAd关闭回调

 @param interstitialAd 插屏广告实例对象
*/
- (void)admg_interstitialDidClose:(ADMobGenInterstitialAd *)interstitialAd{
    
}

/**
 广告展示
 
 @param interstitialAd 广告实例
 */
- (void)admg_interstitialExposure:(ADMobGenInterstitialAd *)interstitialAd{
    
}

@end
