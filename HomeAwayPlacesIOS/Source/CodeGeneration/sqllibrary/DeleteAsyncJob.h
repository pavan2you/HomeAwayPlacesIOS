//
//  DeleteAsyncJob.h
//  FalconParent
//
//  Created by pavan on 04/10/17.
//  Copyright © 2017 Purnatva. All rights reserved.
//

#import "AsyncCUDJob.h"

@interface DeleteAsyncJob : AsyncCUDJob

@property(nonatomic, retain) NSString* primaryKey;
@property(nonatomic, assign) BOOL publish;
@property(nonatomic, assign) int childPolicy;

-(id)initWithTypedDAO:(TypedDAO *)dao;
-(id)initWithTypedDAO:(TypedDAO *)dao withNSString:(NSString *)primaryKey withBOOL:(BOOL)publish;
-(id)initWithTypedDAO:(TypedDAO *)dao withNSString:(NSString *)primaryKey withBOOL:(BOOL)publish withInt:(int)childPolicy;

@end
