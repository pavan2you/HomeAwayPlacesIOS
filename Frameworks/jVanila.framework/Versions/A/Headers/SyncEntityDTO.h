//
//  SyncEntityDTO.h
//  HelloVanila
//
//  Created by Pavan on 07/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "Emulation.h"
#import "DataObject.h"
#import "ICloneableObject.h"

#define SYNC_MODE_NO_BOUNDS 0
#define SYNC_MODE_IN_BOUND  1
#define SYNC_MODE_OUT_BOUND 2
#define SYNC_MODE_BOUNDED   3

@interface SyncEntityDTO : DataObject <NSCoding, NSCopying, ICloneableObject>

@property (nonatomic, retain) NSString *CRUDOperation;
@property (nonatomic, retain) id<IGenericList> entity_uuid_list;
@property (nonatomic, retain) NSString *entity_uuid;
@property (nonatomic, retain) NSString *entity_type;
@property (nonatomic, retain) NSString *url;
@property (nonatomic, assign) long long int last_synced_datetime;
@property (nonatomic, assign) long long int sync_from_datetime;
@property (nonatomic, assign) long long int sync_to_datetime;
@property (nonatomic, retain) NSString *last_synced_item_uuid;

@property (nonatomic, assign) int sync_mode;
@property (nonatomic, assign) long long int bound_interval;
@property (nonatomic, assign) int limit;

+ (NSString *)CLASS_NAME;

@end

