//
//  AZImageDownloadQueue.h
// 
//  Copyright (c) 2014 AdZodiac. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^MPImageDownloadQueueCompletionBlock)(NSArray *errors);

@interface AZImageDownloadQueue : NSObject

// pass useCachedImage:NO to force download of images. default is YES, cached images will not be re-downloaded
- (void)addDownloadImageURLs:(NSArray *)imageURLs completionBlock:(MPImageDownloadQueueCompletionBlock)completionBlock;
- (void)addDownloadImageURLs:(NSArray *)imageURLs completionBlock:(MPImageDownloadQueueCompletionBlock)completionBlock useCachedImage:(BOOL)useCachedImage;

- (void)cancelAllDownloads;

@end
