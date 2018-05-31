//
//  SyncStatsDAO.h
//  jVanila
//
//  Created by Pavan on 11/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "SqliteDataAccessObject.h"
#import "IGenericList.h"
#import "ISyncStatsDAO.h"

@class SyncStatsDTO;

@interface SyncStatsDAO : SqliteDataAccessObject <ISyncStatsDAO>

-(int)createRecordWithSyncStatsDTO:(SyncStatsDTO *)dto;
-(int)updateRecordWithSyncStatsDTO:(SyncStatsDTO *)dto;
-(int)deleteSyncStatsByIdWithNSString:(NSString *)primaryKey;
-(int)deleteAll;

-(SyncStatsDTO *)getRecordWithNSString:(NSString *)primaryKey;
-(id<IGenericList>)getAllRecords;
-(int)getRecordSize;
-(SyncStatsDTO *)getRecordByEntityUuidWithNSString:(NSString *)entity_uuid withNSString:(NSString *)entityClass;

@end
