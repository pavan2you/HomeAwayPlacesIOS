//
//  StaticMapGateway.h
//  HomeAwayPlacesIOS
//
//  Created by pavan on 31/05/18.
//  Copyright © 2018 pavan. All rights reserved.
//

#import <jVanila/jVanila.h>

#import "StaticMapRequestDTO.h"

@interface StaticMapGateway : SyncGateway

-(void)fireLoadStaticMapRequestWithStaticMapRequestDTO:(StaticMapRequestDTO *)dto;

@end
