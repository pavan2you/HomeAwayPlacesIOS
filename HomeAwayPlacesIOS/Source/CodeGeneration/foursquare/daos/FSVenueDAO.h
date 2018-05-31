//
//  FSVenueDAO.h
//  HomeAwayPlacesIOS
//
//  Created by pavan on 31/05/18.
//  Copyright © 2018 pavan. All rights reserved.
//

#import "TypedDAO.h"
#import <jVanila/jVanila.h>
#import "FSVenueDTO.h"

@interface FSVenueDAO : TypedDAO

-(id)initWithISqliteAccessor:(id<ISqliteAccessor>) sqliteAccessor;
-(void)setSQLiteAccessorWithISqliteAccessor:(id<ISqliteAccessor>) sqliteAccessor;
-(BOOL)isSQLiteDatabaseOpen;

-(AsyncToken *)updateRecordAsyncWithFSVenueDTO:(FSVenueDTO *)dto;

@end
