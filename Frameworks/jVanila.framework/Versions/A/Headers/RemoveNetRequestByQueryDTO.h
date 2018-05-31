//
//  RemoveNetRequestByQueryDTO.h
//  jVanila
//
//  Created by pavan on 16/10/17.
//  Copyright © 2017 jVanila. All rights reserved.
//

#import <jVanila/jVanila.h>

@interface RemoveNetRequestByQueryDTO : DataObject <NSCoding, NSCopying, ICloneableObject>

+(NSString *) CLASS_NAME;

@property (nonatomic, retain) NSString *CRUDOperation;

@property (nonatomic, retain) NSString *queryUuid;
@property (nonatomic, retain) NSString *byCrudOperation;
@property (nonatomic, retain) NSString *byNetRequestType;
@property (nonatomic, retain) NSString *byContainedObjectUuid;
@property (nonatomic, assign) BOOL onCompletePauseQs;
@property (nonatomic, assign) BOOL onCompletePauseSyncQ;

@end
