//
//  FlurryBannerCustomEvent.h
//  AdZodiac Mediates Flurry
//
//  Created by Flurry.
//  Copyright (c) 2015 Yahoo, Inc. All rights reserved.
//

#import "FlurryAdBannerDelegate.h"
#if __has_include(<MoPub/MoPub.h>)
#import <AdZodiac/AdZodiac.h>
#else
#import "AZBannerCustomEvent.h"
#endif

/*
 * Certified with Flurry 8.2.2
 */
@interface FlurryBannerCustomEvent : AZBannerCustomEvent <FlurryAdBannerDelegate>

@end
