//
//  SyncEntitiesDTO.h
//  jVanila
//
//  Created by Pavan on 11/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "DataObject.h"
#import "IGenericList.h"

@interface SyncEntitiesDTO : DataObject <NSCoding>

@property (nonatomic, retain) NSString *CRUDOperation;

@property (nonatomic, retain) id<IGenericList> entity_list;
@property (nonatomic, assign) long long int last_synced_datetime;
@property (nonatomic, assign) long long int polling_interval;

@end
