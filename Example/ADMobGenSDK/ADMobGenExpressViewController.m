//
//  ADMobGenExpressViewController.m
//  ADMobGenSDK_Example
//
//  Created by 曹飞 on 2018/7/17.
//  Copyright © 2018年 1594717129@qq.com. All rights reserved.
//

#import "ADMobGenExpressViewController.h"
#import <ADMobGenSDK/ADMobGenNativeExpressAd.h>
#import <ADMobGenAdapter/ADMobGenNativeExpressAdView.h>

@interface ADMobGenExpressViewController () <UITableViewDelegate, UITableViewDataSource, ADMobGenNativeExpressAdDelegate> {
    ADMobGenNativeExpressAd *_expressAd;
    ADMobGenNativeExpressAd *_normalExpressAd;
}

@property (weak, nonatomic) IBOutlet UITableView *tableView;
@property (nonatomic, strong) NSMutableArray<ADMobGenNativeExpressAdView *> *tempViewitems;
@property (nonatomic, strong) NSMutableArray<ADMobGenNativeExpressAdView *> *items;

@end

@implementation ADMobGenExpressViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    UIBarButtonItem *itemLeft = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemCancel target:self action:@selector(onCancelClicked:)];
    self.navigationItem.leftBarButtonItem = itemLeft;
    
    UIBarButtonItem *itemRight = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemRefresh target:self action:@selector(onRefreshClicked:)];
    self.navigationItem.rightBarButtonItem = itemRight;
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"cell"];
    
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
}

- (void)onCancelClicked:(id)sender {
    [self.navigationController dismissViewControllerAnimated:YES completion:nil];
}

- (void)onRefreshClicked:(id)sender {
    if (!_expressAd) {
        // 1 信息流请求对象的初始化, 并声明为全局变量，其中size为期望大小，渲染成功后真实大小可以在广告视图contentSize获取（tip：当你需要高度更高的信息流视图时，因为比例是固定的，可以增加期望大小size的宽度，达到增加视图高度）
        ADMobGenNativeExpressAd *expressAd = [[ADMobGenNativeExpressAd alloc] initWithSize:CGSizeMake([UIScreen mainScreen].bounds.size.width, 10)];
        expressAd.delegate = self;
        // 2 设置信息流广告需要显示的控制器, 保证和信息流展示的控制器是同一个
        expressAd.controller = self;
        
        _expressAd = expressAd;
        //设置信息流广告类型，默认为图文ADMobGenNativeAdTypeNormal,一共支持六种样式的信息流,不同的信息流样式使用不同的实例对象,需要除normal以外其他的信息流样式可以联系ADMobs媒介或运营小姐姐
        [_expressAd setNativeAdType:ADMobGenNativeAdTypeVerticalPic];//信息流样式纯图片
    }
    // 拉取信息流模板广告
    [_expressAd load:2];
    //默认图文信息流
//    [self loadNormalNativeAd];
}

#pragma mark - 默认图文信息流
- (void)loadNormalNativeAd{
    if (!_normalExpressAd) {
        _normalExpressAd = [[ADMobGenNativeExpressAd alloc]initWithSize:CGSizeMake([UIScreen mainScreen].bounds.size.width, 10)];
        _normalExpressAd.delegate = self;
        _normalExpressAd.controller = self;
        [_normalExpressAd setNativeAdType:ADMobGenNativeAdTypeRightPic];
    }
    [_normalExpressAd load:2];
}

#pragma mark - UITableViewDelegate,UITableViewDateSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.items.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell" forIndexPath:indexPath];
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    
    UIView *subView = [cell.contentView viewWithTag:999];
    if ([subView superview]) {
        [subView removeFromSuperview];
    }
    
    ADMobGenNativeExpressAdView *adView = [self.items objectAtIndex:indexPath.row];
    adView.backgroundColor = [UIColor redColor];
    adView.frame = CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, adView.contentSize.height);
    adView.tag = 999;
    
    [cell.contentView addSubview:adView];
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    ADMobGenNativeExpressAdView *adView = [self.items objectAtIndex:indexPath.row];
    //注意：要使ADMobGenNativeExpressAdView响应点击事件还需要调用它的contentSize方法
    return adView.contentSize.height;
}

#pragma mark - ADMobGenNativeExpressAdDelegate

- (void)admg_nativeExpressAdSucessToLoad:(ADMobGenNativeExpressAd *)nativeExpressAd views:(NSArray<__kindof ADMobGenNativeExpressAdView *> *)views {
    //临时存储ADMobGenNativeExpressAdView
    [self.tempViewitems addObjectsFromArray:views];
    //成功回调中，直接返回views中的视图ADMobGenNativeExpressAdView，使用ADMobGenNativeExpressAdView之前需要调用它的render方法进行渲染。
    for (int index = 0; index < views.count; index ++) {
        [views[index] render];
    }
}

- (void)admg_nativeExpressAdFailToLoad:(ADMobGenNativeExpressAd *)nativeExpressAd error:(NSError *)error {
    
}

- (void)admg_nativeExpressAdViewRenderSuccess:(ADMobGenNativeExpressAdView *)nativeExpressAdView {
    //从临时数组中去除
    [self.tempViewitems removeObject:nativeExpressAdView];
    //加入到数据源中，注意：要使ADMobGenNativeExpressAdView响应点击事件还需要调用它的contentSize方法
    [self.items addObject:nativeExpressAdView];
    [self.tableView reloadData];
}

- (void)admg_nativeExpressAdViewRenderFail:(ADMobGenNativeExpressAdView *)nativeExpressAdView {
    //从临时数组中去除
    [self.tempViewitems removeObject:nativeExpressAdView];
}

#pragma mark - lazy
- (NSMutableArray<ADMobGenNativeExpressAdView *> *)tempViewitems {
    if (!_tempViewitems) {
        _tempViewitems = [[NSMutableArray alloc] init];
    }
    return _tempViewitems;
}

- (NSMutableArray *)items {
    if (!_items) {
        _items = [[NSMutableArray alloc] init];
    }
    return _items;
}

@end
