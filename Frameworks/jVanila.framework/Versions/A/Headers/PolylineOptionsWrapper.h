//
//  PolylineOptionsWrapper.h
//  jVanila
//
//  Created by Pavan on 20/11/15.
//  Copyright © 2015 jVanila. All rights reserved.
//

#import "IPolylineOptions.h"
#import "PolylineParams.h"
#import <CoreLocation/CoreLocation.h>
#import <GoogleMaps/GoogleMaps.h>
#import <UIKit/UIKit.h>

@interface PolylineOptionsWrapper : ComparableObject <IPolylineOptions>

@property(nonatomic, retain)PolylineParams *mParams;

@property(nonatomic, retain) GMSMutablePath *path;
@property(nonatomic, assign) CGFloat strokeWidth;
@property(nonatomic, retain) UIColor* strokeColor;
@property(nonatomic, assign) BOOL geodesic;
@property(nonatomic, assign) BOOL visible;
@property(nonatomic, assign) int zIndex;

-(id)initWithPolylineParams:(PolylineParams *)params;

@end
