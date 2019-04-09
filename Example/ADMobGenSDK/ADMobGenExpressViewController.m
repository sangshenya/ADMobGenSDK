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
#import <MJRefresh/MJRefresh.h>

@interface ADMobGenExpressViewController () <UITableViewDelegate, UITableViewDataSource, ADMobGenNativeExpressAdDelegate> {
    ADMobGenNativeExpressAd *_expressAd;
    ADMobGenNativeExpressAd *_normalExpressAd;
    BOOL _footRefresh;
}

@property (weak, nonatomic) IBOutlet UITableView *tableView;

@property (nonatomic, strong) NSMutableArray *items;

@property (nonatomic, strong) NSMutableArray *adItems;

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
    
    __weak typeof(self) weakSelf = self;
    MJRefreshAutoNormalFooter *footer = [MJRefreshAutoNormalFooter footerWithRefreshingBlock:^{
        __strong typeof(self) strongSelf = weakSelf;
        [strongSelf loadListData];
    }];
    footer.onlyRefreshPerDrag = YES;
    footer.refreshingTitleHidden = YES;
    self.tableView.mj_footer = footer;
    
    [self loadListData];
}

- (void)onCancelClicked:(id)sender {
    [self.navigationController dismissViewControllerAnimated:YES completion:nil];
}
/*
 *各信息流高度参考，期望大小的宽度以当前设备的屏幕宽度为标准（特殊情况以实际为准）
 *上图下文和上文下图(图片比例16:9):324(plus),309(8)
 *左图右文和右图左文:87(固定)
 *纯图(图片比例16:9):233(plus),211(8)
 *竖版纯图(图片比例2:3):621(plus),562(8)
 */

- (void)onRefreshClicked:(id)sender {
    if (!_expressAd) {
        // 1 信息流请求对象的初始化, 并声明为全局变量，其中size为期望大小，渲染成功后真实大小可以在广告视图contentSize获取（tip：当你需要高度更高的信息流视图时，因为比例是固定的，可以增加期望大小size的宽度，达到增加视图高度）
        ADMobGenNativeExpressAd *expressAd = [[ADMobGenNativeExpressAd alloc] initWithSize:CGSizeMake([UIScreen mainScreen].bounds.size.width, 10)];
        expressAd.delegate = self;
        // 2 设置信息流广告需要显示的控制器, 保证和信息流展示的控制器是同一个
        expressAd.controller = self;
        
        _expressAd = expressAd;
    // 3 设置信息流广告类型，默认为图文ADMobGenNativeAdTypeNormal，一共支持六种样式的信息流，不同的信息流样式使用不同的实例对象，需要除normal以外其他的信息流样式可以联系ADMobs媒介或运营小姐姐
        [_expressAd setNativeAdType:self.nativeAdType];//信息流样式纯图片
    }
    // 4 拉取信息流模板广告
    [_expressAd load:1];
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
    
    NSString *title = [NSString stringWithFormat:@"ADMobGenNativeExpressAd Test %ld",indexPath.row];
    cell.textLabel.text = title;
    
    id obj = [self.items objectAtIndex:indexPath.row];
    if ([obj isKindOfClass:[ADMobGenNativeExpressAdView class]]) {
        ADMobGenNativeExpressAdView *adView = (ADMobGenNativeExpressAdView *)obj;
        adView.backgroundColor = [UIColor redColor];
        adView.frame = CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, adView.contentSize.height);
        adView.tag = 999;
        
        [cell.contentView addSubview:adView];
    }
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    //注意：要使ADMobGenNativeExpressAdView响应点击事件还需要调用它的contentSize方法
    id obj = [self.items objectAtIndex:indexPath.row];
    if ([obj isKindOfClass:[ADMobGenNativeExpressAdView class]]) {
        ADMobGenNativeExpressAdView *adView = (ADMobGenNativeExpressAdView *)obj;
        return adView.contentSize.height;
        
    }
    return 100;
}

- (CGFloat)tableView:(UITableView *)tableView estimatedHeightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 350;
}

#pragma mark - ADMobGenNativeExpressAdDelegate

- (void)admg_nativeExpressAdSucessToLoad:(ADMobGenNativeExpressAd *)nativeExpressAd views:(NSArray<__kindof ADMobGenNativeExpressAdView *> *)views {
    //加入到数据源中，注意：要使ADMobGenNativeExpressAdView响应点击事件还需要调用它的contentSize方法（请在此时添加到数据源中并且Reload，否则可能出现白屏或者视频无法播放的情况）
    [self.adItems addObjectsFromArray:views];
    //成功回调中，直接返回views中的视图ADMobGenNativeExpressAdView，使用ADMobGenNativeExpressAdView之前需要调用它的render方法进行渲染。
    for (int index = 0; index < views.count; index ++) {
        [views[index] render];
    }
}

- (void)admg_nativeExpressAdFailToLoad:(ADMobGenNativeExpressAd *)nativeExpressAd error:(NSError *)error {
    
}

- (void)admg_nativeExpressAdViewRenderSuccess:(ADMobGenNativeExpressAdView *)nativeExpressAdView {
    //渲染成功，webView此时返回正确的高度
    [self.items addObject:nativeExpressAdView];
    [self.adItems removeObject:nativeExpressAdView];
    [self.tableView.mj_footer endRefreshing];
    _footRefresh = NO;
    [self.tableView reloadData];
}

- (void)admg_nativeExpressAdViewRenderFail:(ADMobGenNativeExpressAdView *)nativeExpressAdView {
    
}

- (void)admg_nativeExpressAdViewClose:(ADMobGenNativeExpressAdView *)nativeExpressAdView{
    
}

#pragma mark - lazy

- (NSMutableArray *)items {
    if (!_items) {
        _items = [[NSMutableArray alloc] init];
    }
    return _items;
}

- (NSMutableArray *)adItems{
    if (!_adItems) {
        _adItems = [NSMutableArray array];
    }
    return _adItems;
}

- (void)loadListData{
    if (_footRefresh) {
        return;
    }
    _footRefresh = YES;
    for (int i = 0; i < 5; i++) {
        UIView *view = [[UIView alloc]init];
        [self.items addObject:view];
    }
    [self onRefreshClicked:nil];
}

@end
