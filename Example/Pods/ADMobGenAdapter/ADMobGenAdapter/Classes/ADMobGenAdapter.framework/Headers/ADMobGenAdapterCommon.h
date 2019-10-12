//
//  ADMobGenAdapterCommon.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/8/6.
//

#ifndef ADMobGenAdapterCommon_h
#define ADMobGenAdapterCommon_h
#import <objc/runtime.h>

typedef NS_ENUM(NSInteger, ADMobGenPlayerState) {
    ADMobGenPlayerStateInitial = 0,//初始化状态
    ADMobGenPlayerStateBuffering = 1,//缓冲中
    ADMobGenPlayerStatePlaying = 2,//播放中
    ADMobGenPlayerStatePaused = 3,//播放暂停
    ADMobGenPlayerStateStopped = 4,//播放停止
    ADMobGenPlayerStateError = 5,//播放出错
    ADMobGenPlayerStateFinish = 6,//播放完成
};

typedef NS_ENUM(NSUInteger, ADMobGenAdPlatform) {
    ADMobGenAdPlatformGDT = 0,//广点通
    ADMobGenAdPlatformWM,//头条
    ADMobGenAdPlatformBaidu,//百度
    ADMobGenAdPlatformADMob,//ADMob
    ADMobGenAdPlatformInmobi,//inmobi
    ADMobGenAdPlatformMTG,//mobvsita
    ADMobGenAdPlatformGoogle,//谷歌
    ADMobGenAdPlatformMGTV,//芒果tv
    ADMobGenAdPlatformNone,//之前版本
};

#endif /* ADMobGenAdapterCommon_h */
