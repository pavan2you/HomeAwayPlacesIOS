//
//  PolyineWrapper.h
//  jVanila
//
//  Created by Pavan on 20/11/15.
//  Copyright © 2015 jVanila. All rights reserved.
//

#import "IPolyline.h"
#import "PolylineOptionsWrapper.h"
#import <GoogleMaps/GoogleMaps.h>

@interface PolylineWrapper : ComparableObject <IPolyline>

@property(nonatomic, retain)GMSPolyline *mPolyline;
@property(nonatomic, retain)PolylineOptionsWrapper *mWrapper;

-(id)initWithPolylineOptions:(PolylineOptionsWrapper *)wrapper mapView:(GMSMapView *)mapView;

@end
