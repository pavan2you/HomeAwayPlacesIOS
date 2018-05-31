//
//  CreateAsyncJob.m
//  FalconParent
//
//  Created by pavan on 04/10/17.
//  Copyright © 2017 Purnatva. All rights reserved.
//

#import "CreateAsyncJob.h"
#import "TreeTypedDAO.h"

@implementation CreateAsyncJob

-(id)initWithTypedDAO:(TypedDAO *)dao withId:(id)dto
{
    if ([super initWithTypedDAO:dao withId:dto]) {
        _childPolicy = -1;
    }
    return self;
}

-(id)initWithTypedDAO:(TypedDAO *)dao withId:(id)dto withInt:(int)childPolicy
{
    if ([super initWithTypedDAO:dao withId:dto]) {
        _childPolicy = childPolicy;
    }
    return self;
}

-(void)executeCud
{
    if (self.childPolicy == -1)
    {
        [self.dao createRecordWithId:self.dto];
    }
    else
    {
        [((TreeTypedDAO *)self.dao) createRecordWithId:self.dto withInt:self.childPolicy];
    }
}

@end
