//
//  ADMobGenBannerAdView.h
//  ADMobGenAdapter
//
//  Created by 曹飞 on 2018/7/26.
//

#import <UIKit/UIKit.h>

@interface ADMobGenBannerAdView : UIView

/**
 填充视图
 */
@property (nonatomic, readonly, strong) UIImageView *mainImgv;

/**
 设置广告内容点击回调事件
 */
- (void)setAdClicked:(void (^)(void))clickBlock;

@end
