//
//  ADMobGenUnifiedNativeViewController.m
//  ADMobGenSDK_Example
//
//  Created by 陶冶明 on 2019/11/6.
//  Copyright © 2019 1594717129@qq.com. All rights reserved.
//

#import "ADMobGenUnifiedNativeViewController.h"
#import <ADMobGenSDK/ADMobGenUnifiedNativeAd.h>
#import "ADMobGenUnifiedNativeTableViewCell.h"

@interface ADMobGenUnifiedNativeViewController () <ADMobGenUnifiedNativeAdDelegate, UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) ADMobGenUnifiedNativeAd *unifiedNativeAd;

@property (nonatomic, strong) NSMutableArray<UIView<ADMobUnifiedNativeAdViewProtocol> *> *items;

@property (nonatomic, strong) UITableView *tableView;

@end

@implementation ADMobGenUnifiedNativeViewController

#pragma mark - Life crycle

- (void)viewDidLoad {
    [super viewDidLoad];
    
    _tableView = [UITableView new];
    [self.view addSubview:_tableView];
    _tableView.frame = self.view.bounds;
    _tableView.delegate = self;
    _tableView.dataSource = self;
    [_tableView registerClass:[ADMobGenUnifiedNativeTableViewCell class] forCellReuseIdentifier:@"cell"];
    
    _items = [NSMutableArray new];
    
    UIBarButtonItem *addButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"加广告" style:UIBarButtonItemStylePlain target:self action:@selector(clickAddButton)];
    UIBarButtonItem *cleanButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"去广告" style:UIBarButtonItemStylePlain target:self action:@selector(clickCleanButton)];
    self.navigationItem.rightBarButtonItems = @[addButtonItem, cleanButtonItem];
}

- (void)dealloc {
    // 5、信息流自渲染广告内存管理，取消注册
    for (UIView<ADMobUnifiedNativeAdViewProtocol> *item in _items) {
        [item admg_unregist];
    }
}

#pragma mark - Touch event

- (void)clickAddButton {
    //  2、加载信息流自渲染广告
    [self.unifiedNativeAd load:1];
}

- (void)clickCleanButton {
    // 5、信息流自渲染广告内存管理，取消注册
    for (UIView<ADMobUnifiedNativeAdViewProtocol> *item in _items) {
        [item admg_unregist];
    }
    self.items = @[].mutableCopy;
    [self.tableView reloadData];
}

#pragma mark - UITableViewDelegate

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return self.view.frame.size.width / 16.0 * 9 + 50 + 50;
}

#pragma mark - UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.items.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    ADMobGenUnifiedNativeTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell"];
    id adView = [self.items objectAtIndex:indexPath.row];
    cell.adView = adView;
    return cell;
}

#pragma mark - ADMobGenUnifiedNativeAdDelegate

- (void)admg_unifiedNativeSuccessToLoad:(ADMobGenUnifiedNativeAd *)unifiedNativeAd viewArray:(NSArray<UIView<ADMobUnifiedNativeAdViewProtocol> *> *)nativeAdViewAry {
    //  3、信息流自渲染广告加载成功
    for (UIView<ADMobUnifiedNativeAdViewProtocol>* nativeAdView in nativeAdViewAry) {
        // 4、信息流自渲染广告视图由开发者渲染
        nativeAdView.frame = CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.width / 16.0 * 9 + 50 + 50);
        
        UIImageView *iconImageView = [UIImageView new];
        [nativeAdView addSubview:iconImageView];
        iconImageView.frame = CGRectMake(12, 3, 44, 44);
        NSString *iconUrlStr = nativeAdView.admg_dataObject.iconImageUrl;
        
        if(iconUrlStr) {
            dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^{
                UIImage *image = [UIImage imageWithData:[NSData dataWithContentsOfURL:[NSURL URLWithString:iconUrlStr]]];
                dispatch_async(dispatch_get_main_queue(), ^{
                    iconImageView.image = image;
                });
            });
        }
        if(nativeAdView.admg_dataObject.iconImage)
            iconImageView.image = nativeAdView.admg_dataObject.iconImage;
        iconImageView.clipsToBounds = YES;
        iconImageView.layer.cornerRadius = 22;
        iconImageView.contentMode = UIViewContentModeScaleAspectFill;
        
        UILabel *titlabel = [UILabel new];
        [nativeAdView addSubview:titlabel];
        titlabel.frame = CGRectMake(12 + 44 + 12, 0, 300, 50);
        titlabel.text = nativeAdView.admg_dataObject.title;
        
        UIImageView *imageView = [UIImageView new];
        [nativeAdView addSubview:imageView];
        imageView.frame = CGRectMake(0, 50, self.view.frame.size.width, self.view.frame.size.width / 16.0 * 9);
        NSString *urlStr = nativeAdView.admg_dataObject.imageUrl;
        
        if(urlStr.length > 0) {
            dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^{
                UIImage *image = [UIImage imageWithData:[NSData dataWithContentsOfURL:[NSURL URLWithString:urlStr]]];
                dispatch_async(dispatch_get_main_queue(), ^{
                    imageView.image = image;
                });
            });
        }
        
        UIView *mediaView = [nativeAdView admg_mediaViewForWidth:imageView.frame.size.width];
        [nativeAdView addSubview:mediaView];
        mediaView.frame = imageView.frame;
        mediaView.hidden = !nativeAdView.admg_dataObject.shouldShowMediaView;
        
        UIImage *logoImage = [nativeAdView logoImageWithText:YES];
        UIImageView *logoImageView = [UIImageView new];
        [nativeAdView addSubview:logoImageView];
        logoImageView.frame = CGRectMake(0, self.view.frame.size.width / 16.0 * 9 + 50, self.view.frame.size.width, 50);
        logoImageView.contentMode = UIViewContentModeBottomRight;
        logoImageView.image = logoImage;
        
        UILabel *descLabel = [UILabel new];
        descLabel.text = nativeAdView.admg_dataObject.desc;
        [nativeAdView addSubview:descLabel];
        descLabel.frame = CGRectMake(12, self.view.frame.size.width / 16.0 * 9 + 50, self.view.frame.size.width, 50);
        
        [nativeAdView admg_regist];
        
        [self.items addObject:nativeAdView];
    }
    [self.tableView reloadData];
}

- (void)admg_unifiedNativeFailToLoad:(ADMobGenUnifiedNativeAd *)unifiedNativeAd error:(NSError *)error {
    NSString *errorStr = [NSString stringWithFormat:@"admg_unifiedNativeFailToLoad error %@", error.description];
    NSLog(@"%@",errorStr);
}

- (void)admg_unifiedNativeClicked:(ADMobGenUnifiedNativeAd *)unifiedNativeAd view:(UIView<ADMobUnifiedNativeAdViewProtocol> *)unifiedNativeAdView {

}

- (void)admg_unifiedNativeExposure:(ADMobGenUnifiedNativeAd *)unifiedNativeAd view:(UIView<ADMobUnifiedNativeAdViewProtocol> *)unifiedNativeAdView {

}

#pragma mark - Lazy load

- (ADMobGenUnifiedNativeAd *)unifiedNativeAd {
    if(!_unifiedNativeAd) {
        //  1、初始化信息流自渲染广告
        _unifiedNativeAd = [[ADMobGenUnifiedNativeAd alloc] initWithViewController:self index:0];
        _unifiedNativeAd.delegate = self;
    }
    return _unifiedNativeAd;
}

@end
