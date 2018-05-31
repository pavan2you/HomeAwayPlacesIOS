//
//  UpdateAsyncJob.h
//  FalconParent
//
//  Created by pavan on 04/10/17.
//  Copyright © 2017 Purnatva. All rights reserved.
//

#import "AsyncCUDJob.h"

@interface UpdateAsyncJob : AsyncCUDJob

@property(nonatomic, assign) int childPolicy;
@property(nonatomic, assign) BOOL shallowUpdate;

-(id)initWithTypedDAO:(TypedDAO *)dao withId:(id)dto withInt:(int)childPolicy;
-(id)initWithTypedDAO:(TypedDAO *)dao withId:(id)dto withBOOL:(BOOL)shallowUpdate;

@end
