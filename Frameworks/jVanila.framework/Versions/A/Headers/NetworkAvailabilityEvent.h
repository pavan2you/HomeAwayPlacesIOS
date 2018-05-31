//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/jvanila/mobile/sync/events/NetworkAvailabilityEvent.java
//
//

#import "Emulation.h"
#import "DataObject.h"

#define NetworkAvailabilityEvent_NOT_REACHABLE 2
#define NetworkAvailabilityEvent_REACHABLE 1
#define NetworkAvailabilityEvent_TYPE_ETHERNET 9
#define NetworkAvailabilityEvent_TYPE_MOBILE 0
#define NetworkAvailabilityEvent_TYPE_NONE -1
#define NetworkAvailabilityEvent_TYPE_WIFI 1

@interface NetworkAvailabilityEvent : DataObject {
 @public
  int mReachableState_;
  int mNetworkType_;
  NSString *reachabilityLabel_;
}

@property (nonatomic, assign) int mReachableState;
@property (nonatomic, assign) int mNetworkType;
@property (nonatomic, copy) NSString *reachabilityLabel;

+ (NSString *)CLASS_NAME;
+ (int)REACHABLE;
+ (int)NOT_REACHABLE;
+ (int)TYPE_NONE;
+ (int)TYPE_MOBILE;
+ (int)TYPE_WIFI;
+ (int)TYPE_ETHERNET;
- (id)initWithInt:(int)reachableState
     withNSString:(NSString *)reachableLabel
          withInt:(int)connectedNwType;
@end

typedef NetworkAvailabilityEvent ComJvanilaMobileSyncEventsNetworkAvailabilityEvent;