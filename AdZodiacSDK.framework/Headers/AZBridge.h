//
//  AZBridge.h
//  AdZodiacSDK
//
//  Copyright (c) 2014 AdZodiac. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MRConstants.h"
#import "AZWebView.h"

@class MRProperty;
@protocol MRBridgeDelegate;

/**
 * The `MRBridge` class is an intermediate object between native code and JavaScript for
 * MRAID ads. The MRAID web view communicates events to `MRBridge` which translates them
 * down to native code. Likewise, native code will communicate with `MRBridge` to execute
 * commands inside the JavaScript. `MRBridge` also inserts mraid.js into the web view when
 * loading an ad's HTML.
 */
@interface AZBridge : NSObject

@property (nonatomic, assign) BOOL shouldHandleRequests;
@property (nonatomic, weak) id<MRBridgeDelegate> delegate;

- (instancetype)initWithWebView:(AZWebView *)webView;

- (void)loadHTMLString:(NSString *)HTML baseURL:(NSURL *)baseURL;

- (void)fireReadyEvent;
- (void)fireChangeEventForProperty:(MRProperty *)property;
- (void)fireChangeEventsForProperties:(NSArray *)properties;
- (void)fireErrorEventForAction:(NSString *)action withMessage:(NSString *)message;

/*
 * fireSizeChangeEvent: will always execute the javascript to notify mraid bridge that the size of the ad may have
 * changed. mraid.js will only fire the change event if the size has actually changed.
 */
- (void)fireSizeChangeEvent:(CGSize)size;

- (void)fireSetScreenSize:(CGSize)size;
- (void)fireSetPlacementType:(NSString *)placementType;
- (void)fireSetCurrentPositionWithPositionRect:(CGRect)positionRect;
- (void)fireSetDefaultPositionWithPositionRect:(CGRect)positionRect;
- (void)fireSetMaxSize:(CGSize)maxSize;

@end

/**
 * The delegate of an `MRBridge` object that implements `MRBridgeDelegate` must provide information
 * about the state of an MRAID ad through `isLoadingAd` and `hasUserInteractedWithWebView` so `MRBridge`
 * can correctly process web view events. The delegate will be notified of specific events that need
 * to be handled natively for an MRAID ad. The delegate is also notified of most web view events so it
 * can perform necessary actions such as changing the ad's state.
 */
@protocol MRBridgeDelegate <NSObject>

- (BOOL)isLoadingAd;
- (MRAdViewPlacementType)placementType;
- (BOOL)hasUserInteractedWithWebViewForBridge:(AZBridge *)bridge;
- (UIViewController *)viewControllerForPresentingModalView;

- (void)nativeCommandWillPresentModalView;
- (void)nativeCommandDidDismissModalView;

- (void)bridge:(AZBridge *)bridge didFinishLoadingWebView:(AZWebView *)webView;
- (void)bridge:(AZBridge *)bridge didFailLoadingWebView:(AZWebView *)webView error:(NSError *)error;

- (void)handleNativeCommandCloseWithBridge:(AZBridge *)bridge;
- (void)bridge:(AZBridge *)bridge performActionForMoPubSpecificURL:(NSURL *)url;
- (void)bridge:(AZBridge *)bridge handleDisplayForDestinationURL:(NSURL *)URL;
- (void)bridge:(AZBridge *)bridge handleNativeCommandUseCustomClose:(BOOL)useCustomClose;
- (void)bridge:(AZBridge *)bridge handleNativeCommandSetOrientationPropertiesWithForceOrientationMask:(UIInterfaceOrientationMask)forceOrientationMask;
- (void)bridge:(AZBridge *)bridge handleNativeCommandExpandWithURL:(NSURL *)url useCustomClose:(BOOL)useCustomClose;
- (void)bridge:(AZBridge *)bridge handleNativeCommandResizeWithParameters:(NSDictionary *)parameters;

@end
