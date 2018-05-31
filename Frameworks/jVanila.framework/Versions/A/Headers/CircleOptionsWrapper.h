//
//  CricleOptionsWrapper.h
//  jVanila
//
//  Created by Pavan on 20/11/15.
//  Copyright © 2015 jVanila. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import "ICircleOptions.h"
#import "CircleParams.h"
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>

@interface CircleOptionsWrapper : ComparableObject <ICircleOptions>

@property(nonatomic, retain)CircleParams *mParams;

@property(nonatomic, assign) CLLocationCoordinate2D position;
@property(nonatomic, assign) CLLocationDistance radius;
@property(nonatomic, assign) CGFloat strokeWidth;
@property(nonatomic, retain) UIColor *strokeColor;
@property(nonatomic, retain) UIColor *fillColor;
@property(nonatomic, retain) NSString* title;
@property(nonatomic, assign) int zIndex;

-(id)initWithCicleParams:(CircleParams *)params;

@end
