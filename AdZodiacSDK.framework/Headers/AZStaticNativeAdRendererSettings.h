//
//  AZStaticNativeAdRendererSettings.h
//  AdZodiacSDK
//
//  Copyright (c) 2015 AdZodiac. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AZNativeAdRendererSettings.h"
#import "AZNativeAdRenderer.h"

@interface AZStaticNativeAdRendererSettings : NSObject <AZNativeAdRendererSettings>

/**
 * A rendering class that must be a UIView that implements the MPNativeAdRendering protocol.
 * The ad will be rendered to a view of this class type.
 */
@property (nonatomic, assign) Class renderingViewClass;

/**
 * A block that returns the size of the view given a maximum width. This needs to be set when
 * used in conjunction with ad placer classes so the ad placers can correctly size the cells
 * that contain the ads.
 *
 * viewSizeHandler is not used for manual native ad integration. You must set the
 * frame of your manually integrated native ad view.
 */
@property (nonatomic, readwrite, copy) MPNativeViewSizeHandler viewSizeHandler;

@end
