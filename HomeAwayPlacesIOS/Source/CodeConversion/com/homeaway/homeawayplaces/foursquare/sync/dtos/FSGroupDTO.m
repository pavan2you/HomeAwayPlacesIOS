//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/homeaway/homeawayplaces/foursquare/sync/dtos/FSGroupDTO.java
//
//

#import "FSGroupDTO.h"

@implementation FSGroupDTO

static NSString * CLASS_NAME_;

@synthesize CRUDOperation = CRUDOperation_;
@synthesize items = items_;

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
  if (self == [FSGroupDTO class]) {
    {
      CLASS_NAME_ = NSStringFromClass([FSGroupDTO class]);
    }
  }
}

- (void)copyAllPropertiesTo:(id)copy {
  
  FSGroupDTO *typedCopy = (FSGroupDTO *) copy;
  typedCopy.CRUDOperation = CRUDOperation_;
  typedCopy.items = items_;
}

@end
