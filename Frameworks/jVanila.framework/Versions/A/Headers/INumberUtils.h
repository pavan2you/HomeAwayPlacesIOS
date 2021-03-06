//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/jvanila/core/INumberUtils.java
//
//



#import "Emulation.h"
#import "IVanilaObject.h"

@protocol INumberUtils < IVanilaObject, NSObject >
- (int)roundOffFloatWithFloat:(float)value;
- (long long int)roundOffDoubleWithDouble:(double)value;
- (double)formatDoubleToDoubleWithDouble:(double)value
                            withNSString:(NSString *)doubleFormat;
- (long long int)roundOffToNearestLongWithDouble:(double)value;
- (double)getFloorOfDoubleWithDouble:(double)value;
- (NSString *)formatFloatWithFloat:(float)value
                      withNSString:(NSString *)floatFormat;
- (float)formatFloatToFloatWithFloat:(float)value
                        withNSString:(NSString *)floatFormat;
- (float)getFloorOfFloatWithFloat:(float)value;
- (float)getCeilOfFloatWithFloat:(float)value;
- (NSString *)formatMinutesWithInt:(int)minutes
                      withNSString:(NSString *)timeFormat;
- (NSString *)stringifyIntWithInt:(int)intValue;
- (NSString *)stringifyLongWithLongInt:(long long int)longValue;
- (NSString *)stringifyDoubleWithDouble:(double)doubleValue;
- (NSString *)stringifyFloatWithFloat:(float)floatValue;
- (float)maxOfFloatsWithFloat:(float)f1
                    withFloat:(float)f2;
- (double)maxOfDoublesWithDouble:(double)d1
                      withDouble:(double)d2;
- (int)maxOfIntsWithInt:(int)i1
                withInt:(int)i2;
- (long long int)maxOfLongsWithLongInt:(long long int)l1
                           withLongInt:(long long int)l2;
- (float)minOfFloatsWithFloat:(float)f1
                    withFloat:(float)f2;
- (double)minOfDoublesWithDouble:(double)d1
                      withDouble:(double)d2;
- (int)minOfIntsWithInt:(int)i1
                withInt:(int)i2;
- (long long int)minOfLongsWithLongInt:(long long int)l1
                           withLongInt:(long long int)l2;
- (BOOL)areBytesEqualWithNSData:(NSData *)b1
                     withNSData:(NSData *)b2;
@end

#define ComJvanilaCoreINumberUtils INumberUtils
