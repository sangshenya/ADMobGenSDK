# ADMobGenSDK

[![CI Status](https://img.shields.io/travis/1594717129@qq.com/ADMobGenSDK.svg?style=flat)](https://travis-ci.org/1594717129@qq.com/ADMobGenSDK)
[![Version](https://img.shields.io/cocoapods/v/ADMobGenSDK.svg?style=flat)](https://cocoapods.org/pods/ADMobGenSDK)
[![License](https://img.shields.io/cocoapods/l/ADMobGenSDK.svg?style=flat)](https://cocoapods.org/pods/ADMobGenSDK)
[![Platform](https://img.shields.io/cocoapods/p/ADMobGenSDK.svg?style=flat)](https://cocoapods.org/pods/ADMobGenSDK)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements

## Installation

ADMobGenSDK is available through [CocoaPods](https://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'ADMobGenSDK'
```

## 1.1 概述

尊敬的开发者朋友，欢迎您使用艾狄墨博集合SDK平台。通过本文档，您可以在几分钟之内轻松完成广告的集成过程。

开发工具： Xcode 8 及以上版本
操作系统： iOS 8.0 及以上版本


## 2.1 采用cocoapods进行SDK的导入

SDK为了支持插件化的广告平台，采用了cocoapods进行广告集成，只需要pod对应平台，就可以集成该平台广告，无须进行其他配置

// 广告调用framework，必须导入
pod ‘ADMobGenSDK’

// 广点通平台
pod ‘ADMobGenGDT’

// 有道平台，注意： 该平台需要引入 `YDAdBrowserController.xib` 资源文件到主工程
pod ‘ADMobGenYD’

// 讯飞平台
pod ‘ADMobGenIFLY’

// 百度平台
pod ‘ADMobGenBaiDu’

// 艾狄墨博平台
pod ‘ADMobGenMCAd’


## 2.2 工程环境配置

1. 打开项目的 app target，查看 Build Settings 中的 Linking-Other Linker Flags 选项，确保含有 -ObjC 一值， 若没有则添加。

2. 在项目的 app target 中，查看 Build Settings 中的 Build options - Enable Bitcode 选项， 设置为NO。

3. info.plist 添加支持 Http访问字段
```ruby

```

4. Info.plist 添加定位权限字段
```
NSLocationWhenInUseUsageDescription
NSLocationAlwaysAndWhenInUseUsageDeion
```

## 3.1 集合SDK的初始化
```
[ADMobGenSDKConfig initWithAppId:@"appid" completionBlock:^(NSError *error) {
    if (error) {
        // SDK启动失败
    }
}];
```

开启定位权限, 更加精准的投放广告
```
[ADMobGenSDKConfig setGpsOn];
```

## 3.2 开屏广告 - ADMobGenSplashAd
```
// 1 初始化
_splashAd = [[ADMobGenSplashAd alloc] init];

// 2 设置默认启动图
_splashAd.backgroundColor = [UIColor yellowColor];

// 3 设置底部logo视图, 高度不能超过屏幕的25%, 建议: 开屏的广告图片默认640 / 960比例
CGFloat bottomViewHeight = [UIScreen mainScreen].bounds.size.height - [UIScreen mainScreen].bounds.size.width * (960 / 640.0);
UIView *view = [[UIView alloc] init];
view.backgroundColor = [UIColor purpleColor];
view.frame = CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, bottomViewHeight);

// 4 展示
UIWindow *window = [UIApplication sharedApplication].delegate.window;
[_splashAd loadAndShowInWindow:window withBottomView:view];
```

## 3.3 banner广告 - ADMobGenBannerView
```
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
```

## 3.4 信息流模板广告 - ADMobGenNativeExpressAd
```
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
```
* 信息流拉取成功后, 获得的 `ADMobGenNativeExpressAdView` 视图需要调用 `[adview render]` 方法, 否则无法进行广告的点击上报和展现上报
* 可在 `admg_nativeExpressAdViewRenderSuccess:` 回调中进行列表数据源的刷新
* `ADMobGenNativeExpressAd` 对象初始化传入的 size, 宽度会根据传入的size固定模板宽度, 高度会自适应, 调用方可以通过 `adview.contentSize` 获取当前信息流模板视图的详细尺寸

// Author

liji@ecook.cn

// License

ADMobGenSDK is available under the MIT license. See the LICENSE file for more info.
