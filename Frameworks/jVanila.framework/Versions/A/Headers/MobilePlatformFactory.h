//
//  MobilePlatformFactory.h
//  HelloVanila
//
//  Created by Pavan on 01/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "VanilaObject.h"
#import "IMobilePlatformFactory.h"
#import "SyncAdapter.h"
#import "ISqliteAccessor.h"
#import "DAOFactory.h"

@interface MobilePlatformFactory : VanilaObject <IMobilePlatformFactory>

-(id)initWithApplication:(id<IApplication>)application;

@end
