//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/homeaway/homeawayplaces/domain/MarkerModel.java
//
//

#import "MarkerModel.h"
#import "Place.h"

@implementation MarkerModel

@synthesize mPlace = mPlace_;
@synthesize mLocationApi = mLocationApi_;

- (id)initWithPlace:(Place *)place {
  if ((self = [super init])) {
    [self init__WithPlace:place];
  }
  return self;
}

- (id)initWithVanilaLocation:(VanilaLocation *)location {
  if ((self = [super init])) {
    Place *place = [[Place alloc] init];
    place.latLng = location;
    place.name = location.label;
    [self init__WithPlace:place];
  }
  return self;
}

- (void)init__WithPlace:(Place *)place  {
  mPlace_ = place;
  mLocationApi_ = [((id<IMobilePlatformFactory>) [MobilePlatformFactoryLocator getMobilePlatformFactory]) getLocationApi];
}

- (Place *)getPlace {
  return mPlace_;
}

- (VanilaLocation *)getLocation {
  return mPlace_.latLng;
}

- (id<IMarkerOptions>)newMarkerOptions  {
  VanilaLocation *location = mPlace_.latLng;
  location.label = mPlace_.name;
  return [self newStillMarkerOptionsWithVanilaLocation:location];
}

- (id<IMarkerOptions>)newStillMarkerOptionsWithVanilaLocation:(VanilaLocation *)location  {
  MarkerParams *markerParams = [[MarkerParams alloc] init];
  markerParams.position = location;
  markerParams.draggable = NO;
  markerParams.flat = NO;
  markerParams.title = location.label;
  return [mLocationApi_ newMarkerOptionsWithMarkerParams:markerParams];
}

- (void)copyAllPropertiesTo:(id)copy {
  
  MarkerModel *typedCopy = (MarkerModel *) copy;
  typedCopy.mPlace = mPlace_;
  typedCopy.mLocationApi = mLocationApi_;
}

@end