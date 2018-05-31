//
//  DeleteInAsyncJob.h
//  FalconParent
//
//  Created by pavan on 04/10/17.
//  Copyright © 2017 Purnatva. All rights reserved.
//

#import "AsyncCUDJob.h"

@interface DeleteInAsyncJob : AsyncCUDJob

@property(nonatomic, assign) int childPolicy;
@property(nonatomic, retain) id<IGenericList> idList;

-(id)initWithTypedDAO:(TypedDAO *)dao withIdList:(id<IGenericList>)idList;
-(id)initWithTypedDAO:(TypedDAO *)dao withIdList:(id<IGenericList>)idList withInt:(int)childPolicy;

@end
