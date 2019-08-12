//
//  ADMobGenNativeExpressCommon.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/6/15.
//

#ifndef ADMobGenNativeExpressCommon_h
#define ADMobGenNativeExpressCommon_h

typedef NS_ENUM(NSInteger, ADMobGenPlayerState) {
    ADMobGenPlayerStateInitial = 0,//初始化状态
    ADMobGenPlayerStateBuffering = 1,//缓冲中
    ADMobGenPlayerStatePlaying = 2,//播放中
    ADMobGenPlayerStatePaused = 3,//播放暂停
    ADMobGenPlayerStateStopped = 4,//播放停止
    ADMobGenPlayerStateError = 5,//播放出错
};

typedef NS_ENUM(NSUInteger, ADMobGenNativeAdType) {
    ADMobGenNativeAdTypeNormal = 0,//上图下文，默认为图文，图片尺寸为16：9
    ADMobGenNativeAdTypePic,//纯图片16：9
    ADMobGenNativeAdTypeRightPic,//右图左文3：2
    ADMobGenNativeAdTypeLeftPic,//左图右文3：2
    ADMobGenNativeAdTypeCenterPic,//上文下图16：9
    ADMobGenNativeAdTypeVerticalPic,//竖版纯图3：2
    ADMobGenNativeAdTypeVideoNormal,// 视频广告默认类型
    ADMobGenNativeAdTypeVideoPic,// 视频广告无文字纯图
    ADMobGenNativeAdTypeVideoCenterPic,// 视频广告上文下图
    ADMobGenNativeAdTypeThreePic,//三图
//    ADMobGenNativeAdTypeDoublePic,//双图双文
    
};

typedef NS_ENUM(NSUInteger, ADMobGenNativeAdPlatform) {
    ADMobGenNativeAdPlatformGDT = 0,//广点通
    ADMobGenNativeAdPlatformWM,//头条
    ADMobGenNativeAdPlatformBaidu,//百度
    ADMobGenNativeAdPlatformADMob,//ADMob
    ADMobGenNativeAdPlatformInmobi,//inmobi
    ADMobGenNativeAdPlatformMTG,//mobvsita
    ADMobGenNativeAdPlatformGoogle,//谷歌
    ADMobGenNativeAdPlatformNone,//之前版本
};


#endif /* ADMobGenNativeExpressCommon_h */
