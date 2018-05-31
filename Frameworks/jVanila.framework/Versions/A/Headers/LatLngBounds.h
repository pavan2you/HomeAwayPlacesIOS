//
//  LatLngBounds.h
//  jVanila
//
//  Created by Pavan on 20/11/15.
//  Copyright © 2015 jVanila. All rights reserved.
//

#import <jVanila/jVanila.h>
#import "ILatLngBounds.h"
#import <GoogleMaps/GoogleMaps.h>

@interface LatLngBounds : VanilaObject <ILatLngBounds>

@property(nonatomic, retain)GMSCoordinateBounds *mLatLngBounds;

@end
