//
//  AssociationDAO.h
//  HomeAwayPlaces
//
//  Created by pavan on 31/05/18.
//  Copyright © 2018 pavan. All rights reserved.
//

#import <jVanila/jVanila.h>

#import "TypedDAO.h"

@interface AssociationDAO : TypedDAO

-(id)initWithISqliteAccessor:(id<ISqliteAccessor>) sqliteAccessor withNSString:(NSString *)name;
-(void)setSQLiteAccessorWithISqliteAccessor:(id<ISqliteAccessor>) sqliteAccessor;
-(BOOL)isSQLiteDatabaseOpen;

@end
