//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/jvanila/core/exception/VanilaException.java
//
//

#import "Emulation.h"


@interface VanilaException : NSException {
 @public
  NSString *exceptionMessage_;
}

@property (nonatomic, copy) NSString *exceptionMessage;

- (id)init;
- (id)initWithNSString:(NSString *)exceptionMessage;
- (NSString *)getExceptionMessage;
@end

typedef VanilaException ComJvanilaCoreExceptionVanilaException;
