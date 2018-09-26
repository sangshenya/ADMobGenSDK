//
//  WMVideoAdView.h
//  WMAdSDK
//
//  Created by gdp on 2017/12/21.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WMPlayer.h"
#import "WMMaterialMeta.h"

NS_ASSUME_NONNULL_BEGIN

/**
 控制网盟视频播放器
 */
@protocol WMVideoEngine <NSObject>

/**
 开始播放
 */
- (void)play;

/**
 暂停播放
 */
- (void)pause;

/**
 获取当前已播放时间
 */
- (CGFloat)currentPlayTime;

/**
 设置是否静音
 */
- (void)setMute:(Boolean)isMute;

@end

@protocol WMVideoAdViewDelegate;

@interface WMVideoAdView : UIView<WMPlayerDelegate, WMVideoEngine>

@property (nonatomic, weak, nullable) id<WMVideoAdViewDelegate> delegate;

/**
 materialMeta 物料信息
 */
@property (nonatomic, strong, readwrite, nullable) WMMaterialMeta *materialMeta;
@property (nonatomic, assign) BOOL isCellVideo;

- (instancetype)initWithMaterial:(WMMaterialMeta *)materialMeta;

@end

@protocol WMVideoAdViewDelegate <NSObject>

@optional
/**
 videoAdView 加载失败

 @param videoAdView 当前展示的 videoAdView 视图
 @param error 错误原因
 */
- (void)videoAdView:(WMVideoAdView *)videoAdView didLoadFailWithError:(NSError *_Nullable)error;

/**
 videoAdView 播放状态改变

 @param videoAdView 当前展示的 videoAdView 视图
 @param playerState 当前播放完成
 */
- (void)videoAdView:(WMVideoAdView *)videoAdView stateDidChanged:(WMPlayerPlayState)playerState;

/**
 videoAdView 播放结束

 @param videoAdView 当前展示的 videoAdView 视图
 */
- (void)playerDidPlayFinish:(WMVideoAdView *)videoAdView;
@end

NS_ASSUME_NONNULL_END
