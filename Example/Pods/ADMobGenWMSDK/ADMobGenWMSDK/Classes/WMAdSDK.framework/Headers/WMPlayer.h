//
//  WMPlayer.h
//  WMAdSDK
//
//  Created by hlw on 2017/12/21.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WMPlayerItem.h"
#import "WMPlayerDefine.h"

@class WMPlayer;

@protocol WMPlayerDelegate <NSObject>

@optional
/**
 * 播放器状态改变
 */
- (void)player:(WMPlayer *)player stateDidChanged:(WMPlayerPlayState)playerState;
/**
 * 播放器准备完成
 */
- (void)playerReadyToPlay:(WMPlayer *)player;
/**
 * 播放完成或者发生错误
 */
- (void)playerDidPlayFinish:(WMPlayer *)player error:(NSError *)error;

/**
 * 播放器上识别的点击事件
 */
- (void)player:(WMPlayer *)player recognizeTapGesture:(UITapGestureRecognizer *)gesture;


/**
 * 播放器播放过程中视图被点击
 */
- (void)playerTouchesBegan:(WMPlayer *)player;

@end

@interface WMPlayer : NSObject

@property (nonatomic, weak) id<WMPlayerDelegate> delegate;

/**
 * 播放内容视图
 */
@property (nonatomic, strong, readonly) UIView *view;

/**
 * 播放器状态
 * 支持KVO
 */
@property (nonatomic, assign, readonly) WMPlayerPlayState state;

/**
 * 播放资源总时长
 */
@property (nonatomic, assign, readonly) NSTimeInterval duration;

/**
 * 当前可播放时长
 */
@property (nonatomic, assign, readonly) NSTimeInterval playableDuration;

/**
 * 实际观看时长
 */
@property (nonatomic, assign, readonly) NSTimeInterval watchedDuration;

/**
 * 当前播放时间
 */
@property (nonatomic, assign, readonly) CGFloat currentPlayTime;

/**
 * 当前播放资源Item
 */
@property (nonatomic, strong, readonly) WMPlayerItem *currentPlayerItem;

/**
 * 播放器控制层容器,默认视图支持部分定制或完全自定义
 * 默认显示控制层全部元素,可以定制部分视图元素显示/隐藏
 * 若完全自定义,需先隐藏全部默认视图元素 再在容器上添加自定义视图
 */
@property (nonatomic, strong, readonly) UIView<WMPlayerControlViewProtocol> *controlContainer;

/**
 * 播放内容视图填充方式
 * 默认：等比例填充，直到一个维度到达区域边界
 */
@property (nonatomic, assign) WMPlayerLayerGravity playerLayerGravity;

/**
 * 播放视图上手势操作选项开关
 * 默认全开
 */
@property (nonatomic, assign) WMPlayerGestureOption option;

/**
 * 静音设置
 */
@property (nonatomic, assign) BOOL mute;

/**
 * 当前是否全屏显示
 */
@property (nonatomic, assign, readonly) BOOL isFullScreen;

/** 设置自定义ControlView */
@property (nonatomic, strong) UIView *controlView;

/**
 * 支持自动转屏,默认NO
 */
@property (nonatomic, assign) BOOL shouldAutoRotate;

+ (instancetype)playerWithPlayerItem:(WMPlayerItem *)item;

- (void)replaceCurrentItemWithPlayerItem:(WMPlayerItem *)item;

- (instancetype)initWithPlayerItem:(WMPlayerItem *)item NS_DESIGNATED_INITIALIZER;

@end

@interface WMPlayer (WMPlayerControl)

/**
 * 播放
 */
- (void)play;

/**
 * 暂停
 */
- (void)pause;

/**
 * 重播
 */
- (void)replay;

/**
 * 停止
 */
- (void)stop;

/**
 * 跳到指定时间播放
 */
- (void)seekToTime:(NSInteger)time completion:(void(^)(BOOL success))completion;

/**
 * 全屏/竖屏 切换显示
 */
- (void)changeOrientationScreen;


/**
 * 处于后台模式
 */
- (BOOL)isEnterBackground;

@end
