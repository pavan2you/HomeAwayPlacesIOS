//
//  CircleWrapper.h
//  jVanila
//
//  Created by Pavan on 20/11/15.
//  Copyright © 2015 jVanila. All rights reserved.
//

#import <GoogleMaps/GoogleMaps.h>
#import "ICircle.h"
#import "CircleOptionsWrapper.h"

@interface CircleWrapper : ComparableObject<ICircle>

@property(nonatomic, retain)GMSCircle *mCircle;
@property(nonatomic, retain)CircleOptionsWrapper *mWrapper;

-(id)initWithCircleOptions:(CircleOptionsWrapper *)wrapper mapView:(GMSMapView *)mapView;

@end
