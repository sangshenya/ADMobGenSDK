//
//  ADMobGenNativeTool.h
//  ADMobGenAdapter
//
//  Created by kaifa on 2018/8/13.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ADMobGenPlayerState) {
    ADMobGenPlayerStateInitial = 0,//初始化状态
    ADMobGenPlayerStateBuffering = 1,//缓冲中
    ADMobGenPlayerStatePlaying = 2,//播放中
    ADMobGenPlayerStatePaused = 3,//播放暂停
    ADMobGenPlayerStateStopped = 4,//播放停止
    ADMobGenPlayerStateError = 5,//播放出错
};

typedef NS_ENUM(NSUInteger, ADMobGenNativeToolType) {
    ADMobGenNativeToolTypeNormal = 0,//上图下文，默认为图文，图片尺寸为16：9
    ADMobGenNativeToolTypePic,//纯图片16：9
    ADMobGenNativeToolTypeRightPic,//右图左文3：2
    ADMobGenNativeToolTypeLeftPic,//左图右文3：2
    ADMobGenNativeToolTypeCenterPic,//上文下图16：9
    ADMobGenNativeToolTypeVerticalPic,//竖版纯图3：2
    ADMobGenNativeToolTypeVideoNormal,// 视频广告默认类型
    ADMobGenNativeToolTypeVideoPic,// 视频广告无文字纯图
    ADMobGenNativeToolTypeVideoCenterPic,// 视频广告上文下图
    ADMobGenNativeToolTypeThreePic,//三图
};

typedef NS_ENUM(NSUInteger, ADMobGenNativeToolPlatform) {
    ADMobGenNativeToolPlatformGDT = 0,//广点通
    ADMobGenNativeToolPlatformWM,//头条
    ADMobGenNativeToolPlatformBaidu,//百度
    ADMobGenNativeToolPlatformADMob,//ADMob
    ADMobGenNativeToolPlatformInmobi,//inmobi
    ADMobGenNativeToolPlatformMTG,//mobvsita
    ADMobGenNativeToolPlatformGoogle,//谷歌
    ADMobGenNativeToolPlatformNone,//之前版本
};

@interface ADMobGenNativeTool : NSObject

+ (NSString *)htmlStringWithMainImageurl:(NSString *)imageurl
                                   title:(NSString *)title
                                subTitle:(NSString *)subTitle
                                  adType:(ADMobGenNativeToolType)adType
                                platform:(ADMobGenNativeToolPlatform)platform;

+ (NSString *)htmlStringWithMainImageurlArray:(NSArray *)imageUrlArray
                                   title:(NSString *)title
                                subTitle:(NSString *)subTitle
                                  adType:(ADMobGenNativeToolType)adType
                                platform:(ADMobGenNativeToolPlatform)platform;


@end
