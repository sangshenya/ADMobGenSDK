//
//  ADMobGenNativeExpressAdRelatedView.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/6/21.
//

#import <Foundation/Foundation.h>
#import "ADMobGenNativeExpressCommon.h"

#define kTopSpace 10

//文字之间的间隙
#define kAdOrTestSpace 8

//左图右文、右图左文图片宽高
#define kLeftRightImageWidth 111
#define kLeftRightImageHeight 74

//广告字样label大小
#define kAdWidth 32
#define kAdHeight 18

//关闭按钮
#define kNormalCloseWidth 18
#define kBigCloseWidth 20

//logo
#define kAdLogoScale 0.4
#define kLogoScale 0.72

NS_ASSUME_NONNULL_BEGIN

@interface ADMobGenNativeExpressAdRelatedView : NSObject

- (instancetype)initWithAdDes:(NSString *)adDes adTitle:(NSString *)adTitle adType:(ADMobGenNativeAdType)adType normalSize:(CGSize)normalSize;

@property (nonatomic, strong) UILabel *labTitle;
@property (nonatomic, strong) UILabel *labDes;
@property (nonatomic, strong) UILabel *labAd;
@property (nonatomic, strong) UIButton *closeButton;

- (void)setCloseAction:(void (^)(void))closeAction;

// 目前支持inmob、mobvsita、admobile、wm的logo获取
+ (UIImage *)getLogoWithAdLabel:(BOOL)hasAdLabel platform:(ADMobGenNativeAdPlatform)platform;

- (CGRect)getImageViewFrame;

- (CGSize)getContentSize;

@end

NS_ASSUME_NONNULL_END
