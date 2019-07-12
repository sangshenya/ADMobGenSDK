//
//  ADMobileAdNative.h
//  ADMobileAdSDK
//
//  Created by 陈坤 on 2019/3/5.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 Native advertisement request type
 */
typedef NS_ENUM(NSInteger, ADMobileAdRequestType) {
    ADMobileAdRequestType_BANNER      = 5, // request adver with banner type
    ADMobileAdRequestType_STARTUP     = 6, // request adver with startup type
    ADMobileAdRequestType_INFORMATION = 7  // request adver with information type
};

@protocol ADMobileAdNativeDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface ADMobileAdNative : NSObject

/// Details about the document of the adver
@property (nonatomic, copy) NSString *content;
/// Title of the Adver
@property (nonatomic, copy) NSString *title;
/// Image url of the Adver
@property (nonatomic, copy) NSString *imageUrl;
/// logo url of the adver channel, the default image size is 25*20
@property (nonatomic, copy) NSString *channelLogoUrl;
/// Adver type you needed
@property (nonatomic, assign) ADMobileAdRequestType adRequestType;
/// The delegate to receive callbacks
@property (nonatomic, weak) id<ADMobileAdNativeDelegate> delegate;
/// Image url List of the Adver
@property (nonatomic, copy) NSArray<NSString *> *imageUrlList;

- (instancetype)init NS_UNAVAILABLE;

/**
 Init the native adver instance with the type you choose, and the call back delegate
 
 @param requestType Adver type you needed
 @param delegate The delegate to receive callbacks
 @return native adver instance
 */
- (instancetype)initWithAdRequestType:(ADMobileAdRequestType)requestType delegate:(id<ADMobileAdNativeDelegate>)delegate;

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

 */
- (void)unRegisterView;

/**
 Use this method to stop tracking impressions on a particular view. This method should be called especially when using native ads inside UITableView.
 
 @param view The view on which the impressions should not be tracked anymore
 */
+ (void)unRegisterView:(UIView *)view;

@end

@protocol ADMobileAdNativeDelegate <NSObject>

@required

/**
 Notifies the delegate that the native adver has finished loading
 */
- (void)onNativeAdDidFinishLoading:(ADMobileAdNative *)nativeAd;

@optional

/**
 Notifies the delegate that the native adver has failed to load with error
 */
- (void)onNativeAd:(ADMobileAdNative *)nativeAd didFailToLoadWithError:(NSError *)error;

/**
 Notifies the delegate that the native adver has been exposure
 */
- (void)onNativeAdDidExposure:(ADMobileAdNative *)nativeAd;

/**
 Notifies the delegate that the native adver has been clicked
 */
- (void)onNativeAdDidClicked:(ADMobileAdNative *)nativeAd linkUrl:(NSURL *)linkUrl;

/**
 Notifies the delegate that the user will open a new viewcontroller about the adver
 */
- (void)onNativeAdWillPresentAdverViewController:(ADMobileAdNative *)nativeAd;

/**
 Notifies the delegate that the user will cancel a the viewcontroller what's been presented
 */
- (void)onNativeAdDidDismissAdverViewController:(ADMobileAdNative *)nativeAd;

/**
 Notifies the delegate that the user will be taken outside the application context.
 */
- (void)onNativeAdWillLeaveApplication:(ADMobileAdNative *)nativeAd;

@end

NS_ASSUME_NONNULL_END
