//
//  AZNativeCache.h
//  AdZodiac
//
//  Copyright (c) 2014 AdZodiac. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AZNativeCache : NSObject

+ (instancetype)sharedCache;

/*
 * Do NOT call any of the following methods on the main thread, potentially lengthy wait for disk IO
 */
- (BOOL)cachedDataExistsForKey:(NSString *)key;
- (NSData *)retrieveDataForKey:(NSString *)key;
- (void)storeData:(NSData *)data forKey:(NSString *)key;
- (void)removeAllDataFromCache;
- (void)setInMemoryCacheEnabled:(BOOL)enabled;

@end
