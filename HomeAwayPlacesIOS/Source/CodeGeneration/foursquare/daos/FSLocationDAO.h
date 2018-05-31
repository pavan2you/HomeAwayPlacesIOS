//
//  FSLocationDAO.h
//  HomeAwayPlacesIOS
//
//  Created by pavan on 31/05/18.
//  Copyright © 2018 pavan. All rights reserved.
//

#import "TypedDAO.h"

@interface FSLocationDAO : TypedDAO

-(id)initWithISqliteAccessor:(id<ISqliteAccessor>) sqliteAccessor;
-(void)setSQLiteAccessorWithISqliteAccessor:(id<ISqliteAccessor>) sqliteAccessor;
-(BOOL)isSQLiteDatabaseOpen;

@end
