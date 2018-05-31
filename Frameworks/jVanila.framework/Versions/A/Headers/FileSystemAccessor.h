//
//  FileSystemAccessor.h
//  HelloVanila
//
//  Created by Pavan on 01/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "VanilaObject.h"
#import "IFileAccessor.h"

@interface FileSystemAccessor : VanilaObject <IFileAccessor>

+(NSString *)getApplicationDocumentsDirectory;
+(BOOL)addSkipBackupAttributeToItemAtURL:(NSURL *)URL;
+(void)copyFilesFromFolder:(NSString *)sFolder toFolder:(NSString *)dFolder;

@end
