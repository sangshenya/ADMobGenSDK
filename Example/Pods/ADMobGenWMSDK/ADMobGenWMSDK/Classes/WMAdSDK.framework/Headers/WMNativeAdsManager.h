//
//  WMNativeAdsManager.h
//  WMAdSDK
//
//  Created by chenren on 24/05/2017.
//  Copyright © 2017 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "WMAdSlot.h"
#import "WMMaterialMeta.h"
#import "WMNativeAd.h"

@protocol WMNativeAdsManagerDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface WMNativeAdsManager : NSObject

@property (nonatomic, strong, nullable) WMAdSlot *adslot;
@property (nonatomic, strong, nullable) NSArray<WMMaterialMeta *> *data;
@property (nonatomic, weak, nullable) id<WMNativeAdsManagerDelegate> delegate;

- (instancetype)initWithSlot:(WMAdSlot * _Nullable) slot;

- (void)registerTableView:(UITableView *)tableView
                 delegate:(id<WMNativeAdsManagerDelegate> )delegate;

- (void)unregisterTableView;

- (void)loadAdData;


/**
 请求广告素材数量， 建议不超过 3个左右
 最多不操过10个一次
 @param count 最多广告返回的广告素材的数量
 */
- (void)loadAdDataWithCount:(NSInteger)count;

@end

@protocol WMNativeAdsManagerDelegate <NSObject>

@optional

- (void)nativeAdsManagerDidLoad:(NSArray<WMMaterialMeta *> *_Nullable)nativeAd;

- (void)nativeAdsManager:(WMNativeAdsManager *)adsManager didFailWithError:(NSError *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
