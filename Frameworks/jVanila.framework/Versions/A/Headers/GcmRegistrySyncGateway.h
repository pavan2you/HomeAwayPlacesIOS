//
//  GcmRegistrySyncGateway.h
//  jVanila
//
//  Created by Pavan on 11/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "SyncGateway.h"
#import "GcmRegistrySyncOutDTO.h"

@interface GcmRegistrySyncGateway : SyncGateway

+(NSString *) CLASS_NAME;
+(NSString *) GCM_REGISTRY_OBJ;
+(NSString *) GCM_UNREGISTRY_OBJ;

-(void)fireDeviceRegistrationIdRequestWithGcmRegistrySyncOutDTO:(GcmRegistrySyncOutDTO *)dto;
-(void)fireDeviceUnRegistrationIdRequestWithGcmRegistrySyncOutDTO:(GcmRegistrySyncOutDTO *)dto;

@end
