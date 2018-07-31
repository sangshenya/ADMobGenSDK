//
//  MCAdNative.h
//  MCAdSDK
//
//  Created by 曹飞 on 2017/7/31.
//  Copyright © 2017年 曹飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 Native advertisement request type
 */
typedef NS_ENUM(NSInteger, MCAdRequestType) {
    MCAdRequestType_BANNER      = 5, // request adver with banner type
    MCAdRequestType_STARTUP     = 6, // request adver with startup type
    MCAdRequestType_INFORMATION = 7  // request adver with information type
};

@protocol MCAdNativeDelegate;

@interface MCAdNative : NSObject

/// Details about the document of the adver
@property (nonatomic, copy) NSString *content;
/// Title of the Adver
@property (nonatomic, copy) NSString *title;
/// Image url of the Adver
@property (nonatomic, copy) NSString *imageUrl;
/// logo url of the adver channel, the default image size is 25*20
@property (nonatomic, copy) NSString *channelLogoUrl;
/// Adver type you needed
@property (nonatomic, assign) MCAdRequestType adRequestType;
/// The delegate to receive callbacks
@property (nonatomic, weak) id<MCAdNativeDelegate> delegate;

- (instancetype)init NS_UNAVAILABLE;

/**
 Init the native adver instance by the type you choose
 
 @param requestType Adver type you needed
 @return native adver instance
 */
- (instancetype)initWithAdRequestType:(MCAdRequestType)requestType;

/**
 Init the native adver instance with the type you choose, and the call back delegate
 
 @param requestType Adver type you needed
 @param delegate The delegate to receive callbacks
 @return native adver instance
 */
- (instancetype)initWithAdRequestType:(MCAdRequestType)requestType delegate:(id<MCAdNativeDelegate>)delegate NS_DESIGNATED_INITIALIZER;

/**
 request a native adver data
 */
- (void)request;

/**
 Register the native adver instance to the rendered view to fire impressions.
 
 @param view The view that has rendered the native ad's content
 */
- (void)registerFroView:(UIView *)view;

/**
 Use this method to stop tracking impressions on a particular view. This method should be called especially when using native ads inside UITableView.
 
 @param view The view on which the impressions should not be tracked anymore
 */
+ (void)unRegisterView:(UIView *)view;

@end

@protocol MCAdNativeDelegate <NSObject>

@required

/**
 Notifies the delegate that the native adver has finished loading
 */
- (void)onNativeAdDidFinishLoading:(MCAdNative *)nativeAd;

@optional

/**
 Notifies the delegate that the native adver has failed to load with error
 */
- (void)onNativeAd:(MCAdNative *)nativeAd didFailToLoadWithError:(NSError *)error;

/**
 Notifies the delegate that the native adver has been clicked
 */
- (void)onNativeAdDidClicked:(MCAdNative *)nativeAd linkUrl:(NSURL *)linkUrl;

/**
 Notifies the delegate that the user will open a new viewcontroller about the adver
 */
- (void)onNativeAdWillPresentAdverViewController:(MCAdNative *)nativeAd;

/**
 Notifies the delegate that the user will cancel a the viewcontroller what's been presented
 */
- (void)onNativeAdDidDismissAdverViewController:(MCAdNative *)nativeAd;

/**
 Notifies the delegate that the user will be taken outside the application context.
 */
- (void)onNativeAdWillLeaveApplication:(MCAdNative *)nativeAd;

@end

