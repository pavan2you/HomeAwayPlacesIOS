//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/jvanila/mobile/sync/INetRequestQueue.java
//
//

@class NetRequestDTO;
@class RemoveNetRequestByQueryDTO;
@protocol IGenericList;

#import "Emulation.h"
#import "IVanilaObject.h"

@protocol INetRequestQueue < IVanilaObject, NSObject >
- (void)loadQueues;
- (void)pauseQueues;
- (void)pauseSyncQ;
- (void)resumeQueues;
- (void)resumeSyncQ;
- (void)processQueues;
- (void)clearQueuesCache;
- (void)clearQueues;
- (void)clearAsyncQ;
- (BOOL)areQueuesPaused;
- (void)addNetRequestWithNetRequestDTO:(NetRequestDTO *)netRequest;
- (void)onRequestCompleteWithNetRequestDTO:(NetRequestDTO *)netRequest;
- (void)onRequestFailureWithNetRequestDTO:(NetRequestDTO *)netRequest;
- (void)onRequestInCompleteWithNetRequestDTO:(NetRequestDTO *)netRequest;
- (BOOL)areQueuesLoaded;
- (void)removeNetRequestByQueryWithRemoveNetRequestByQueryDTO:(RemoveNetRequestByQueryDTO *)queryDTO;
- (void)removeNetRequestsByCRUDOperationWithUnichar:(char)crudOperation;
- (void)removeNetRequestsByNetRequestTypeWithNSString:(NSString *)netRequestType;
- (void)removeNetRequestsByContainedObjectUniqueIdWithNSString:(NSString *)objectUniqueId;
- (void)clearOutgoingRequests;
- (id<IGenericList>)getCUDNetRequestList;
@end

#define ComJvanilaMobileSyncINetRequestQueue INetRequestQueue