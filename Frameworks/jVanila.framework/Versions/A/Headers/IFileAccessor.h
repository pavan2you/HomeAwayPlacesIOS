//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/jvanila/core/io/IFileAccessor.java
//
//


@class DataObject;

#import "Emulation.h"
#import "IVanilaObject.h"

@protocol IFileAccessor < IVanilaObject, NSObject >
- (void)writeBytesWithNSData:(NSData *)bytesToBeWritten
                           withNSString:(NSString *)fileName
                           withNSString:(NSString *)secretKey;
- (NSData *)readBytesWithNSString:(NSString *)fileName
                           withNSString:(NSString *)secretKey;
- (void)writeWithId:(id)data
       withNSString:(NSString *)fileName
       withNSString:(NSString *)secretKey;
- (id)readWithNSString:(NSString *)fileName
          withNSString:(NSString *)secretKey;
- (void)writeWithDataObject:(DataObject *)object
                                        withNSString:(NSString *)secretKey;
- (DataObject *)readWithClass:(Class )dataObjectClass
                                             withNSString:(NSString *)secretKey;
- (void)writeFileWithNSString:(NSString *)path
                 withNSString:(NSString *)fileName
        withNSData:(NSData *)dataBytes;
- (NSData *)readFileWithNSString:(NSString *)folderPath
                          withNSString:(NSString *)fileName;
- (BOOL)isFileExistsWithNSString:(NSString *)fileName;
- (BOOL)isFileExistsWithNSString:(NSString *)folderPath
                    withNSString:(NSString *)fileName;
- (void)deleteFileWithNSString:(NSString *)absPathToFile;
- (void)deleteFileWithNSString:(NSString *)folderPath
                  withNSString:(NSString *)fileName;
- (void)deleteFolderWithNSString:(NSString *)folder;
- (NSString *)getAbsoluteFilePathWithNSString:(NSString *)folderPath
                                 withNSString:(NSString *)fileName;
- (NSString *)getBase64ImageThumbnailWithNSString:(NSString *)fileName
                                          withInt:(int)w
                                          withInt:(int)h
                                          withInt:(int)compression;
- (long long int)getFileLengthWithNSString:(NSString *)absPathToFile;
@end

#define ComJvanilaCoreIoIFileAccessor IFileAccessor
