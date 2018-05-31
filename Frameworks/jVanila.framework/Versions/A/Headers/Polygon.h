//
//  Polygon.h
//  HelloVanila
//
//  Created by Pavan on 11/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "VanilaObject.h"
#import "IPolygon.h"
#import "IGenericList.h"
#import <GoogleMaps/GoogleMaps.h>

@interface Polygon : VanilaObject <IPolygon>

@property(nonatomic, retain)id<IGenericList> mLocations;

@property(nonatomic, retain) GMSMutablePath *path;

-(id)initWithLocations:(id<IGenericList>)locations;

@end
