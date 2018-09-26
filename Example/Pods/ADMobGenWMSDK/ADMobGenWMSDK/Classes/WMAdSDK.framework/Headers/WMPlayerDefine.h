//
//  WMPlayerDefine.h
//  WMAdSDK
//
//  Created by carl on 2017/12/24.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 * 播放器种状态
 */
typedef NS_ENUM(NSInteger, WMPlayerPlayState) {
    WMPlayerStateFailed    = 0,  // 播放失败
    WMPlayerStateBuffering = 1,  // 缓冲中
    WMPlayerStatePlaying   = 2,  // 播放中
    WMPlayerStateStopped   = 3,  // 停止播放
    WMPlayerStatePause     = 4   // 暂停播放
};

/**
 * playerLayer的填充模式
 */
typedef NS_ENUM(NSInteger, WMPlayerLayerGravity) {
    WMPlayerLayerGravityResize,           // 非均匀模式。两个维度完全填充至整个视图区域
    WMPlayerLayerGravityResizeAspect,     // 等比例填充，直到一个维度到达区域边界
    WMPlayerLayerGravityResizeAspectFill  // 等比例填充，直到填充满整个视图区域，其中一个维度的部分区域会被裁剪
};

/**
 * 手势交互操作
 */
typedef NS_OPTIONS(NSInteger, WMPlayerGestureOption) {
    WMPlayerGestureOptionNone              = 0,
    WMPlayerGestureOptionVolumeEnabled     = 1 << 0,
    WMPlayerGestureOptionBrightnessEnabled = 1 << 1,
    WMPlayerGestureOptionFastSkipEnabled   = 1 << 2,
    WMPlayerGestureOptionSigleTapEnabled   = 1 << 3,
    WMPlayerGestureOptionDoubleTapEnabled  = 1 << 4,
};
/**
 * 默认的控制视图或完成视图的元素
 */
typedef NS_OPTIONS(NSInteger, WMPlayerDefaultControlElement) {
    WMPlayerControlElementNone     = 0,
    WMPlayerControlElementTop      = 1 << 0,
    WMPlayerControlElementBottom   = 1 << 1,
    WMPlayerControlElementActivity = 1 << 2,
    WMPlayerControlElementFailHint = 1 << 3,
    WMPlayerControlElementProgress = 1 << 4,
    WMPlayerControlElementPlay     = 1 << 5,
    WMPlayerControlElementReplay   = 1 << 6,
};

@protocol WMPlayerControlViewProtocol <NSObject>

/**
 * 设置默认控制视图或完成视图的元素组合方式
 * 默认显示全部
 */
- (void)setPlayerDefaultControlElement:(WMPlayerDefaultControlElement)element;
/**
 * 获取播放完成视图容器
 * 若需自定义可先移除WMPlayerControlElementReplay,再添加自定义视图
 */
- (UIView *)finishedContainer;

@end
