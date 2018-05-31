//
//  AsyncCUDJob.h
//  FalconParent
//
//  Created by pavan on 04/10/17.
//  Copyright © 2017 Purnatva. All rights reserved.
//

#import <jVanila/jVanila.h>
#import "TypedDAO.h"

@interface AsyncCUDJob : AsyncJob

@property(nonatomic, retain) TypedDAO* dao;
@property(nonatomic, retain) id dto;

-(id)initWithTypedDAO:(TypedDAO *)dao withId:(id)dto;
-(void)executeCud;

@end
