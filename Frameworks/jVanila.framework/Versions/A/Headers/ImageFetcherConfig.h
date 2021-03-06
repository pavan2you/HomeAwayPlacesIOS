//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/jvanila/mobile/imageloader/ImageFetcherConfig.java
//
//

#import "Emulation.h"
#import "VanilaObject.h"

#define ImageFetcherConfig_FETCH_POLICY_CACHE 0
#define ImageFetcherConfig_FETCH_POLICY_CACHE_OR_NETWORK 2
#define ImageFetcherConfig_FETCH_POLICY_NETWORK 1

@interface ImageFetcherConfig : VanilaObject {
 @public
  id nativeContext__;
  NSString *cacheDirectory__;
  int placeHolderResId_;
  int fetchPolicy__;
  int imageSize__;
}

@property (nonatomic, strong) id nativeContext_;
@property (nonatomic, copy) NSString *cacheDirectory_;
@property (nonatomic, assign) int placeHolderResId;
@property (nonatomic, assign) int fetchPolicy_;
@property (nonatomic, assign) int imageSize_;

+ (int)FETCH_POLICY_CACHE;
+ (int)FETCH_POLICY_NETWORK;
+ (int)FETCH_POLICY_CACHE_OR_NETWORK;
- (id)init;
- (id)initWithId:(id)nativeContext
    withNSString:(NSString *)cacheDirectory
         withInt:(int)placeHolderResId
         withInt:(int)imageSize
         withInt:(int)fetchPolicy;
- (ImageFetcherConfig *)placeHolderWithInt:(int)resId;
- (ImageFetcherConfig *)cacheDirectoryWithNSString:(NSString *)cacheDirectory;
- (ImageFetcherConfig *)fetchPolicyWithInt:(int)fetchPolicy;
- (ImageFetcherConfig *)imageSizeWithInt:(int)imageSize;
- (ImageFetcherConfig *)nativeContextWithId:(id)nativeContext;
@end

typedef ImageFetcherConfig ComJvanilaMobileImageloaderImageFetcherConfig;
