//
//  JSONUtils.h
//  HelloVanila
//
//  Created by Pavan on 29/10/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

@class DataObject;

@interface JSONUtils : NSObject

+(NSDictionary *)getDictionaryFromData:(NSData *)data;
+(NSString *)getClassNameFromString:(NSString *)string;
+(NSString *)getJsonStringForObject:(id)object;
+(id)getDTOFromJSONDictionary:(NSDictionary *)JSONDictionary withClassName:(NSString *)className;

+(DataObject *)toDataObjectWithNSString:(NSString *)jsonString withClass:(Class)clazz;
+(DataObject *)toDataObjectWithNSData:(NSData *)data withNSString:(NSString *)className;
+(NSString *)toJsonWithDataObject:(DataObject *)dtoObj;

@end
