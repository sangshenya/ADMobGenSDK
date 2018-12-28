//
//  ADMobGenViewController.m
//  ADMobGenSDK
//
//  Created by 1594717129@qq.com on 07/13/2018.
//  Copyright (c) 2018 1594717129@qq.com. All rights reserved.
//

#import "ADMobGenViewController.h"
#import "ADMobGenExpressViewController.h"
#import "ADMobGenSplashAdViewController.h"
#import "ADMobGenBannerViewController.h"
#import <ADMobGenFoundation/UIColor+ADMobGen.h>
#import <ADMobGenFoundation/UIFont+ADMobGen.h>

@interface ADMobGenViewController ()<UITableViewDelegate,UITableViewDataSource>

@property (nonatomic, strong) UITableView *mainTableView;

@property (nonatomic, strong) NSArray *dataArray;

@end

@implementation ADMobGenViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    self.title = @"ADMobGenSDK Demo";
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    self.dataArray = @[@[@"开屏广告",@"banner"],@[@"原生模版上图下文",@"原生模版下图上文",@"原生模版左图右文",@"原生模版右图左文",@"原生模版纯图",@"原生模版竖图"]];
    
    [self.view addSubview:self.mainTableView];
    
    [self.mainTableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"cell"];
    
}

#pragma mark - UITableViewDelegate,UITableViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return self.dataArray.count;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return [[self.dataArray objectAtIndex:section] count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell" forIndexPath:indexPath];
    NSArray *array = [self.dataArray objectAtIndex:indexPath.section];
    UIView *view = [cell.contentView viewWithTag:999];
    if (view) {
        [view removeFromSuperview];
    }
    UILabel *labTitle = [[UILabel alloc]init];
    labTitle.font = [UIFont PingFangMediumFont:18];
    labTitle.textColor = [UIColor colorWithHexString:@"#535353"];
    labTitle.tag = 999;
    labTitle.text = [array objectAtIndex:indexPath.row];
    [cell.contentView addSubview:labTitle];
    labTitle.frame = CGRectMake(19, 15, [UIScreen mainScreen].bounds.size.width - 38, 30);
    
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    return 60;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    [tableView deselectRowAtIndexPath:indexPath animated:NO];
    if (indexPath.section == 0) {
        switch (indexPath.row) {
            case 0:
            {
                [self loadSplash];
            }
                break;
            case 1:
            {
                [self loadBanner];
            }
                break;
                
            default:
                break;
        }
    } else {//@[@"原生模版上图下文",@"原生模版下图上文",@"原生模版左图右文",@"原生模版右图左文",@"原生模版纯图",@"原生模版竖图",@"原生模版视频（样式同上图下文）",@"原生模版视频（样式同纯图）",@"原生模版视频（样式同下图上文）"]
        switch (indexPath.row) {
            case 0:
            {
                [self loadNativeExpress:ADMobGenNativeAdTypeNormal];
            }
                break;
            case 1:
            {
                [self loadNativeExpress:ADMobGenNativeAdTypeCenterPic];
            }
                break;
            case 2:
            {
                [self loadNativeExpress:ADMobGenNativeAdTypeLeftPic];
            }
                break;
            case 3:
            {
                [self loadNativeExpress:ADMobGenNativeAdTypeRightPic];
            }
                break;
            case 4:
            {
                [self loadNativeExpress:ADMobGenNativeAdTypePic];
            }
                break;
            case 5:
            {
                [self loadNativeExpress:ADMobGenNativeAdTypeVerticalPic];
            }
                break;
                
            default:
                break;
        }
    }
}

- (UITableView *)mainTableView{
    if (!_mainTableView) {
        _mainTableView = [[UITableView alloc]initWithFrame:CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height) style:UITableViewStylePlain];
        _mainTableView.delegate = self;
        _mainTableView.dataSource = self;
        _mainTableView.backgroundColor = [UIColor whiteColor];
        
        
    }
    return _mainTableView;
}





#pragma mark -
- (void) loadSplash {
    ADMobGenSplashAdViewController *vc = [ADMobGenSplashAdViewController new];
    //    UINavigationController *nav = [[UINavigationController alloc]initWithRootViewController:vc];
    //    [self presentViewController:nav animated:YES completion:nil];
    [self.navigationController pushViewController:vc animated:YES];
}

- (void) loadBanner {
    ADMobGenBannerViewController *vc = [ADMobGenBannerViewController new];
    UINavigationController *nav = [[UINavigationController alloc]initWithRootViewController:vc];
    [self presentViewController:nav animated:YES completion:nil];
}


- (void) loadNativeExpress:(ADMobGenNativeAdType)adType {
    ADMobGenExpressViewController *vc = [ADMobGenExpressViewController new];
    vc.nativeAdType = adType;
    UINavigationController *nav = [[UINavigationController alloc]initWithRootViewController:vc];
    [self presentViewController:nav animated:YES completion:nil];
}











@end
