//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/homeaway/homeawayplaces/foursquare/sync/dtos/FSCategoryDTO.java
//
//

#import "FSCategoryDTO.h"
#import "FSIconDTO.h"

@implementation FSCategoryDTO

static NSString * CLASS_NAME_;

@synthesize CRUDOperation = CRUDOperation_;
@synthesize id_ = id__;
@synthesize name = name_;
@synthesize pluralName = pluralName_;
@synthesize shortName = shortName_;
@synthesize icon = icon_;
@synthesize primary = primary_;

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
  if (self == [FSCategoryDTO class]) {
    {
      CLASS_NAME_ = NSStringFromClass([FSCategoryDTO class]);
    }
  }
}

- (void)copyAllPropertiesTo:(id)copy {
  
  FSCategoryDTO *typedCopy = (FSCategoryDTO *) copy;
  typedCopy.CRUDOperation = CRUDOperation_;
  typedCopy.id_ = id__;
  typedCopy.name = name_;
  typedCopy.pluralName = pluralName_;
  typedCopy.shortName = shortName_;
  typedCopy.icon = icon_;
  typedCopy.primary = primary_;
}

@end