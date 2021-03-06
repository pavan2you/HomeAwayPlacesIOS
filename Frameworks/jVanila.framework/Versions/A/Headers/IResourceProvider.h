//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/jvanila/core/locale/IResourceProvider.java
//
//

@class IOSObjectArray;
@class Resource;

#import "Emulation.h"
#import "IVanilaObject.h"

@protocol IResourceProvider < IVanilaObject, NSObject >
- (int)getResourceIdentifierWithNSString:(NSString *)resourceName
                            withNSString:(NSString *)defType;
- (int)getResourceIdentifierWithNSString:(NSString *)resourceName
                            withNSString:(NSString *)defType
                            withNSString:(NSString *)defPackage;
- (NSString *)getStringWithNSString:(NSString *)key;
- (NSString *)getStringWithNSString:(NSString *)key withNSArray:(NSArray *)params, ...;
- (id)resolveResourceWithResource:(Resource *)resource;
@end

#define ComJvanilaCoreLocaleIResourceProvider IResourceProvider
