//
//  CreateAsyncJob.h
//  FalconParent
//
//  Created by pavan on 04/10/17.
//  Copyright © 2017 Purnatva. All rights reserved.
//

#import <jVanila/jVanila.h>
#import "AsyncCUDJob.h"

@interface CreateAsyncJob : AsyncCUDJob

@property(nonatomic, assign) int childPolicy;

-(id)initWithTypedDAO:(TypedDAO *)dao withId:(id)dto withInt:(int)childPolicy;

@end
