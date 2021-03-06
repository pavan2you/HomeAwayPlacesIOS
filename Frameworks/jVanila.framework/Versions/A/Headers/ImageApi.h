//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/jvanila/mobile/imageloader/ImageApi.java
//
//


@class FileDownloadDTO;
@class ImageFetcherConfig;
@protocol IGenericList;
@protocol IImageFetcher;

#import "Emulation.h"
#import "VanilaObject.h"

@interface ImageApi : VanilaObject {
 @public
  id<IImageFetcher> mFetcher_;
}

@property (nonatomic, strong) id<IImageFetcher> mFetcher;

+ (ImageApi *)sImageApi;
+ (void)setSImageApiWithImageApi:(ImageApi *)sImageApi;
+ (ImageApi *)get;
- (id)init;
- (void)loadFetcherInternal;
- (ImageFetcherConfig *)newConfig ;
- (ImageApi *)withWithImageFetcherConfig:(ImageFetcherConfig *)config;
- (ImageApi *)load__WithNSString:(NSString *)url
                                                   withId:(id)intoImageView;
- (ImageApi *)load__WithFileDownloadDTO:(FileDownloadDTO *)fileDownloadDTO;
- (ImageApi *)updateWithNSString:(NSString *)url
                                    withNSData:(NSData *)withBytes;
- (ImageApi *)pause;
- (ImageApi *)resume;
- (ImageApi *)unload;
- (ImageApi *)destroy;
- (ImageApi *)removeWithIGenericList:(id<IGenericList>)imageUrls
                                                                          withNSString:(NSString *)bgProcessingId;
- (ImageApi *)removeWithNSString:(NSString *)url
                                             withNSString:(NSString *)bgProcessingId;
+ (void)release__;
@end

typedef ImageApi ComJvanilaMobileImageloaderImageApi;
