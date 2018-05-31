//
//  SQLiteQuery.m
//  FalconParent
//
//  Created by pavan on 04/10/17.
//  Copyright © 2017 Purnatva. All rights reserved.
//

#import "SQLiteQuery.h"

@interface SQLiteQuery()

@property (nonatomic, retain) id<ToDataObjectConverter> converter;
@property (nonatomic, assign) int childPolicy;
@property (nonatomic, retain) AsyncJob *asyncJob;

@end

@implementation SQLiteQuery

-(id)initWith:(sqlite3*)database withQuery:(const char *)query withToDataObjectConverter:(id<ToDataObjectConverter>)converter
{
    return [self initWith:database withQuery:query withToDataObjectConverter:converter withInt:-1];
}

-(id)initWith:(sqlite3*)database withQuery:(const char *)query withToDataObjectConverter:(id<ToDataObjectConverter>)converter withInt:(int)childPolicy
{
    if ([super init])
    {
        sqlDB = database;
        queryToProcess = query;
        _converter = converter;
        _childPolicy = childPolicy;
    }
    
    return self;
}

-(NSString *)getColumnAtIndex:(int)index
{
    NSString *column = nil;
    
    sqlite3_stmt *selectSt;
    if (sqlite3_prepare_v2(sqlDB, queryToProcess, -1, &selectSt, NULL) == SQLITE_OK)
    {
        if (sqlite3_step(selectSt) == SQLITE_ROW)
        {
            column = [VanilaCustomUtility getNSStringFromUTF8String:(char *)sqlite3_column_text(selectSt, index)];
        }
    }
    sqlite3_finalize(selectSt);
    
    return column;
}

-(id<IGenericList>)getColumnListAtIndex:(int)index
{
    id<IGenericList> columnList = nil;
    
    sqlite3_stmt *selectSt;
    if (sqlite3_prepare_v2(sqlDB, queryToProcess, -1, &selectSt, NULL) == SQLITE_OK) {
        columnList = [[GenericList alloc] init];
        while (sqlite3_step(selectSt) == SQLITE_ROW) {
            NSString *columnValue = [VanilaCustomUtility getNSStringFromUTF8String:(char *)sqlite3_column_text(selectSt, index)];
            [columnList addWithId:columnValue];
        }
    }
    sqlite3_finalize(selectSt);
    
    if ([columnList size] == 0) {
        columnList = nil;
    }
    
    return columnList;
}

-(id<IGenericList>)getRecordList
{
    id<IGenericList> dtoList = nil;
    
    sqlite3_stmt *selectSt;
    if (sqlite3_prepare_v2(sqlDB, queryToProcess, -1, &selectSt, NULL) == SQLITE_OK)
    {
        dtoList = [[GenericList alloc] init];
        while (sqlite3_step(selectSt) == SQLITE_ROW)
        {
            id dto = [self.converter toDataObject:selectSt withInt:self.childPolicy];
            [dtoList addWithId:dto];
        }
    }
    sqlite3_finalize(selectSt);
    
    if ([dtoList size] == 0) {
        dtoList = nil;
    }
    return dtoList;
}

-(id)getRecord
{
    id dto = nil;
    
    sqlite3_stmt *selectSt;
    if (sqlite3_prepare_v2(sqlDB, queryToProcess, -1, &selectSt, NULL) == SQLITE_OK)
    {
        if (sqlite3_step(selectSt) == SQLITE_ROW)
        {
            dto = [self.converter toDataObject:selectSt withInt:self.childPolicy];
        }
    }
    sqlite3_finalize(selectSt);
    
    return dto;
}

-(int)getCount
{
    int count = 0;
    
    sqlite3_stmt *selectSt;
    if (sqlite3_prepare_v2(sqlDB, queryToProcess, -1, &selectSt, NULL) == SQLITE_OK) {
        if (sqlite3_step(selectSt) == SQLITE_ROW) {
            count++;
        }
    }
    sqlite3_finalize(selectSt);
    
    return count;
}

-(BOOL)execute
{
    BOOL bResult = NO;
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(sqlDB, queryToProcess, -1, &stmt, NULL) == SQLITE_OK) {
        if (sqlite3_step(stmt) == SQLITE_DONE) {
            bResult = YES;
        }
    }
    sqlite3_finalize(stmt);
    return bResult;
}

-(AsyncToken *)getRecordListAsync
{
    self.asyncJob = [[GetRecordListAsync alloc] initWithSQLiteQuery:self];
    return [self.asyncJob post];
}

-(AsyncToken *)getRecordAsync
{
    self.asyncJob = [[GetRecordAsync alloc] initWithSQLiteQuery:self];
    return [self.asyncJob post];
}

-(AsyncToken *)getCountAsync
{
    self.asyncJob = [[GetCountAsync alloc] initWithSQLiteQuery:self];
    return [self.asyncJob post];
}

-(AsyncToken *)executeAsync
{
    self.asyncJob = [[ExecuteAsync alloc] initWithSQLiteQuery:self];
    return [self.asyncJob post];
}

-(void)cancel
{
    [self.asyncJob cancel];
}

@end

#pragma Inner classes

@implementation GetRecordListAsync

-(id)initWithSQLiteQuery:(SQLiteQuery *)outer
{
    if ((self = [super init])) {
        outerClass = outer;
    }
    
    return self;
}

-(void)execute
{
    self.mToken.result = [outerClass getRecordList];
}

@end


@implementation GetRecordAsync

-(id)initWithSQLiteQuery:(SQLiteQuery *)outer
{
    if ((self = [super init])) {
        outerClass = outer;
    }
    
    return self;
}

-(void)execute
{
    self.mToken.result = [outerClass getRecord];
}

@end


@implementation GetCountAsync

-(id)initWithSQLiteQuery:(SQLiteQuery *)outer
{
    if ((self = [super init])) {
        outerClass = outer;
    }
    
    return self;
}

-(void)execute
{
    self.mToken.result = @([outerClass getCount]);
}

@end


@implementation ExecuteAsync

-(id)initWithSQLiteQuery:(SQLiteQuery *)outer
{
    if ((self = [super init])) {
        outerClass = outer;
    }
    
    return self;
}

-(void)execute
{
    self.mToken.result = @([outerClass execute]);
}

@end
