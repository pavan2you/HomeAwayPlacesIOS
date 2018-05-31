//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/jvanila/mobile/imageloader/IImageFetcher.java
//
//


@class FileDownloadDTO;
@class ImageFetcherConfig;
@protocol IGenericList;

#import "Emulation.h"
#import "IVanilaObject.h"

@protocol IImageFetcher < IVanilaObject, NSObject >
- (id<IImageFetcher>)loadWithWithImageFetcherConfig:(ImageFetcherConfig *)config;
- (id<IImageFetcher>)unloadCache;
- (id<IImageFetcher>)destroyCache;
- (id<IImageFetcher>)setPauseLoadingWithBOOL:(BOOL)pause;
- (id<IImageFetcher>)loadImageWithFileDownloadDTO:(FileDownloadDTO *)fileDownloadDTO;
- (id<IImageFetcher>)loadImageWithId:(id)nativeImageObject
                                                 withNSString:(NSString *)imageUrl;
- (id<IImageFetcher>)updateImageWithNSString:(NSString *)url
                                                withNSData:(NSData *)bytes;
- (id<IImageFetcher>)removeWithIGenericList:(id<IGenericList>)imageUrls
                                                                                 withNSString:(NSString *)bgProcessingId;
@end

#define ComJvanilaMobileImageloaderIImageFetcher IImageFetcher
