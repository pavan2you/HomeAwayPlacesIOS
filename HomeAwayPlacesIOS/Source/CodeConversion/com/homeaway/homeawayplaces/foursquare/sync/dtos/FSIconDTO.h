//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/homeaway/homeawayplaces/foursquare/sync/dtos/FSIconDTO.java
//
//

#import <jVanila/jvanila.h>


#define FSIconDTO_serialVersionUID 1

@interface FSIconDTO : DataObject {
 @public
  NSString *CRUDOperation_;
  NSString *prefix_;
  NSString *suffix_;
}

@property (nonatomic, copy) NSString *CRUDOperation;
@property (nonatomic, copy) NSString *prefix;
@property (nonatomic, copy) NSString *suffix;

+ (NSString *)CLASS_NAME;
- (id)init;
@end

typedef FSIconDTO ComHomeawayHomeawayplacesFoursquareSyncDtosFSIconDTO;