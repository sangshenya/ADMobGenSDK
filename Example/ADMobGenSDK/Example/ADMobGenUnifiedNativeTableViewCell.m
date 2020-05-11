//
//  ADMobGenUnifiedNativeTableViewCell.m
//  ADMobGenSDK_Example
//
//  Created by 陶冶明 on 2019/11/6.
//  Copyright © 2019 1594717129@qq.com. All rights reserved.
//

#import "ADMobGenUnifiedNativeTableViewCell.h"

@implementation ADMobGenUnifiedNativeTableViewCell

- (void)setAdView:(UIView *)adView {
    if(_adView.superview == self)
        [_adView removeFromSuperview];
    _adView = adView;
    [self.contentView addSubview:_adView];
}

- (void)layoutSubviews {
    _adView.frame = self.bounds;
}



@end
