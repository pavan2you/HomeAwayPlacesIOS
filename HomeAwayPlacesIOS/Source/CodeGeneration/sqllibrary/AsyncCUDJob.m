//
//  AsyncCUDJob.m
//  FalconParent
//
//  Created by pavan on 04/10/17.
//  Copyright © 2017 Purnatva. All rights reserved.
//

#import "AsyncCUDJob.h"

@implementation AsyncCUDJob

-(id)initWithTypedDAO:(TypedDAO *)dao withId:(id)dto
{
    if ([super init]) {
        _dao = dao;
        _dto = dto;
    }
    return self;
}

-(void)execute
{
    if (self.dao == nil || self.dto == nil || [self getToken] == nil) {
        return;
    }
    
    [self executeCud];
}

-(void)executeCud
{
    //subclasses should implement this.
}

-(void)finish
{
    //NA
}

@end
