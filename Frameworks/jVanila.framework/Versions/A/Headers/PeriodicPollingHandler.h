//
//  PeriodicPollingHandler.h
//  HelloVanila
//
//  Created by Pavan on 01/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "VanilaObject.h"
#import "IPeriodicPollingPool.h"
#import "IGenericMap.h"

@interface PeriodicPollingHandler : VanilaObject <IPeriodicPollingPool>

@property (nonatomic, retain) id<IGenericMap> mPollingJobsMap;

@end
