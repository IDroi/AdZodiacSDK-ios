//
//  AZURLActionInfo.h
//  AdZodiac
//
//  Copyright (c) 2015 AdZodiac. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "AZEnhancedDeeplinkRequest.h"

#ifndef NS_ENUM
#define NS_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
#endif

typedef NS_ENUM(NSUInteger, MPURLActionType) {
    MPURLActionTypeStoreKit,
    MPURLActionTypeGenericDeeplink,
    MPURLActionTypeEnhancedDeeplink,
    MPURLActionTypeOpenInSafari,
    MPURLActionTypeOpenURLInWebView,
    MPURLActionTypeOpenInWebView,
    MPURLActionTypeShare
};

@interface AZURLActionInfo : NSObject

@property (nonatomic, readonly) MPURLActionType actionType;
@property (nonatomic, readonly, copy) NSURL *originalURL;
@property (nonatomic, readonly, copy) NSString *iTunesItemIdentifier;
@property (nonatomic, readonly, copy) NSURL *iTunesStoreFallbackURL;
@property (nonatomic, readonly, copy) NSURL *safariDestinationURL;
@property (nonatomic, readonly, copy) NSString *HTTPResponseString;
@property (nonatomic, readonly, copy) NSURL *webViewBaseURL;
@property (nonatomic, readonly, copy) NSURL *deeplinkURL;
@property (nonatomic, readonly, strong) AZEnhancedDeeplinkRequest *enhancedDeeplinkRequest;
@property (nonatomic, readonly, copy) NSURL *shareURL;

+ (instancetype)infoWithURL:(NSURL *)URL iTunesItemIdentifier:(NSString *)identifier iTunesStoreFallbackURL:(NSURL *)URL;
+ (instancetype)infoWithURL:(NSURL *)URL safariDestinationURL:(NSURL *)safariDestinationURL;
+ (instancetype)infoWithURL:(NSURL *)URL HTTPResponseString:(NSString *)responseString webViewBaseURL:(NSURL *)baseURL;
+ (instancetype)infoWithURL:(NSURL *)URL webViewBaseURL:(NSURL *)baseURL;
+ (instancetype)infoWithURL:(NSURL *)URL deeplinkURL:(NSURL *)deeplinkURL;
+ (instancetype)infoWithURL:(NSURL *)URL enhancedDeeplinkRequest:(AZEnhancedDeeplinkRequest *)request;
+ (instancetype)infoWithURL:(NSURL *)URL shareURL:(NSURL *)shareURL;

@end
