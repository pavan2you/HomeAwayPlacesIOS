//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/homeaway/homeawayplaces/foursquare/sync/dtos/FSItemDTO.java
//
//

#import "FSItemDTO.h"
#import "FSVenueDTO.h"

@implementation FSItemDTO

static NSString * CLASS_NAME_;

@synthesize CRUDOperation = CRUDOperation_;
@synthesize referralId = referralId_;
@synthesize venue = venue_;
@synthesize tips = tips_;

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
  if (self == [FSItemDTO class]) {
    {
      CLASS_NAME_ = NSStringFromClass([FSItemDTO class]);
    }
  }
}

- (void)copyAllPropertiesTo:(id)copy {
  
  FSItemDTO *typedCopy = (FSItemDTO *) copy;
  typedCopy.CRUDOperation = CRUDOperation_;
  typedCopy.referralId = referralId_;
  typedCopy.venue = venue_;
  typedCopy.tips = tips_;
}

@end
