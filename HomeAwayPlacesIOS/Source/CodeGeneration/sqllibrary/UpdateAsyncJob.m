//
//  UpdateAsyncJob.m
//  FalconParent
//
//  Created by pavan on 04/10/17.
//  Copyright © 2017 Purnatva. All rights reserved.
//

#import "UpdateAsyncJob.h"
#import "TreeTypedDAO.h"

@implementation UpdateAsyncJob

-(id)initWithTypedDAO:(TypedDAO *)dao withId:(id)dto
{
    if ([super initWithTypedDAO:dao withId:dto]) {
        _childPolicy = -1;
        _shallowUpdate = NO;
    }
    return self;
}

-(id)initWithTypedDAO:(TypedDAO *)dao withId:(id)dto withInt:(int)childPolicy
{
    if ([super initWithTypedDAO:dao withId:dto]) {
        _childPolicy = childPolicy;
        _shallowUpdate = NO;
    }
    return self;
}

-(id)initWithTypedDAO:(TypedDAO *)dao withId:(id)dto withBOOL:(BOOL)shallowUpdate
{
    if ([super initWithTypedDAO:dao withId:dto]) {
        _childPolicy = -1;
        _shallowUpdate = shallowUpdate;
    }
    return self;
}

-(void)executeCud
{
    if (self.childPolicy == -1)
    {
        if (self.shallowUpdate == YES)
        {
            [self.dao updateRecordShallowWithId:self.dto];
        }
        else {
            [self.dao updateRecordWithId:self.dto];
        }
    }
    else
    {
        [((TreeTypedDAO *)self.dao) updateRecordWithId:self.dto withInt:self.childPolicy];
    }
}

@end
