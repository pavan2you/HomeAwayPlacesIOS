//
//  FileDTO.h
//  jVanila
//
//  Created by pavan on 11/01/17.
//  Copyright © 2017 jVanila. All rights reserved.
//

#import <jVanila/jVanila.h>

@interface FileDTO : DataObject <NSCoding, NSCopying, ICloneableObject>

@property (nonatomic, retain) NSString *CRUDOperation;

@property (nonatomic, retain) NSString *fileName;
@property (nonatomic, retain) NSString *fileUri;
@property (nonatomic, assign) long long int fileSize;
@property (nonatomic, retain) NSString *mimeType;
@property (nonatomic, retain) id<IGenericList> file_list;
@property (nonatomic, assign) long long lastModified;

+ (NSString *)CLASS_NAME;
@end
