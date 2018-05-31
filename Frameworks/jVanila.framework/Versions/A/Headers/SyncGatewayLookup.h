//
//  SyncGatewayLookup.h
//  HelloVanila
//
//  Created by Pavan on 01/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "INetRequestQueue.h"
#import "IPeriodicPollingPool.h"

@class SyncGateway;

@interface SyncGatewayLookup : NSObject

@property (nonatomic, retain) id<INetRequestQueue> mNetRequestQueue;
@property (nonatomic, retain) id<IPeriodicPollingPool> mPeriodicPollingPool;

- (id)initWithINetRequestQueue:(id<INetRequestQueue>)netRequestQueue
      withIPeriodicPollingPool:(id<IPeriodicPollingPool>)periodicPollingPool;

-(SyncGateway *)getSyncGatewayWithNSString:(NSString *)syncGatewayClassName;

@end
