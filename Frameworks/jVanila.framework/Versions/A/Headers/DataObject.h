//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/jvanila/core/io/DataObject.java
//
//

@protocol IComparableObject;
@protocol IGenericList;
@protocol IWeakReference;

#import "Emulation.h"
#import "IEvent.h"

#define DataObject_serialVersionUID 1

@interface DataObject : NSObject < IEvent > {
 @public
  id<IWeakReference> tag_;
  id<IGenericList> tagList_;
  id<IGenericList> customTransientProperties_;
  id<IGenericList> mMandatoryFields_;
}

@property (nonatomic, strong) id<IWeakReference> tag;
@property (nonatomic, strong) id<IGenericList> tagList;
@property (nonatomic, strong) id<IGenericList> customTransientProperties;
@property (nonatomic, strong) id<IGenericList> mMandatoryFields;

+ (NSString *)CLASS_NAME;
- (BOOL)isEqualsToWithIComparableObject:(id<IComparableObject>)object;
- (NSUInteger)hashOfObject;
- (BOOL)isInstanceOfWithClass:(Class )clazz;
- (NSString *)getClassName;
- (NSString *)stringify;
- (id)init;
- (void)loadCustomTransientProperties;
- (BOOL)isOutOfRangeWithInt:(int)field
                    withInt:(int)min
                    withInt:(int)max
               withNSString:(NSString *)fieldName;
- (BOOL)isLessThanWithDouble:(double)field
                  withDouble:(double)limit
                withNSString:(NSString *)fieldName;
- (BOOL)isEmptyWithIGenericList:(id<IGenericList>)list
                                            withNSString:(NSString *)fieldName;
- (BOOL)isEmptyWithNSString:(NSString *)field
               withNSString:(NSString *)fieldName;
- (BOOL)isEmptyWithDataObject:(DataObject *)field
                                          withNSString:(NSString *)fieldName;
- (BOOL)isMandatoryDataMissing;
- (BOOL)isEmptyWithIGenericList:(id<IGenericList>)list;
- (BOOL)isEmptyWithNSString:(NSString *)field;
@end

typedef DataObject ComJvanilaCoreIoDataObject;
