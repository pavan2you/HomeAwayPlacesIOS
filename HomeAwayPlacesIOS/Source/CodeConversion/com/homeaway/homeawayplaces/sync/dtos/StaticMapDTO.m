//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/homeaway/homeawayplaces/sync/dtos/StaticMapDTO.java
//
//

#import "StaticMapDTO.h"

@implementation StaticMapDTO

static NSString * CLASS_NAME_;

@synthesize CRUDOperation = CRUDOperation_;
@synthesize mapRawData = mapRawData_;

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
  if (self == [StaticMapDTO class]) {
    {
      CLASS_NAME_ = NSStringFromClass([StaticMapDTO class]);
    }
  }
}

- (void)copyAllPropertiesTo:(id)copy {
  
  StaticMapDTO *typedCopy = (StaticMapDTO *) copy;
  typedCopy.CRUDOperation = CRUDOperation_;
  typedCopy.mapRawData = mapRawData_;
}

@end