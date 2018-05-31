//
//  SyncStatsDTO.h
//  jVanila
//
//  Created by Pavan on 11/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "DataObject.h"

@interface SyncStatsDTO : DataObject

@property (nonatomic, retain) NSString *statUuid;
@property (nonatomic, retain) NSString *endPoint;
@property (nonatomic, retain) NSString *entityUuid;
@property (nonatomic, assign) long long int syncFromDateTime;
@property (nonatomic, assign) long long int syncToDateTime;
@property (nonatomic, assign) long long int lastSyncDateTime;
@property (nonatomic, retain) NSString *lastSyncedItemUuid;

@property (nonatomic, retain) NSString *CRUDOperation;


@end
