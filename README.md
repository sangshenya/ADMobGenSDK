# ADMobGenSDK iOS接入文档 v1.4.2

## 修订历史

| 文档版本| 修订日期| 修订说明|
| --- | --- | --- |
| v1.3.5 | 2018-12-3 | 文档新增demo地址 未导入ADMob平台崩溃提示 Banner广告多尺寸 |
| v1.3.6 | 2018-12-8 | 文档新增SDK问题整理 Banner广告多尺寸列表 信息流模版广告多样式列表 |
| v1.4.2 | 2018-12-27 | demo地址更新 广点通、头条SDK更新适配 信息流模板广告的接入更新 新增信息流模板各样式的参考高度 |

## 导入ADMobGenSDK

```ruby
pod 'ADMobGenSDK'
```

 常用SDK最新的版本号
```ruby
ADMobGenFoundation (0.4.0)
ADMobGenAdapter (1.1.5)
ADMobGenGDT (0.6.2及以上)
ADMobGenMCAd (0.3.8)
ADMobGenMCAdSDK (0.3.4)
ADMobGenNetwork (0.3.2)
ADMobGenSDK (1.4.2及以上)
ADMobGenSDKWM (0.7.5)
ADMobGenWMSDK (0.2.2)
```

<br>

## 1.1 概述

尊敬的开发者朋友，欢迎您使用艾狄墨博集合SDK平台。通过本文档，您可以在几分钟之内轻松完成广告的集成过程。

开发工具： Xcode 8 及以上版本

操作系统： iOS 8.0 及以上版本

* `Demo地址`[[ADMobGenSDK Demo]](https://github.com/sangshenya/ADMobGenSDK)

<br>

## 2.1 采用cocoapods进行SDK的导入

SDK为了支持插件化的广告平台，采用了cocoapods进行广告集成，只需要pod对应平台，就可以集成该平台广告，无须进行其他配置

`注意：如果不导入ADMob(艾狄墨博)平台会导致崩溃`

* [[Link]](https://github.com/sangshenya/ADMobGenSDK) 广告调用framework，必须导入
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

* [[Link]](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenSDKWM) 头条平台，必须导入
```ruby
pod 'ADMobGenSDKWM'
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


<br>

## 2.2 手动导入SDK方式

下载各SDK拖入到工程中，在Demo中的Pods/Pods目录下也可以找到必须导入的framework

* 必要SDK
    * 广告调用所需framework

        [ADMobGenSDK.framework](https://github.com/sangshenya/ADMobGenSDK)

        [ADMobGenAdapter.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenAdapter)

        [ADMobGenFoundation.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenFoundation)

        [ADMobGenNetwork.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenNetwork)

    * 艾狄墨博平台

        `同时导入`[ADMobGenMCAd.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenMCAd) 和 [MCAdSDK.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenMCAdSDK)以及资源文件[MCAdBundles.bundle](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenMCAd/tree/master/ADMobGenMCAd/Assets)

    * 广点通平台

        [ADMobGenGDT.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenGDT)

    * 头条平台

        `同时导入` [ADMobGenWM.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenWMSDK),  [BUAdSDK.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenSDKWM) 以及资源文件[BUAdSDK.bundle](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenWMSDK/tree/master/ADMobGenWMSDK/Assets)

<br>

* 可选SDK(暂无需导入，需导入时会另行通知)

    * 有道平台
    
        [ADMobGenYD.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenYD) 以及资源文件 [YDAdBrowserController.xib](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenSDK/tree/master/Example/ADMobGenSDK)
    
    * 讯飞平台
    
        [ADMobGenIFLY.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenIFLY)
    
    * 百度平台
    
        `同时导入`[ADMobGenBaiDu.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenBaiDu),  [BaiduMobAdSDK.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenBaiDuSDK) 以及资源文件 [baidumobadsdk.bundle](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenBaiDuSDK/tree/master/ADMobGenBaiDuSDK/Assets)
        
    * Mobvsita平台
      
        `同时导入` [ADMobGenMTGSDK.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenMTGSDK),  [ADMobGenMTG.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenMTG) 
       
    * 哒萌平台
      
        [ADMobGenAddamSDK.framework](http://121.41.108.203/ADMobGenKit-Modules/ADMobGenAddamSDK)
        
    

<br>

## 3.1 工程环境配置

1. `如果采用cocoapods方式导入SDK, 可跳过该步骤`
手动方式导入,添加如下依赖库:
```obj-c
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
```obj-c
<key>NSAppTransportSecurity</key>
<dict>
    <key>NSAllowsArbitraryLoads</key>
    <true/>
</dict>
```

4. Info.plist 添加定位权限字段
```obj-c
NSLocationWhenInUseUsageDescription
NSLocationAlwaysAndWhenInUseUsageDeion
```

<br>

## 4.1 集合SDK的初始化

`申请的appid和你的包名相对应，根据双方商务协调，去确定需要拉取的广告平台`
```obj-c
[ADMobGenSDKConfig initWithAppId:@"appid" completionBlock:^(NSError *error) {
    if (error) {
        // SDK启动失败
    }
}];
```

开启定位权限, 更加精准的投放广告
```obj-c
[ADMobGenSDKConfig setGpsOn];
```

用户日志输出等级
```obj-c
//默认为ADMobGenLogLevelNone
[ADMobGenSDKConfig setLogLevel:ADMobGenLogLevelError];
```

获取ADMobGenSDK版本号
```obj-c
//获取SDK版本号
NSString *sdkVersion = [ADMobGenSDKConfig getSDKVersion];
```

测试Debug包需要，一般情况下不开启,需要时会另行通知
```obj-c
//广告SDK Debug模式
[ADMobGenSDKConfig setDebugMode:@(YES)];
```


<br>

## 4.2 开屏广告 - ADMobGenSplashAd

开屏广告请求示例：
```obj-c
//注意：1、当你在控制器中加载开屏时，请勿在viewWillAppear中加载开屏，该方法会调用多次，使得展示多次开屏广告。2、在viewDidLoad中加载开屏广告的时候，如果该控制器没有用导航栏承载，会出现无法展示广告，却走了加载成功的回调方法。3、当你在rootViewController中有做模态弹出其他的控制器（包含UIAlertController）的操作时，可能会出现广告加载不出的情况（广点通广告无法加载）。
// 1 初始化
_splashAd = [[ADMobGenSplashAd alloc] init];

// 2 设置默认启动图(一般设置启动图的平铺颜色为背景颜色，使得视觉效果更加平滑)
_splashAd.backgroundColor = [UIColor getColorWithImage:[UIImage imageNamed:@"750×1334"] withNewSize:[UIScreen mainScreen].bounds.size];

_splashAd.delegate = self;

// 3 设置底部logo视图, 高度不能超过屏幕的25%, 除iPhoneX以外建议: 开屏的广告图片默认640 / 960比例，如果是iPhoneX注意bottomViewHeight不能超过屏幕的25%
CGFloat bottomViewHeight;
if (kIPhoneX) {
    bottomViewHeight = [UIScreen mainScreen].bounds.size.height * 0.25;
} else {
    bottomViewHeight = [UIScreen mainScreen].bounds.size.height - [UIScreen mainScreen].bounds.size.width * (960 / 640.0);
}

UIView *bottomView = [[UIView alloc] init];
bottomView.backgroundColor = [UIColor whiteColor];
bottomView.frame = CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, bottomViewHeight);
// 4 设置logo，根据自己的实际情况来设置
UIImageView *logoImageView = [[UIImageView alloc]initWithImage:[UIImage imageNamed:@"ADMob_Logo.png"]];
logoImageView.frame = CGRectMake(([UIScreen mainScreen].bounds.size.width-135)/2, (bottomViewHeight-46)/2, 135, 46);
[bottomView addSubview:logoImageView];

// 5 展示
UIWindow *window = [UIApplication sharedApplication].delegate.window;
[_splashAd loadAndShowInWindow:window withBottomView:bottomView];

// 6 代理回调
#pragma mark - ADMobGenSplashAdDelegate
// 开屏展现回调
- (void)admg_splashAdSuccessToPresentScreen:(ADMobGenSplashAd *)splashAd{

}
// 加载失败调用该方法
- (void)admg_splashAd:(ADMobGenSplashAd *)splash failToPresentScreen:(NSError *)error{
    _splashAd = nil;
    if (error) {
    //NSLog(@"");ADMobGenLogLevelError自动打印错误信息，也可打印error查看
    }
}
// 加载成功，开屏被关闭调用该方法
- (void)admg_splashAdClosed:(ADMobGenSplashAd *)splashAd{
    _splashAd = nil;
}
```
开屏广告注意事项：

* 推荐在 `AppDelegate`的 `didFinishLaunchingWithOptions`方法的 `return YES`之前调用开屏。
* 销毁开屏对象请在开屏加载失败和开屏关闭的回调中置空，切忌在点击回调中置空，可能会造成从落地页返回App的时候出现广告视图依旧存在的情况，因为开屏的生命周期是请求-展示-/落地页(点击)-/关闭。
* 当使用控制器承载开屏广告时，有以下三个需要注意的事项：
* 1、请勿在`viewWillAppear`中调用开屏广告，否则会出现开屏方法多次被调用。
* 2、当前控制器需要导航栏控制器承载，否则会出现广告请求成功却不展示的情况。
* 3、当你在rootViewController中有做模态弹出其他的控制器的操作时，可能会出现广告加载不出的情况（广点通广告无法加载）。
* 4、切勿在点击回调中将开屏实例对象置空，否则广点通下载类广告落地页无法关闭，头条广告悬停在屏幕无法消失。

<br>

## 4.3 banner广告 - ADMobGenBannerView

横幅广告支持多尺寸，如下：
```obj-c
typedef NS_ENUM(NSUInteger, ADMobGenBannerAdSize) {
    ADMobGenBannerAdSizeNormal = 0,//640:100
    ADMobGenBannerAdSize600_150 = 1,//600:150
    ADMobGenBannerAdSize690_388 = 2,//690:388
    ADMobGenBannerAdSize600_400 = 3,//600:400
    ADMobGenBannerAdSize600_260 = 4,//600:260
};
```
横幅广告请求示例：
```obj-c
if (_bannerView) {
    [_bannerView removeFromSuperview];
    _bannerView = nil;
}

// 1 初始化banner视图，bannerSize为banner的宽高比，以视图的宽度为准，当需要使用除默认尺寸以外的请与我们的商务联系
_bannerView = [[ADMobGenBannerView alloc] initWithFrame:CGRectZero withBannerSize:ADMobGenBannerAdSize600_150];
_bannerView.delegate = self;
_bannerView.backgroundColor = [UIColor redColor];

// 2 添加到父视图上，ADMobGenBannerView的比例请尽量与bannerSize保持一致
//    CGFloat height = [UIScreen mainScreen].bounds.size.width * (5 / 32.0);
//    CGFloat width = [UIScreen mainScreen].bounds.size.width;
CGFloat height = ([UIScreen mainScreen].bounds.size.width)/4;
CGFloat width = [UIScreen mainScreen].bounds.size.width;
_bannerView.frame = CGRectMake(0, [UIScreen mainScreen].bounds.size.height - height, width, height);
[self.view addSubview:_bannerView];

// 3 加载并显示广告 注意: 请确保banner视图显示在屏幕内的时候,调用load方法
[_bannerView loadWithError:nil];

// 4 代理回调
#pragma mark - ADMobGenBannerViewDelegate
// 加载成功
- (void)admg_bannerViewDidReceived:(ADMobGenBannerView *)bannerView{
    NSLog(@"load banner success");
}
// 加载失败
- (void)admg_bannerViewFailToReceived:(ADMobGenBannerView *)bannerView error:(NSError *)error{
    if (error) {
        //请求失败时，将banner视图的高度置为0，就不会出现空白区域
        CGRect rect = _bannerView.frame;
        _bannerView.frame = CGRectMake(rect.origin.x, rect.origin.y, rect.size.width, 0);
    }
}
```

<br>

## 4.4 信息流模板广告 - ADMobGenNativeExpressAd

信息流模板广告返回的是广告视图，可以支持多个样式。各个样式描述如下：
```obj-c
//同类型的高度一致，以真实返回视图的高度为准，如有其他需求请联系我方商务
typedef NS_ENUM(NSUInteger, ADMobGenNativeAdType) {
    ADMobGenNativeAdTypeNormal = 0,//上图下文，默认为图文，图片比例为16：9
    ADMobGenNativeAdTypePic,//纯图片，图片比例16：9
    ADMobGenNativeAdTypeRightPic,//右图左文，图片比例3：2
    ADMobGenNativeAdTypeLeftPic,//左图右文，图片比例3：2
    ADMobGenNativeAdTypeCenterPic,//上文下图，图片比例16：9
    ADMobGenNativeAdTypeVerticalPic,//竖版纯图，图片比例3：2
};
```

信息流模板广告返回的是广告视图，各样式的尺寸高度如下（以实际情况为准）：
```obj-c
/*
*各信息流高度参考，期望大小的宽度以当前设备的屏幕宽度为标准（特殊情况以实际为准）
*上图下文和上文下图(图片比例16:9):324(plus),302(8)
*左图右文和右图左文:87(固定)
*纯图(图片比例16:9):233(plus),211(8)
*竖版纯图(图片比例2:3):621(plus),562(8)
*/
```

信息流模板广告请求示例：
```obj-c

if (!_expressAd) {
    // 1 信息流请求对象的初始化, 并声明为全局变量
    ADMobGenNativeExpressAd *expressAd = [[ADMobGenNativeExpressAd alloc] initWithSize:CGSizeMake([UIScreen mainScreen].bounds.size.width, 100)];
    expressAd.delegate = self;
    // 2 设置信息流广告需要显示的控制器, 保证和信息流展示的控制器是同一个
    expressAd.controller = self;
    // 3 设置信息流广告类型，默认为图文ADMobGenNativeAdTypeNormal,一共支持六种样式的信息流,不同的信息流样式使用不同的实例对象,需要除normal以外其他的信息流样式可以联系ADMobs媒介或运营小姐姐
    [expressAd setNativeAdType:ADMobGenNativeAdTypePic];//信息流样式纯图片

    _expressAd = expressAd;
}

// 4 拉取信息流模板广告
[_expressAd load:4];

// 5 代理回调
#pragma mark - ADMobGenNativeExpressAdDelegate
// 加载成功
- (void)admg_nativeExpressAdSucessToLoad:(ADMobGenNativeExpressAd *)nativeExpressAd views:(NSArray<__kindof ADMobGenNativeExpressAdView *> *)views {
    //加入到数据源中，注意：要使ADMobGenNativeExpressAdView响应点击事件还需要调用它的contentSize方法（请在此时添加到数据源中，否则可能出现白屏或者视频无法播放的情况）
    [self.items addObjectsFromArray:views];
    //成功回调中，直接返回views中的视图ADMobGenNativeExpressAdView，使用ADMobGenNativeExpressAdView之前需要调用它的render方法进行渲染。
    for (int index = 0; index < views.count; index ++) {
        [views[index] render];
    }
    [self.tableView reloadData];
}
// 加载失败回调
- (void)admg_nativeExpressAdFailToLoad:(ADMobGenNativeExpressAd *)nativeExpressAd error:(NSError *)error {

}
// 渲染成功回调
- (void)admg_nativeExpressAdViewRenderSuccess:(ADMobGenNativeExpressAdView *)nativeExpressAdView {
    //刷新，此时webView加载可返回正确的高度
    [self.tableView reloadData];

}
// 渲染失败
- (void)admg_nativeExpressAdViewRenderFail:(ADMobGenNativeExpressAdView *)nativeExpressAdView {
    //从临时数组中去除
    [self.tempViewitems removeObject:nativeExpressAdView];
}
```

信息流模版广告注意事项：
* 信息流拉取成功后, 获得的 `ADMobGenNativeExpressAdView` 视图需要调用 `[adview render]` 方法, 否则无法进行广告的点击上报和展现上报。在渲染成功的回调中再调用`render`方法，会再次调起渲染成功回调，造成死循环。
* 如果同时使用到 `ADMobGenNativeAdTypeNormal` `ADMobGenNativeAdTypePic`两种信息流类型,是在同样的代理方法中返回`ADMobGenNativeExpressAdView`视图，可调用 `[nativeExpressAdView getNativeAdType]`来判断该视图是哪种类型
* `ADMobGenNativeExpressAd` 对象初始化传入的 size, 宽度会根据传入的size固定模板宽度, 高度会自适应, 调用方可以通过 `adview.contentSize` 获取当前信息流模板视图的详细尺寸，如不使用`adview.contentSize`会出现无法点击的问题。


<br>


## 问题排查

用户日志输出等级设置之后会在控制台打印各类信息，或者在广告请求的错误回调中也会带有各个类型的错误，错误代码说明如下：

| 错误代码 | 错误说明 |
| --- | --- |
| 1001 | SDK初始化失败 |
| 1002 | appId为空 |
| 1003 | 包名和appId不对应 |
| 1004 | 请求配置为空 |
| -9995 | 请求超时 |
| -9996 | 获取广告失败 |
| -9997 | 未获取到加载广告的平台 ：第一次启动未获取到配置信息或者运营未配置广告 |
| -9999 | 横屏不加载开屏广告 |

如碰到其他非常见问题，请查阅下表或者反馈问题至ADMob方技术人员

* Q：开屏广告有时候出现落地页无法关闭，或者落地页关闭之后广告视图不消失？

  `请检查是否在开屏广告的点击回调中将开屏广告的实例对象置空。开屏广告的实例对象置空会导致开屏广告的生命周期中断，开屏广告正常的生命周期为‘请求-展现-点击-落地页-关闭’，请在开屏广告的关闭回调中置空它。`

* Q：请求开屏广告时在控制台出现请求失败的错误信息却没有执行错误回调

  `开屏广告目前设置超时时间为3s，请检查是否开屏广告的代理对象已经被置空了，导致没有执行错误回调`

* Q：请求信息流模版广告时，点击之后落地页无法关闭

  `请检查是否是信息流广告的实例对象的控制器设置问题，保证和信息流展示的控制器是同一个`

* Q：请求信息流模版广告时，广告无法点击

  `请检查是否调用信息流模版视图的contentSize方法`

* Q：请求信息流模版广告时，出现信息流显示不全或者文字会重复

  `请检查是否调用信息流模版视图的render方法`


## 作者

liji@ecook.cn,sangshen@ecook.cn
