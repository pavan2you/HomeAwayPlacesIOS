//
//  TreeTypedDAO.m
//  FalconParent
//
//  Created by pavan on 04/10/17.
//  Copyright © 2017 Purnatva. All rights reserved.
//

#import "TreeTypedDAO.h"
#import "CreateAsyncJob.h"
#import "UpdateAsyncJob.h"
#import "DeleteAsyncJob.h"
#import "DeleteInAsyncJob.h"
#import "SQLiteQuery.h"

@implementation TreeTypedDAO

-(id)toDataObject:(sqlite3_stmt *)selectSt
{
    return [self toDataObject:selectSt withInt:TreeTypedDAO_CHILD_FETCH_POLICY_SHALLOW];
}

-(int)createRecordWithId:(id)dto
{
    NSException* exception = [NSException exceptionWithName:@"UnsupportedMethodException" reason:@"use createRecordWithId:withInt:" userInfo:nil];
    @throw exception;
}

-(int)createRecordWithId:(id)dto withInt:(int)childPolicy
{
    //subclasses should override
    return -1;
}

-(AsyncToken *)createRecordAsyncWithId:(id)dto
{
    NSException* exception = [NSException exceptionWithName:@"UnsupportedMethodException" reason:@"use createRecordAsyncWithId:withInt:" userInfo:nil];
    @throw exception;
}

-(AsyncToken *)createRecordAsyncWithId:(id)dto withInt:(int)childPolicy
{
    return [[[CreateAsyncJob alloc] initWithTypedDAO:self withId:dto withInt:childPolicy] post];
}

-(int)updateRecordWithId:(id)dto
{
    NSException* exception = [NSException exceptionWithName:@"UnsupportedMethodException" reason:@"use updateRecordWithId:withInt:" userInfo:nil];
    @throw exception;
}

-(int)updateRecordWithId:(id)dto withInt:(int)childPolicy
{
    [self deleteRecordByIdAndPublishWithNSString:[self.mTableInfo getValueOfId:dto withColumnName:self.mTableInfo.primaryKey] withInt:childPolicy withBOOL:NO];
    return [self createRecordWithId:dto withInt:childPolicy];
}

-(AsyncToken *)updateRecordAsyncWithId:(id)dto
{
    NSException* exception = [NSException exceptionWithName:@"UnsupportedMethodException" reason:@"use updateRecordAsyncWithId:withInt:" userInfo:nil];
    @throw exception;
}

-(AsyncToken *)updateRecordAsyncWithId:(id)dto withInt:(int)childPolicy
{
    return [[[UpdateAsyncJob alloc] initWithTypedDAO:self withId:dto withInt:childPolicy] post];
}

-(BOOL)deleteRecordById:(id)dto
{
    NSException* exception = [NSException exceptionWithName:@"UnsupportedMethodException" reason:@"use deleteRecordById:withInt:" userInfo:nil];
    @throw exception;
}

-(BOOL)deleteRecordById:(id)dto withInt:(int)childPolicy
{
    BOOL needDependableDelete = [self needDependableDAODeleteCallWithId:dto];
    return [self deleteRecordByIdAndPublishWithNSString:[self.mTableInfo getValueOfId:dto withColumnName:self.mTableInfo.primaryKey] withInt:childPolicy withBOOL:YES withBOOL:needDependableDelete];
}

-(BOOL)deleteRecordByIdWithNSString:(NSString *)primaryKey
{
    NSException* exception = [NSException exceptionWithName:@"UnsupportedMethodException" reason:@"use deleteRecordByIdWithNSString:withInt:" userInfo:nil];
    @throw exception;
}

-(BOOL)deleteRecordByIdWithNSString:(NSString *)primaryKey withInt:(int)childPolicy
{
    return [self deleteRecordByIdAndPublishWithNSString:primaryKey withInt:childPolicy withBOOL:YES];
}

-(AsyncToken *)deleteRecordByIdAsyncWithNSString:(NSString *)primaryKey
{
    NSException* exception = [NSException exceptionWithName:@"UnsupportedMethodException" reason:@"use deleteRecordByIdAsyncWithNSString:withInt:" userInfo:nil];
    @throw exception;
}

-(AsyncToken *)deleteRecordByIdAsyncWithNSString:(NSString *)primaryKey withInt:(int)childPolicy
{
    return [[[DeleteAsyncJob alloc] initWithTypedDAO:self withNSString:primaryKey withBOOL:YES withInt:childPolicy] post];
}

-(BOOL)deleteRecordByIdWithNSString:(NSString *)primaryKey withBOOL:(BOOL)publish
{
    NSException* exception = [NSException exceptionWithName:@"UnsupportedMethodException" reason:@"use deleteRecordByIdWithNSString:withInt:withBOOL:" userInfo:nil];
    @throw exception;
}

-(BOOL)deleteRecordByIdAndPublishWithNSString:(NSString *)primaryKey withInt:(int)childPolicy withBOOL:(BOOL)publish
{
    return [self deleteRecordByIdAndPublishWithNSString:primaryKey withInt:childPolicy withBOOL:publish withBOOL:YES];
}

-(BOOL)deleteRecordByIdAndPublishWithNSString:(NSString *)primaryKey withBOOL:(BOOL)publish withBOOL:(BOOL)needDependableDAODelete
{
    NSException* exception = [NSException exceptionWithName:@"UnsupportedMethodException" reason:@"use deleteRecordByIdWithNSString:withInt:withBOOL:withBOOL:" userInfo:nil];
    @throw exception;
}

-(BOOL)deleteRecordByIdAndPublishWithNSString:(NSString *)primaryKey withInt:(int)childPolicy withBOOL:(BOOL)publish withBOOL:(BOOL)needDependableDAODelete
{
    if (needDependableDAODelete == YES)
    {
        id<IGenericList> daoList = [self loadDependableDaoList];
        if (daoList)
        {
            id dto = [self getRecordWithNSString:primaryKey];
            if (dto) {
                [self deleteDependableRecordsWithMessageDTO:dto withNSString:primaryKey withIGenericList:daoList];
            }
        }
    }
    
    if (childPolicy == TreeTypedDAO_CHILD_FETCH_POLICY_DEEP)
    {
        id<IGenericList> childUuidList = [self getChildUuidListWithNSString:primaryKey withInt:childPolicy withIGenericList:[[GenericList alloc] init]];
        [self deleteRecordByIdListChunkByChunkWithIGenericList:childUuidList];
    }
    
    return [self deleteRecordByColumnWithNSString:self.mTableInfo.primaryKey withNSString:primaryKey];
}
 
- (void)deleteDependableRecordsWithMessageDTO:(id)dto withNSString:(NSString *)primaryKey withIGenericList:(id<IGenericList>)daoList
{
    for (id dao in daoList)
    {
        TypedDAO *_dao = (TypedDAO *)dao;
        [_dao deleteRecordByColumnWithNSString:_dao.mTableInfo.foreignKey withNSString:primaryKey];
    }
}

-(BOOL)deleteRecordByIdListWithIGenericList:(id<IGenericList>)idList withInt:(int)childPolicy
{
    id<IGenericList> outUuidList = [[GenericList alloc] init];
    if (childPolicy == TreeTypedDAO_CHILD_FETCH_POLICY_DEEP)
    {
        for (id uuid in idList)
        {
            outUuidList = [self getChildUuidListWithNSString:uuid withInt:childPolicy withIGenericList:outUuidList];
            [outUuidList addWithId:uuid];
        }
    }
    else {
        outUuidList = idList;
    }
    
    return [self deleteRecordByIdListChunkByChunkWithIGenericList:outUuidList];
}

-(AsyncToken *)deleteRecordByIdListAsyncWithIGenericList:(id<IGenericList>)idList withInt:(int)childPolicy
{
    return [[[DeleteInAsyncJob alloc] initWithTypedDAO:self withIdList:idList withInt:childPolicy] post];
}

-(id<IGenericList>)getChildUuidListWithNSString:(NSString *)parentUuid withInt:(int)childPolicy withIGenericList:(id<IGenericList>)fillInOutList
{
    //subclasses should override
    return 0;
}


@end
