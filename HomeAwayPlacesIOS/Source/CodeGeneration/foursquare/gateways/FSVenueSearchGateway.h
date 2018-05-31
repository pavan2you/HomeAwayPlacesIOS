//
//  FSVenueSearchGateway.h
//  HomeAwayPlacesIOS
//
//  Created by pavan on 31/05/18.
//  Copyright © 2018 pavan. All rights reserved.
//

#import <jVanila/jVanila.h>

#import "FSRequestDTO.h"

@interface FSVenueSearchGateway : SyncGateway

-(void)fireReadVenueListRequestWithFSRequestDTO:(FSRequestDTO *)dto;
@end
