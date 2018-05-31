//
//  DeleteAsyncJob.m
//  FalconParent
//
//  Created by pavan on 04/10/17.
//  Copyright © 2017 Purnatva. All rights reserved.
//

#import "DeleteAsyncJob.h"
#import "TreeTypedDAO.h"

@implementation DeleteAsyncJob

-(id)initWithTypedDAO:(TypedDAO *)dao
{
    if ([super initWithTypedDAO:dao withId:nil]) {
        _childPolicy = -1;
    }
    return self;
}

-(id)initWithTypedDAO:(TypedDAO *)dao withNSString:(NSString *)primaryKey withBOOL:(BOOL)publish
{
    if ([super initWithTypedDAO:dao withId:nil]) {
        _primaryKey = primaryKey;
        _publish = publish;
        _childPolicy = -1;
    }
    return self;
}

-(id)initWithTypedDAO:(TypedDAO *)dao withNSString:(NSString *)primaryKey withBOOL:(BOOL)publish withInt:(int)childPolicy
{
    if ([super initWithTypedDAO:dao withId:nil]) {
        _primaryKey = primaryKey;
        _publish = publish;
        _childPolicy = childPolicy;
    }
    return self;
}

-(void)execute
{
    if (self.dao == nil || [self getToken] == nil) {
        return;
    }
    
    [self executeCud];
}

-(void)executeCud
{
    if (self.primaryKey == nil)
    {
        [self.dao deleteAll];
    }
    else if (self.childPolicy == -1)
    {
        [self.dao deleteRecordByIdWithNSString:self.primaryKey];
    }
    else
    {
        [((TreeTypedDAO *)self.dao) deleteRecordByIdWithNSString:self.primaryKey withInt:self.childPolicy];
    }
}

@end
