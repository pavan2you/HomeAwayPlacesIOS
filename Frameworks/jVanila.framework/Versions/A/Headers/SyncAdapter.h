//
//  SyncAdapter.h
//  HelloVanila
//
//  Created by Pavan on 01/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "VanilaObject.h"
#import "ISyncAdapter.h"
#import "ISyncAdapterLoadCallback.h"

@class NetRequestQueue;

#define NET_REQUEST_SUCCESS @"NetRequestSuccess"
#define NET_REQUEST_FAILURE @"NetRequestFailure"

@interface SyncAdapter : VanilaObject <ISyncAdapter>

@property (nonatomic, retain) NetRequestQueue *mNetRequestQueueHandler;

-(id)initWithHttpHeaderBuilder:(HttpHeaderBuilder *)httpHeaderBuilder callback:(id<ISyncAdapterLoadCallback>)callback pubSubTransceiver:(id<IPubSubTransceiver>)pubSubTransceiver;

@end
