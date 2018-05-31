//
//  DeleteInAsyncJob.m
//  FalconParent
//
//  Created by pavan on 04/10/17.
//  Copyright © 2017 Purnatva. All rights reserved.
//

#import "DeleteInAsyncJob.h"
#import "TreeTypedDAO.h"

@implementation DeleteInAsyncJob

-(id)initWithTypedDAO:(TypedDAO *)dao withIdList:(id<IGenericList>)idList
{
    if ([super initWithTypedDAO:dao withId:nil]) {
        _idList = idList;
        _childPolicy = -1;
    }
    return self;
}

-(id)initWithTypedDAO:(TypedDAO *)dao withIdList:(id<IGenericList>)idList withInt:(int)childPolicy
{
    if ([super initWithTypedDAO:dao withId:nil]) {
        _idList = idList;
        _childPolicy = childPolicy;
    }
    return self;
}

-(void)execute
{
    if (self.dao == nil || self.idList == nil || [self getToken] == nil) {
        return;
    }
    
    [self executeCud];
}

-(void)executeCud
{
    if (self.childPolicy == -1)
    {
        [self.dao deleteRecordByIdListWithIGenericList:self.idList];
    }
    else
    {
        [((TreeTypedDAO *)self.dao) deleteRecordByIdListWithIGenericList:self.idList withInt:self.childPolicy];
    }
}

@end
