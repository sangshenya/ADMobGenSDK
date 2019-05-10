//
//  ADMobGenNativeExpressAdRelatedView.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/3/20.
//

#import <Foundation/Foundation.h>
#import "ADMobGenNativeTool.h"

//左右间隙
#define kLeftSpace 16
//上下间隙
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

- (instancetype)initWithAdDes:(NSString *)adDes adTitle:(NSString *)adTitle adType:(ADMobGenNativeToolType)adType normalSize:(CGSize)normalSize;

@property (nonatomic, strong) UILabel *labTitle;
@property (nonatomic, strong) UILabel *labDes;
@property (nonatomic, strong) UILabel *labAd;
@property (nonatomic, strong) UIButton *closeButton;
@property (nonatomic, strong) UIImage *closeImage;
// 目前支持inmob、mobvsita、admobile、wm的logo获取
+ (UIImage *)getLogoWithAdLabel:(BOOL)hasAdLabel platform:(ADMobGenNativeToolPlatform)platform;

- (void)setCloseAction:(void (^)(void))closeAction;

@end

NS_ASSUME_NONNULL_END
