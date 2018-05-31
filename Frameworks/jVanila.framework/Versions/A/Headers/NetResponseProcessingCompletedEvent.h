//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/jvanila/mobile/sync/events/NetResponseProcessingCompletedEvent.java
//
//

@class NetRequestStatsDTO;

#import "Emulation.h"
#import "DataObject.h"

@interface NetResponseProcessingCompletedEvent : DataObject {
 @public
  NSString *mRequestType_;
  NSString *mContainedObjectUniqueId_;
  DataObject *mProcessedResultDTO_;
  NetRequestStatsDTO *processingStats_;
}

@property (nonatomic, copy) NSString *mRequestType;
@property (nonatomic, copy) NSString *mContainedObjectUniqueId;
@property (nonatomic, strong) DataObject *mProcessedResultDTO;
@property (nonatomic, strong) NetRequestStatsDTO *processingStats;

+ (NSString *)CLASS_NAME;
- (NSString *)description;
@end

typedef NetResponseProcessingCompletedEvent ComJvanilaMobileSyncEventsNetResponseProcessingCompletedEvent;