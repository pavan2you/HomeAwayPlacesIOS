//
//  TreeTypedDAO.h
//  FalconParent
//
//  Created by pavan on 04/10/17.
//  Copyright © 2017 Purnatva. All rights reserved.
//

#define TreeTypedDAO_CHILD_FETCH_POLICY_DEEP 0
#define TreeTypedDAO_CHILD_FETCH_POLICY_COUNT_ONLY 1
#define TreeTypedDAO_CHILD_FETCH_POLICY_SHALLOW 2

#import <jVanila/jVanila.h>
#import "TypedDAO.h"

@interface TreeTypedDAO : TypedDAO

-(int)createRecordWithId:(id)dto withInt:(int)childPolicy;
-(AsyncToken *)createRecordAsyncWithId:(id)dto withInt:(int)childPolicy;

-(int)updateRecordWithId:(id)dto withInt:(int)childPolicy;
-(AsyncToken *)updateRecordAsyncWithId:(id)dto withInt:(int)childPolicy;

-(BOOL)deleteRecordById:(id)dto withInt:(int)childPolicy;
-(BOOL)deleteRecordByIdWithNSString:(NSString *)primaryKey withInt:(int)childPolicy;
-(AsyncToken *)deleteRecordByIdAsyncWithNSString:(NSString *)primaryKey withInt:(int)childPolicy;
-(BOOL)deleteRecordByIdAndPublishWithNSString:(NSString *)primaryKey withInt:(int)childPolicy withBOOL:(BOOL)publish;
-(BOOL)deleteRecordByIdAndPublishWithNSString:(NSString *)primaryKey withInt:(int)childPolicy withBOOL:(BOOL)publish withBOOL:(BOOL)needDependableDAODelete;
-(BOOL)deleteRecordByIdListWithIGenericList:(id<IGenericList>)idList withInt:(int)childPolicy;
-(AsyncToken *)deleteRecordByIdListAsyncWithIGenericList:(id<IGenericList>)idList withInt:(int)childPolicy;

-(id<IGenericList>)getChildUuidListWithNSString:(NSString *)parentUuid withInt:(int)childPolicy withIGenericList:(id<IGenericList>)fillInOutList;

@end
