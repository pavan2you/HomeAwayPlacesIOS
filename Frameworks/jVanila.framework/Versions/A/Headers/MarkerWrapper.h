//
//  MarkerWrapper.h
//  jVanila
//
//  Created by Pavan on 20/11/15.
//  Copyright © 2015 jVanila. All rights reserved.
//

#import <GoogleMaps/GoogleMaps.h>
#import "MarkerOptionsWrapper.h"
#import "IMarker.h"

@interface MarkerWrapper : ComparableObject <IMarker>

@property(nonatomic, retain)GMSMarker *mMarker;
@property(nonatomic, retain)MarkerOptionsWrapper *mWrapper;

-(id)initWithMarkerOptions:(MarkerOptionsWrapper *)wrapper mapView:(GMSMapView *)mapView;

@end
