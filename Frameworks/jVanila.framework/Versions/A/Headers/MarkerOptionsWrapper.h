//
//  MarkerOptionsWrapper.h
//  jVanila
//
//  Created by Pavan on 20/11/15.
//  Copyright © 2015 jVanila. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import "IMarkerOptions.h"
#import "MarkerParams.h"
#import <CoreLocation/CoreLocation.h>

@interface MarkerOptionsWrapper : ComparableObject <IMarkerOptions>

@property(nonatomic, retain)MarkerParams *mParams;

@property(nonatomic, assign) CLLocationCoordinate2D position;
@property(nonatomic, assign) float opacity;
@property(nonatomic, assign) CGPoint groundAnchor;
@property(nonatomic, assign) BOOL draggable;
@property(nonatomic, retain) id icon;
@property(nonatomic, assign) BOOL flat;
@property(nonatomic, assign) CGPoint infoWindowAnchor;
@property(nonatomic, assign) BOOL visible;
@property(nonatomic, assign) CLLocationDegrees rotation;
@property(nonatomic, retain) NSString* title;
@property(nonatomic, retain) NSString* snippet;
@property(nonatomic, assign) int zIndex;

-(id)initWithMarkerParams:(MarkerParams *)params;

@end
