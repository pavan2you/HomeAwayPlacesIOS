//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/jvanila/core/datatype/IDateTime.java
//
//

#import "Emulation.h"
#import "ICloneableObject.h"

@protocol IDateTime < ICloneableObject, NSObject >
- (long long int)getDifferenceInSecondsWithIDateTime:(id<IDateTime>)date;
- (void)setTimeInMillisecondsWithLongInt:(long long int)timeInMillis;
- (long long int)getTimeInMilliseconds;
@end

#define ComJvanilaCoreDatatypeIDateTime IDateTime