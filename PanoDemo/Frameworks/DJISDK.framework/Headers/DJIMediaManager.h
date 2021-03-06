//
//  DJIMediaManager.h
//  DJISDK
//
//  Copyright © 2015, DJI. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DJIMedia;

/*********************************************************************************/
#pragma mark - DJIMediaManager
/*********************************************************************************/

/**
 *  The media manager is used to interact with the file system on the SD card.
 *  By using the media manager, the user can get the metadata for all the multimedia
 *  files, and has access to each individual multimedia file.
 */
@interface DJIMediaManager : NSObject

/**
 *  Fetch the media list from the remote album. Set the camera's work mode to `DJICameraModeMediaDownload` before executing this method.
 *
 *  @param block Remote execute result. Objects in mediaList are kind of class DJIMedia.
 */
- (void)fetchMediaListWithCompletion:(void (^_Nonnull)(NSArray<DJIMedia *> *_Nullable mediaList, NSError *_Nullable error))block;

/**
 *  Delete media files from remote album. Set the camera's work mode to `DJICameraModeMediaDownload` before executing this method. Deletion is not supported by the media file generated by a panorama mission.
 *
 *  @param media  Media files to be deleted.
 *  @param block  The remote execution result. 'deleteFailures' will contain media that failed to delete.
 */
- (void)deleteMedia:(NSArray<DJIMedia *> *_Nonnull)media withCompletion:(void (^_Nullable)(NSArray<DJIMedia *> *_Nonnull deleteFailures, NSError *_Nullable error))block;

@end

NS_ASSUME_NONNULL_END