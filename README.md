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

<br>

## 1.1 概述

尊敬的开发者朋友，欢迎您使用艾狄墨博集合SDK平台。通过本文档，您可以在几分钟之内轻松完成广告的集成过程。

开发工具： Xcode 8 及以上版本

操作系统： iOS 8.0 及以上版本

<br>

## 2.1 采用cocoapods进行SDK的导入

SDK为了支持插件化的广告平台，采用了cocoapods进行广告集成，只需要pod对应平台，就可以集成该平台广告，无须进行其他配置

* [[Link]](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenSDK) 广告调用framework，必须导入
```ruby
pod 'ADMobGenSDK'
```

* [[Link]](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenGDT) 广点通平台，必须导入
```ruby
pod 'ADMobGenGDT'
```

* [[Link]](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenMCAd) 艾狄墨博平台，必须导入
```ruby
pod 'ADMobGenMCAd'
```

* [[Link]](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenYD) 有道平台，暂无需导入（需导入会另行通知），`注意：该平台需要手动引入` [YDAdBrowserController.xib](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenSDK/tree/master/Example/ADMobGenSDK) `资源文件到主工程`
```ruby
pod 'ADMobGenYD'
```

* [[Link]](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenIFLY) 讯飞平台，暂无需导入（需导入会另行通知）
```ruby
pod 'ADMobGenIFLY'
```

* [[Link]](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenBaiDu) 百度平台，暂无需导入（需导入会另行通知）
```ruby
pod 'ADMobGenBaiDu'
```

* [[Link]](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenMTG) Mobvsita平台，暂无需导入（需导入会另行通知）
```ruby
pod 'ADMobGenMTG'
```

* [[Link]](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenAddamSDK) 哒萌平台，暂无需导入（需导入会另行通知）
```ruby
pod 'ADMobGenAddamSDK'
```

* [[Link]](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenSDKWM) 头条平台，暂无需导入（需导入会另行通知）
```ruby
pod 'ADMobGenSDKWM'
```


<br>

## 2.2 手动导入SDK方式

下载各SDK拖入到工程中

* 必要SDK
    * 广告调用所需framework
    
        [ADMobGenSDK.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenSDK)

        [ADMobGenAdapter.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenAdapter)

        [ADMobGenFoundation.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenFoundation)

        [ADMobGenNetwork.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenNetwork)
    
    * 艾狄墨博平台
    
        `同时导入`[ADMobGenMCAd.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenMCAd) 和 [ADMobGenMCAdSDK.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenMCAdSDK)
    
    * 广点通平台
    
        [ADMobGenGDT.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenGDT)

<br>

* 可选SDK(暂无需导入，需导入时会另行通知)

    * 有道平台
    
        [ADMobGenYD.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenYD) 以及资源文件 [YDAdBrowserController.xib](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenSDK/tree/master/Example/ADMobGenSDK)
    
    * 讯飞平台
    
        [ADMobGenIFLY.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenIFLY)
    
    * 百度平台
    
        `同时导入`[ADMobGenBaiDu.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenBaiDu),  [ADMobGenBaiDuSDK.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenBaiDuSDK) 以及资源文件 [baidumobadsdk.bundle](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenBaiDuSDK/tree/master/ADMobGenBaiDuSDK/Assets)
        
    * Mobvsita平台
        
        `同时导入` [ADMobGenMTGSDK.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenMTGSDK),  [ADMobGenMTG.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenMTG) 
       
    * 哒萌平台
       
        [ADMobGenAddamSDK.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenAddamSDK)
        
    * 头条平台
        
        `同时导入` [ADMobGenWMSDK.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenWMSDK),  [ADMobGenSDKWM.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenSDKWM) 
    
<br>

## 3.1 工程环境配置

1. `如果采用cocoapods方式导入SDK, 可跳过该步骤`
手动方式导入,添加如下依赖库:
```objective-c
AdSupport.framework 
CoreLocation.framework 
QuartzCore.framework 
SystemConfiguration.framework
CoreTelephony.framework
libz.tbd 
WebKit.framework (Optional)
libxml2.tbd
Security.framework 
StoreKit.framework
MessageUI.framework
libc++.dylib
CoreGraphics.framework
EventKit.framework
EventKitUI.framework
SafariServices.framework
CoreMotion.framework
MediaPlayer.framework
```
以下为Mobvsita平台所需
```
UIKit.framework
Foundation.framework
AVFoundation.framework
Accelerate.framework
libsqlite3.dylib
```

2. 打开项目的 app target，查看 Build Settings 中的 Linking-Other Linker Flags 选项，确保含有 -ObjC 一值， 若没有则添加。

3. 在项目的 app target 中，查看 Build Settings 中的 Build options - Enable Bitcode 选项， 设置为NO。

4. info.plist 添加支持 Http访问字段
```objective-c
<key>NSAppTransportSecurity</key>
<dict>
    <key>NSAllowsArbitraryLoads</key>
    <true/>
</dict>
```

4. Info.plist 添加定位权限字段
```objective-c
NSLocationWhenInUseUsageDescription
NSLocationAlwaysAndWhenInUseUsageDeion
```

<br>

## 4.1 集合SDK的初始化

`申请的appid和你的包名相对应，根据双方商务协调，去确定需要拉取的广告平台`
```objective-c
[ADMobGenSDKConfig initWithAppId:@"appid" completionBlock:^(NSError *error) {
    if (error) {
        // SDK启动失败
    }
}];
```

开启定位权限, 更加精准的投放广告
```objective-c
[ADMobGenSDKConfig setGpsOn];
```

<br>

## 4.2 开屏广告 - ADMobGenSplashAd
```objective-c
// 1 初始化
_splashAd = [[ADMobGenSplashAd alloc] init];

// 2 设置默认启动图(一般设置启动图的平铺颜色为背景颜色，使得视觉效果更加平滑)
_splashAd.backgroundColor = [UIColor yellowColor];

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
```

<br>

## 4.3 banner广告 - ADMobGenBannerView
```objective-c
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

<br>

## 4.4 信息流模板广告 - ADMobGenNativeExpressAd
```objective-c
if (!_expressAd) {
    // 1 信息流请求对象的初始化, 并声明为全局变量
    ADMobGenNativeExpressAd *expressAd = [[ADMobGenNativeExpressAd alloc] initWithSize:CGSizeMake([UIScreen mainScreen].bounds.size.width, 100)];
    expressAd.delegate = self;
    // 2 设置信息流广告需要显示的控制器, 保证和信息流展示的控制器是同一个
    expressAd.controller = self;
    //设置信息流广告类型，默认为图文ADMobGenNativeAdTypeNormal,不同的信息流样式使用不同的实例对象
    [_expressAd setNativeAdType:ADMobGenNativeAdTypePic];//信息流样式纯图片

    _expressAd = expressAd;
}

// 拉取信息流模板广告
[_expressAd load:4];
```

* 信息流拉取成功后, 获得的 `ADMobGenNativeExpressAdView` 视图需要调用 `[adview render]` 方法, 否则无法进行广告的点击上报和展现上报
* 可在 `admg_nativeExpressAdViewRenderSuccess:` 回调中进行列表数据源的刷新
* 如果同时使用到 `ADMobGenNativeAdTypeNormal` `ADMobGenNativeAdTypePic`两种信息流类型,是在同样的代理方法中返回`ADMobGenNativeExpressAdView`视图，可调用 `[nativeExpressAdView getNativeAdType]`来判断该视图是哪种类型
* `ADMobGenNativeExpressAd` 对象初始化传入的 size, 宽度会根据传入的size固定模板宽度, 高度会自适应, 调用方可以通过 `adview.contentSize` 获取当前信息流模板视图的详细尺寸

<br>

## Author

liji@ecook.cn,sangshen@ecook.cn

## License

ADMobGenSDK is available under the MIT license. See the [LICENSE](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenSDK/blob/master/LICENSE) file for more info.
