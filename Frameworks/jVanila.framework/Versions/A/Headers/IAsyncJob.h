//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/jvanila/mobile/job/IAsyncJob.java
//
//

@class AsyncToken;
@class JobState;
@protocol IAsyncTokenResultCallback;

#import "Emulation.h"
#import "IComparable.h"
#import "IVanilaObject.h"
#import "IPrioritable.h"

@protocol IAsyncJob < IVanilaObject, IPrioritable, IComparable, NSObject >
- (id<IAsyncJob>)thenDoWithIAsyncJob:(id<IAsyncJob>)nextJob;
- (id<IAsyncJob>)getNext;
- (BOOL)hasNext;
- (void)execute;
- (void)finish;
- (void)setIsForegroundJobWithBOOL:(BOOL)isForegroundJob;
- (BOOL)isForegroundJob;
- (void)setIsBgFgJobWithBOOL:(BOOL)isBgFgJob;
- (BOOL)isBgFgJob;
- (void)setIsIOJobWithBOOL:(BOOL)isIOJob;
- (BOOL)isIOJob;
- (void)setIsNetworkJobWithBOOL:(BOOL)isNetworkJob;
- (BOOL)isNetworkJob;
- (void)setDelayWithInt:(int)delay;
- (int)getDelay;
- (void)setPeriodicIntervalWithInt:(int)period;
- (int)getPeriodicInterval;
- (void)setCanExecuteInParallelWithBOOL:(BOOL)parallel;
- (BOOL)canExecuteInParallel;
- (AsyncToken *)post;
- (AsyncToken *)postWithIAsyncTokenResultCallback:(id<IAsyncTokenResultCallback>)callback;
- (AsyncToken *)postCancelled;
- (AsyncToken *)postCancelledWithIAsyncTokenResultCallback:(id<IAsyncTokenResultCallback>)callback;
- (AsyncToken *)getToken;
- (void)cancel;
- (BOOL)isCancelled;
- (BOOL)isFinished;
- (void)setStateWithJobState:(JobState *)state;
- (JobState *)getState;
- (void)setProcessOnThreadWithNSString:(NSString *)threadName;
- (NSString *)getProcessOnThread;
- (NSString *)getNotifyOnThread;
- (void)setNotifyOnThreadWithNSString:(NSString *)jobRouterThreadName;
- (void)setJobFamilyWithNSString:(NSString *)tag;
- (NSString *)getJobFamily;
- (void)setPriorityWithInt:(int)priority;
- (void)setJobIdWithLongInt:(long long int)id_;
- (long long int)getJobId;
- (void)setTagWithId:(id)tag;
- (id)getTag;
- (void)setLogTagWithNSString:(NSString *)logTag;
- (NSString *)getLogTag;
@end

#define ComJvanilaMobileJobIAsyncJob IAsyncJob
