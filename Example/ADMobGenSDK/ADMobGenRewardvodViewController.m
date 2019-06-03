//
//  ADMobGenRewardvodViewController.m
//  ADMobGenSDK_Example
//
//  Created by 陈坤 on 2018/12/25.
//  Copyright © 2018 1594717129@qq.com. All rights reserved.
//

#import "ADMobGenRewardvodViewController.h"
#import <ADMobGenSDK/ADMobGenRewardvodAd.h>
//#import "ADMobGenRewardvodAd.h"
#import <ADMobGenFoundation/ADMobGenSDKMacros.h>

@interface ADMobGenRewardvodViewController ()<ADMobGenRewardvodAdDelegate>{
    ADMobGenRewardvodAd *_rewardvodAd;
    UIButton *_rewardvodButton;
}

@end

@implementation ADMobGenRewardvodViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    UIBarButtonItem *itemLeft = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemCancel target:self action:@selector(onCancelClicked:)];
    self.navigationItem.leftBarButtonItem = itemLeft;

    _rewardvodButton = [UIButton new];
    _rewardvodButton.backgroundColor = [UIColor orangeColor];
    _rewardvodButton.layer.cornerRadius = 20;
    
    _rewardvodButton.frame = CGRectMake((kADMGScreenWidth -150)/2, kADMGTopBarHeight + 100, 150, 40);
    [_rewardvodButton setTitle:@"激励视频" forState:UIControlStateNormal];
    [_rewardvodButton setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [self.view  addSubview:_rewardvodButton];
    [_rewardvodButton addTarget:self action:@selector(test4:) forControlEvents:UIControlEventTouchUpInside];
}

- (void)onCancelClicked:(id)sender {
    [self.navigationController dismissViewControllerAnimated:YES completion:nil];
}

#pragma mark -
- (void)test4:(UIButton *)sender {
    if (sender.selected) {
        return;
    }
    sender.selected = YES;
    // 1、初始化激励视频广告对象，每次请求数据 需要重新创建
    _rewardvodAd = [[ADMobGenRewardvodAd alloc]init];
    _rewardvodAd.delegate = self;
    _rewardvodAd.controller = self;
    // 2、加载激励视频广告，播放一次之后需要重新拉取广告
    [_rewardvodAd loadVideoAd];
}

- (void)showRewardAd{
    if (![_rewardvodAd rewardvodAdIsValid]) {
        NSLog(@"物料料已过期，请重新加载");
        return;
    }
    if ([_rewardvodAd rewardvodAdIsReady]) { //广告已经准备好了了
        [_rewardvodAd showRewardvodAd];
    }
}


#pragma mark - ADMobGeRewardvodDelegate
/**
 广告数据加载成功回调
 
 @param rewardvodAd 广告实例
 */
- (void)admg_rewardvodAdLoadSuccessCallBack:(ADMobGenRewardvodAd *)rewardvodAd{
    //3、展示激励视频广告，可在广告数据加载成功回调中或者视频数据下载成功回调，强烈建议在本回调中展示广告，否则会出现
    [self showRewardAd];
    _rewardvodButton.selected = NO;
}
/**
 视频数据下载成功回调，已经下载过的视频会直接回调
 
 @param rewardvodAd 广告实例
 */
- (void)admg_rewardvodAdVideoLoadSuccessCallBack:(ADMobGenRewardvodAd *)rewardvodAd{
    NSLog(@"视频数据下载成功");
}
/**
 视频播放页即将展示回调
 
 @param rewardvodAd 广告实例
 */
- (void)admg_rewardvodAdWillVisibleCallBack:(ADMobGenRewardvodAd *)rewardvodAd{
    NSLog(@"视频播放页即将展示");
}
/**
 视频广告曝光回调
 
 @param rewardvodAd 广告实例
 */
- (void)admg_rewardvodAdDidVisibleCallBack:(ADMobGenRewardvodAd *)rewardvodAd{
    NSLog(@"视频广告曝光");
}
/**
 视频播放页关闭回调
 
 @param rewardvodAd 广告实例
 */
- (void)admg_rewardvodAdDidCloseCallBack:(ADMobGenRewardvodAd *)rewardvodAd{
    NSLog(@"视频播放页关闭回调");
}
/**
 视频广告信息点击回调
 
 @param rewardvodAd 广告实例
 */
- (void)admg_rewardvodAdDidClickCallBack:(ADMobGenRewardvodAd *)rewardvodAd{
    NSLog(@"视频广告信息点击回调");
}
/**
 视频广告视频播放完成
 
 @param rewardvodAd 广告实例
 */
- (void)admg_rewardvodAdDidPlayFinishCallBack:(ADMobGenRewardvodAd *)rewardvodAd{
    NSLog(@"视频广告视频播放完成");
}

/**
 视频广告视频达到奖励条件
 
 @param rewardvodAd 广告实例
 */
- (void)admg_rewardvodAdDidRewardEffective:(ADMobGenRewardvodAd *)rewardvodAd{
    NSLog(@"视频广告视频达到奖励条件");
}
/**
 视频广告各种错误信息回调
 
 @param rewardvodAd 广告实例
 @param error 具体错误信息
 */
- (void)admg_rewardvodAdFailToLoadCallBack:(ADMobGenRewardvodAd *)rewardvodAd error:(NSError *)error{
    NSLog(@"视频广告错误信息回调%@",error);
}

@end
