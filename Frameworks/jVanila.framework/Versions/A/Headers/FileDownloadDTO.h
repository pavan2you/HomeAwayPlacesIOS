//
//  FileDownloadDTO.h
//  jVanila
//
//  Created by Pavan on 11/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "DataObject.h"
#import "IGenericList.h"
#import "ICloneableObject.h"

@interface FileDownloadDTO : DataObject <NSCoding, NSCopying, ICloneableObject>

@property (nonatomic, retain) NSString *CRUDOperation;
@property (nonatomic, retain) NSString *FileName;
@property (nonatomic, retain) NSString *FolderPath;
@property (nonatomic, retain) NSString *Url;
@property (nonatomic, retain) NSString *EnclosedRequestType;
@property (nonatomic, retain) id<IGenericList> HeaderList;
@property (nonatomic, retain) NSData *FileContentBytes;

@end
