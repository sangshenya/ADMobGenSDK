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
        // 1 信息流请求对象的初始化, 并声明为全局变量
        ADMobGenNativeExpressAd *expressAd = [[ADMobGenNativeExpressAd alloc] initWithSize:CGSizeMake([UIScreen mainScreen].bounds.size.width, 100)];
        expressAd.delegate = self;
        // 2 设置信息流广告需要显示的控制器, 保证和信息流展示的控制器是同一个
        expressAd.controller = self;
        
        _expressAd = expressAd;
    }
    
    // 拉取信息流模板广告
    [_expressAd load:4];
}

#pragma mark -

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
    adView.tag = 999;
    [cell.contentView addSubview:adView];
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    ADMobGenNativeExpressAdView *adView = [self.items objectAtIndex:indexPath.row];
    return adView.contentSize.height;
}

#pragma mark - ADMobGenNativeExpressAdDelegate

- (void)admg_nativeExpressAdSucessToLoad:(ADMobGenNativeExpressAd *)nativeExpressAd views:(NSArray<__kindof ADMobGenNativeExpressAdView *> *)views {
    [self.tempViewitems addObjectsFromArray:views];
    
    for (int index = 0; index < views.count; index ++) {
        [views[index] render];
    }
}

- (void)admg_nativeExpressAdFailToLoad:(ADMobGenNativeExpressAd *)nativeExpressAd error:(NSError *)error {
    
}

- (void)admg_nativeExpressAdViewRenderSuccess:(ADMobGenNativeExpressAdView *)nativeExpressAdView {
    [self.tempViewitems removeObject:nativeExpressAdView];
    [self.items addObject:nativeExpressAdView];
    
    [self.tableView reloadData];
}

- (void)admg_nativeExpressAdViewRenderFail:(ADMobGenNativeExpressAdView *)nativeExpressAdView {
    [self.tempViewitems removeObject:nativeExpressAdView];
}

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
