//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/homeaway/homeawayplaces/foursquare/sync/dtos/FSPriceDTO.java
//
//

#import "FSPriceDTO.h"

@implementation FSPriceDTO

static NSString * CLASS_NAME_;

@synthesize CRUDOperation = CRUDOperation_;
@synthesize tier = tier_;
@synthesize message = message_;
@synthesize currency = currency_;

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
  if (self == [FSPriceDTO class]) {
    {
      CLASS_NAME_ = NSStringFromClass([FSPriceDTO class]);
    }
  }
}

- (void)copyAllPropertiesTo:(id)copy {
  
  FSPriceDTO *typedCopy = (FSPriceDTO *) copy;
  typedCopy.CRUDOperation = CRUDOperation_;
  typedCopy.tier = tier_;
  typedCopy.message = message_;
  typedCopy.currency = currency_;
}

@end