//
//  TypedDAO.m
//  FalconParent
//
//  Created by pavan on 04/10/17.
//  Copyright © 2017 Purnatva. All rights reserved.
//

#import "TypedDAO.h"
#import "CreateAsyncJob.h"
#import "UpdateAsyncJob.h"
#import "DeleteAsyncJob.h"
#import "DeleteInAsyncJob.h"
#import "SQLiteQuery.h"

@implementation TypedDAO

-(id)initWithSQLiteDatabase:(sqlite3*) argSQLDB withSQLiteTableInfo:(SQLiteTableInfo *)tableInfo
{
    if ([super initWithSQLiteDatabase:argSQLDB]) {
        _mTableInfo = tableInfo;
    }
    
    return self;
}

-(id<IGenericList>)loadDependableDaoList
{
    return nil;
}

-(SQLiteTableInfo *)getTableInfo
{
    return self.mTableInfo;
}

-(id)toDataObject:(sqlite3_stmt *)selectSt withInt:(int)childPolicy
{
    return [self toDataObject:selectSt];
}

-(id)toDataObject:(sqlite3_stmt *)selectSt
{
    return nil;
}

-(BOOL)needDependableDAODeleteCallWithId:(id)dto
{
    return YES;
}

-(id<IGenericList>) getUuidListChunksWithIIGenericList:(id<IGenericList>)idList
{
    id<IGenericList> uuidListChunks = [[GenericList alloc] init];
    id<IGenericList> uuidListChunk = [[GenericList alloc] init];
    [uuidListChunks addWithId:uuidListChunk];
    
    for (int i = 0, j = 0; i < [idList size]; i++)
    {
        [uuidListChunk addWithId:[idList getWithInt:i]];
        if (j++ == 100)
        {
            //reset
            uuidListChunk = [[GenericList alloc] init];
            [uuidListChunks addWithId:uuidListChunk];
            j = 0;
        }
    }
    
    return uuidListChunks;
}

-(int)createRecordWithId:(id)dto
{
    //subclasses should override
    return -1;
}

-(int)createRecordShallowWithId:(id)dto
{
    //subclasses should override
    return -1;
}

-(AsyncToken *)createRecordAsyncWithId:(id)dto
{
    return [[[CreateAsyncJob alloc] initWithTypedDAO:self withId:dto] post];
}

-(int)updateRecordWithId:(id)dto
{
    [self deleteRecordByIdWithNSString:[self.mTableInfo getValueOfId:dto withColumnName:self.mTableInfo.primaryKey] withBOOL:NO];
    return [self createRecordWithId:dto];
}

-(int)updateRecordShallowWithId:(id)dto
{
    [self deleteRecordByColumnWithNSString:self.mTableInfo.primaryKey withNSString:[self.mTableInfo getValueOfId:dto withColumnName:self.mTableInfo.primaryKey]];
    return [self createRecordShallowWithId:dto];
}

-(AsyncToken *)updateRecordAsyncWithId:(id)dto
{
    return [[[UpdateAsyncJob alloc] initWithTypedDAO:self withId:dto] post];
}

-(AsyncToken *)updateRecordShallowAsyncWithId:(id)dto
{
    return [[[UpdateAsyncJob alloc] initWithTypedDAO:self withId:dto withBOOL:YES] post];
}

-(BOOL)deleteAll
{
    id<IGenericList> daoList = [self loadDependableDaoList];
    if (daoList)
    {
        for (id dao in daoList)
        {
            [((TypedDAO *)dao) deleteAll];
        }
    }
    
    const char *query = [[NSString stringWithFormat:@"DELETE FROM %@", self.mTableInfo.name] UTF8String];
    return [[[SQLiteQuery alloc] initWith:sqlDB withQuery:query withToDataObjectConverter:self] execute];
}

-(AsyncToken *)deleteAllAsync
{
    return [[[DeleteAsyncJob alloc] initWithTypedDAO:self] post];
}

-(BOOL)deleteRecordById:(id)dto
{
    BOOL needDependableDelete = [self needDependableDAODeleteCallWithId:dto];
    return [self deleteRecordByIdWithNSString:[self.mTableInfo getValueOfId:dto withColumnName:self.mTableInfo.primaryKey] withBOOL:YES withBOOL:needDependableDelete];
}

-(BOOL)deleteRecordByIdWithNSString:(NSString *)primaryKey
{
    return [self deleteRecordByIdWithNSString:primaryKey withBOOL:YES];
}

-(AsyncToken *)deleteRecordByIdAsyncWithNSString:(NSString *)primaryKey
{
    return [[[DeleteAsyncJob alloc] initWithTypedDAO:self withNSString:primaryKey withBOOL:YES] post];
}

-(BOOL)deleteRecordByIdWithNSString:(NSString *)primaryKey withBOOL:(BOOL)publish
{
    return [self deleteRecordByIdWithNSString:primaryKey withBOOL:publish withBOOL:YES];
}

-(BOOL)deleteRecordByIdWithNSString:(NSString *)primaryKey withBOOL:(BOOL)publish withBOOL:(BOOL)needDependableDAODelete
{
    if (needDependableDAODelete == YES)
    {
        id<IGenericList> daoList = [self loadDependableDaoList];
        if (daoList)
        {
            for (id dao in daoList)
            {
                TypedDAO *_dao = (TypedDAO *)dao;
                [_dao deleteRecordByColumnWithNSString:_dao.mTableInfo.foreignKey withNSString:primaryKey];
            }
        }
    }
    
    return [self deleteRecordByColumnWithNSString:self.mTableInfo.primaryKey withNSString:primaryKey];
}

-(BOOL)deleteRecordByColumnWithNSString:(NSString *)columnName withNSString:(NSString *)columnValue
{
    const char *query = [[NSString stringWithFormat:@"DELETE FROM %@ WHERE %@ =\"%@\"", self.mTableInfo.name, columnName, columnValue] UTF8String];
    return [[[SQLiteQuery alloc] initWith:sqlDB withQuery:query withToDataObjectConverter:self] execute];
}

-(AsyncToken *)deleteRecordByColumnAsyncWithNSString:(NSString *)columnName withNSString:(NSString *)columnValue
{
    const char *query = [[NSString stringWithFormat:@"DELETE FROM %@ WHERE %@ =\"%@\"", self.mTableInfo.name, columnName, columnValue] UTF8String];
    return [[[SQLiteQuery alloc] initWith:sqlDB withQuery:query withToDataObjectConverter:self] executeAsync];
}

-(BOOL)deleteRecordByIdListWithIGenericList:(id<IGenericList>)idList
{
    id<IGenericList> daoList = [self loadDependableDaoList];
    if (daoList)
    {
        for (id dao in daoList)
        {
            TypedDAO *_dao = (TypedDAO *)dao;
            [_dao deleteRecordByColumnInListWithNSString:_dao.mTableInfo.foreignKey withIGenericList:idList];
        }
    }
    
    return [self deleteRecordByColumnInListWithNSString:self.mTableInfo.primaryKey withIGenericList:idList];;
}

-(AsyncToken *)deleteRecordByIdListAsyncWithIGenericList:(id<IGenericList>)idList
{
    return [[[DeleteInAsyncJob alloc] initWithTypedDAO:self withIdList:idList] post];
}

-(BOOL)deleteRecordByIdListChunkByChunkWithIGenericList:(id<IGenericList>)idList
{
    BOOL result = NO;
    if (idList != nil && [idList size] > 0)
    {
        id<IGenericList> uuidListChunks = [self getUuidListChunksWithIIGenericList:idList];
        for (id chunk in uuidListChunks)
        {
            id<IGenericList> chunkList = chunk;
            result |= [self deleteRecordByIdListWithIGenericList:chunkList];
        }
    }
    
    return result;
}

-(BOOL)deleteRecordByColumnInListWithNSString:(NSString *)columnName withIGenericList:(id<IGenericList>)columnValueList
{
    NSArray *values = (((GenericList *) columnValueList).mObjectList);
    const char *query = [[NSString stringWithFormat:@"DELETE FROM %@ WHERE %@ IN ('%@')", self.mTableInfo.name, columnName, [values componentsJoinedByString:@"','"]] UTF8String];
    
    return [[[SQLiteQuery alloc] initWith:sqlDB withQuery:query withToDataObjectConverter:self] execute];
}

-(AsyncToken *)deleteRecordByColumnInListAsyncWithNSString:(NSString *)columnName withIGenericList:(id<IGenericList>)columnValueList
{
    NSArray *values = (((GenericList *) columnValueList).mObjectList);
    const char *query = [[NSString stringWithFormat:@"DELETE FROM %@ WHERE %@ IN ('%@')", self.mTableInfo.name, columnName, [values componentsJoinedByString:@"','"]] UTF8String];
    
    return [[[SQLiteQuery alloc] initWith:sqlDB withQuery:query withToDataObjectConverter:self] executeAsync];
}

-(int)getRecordCount
{
    const char *query = [[NSString stringWithFormat:@"SELECT COUNT(%@) AS Count FROM %@", self.mTableInfo.primaryKey, self.mTableInfo.name] UTF8String];
    
    return [[[SQLiteQuery alloc] initWith:sqlDB withQuery:query withToDataObjectConverter:self] getCount];
}

-(AsyncToken *)getRecordCountAsync
{
    const char *query = [[NSString stringWithFormat:@"SELECT COUNT(%@) AS Count FROM %@", self.mTableInfo.primaryKey, self.mTableInfo.name] UTF8String];
    
    return [[[SQLiteQuery alloc] initWith:sqlDB withQuery:query withToDataObjectConverter:self] getCountAsync];
}

-(id<IGenericList>)getAllRecords
{
    const char *query = [[NSString stringWithFormat:@"SELECT * FROM %@", self.mTableInfo.name] UTF8String];
    
    return [[[SQLiteQuery alloc] initWith:sqlDB withQuery:query withToDataObjectConverter:self] getRecordList];
}

-(AsyncToken *)getAllRecordsAsync
{
    const char *query = [[NSString stringWithFormat:@"SELECT * FROM %@", self.mTableInfo.name] UTF8String];
    
    return [[[SQLiteQuery alloc] initWith:sqlDB withQuery:query withToDataObjectConverter:self] getRecordListAsync];
}

-(id)getRecordWithNSString:(NSString *)primaryKey
{
    return [self getRecordByColumnWithNSString:self.mTableInfo.primaryKey withNSString:primaryKey];
}

-(AsyncToken *)getRecordAsyncWithNSString:(NSString *)primaryKey
{
    return [self getRecordByColumnAsyncWithNSString:self.mTableInfo.primaryKey withNSString:primaryKey];
}

-(id)getRecordByColumnWithNSString:(NSString *)columnName withNSString:(NSString *)columnValue
{
    const char *query = [[NSString stringWithFormat:@"SELECT * FROM %@ WHERE %@ =\"%@\"", self.mTableInfo.name, columnName, columnValue] UTF8String];
    
    return [[[SQLiteQuery alloc] initWith:sqlDB withQuery:query withToDataObjectConverter:self] getRecord];
}

-(AsyncToken *)getRecordByColumnAsyncWithNSString:(NSString *)columnName withNSString:(NSString *)columnValue
{
    const char *query = [[NSString stringWithFormat:@"SELECT * FROM %@ WHERE %@ =\"%@\"", self.mTableInfo.name, columnName, columnValue] UTF8String];
    
    return [[[SQLiteQuery alloc] initWith:sqlDB withQuery:query withToDataObjectConverter:self] getRecordAsync];
}

-(id<IGenericList>)getRecordListByColumnWithNSString:(NSString *)columnName withNSString:(NSString *)columnValue
{
    const char *query = [[NSString stringWithFormat:@"SELECT * FROM %@ WHERE %@ =\"%@\"", self.mTableInfo.name, columnName, columnValue] UTF8String];
    
    return [[[SQLiteQuery alloc] initWith:sqlDB withQuery:query withToDataObjectConverter:self] getRecordList];
}

-(AsyncToken *)getRecordListByColumnAsyncWithNSString:(NSString *)columnName withNSString:(NSString *)columnValue
{
    const char *query = [[NSString stringWithFormat:@"SELECT * FROM %@ WHERE %@ =\"%@\"", self.mTableInfo.name, columnName, columnValue] UTF8String];
    
    return [[[SQLiteQuery alloc] initWith:sqlDB withQuery:query withToDataObjectConverter:self] getRecordListAsync];
}

-(id<IGenericList>)getRecordListByColumnInWithNSString:(NSString *)columnName withIGenericList:(id<IGenericList>)columnValueList
{
    NSArray *values = (((GenericList *) columnValueList).mObjectList);
    const char *query = [[NSString stringWithFormat:@"SELECT * FROM %@ WHERE %@ IN ('%@')", self.mTableInfo.name, columnName, [values componentsJoinedByString:@"','"]] UTF8String];
    
    return [[[SQLiteQuery alloc] initWith:sqlDB withQuery:query withToDataObjectConverter:self] getRecordList];
}

-(AsyncToken *)getRecordListByColumnInAsyncWithNSString:(NSString *)columnName withIGenericList:(id<IGenericList>)columnValueList
{
    NSArray *values = (((GenericList *) columnValueList).mObjectList);
    const char *query = [[NSString stringWithFormat:@"SELECT * FROM %@ WHERE %@ IN ('%@')", self.mTableInfo.name, columnName, [values componentsJoinedByString:@"','"]] UTF8String];
    
    return [[[SQLiteQuery alloc] initWith:sqlDB withQuery:query withToDataObjectConverter:self] getRecordListAsync];
}

-(id<IGenericList>)getColumnListAtIndexWithNSString:(NSString *)columnName withInt:(int)atIndex
{
    const char *query = [[NSString stringWithFormat:@"SELECT %@ FROM %@", columnName, self.mTableInfo.name] UTF8String];
    
    return [[[SQLiteQuery alloc] initWith:sqlDB withQuery:query withToDataObjectConverter:self] getColumnListAtIndex:atIndex];
}

-(BOOL)isRecordExitsWithNSString:(NSString *)primaryKey
{
    const char *query = [[NSString stringWithFormat:@"SELECT * FROM %@ WHERE %@ =\"%@\"", self.mTableInfo.name, self.mTableInfo.primaryKey, primaryKey] UTF8String];
    
    return [[[SQLiteQuery alloc] initWith:sqlDB withQuery:query withToDataObjectConverter:self] getCount] > 0;
}

@end
