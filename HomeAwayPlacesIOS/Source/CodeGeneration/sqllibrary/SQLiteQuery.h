//
//  SQLiteQuery.h
//  FalconParent
//
//  Created by pavan on 04/10/17.
//  Copyright © 2017 Purnatva. All rights reserved.
//

@class GetRecordListAsync;
@class GetRecordAsync;
@class GetCountAsync;
@class ExecuteAsync;

#import <Foundation/Foundation.h>
#import <jVanila/jVanila.h>
#import "ToDataObjectConverter.h"

@interface SQLiteQuery : NSObject {
    sqlite3 *sqlDB;
    const char* queryToProcess;
}

-(id)initWith:(sqlite3*)database withQuery:(const char *)query withToDataObjectConverter:(id<ToDataObjectConverter>)converter;
-(id)initWith:(sqlite3*)database withQuery:(const char *)query withToDataObjectConverter:(id<ToDataObjectConverter>)converter withInt:(int)childPolicy;

-(NSString *)getColumnAtIndex:(int)index;
-(id<IGenericList>)getColumnListAtIndex:(int)index;
-(id<IGenericList>)getRecordList;
-(id)getRecord;
-(int)getCount;
-(BOOL)execute;
-(AsyncToken *)getRecordListAsync;
-(AsyncToken *)getRecordAsync;
-(AsyncToken *)getCountAsync;
-(AsyncToken *)executeAsync;

@end

@interface GetRecordListAsync : AsyncJob {
@public
    SQLiteQuery *outerClass;
}

-(id)initWithSQLiteQuery:(SQLiteQuery *)outer;

@end

@interface GetRecordAsync : AsyncJob {
@public
    SQLiteQuery *outerClass;
}

-(id)initWithSQLiteQuery:(SQLiteQuery *)outer;

@end

@interface GetCountAsync : AsyncJob {
@public
    SQLiteQuery *outerClass;
}

-(id)initWithSQLiteQuery:(SQLiteQuery *)outer;

@end

@interface ExecuteAsync : AsyncJob {
@public
    SQLiteQuery *outerClass;
}

-(id)initWithSQLiteQuery:(SQLiteQuery *)outer;

@end
