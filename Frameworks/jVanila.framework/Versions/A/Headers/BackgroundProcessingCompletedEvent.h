//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/jvanila/mobile/sync/events/BackgroundProcessingCompletedEvent.java
//
//

#import "Emulation.h"
#import "DataObject.h"

@interface BackgroundProcessingCompletedEvent : DataObject {
 @public
  NSString *bgProcessingId_;
  id result_;
}

@property (nonatomic, copy) NSString *bgProcessingId;
@property (nonatomic, strong) id result;

+ (NSString *)CLASS_NAME;
- (id)initWithNSString:(NSString *)bgProcessingId
                withId:(id)result;
- (NSString *)description;
@end

typedef BackgroundProcessingCompletedEvent ComJvanilaMobileSyncEventsBackgroundProcessingCompletedEvent;
