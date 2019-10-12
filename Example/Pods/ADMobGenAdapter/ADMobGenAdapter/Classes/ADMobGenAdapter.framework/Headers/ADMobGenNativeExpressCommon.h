//
//  ADMobGenNativeExpressCommon.h
//  ADMobGenAdapter
//
//  Created by 陈坤 on 2019/6/15.
//

#ifndef ADMobGenNativeExpressCommon_h
#define ADMobGenNativeExpressCommon_h


typedef NS_ENUM(NSUInteger, ADMobGenNativeAdType) {
    ADMobGenNativeAdTypeNormal = 0,//上图下文，默认为图文，图片尺寸为16：9
    ADMobGenNativeAdTypePic,//纯图片16：9
    ADMobGenNativeAdTypeRightPic,//右图左文3：2
    ADMobGenNativeAdTypeLeftPic,//左图右文3：2
    ADMobGenNativeAdTypeCenterPic,//上文下图16：9
    ADMobGenNativeAdTypeVerticalPic,//竖版纯图3：2
    ADMobGenNativeAdTypeThreePic,//三图
    ADMobGenNativeAdTypeDoublePic,//双图双文
    
};


#endif /* ADMobGenNativeExpressCommon_h */
