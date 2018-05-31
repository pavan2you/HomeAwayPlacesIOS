//
//  PollingHandler.h
//  HelloVanila
//
//  Created by Pavan on 01/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NetRequestDTO.h"
#import "IPollingRequestHost.h"

@interface PollingHandler : NSObject

-(id)initWithNetRequestDTO:(NetRequestDTO *)netRequest withIPollingRequestHost:(id<IPollingRequestHost>)pollingRequestHost;
- (void)startPolling;
- (void)stopPolling;

@end
