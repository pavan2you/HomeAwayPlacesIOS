//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/homeaway/homeawayplaces/sync/dtos/StaticMapDTO.java
//
//



#import <jVanila/jvanila.h>


#define StaticMapDTO_serialVersionUID 1

@interface StaticMapDTO : DataObject {
 @public
  NSString *CRUDOperation_;
  NSData *mapRawData_;
}

@property (nonatomic, copy) NSString *CRUDOperation;
@property (nonatomic, strong) NSData *mapRawData;

+ (NSString *)CLASS_NAME;
- (id)init;
@end

typedef StaticMapDTO ComHomeawayHomeawayplacesSyncDtosStaticMapDTO;
