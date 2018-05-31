//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/jvanila/mobile/job/AsyncToken.java
//
//

@protocol IAsyncJob;
@protocol IAsyncTokenResultCallback;
@protocol IGenericList;

#import "Emulation.h"
#import "DataObject.h"

@interface AsyncToken : DataObject {
 @public
  NSString *tokenUuid_;
  id<IAsyncJob> job_;
  id result_;
  id hook_;
  id<IGenericList> callbacks_;
}

@property (nonatomic, copy) NSString *tokenUuid;
@property (nonatomic, strong) id<IAsyncJob> job;
@property (nonatomic, strong) id result;
@property (nonatomic, strong) id hook;
@property (nonatomic, strong) id<IGenericList> callbacks;

+ (NSString *)CLASS_NAME;
- (id)init;
- (void)addCallbackWithIAsyncTokenResultCallback:(id<IAsyncTokenResultCallback>)callback;
- (void)removeCallbackWithIAsyncTokenResultCallback:(id<IAsyncTokenResultCallback>)callback;
- (void)setResultWithId:(id)result;
- (BOOL)isEqual:(id)o;
- (NSUInteger)hash;
@end

typedef AsyncToken ComJvanilaMobileJobAsyncToken;