//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/homeaway/homeawayplaces/sync/dtos/StaticMapRequestDTO.java
//
//

#import "StaticMapRequestDTO.h"

@implementation StaticMapRequestDTO

static NSString * CLASS_NAME_;

@synthesize CRUDOperation = CRUDOperation_;
@synthesize centerLatitude = centerLatitude_;
@synthesize centerLongitude = centerLongitude_;
@synthesize zoomLevel = zoomLevel_;
@synthesize width = width_;
@synthesize height = height_;
@synthesize entityName = entityName_;
@synthesize locationPoints = locationPoints_;
@synthesize radius = radius_;
@synthesize markerList = markerList_;

+ (NSString *)CLASS_NAME {
  return CLASS_NAME_;
}

- (id)init {
  if ((self = [super init])) {
    CRUDOperation_ = @"U";
  }
  return self;
}

+ (void)initialize {
  if (self == [StaticMapRequestDTO class]) {
    {
      CLASS_NAME_ = NSStringFromClass([StaticMapRequestDTO class]);
    }
  }
}

- (void)copyAllPropertiesTo:(id)copy {
  
  StaticMapRequestDTO *typedCopy = (StaticMapRequestDTO *) copy;
  typedCopy.CRUDOperation = CRUDOperation_;
  typedCopy.centerLatitude = centerLatitude_;
  typedCopy.centerLongitude = centerLongitude_;
  typedCopy.zoomLevel = zoomLevel_;
  typedCopy.width = width_;
  typedCopy.height = height_;
  typedCopy.entityName = entityName_;
  typedCopy.locationPoints = locationPoints_;
  typedCopy.radius = radius_;
  typedCopy.markerList = markerList_;
}

@end