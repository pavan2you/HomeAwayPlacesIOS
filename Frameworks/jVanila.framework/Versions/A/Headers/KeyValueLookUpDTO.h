//
//  KeyValueLookUpDTO.h
//  HelloVanila
//
//  Created by Pavan on 29/10/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "DataObject.h"

@interface KeyValueLookUpDTO : DataObject <NSCoding>

+(NSString *) CLASS_NAME;

@property (nonatomic, retain) NSMutableDictionary *userPreference;

- (void)putIntWithNSString:(NSString *)key
                   withInt:(int)value;
- (void)putFloatWithNSString:(NSString *)key
                   withFloat:(float)value;
- (void)putLongWithNSString:(NSString *)key
                withLongInt:(long long int)value;
- (void)putBooleanWithNSString:(NSString *)key
                      withBOOL:(BOOL)value;
- (void)putStringWithNSString:(NSString *)key
                 withNSString:(NSString *)value;
- (void)putNSCodingWithNSString:(NSString *)key
                 withNSCoding:(id<NSCoding>)value;
- (void)removeWithNSString:(NSString *)key;
- (void)removeAll;
- (int)getIntWithNSString:(NSString *)key
                  withInt:(int)defValue;
- (long long int)getLongWithNSString:(NSString *)key
                         withLongInt:(long long int)defValue;
- (float)getFloatWithNSString:(NSString *)key
                    withFloat:(float)defValue;
- (BOOL)getBooleanWithNSString:(NSString *)key
                      withBOOL:(BOOL)defValue;
- (NSString *)getStringWithNSString:(NSString *)key
                       withNSString:(NSString *)defValue;
-(id<NSCoding>) getNSCodingWithNSString:(NSString *)key;
- (BOOL)containsWithNSString:(NSString *)key;

//Private
-(void)savePreference;

@end
