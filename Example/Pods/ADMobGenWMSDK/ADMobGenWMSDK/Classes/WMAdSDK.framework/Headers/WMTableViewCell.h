//
//  WMTableViewCell.h
//  WMAdSDK
//
//  Created by chenren on 26/05/2017.
//  Copyright © 2017 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WMMaterialMeta.h"

@protocol WMTableViewCellDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface WMTableViewCell : UITableViewCell

@property (nonatomic, weak, nullable) id<WMTableViewCellDelegate> delegate;

/**
 materialMeta 物料信息
 */
@property (nonatomic, strong, readwrite, nullable) WMMaterialMeta *materialMeta;

/**
 dislike 按钮懒加载，需要主动添加到 View，处理 materialMeta.filterWords反馈
         提高广告信息推荐精度
 */
@property (nonatomic, strong, readonly, nullable) UIButton *dislikeButton;

/**
 adLabel 推广标签懒加载， 需要主动添加到 View
 */
@property (nonatomic, strong, readonly, nullable) UILabel *adLabel;

/**
 logoImageView 网盟广告标识，需要主动添加到 View
 */
@property (nonatomic, strong) UIImageView *logoImageView;

- (void)registerViewForInteraction:(UIView *)view
                          delegate:(id<WMTableViewCellDelegate>)delegate;

- (void)registerViewForInteraction:(UIView *)view
               withInteractionType:(WMInteractionType)interactionType
                          delegate:(id<WMTableViewCellDelegate>)delegate;

- (void)registerViewForInteraction:(UIView *)view
                          delegate:(id<WMTableViewCellDelegate>)delegate
                withClickableViews:(NSArray<UIView *> *_Nullable)clickableViews;

- (void)registerViewForCustomInteraction:(UIView *)view
                                delegate:(id<WMTableViewCellDelegate>)delegate;

- (void)didSelectWithDelegate:(id<WMTableViewCellDelegate>)delegate;
- (void)dislikeAction:(id)sender;
@end


@protocol WMTableViewCellDelegate <NSObject>

@optional

/**
 当前Cell被点击

 @param cell 当前的Cell
 @param view 被点击的视图
 */
- (void)wmTableViewCellDidClick:(WMTableViewCell *)cell withView:(UIView *_Nullable)view;

/**
 当前Cell首次展示
 @param cell 当前的Cell
 */
- (void)wmTableViewCellDidBecomeVisible:(WMTableViewCell *)cell;

/**
 用户点击 dislike功能
 @param cell 当前的Cell
 @param filterWords 不喜欢的原因， 可能为空
 */
- (void)wmTableViewCell:(WMTableViewCell *)cell  dislikeWithReason:(NSArray<WMDislikeWords *> *)filterWords;
@end

NS_ASSUME_NONNULL_END
