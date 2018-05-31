//
//  TypedDAO.h
//  FalconParent
//
//  Created by pavan on 04/10/17.
//  Copyright © 2017 Purnatva. All rights reserved.
//

#import <jVanila/jVanila.h>
#import "ToDataObjectConverter.h"
#import "SQLiteTableInfo.h"

@interface TypedDAO : SqliteDataAccessObject < ToDataObjectConverter >

@property (nonatomic, retain) SQLiteTableInfo *mTableInfo;

-(id)initWithSQLiteDatabase:(sqlite3*) argSQLDB withSQLiteTableInfo:(SQLiteTableInfo *)tableInfo;

-(id<IGenericList>)loadDependableDaoList;
-(SQLiteTableInfo *)getTableInfo;
-(id)toDataObject:(sqlite3_stmt *)selectSt;
-(BOOL)needDependableDAODeleteCallWithId:(id)dto;

-(int)createRecordWithId:(id)dto;
-(int)createRecordShallowWithId:(id)dto;
-(AsyncToken *)createRecordAsyncWithId:(id)dto;

-(int)updateRecordWithId:(id)dto;
-(int)updateRecordShallowWithId:(id)dto;
-(AsyncToken *)updateRecordAsyncWithId:(id)dto;
-(AsyncToken *)updateRecordShallowAsyncWithId:(id)dto;

-(BOOL)deleteAll;
-(AsyncToken *)deleteAllAsync;
-(BOOL)deleteRecordById:(id)dto;
-(BOOL)deleteRecordByIdWithNSString:(NSString *)primaryKey;
-(AsyncToken *)deleteRecordByIdAsyncWithNSString:(NSString *)primaryKey;
-(BOOL)deleteRecordByIdWithNSString:(NSString *)primaryKey withBOOL:(BOOL)publish;
-(BOOL)deleteRecordByIdWithNSString:(NSString *)primaryKey withBOOL:(BOOL)publish withBOOL:(BOOL)needDependableDAODelete;
-(BOOL)deleteRecordByColumnWithNSString:(NSString *)columnName withNSString:(NSString *)columnValue;
-(AsyncToken *)deleteRecordByColumnAsyncWithNSString:(NSString *)columnName withNSString:(NSString *)columnValue;
-(BOOL)deleteRecordByIdListWithIGenericList:(id<IGenericList>)idList;
-(AsyncToken *)deleteRecordByIdListAsyncWithIGenericList:(id<IGenericList>)idList;
-(BOOL)deleteRecordByIdListChunkByChunkWithIGenericList:(id<IGenericList>)idList;
-(BOOL)deleteRecordByColumnInListWithNSString:(NSString *)columnName withIGenericList:(id<IGenericList>)columnValueList;
-(AsyncToken *)deleteRecordByColumnInListAsyncWithNSString:(NSString *)columnName withIGenericList:(id<IGenericList>)columnValueList;

-(int)getRecordCount;
-(AsyncToken *)getRecordCountAsync;
-(id<IGenericList>)getAllRecords;
-(AsyncToken *)getAllRecordsAsync;
-(id)getRecordWithNSString:(NSString *)primaryKey;
-(AsyncToken *)getRecordAsyncWithNSString:(NSString *)primaryKey;
-(id)getRecordByColumnWithNSString:(NSString *)columnName withNSString:(NSString *)columnValue;
-(AsyncToken *)getRecordByColumnAsyncWithNSString:(NSString *)columnName withNSString:(NSString *)columnValue;
-(id<IGenericList>)getRecordListByColumnWithNSString:(NSString *)columnName withNSString:(NSString *)columnValue;
-(AsyncToken *)getRecordListByColumnAsyncWithNSString:(NSString *)columnName withNSString:(NSString *)columnValue;
-(id<IGenericList>)getRecordListByColumnInWithNSString:(NSString *)columnName withIGenericList:(id<IGenericList>)columnValueList;
-(AsyncToken *)getRecordListByColumnInAsyncWithNSString:(NSString *)columnName withIGenericList:(id<IGenericList>)columnValueList;
-(id<IGenericList>)getColumnListAtIndexWithNSString:(NSString *)columnName withInt:(int)atIndex;

-(BOOL)isRecordExitsWithNSString:(NSString *)primaryKey;
@end
