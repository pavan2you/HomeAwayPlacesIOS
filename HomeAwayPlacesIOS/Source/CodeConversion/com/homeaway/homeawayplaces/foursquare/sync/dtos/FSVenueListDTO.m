//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/homeaway/homeawayplaces/foursquare/sync/dtos/FSVenueListDTO.java
//
//

#import "FSVenueHoursDTO.h"
#import "FSVenueListDTO.h"

@implementation FSVenueListDTO

static NSString * CLASS_NAME_;

@synthesize CRUDOperation = CRUDOperation_;
@synthesize venus = venus_;

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
  if (self == [FSVenueListDTO class]) {
    {
      CLASS_NAME_ = NSStringFromClass([FSVenueHoursDTO class]);
    }
  }
}

- (void)copyAllPropertiesTo:(id)copy {
  
  FSVenueListDTO *typedCopy = (FSVenueListDTO *) copy;
  typedCopy.CRUDOperation = CRUDOperation_;
  typedCopy.venus = venus_;
}

@end
