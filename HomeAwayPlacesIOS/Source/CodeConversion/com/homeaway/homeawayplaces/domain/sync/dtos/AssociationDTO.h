//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/homeaway/homeawayplaces/domain/sync/dtos/AssociationDTO.java
//
//

#import <jVanila/jvanila.h>



#define AssociationDTO_serialVersionUID 1

@interface AssociationDTO : DataObject < ICloneableObject > {
 @public
  NSString *CRUDOperation_;
  NSString *lhs_uuid_;
  NSString *rhs_uuid_;
}

@property (nonatomic, copy) NSString *CRUDOperation;
@property (nonatomic, copy) NSString *lhs_uuid;
@property (nonatomic, copy) NSString *rhs_uuid;

+ (NSString *)CLASS_NAME;
- (id)init;
- (id<ICloneableObject>)deepClone;
@end

typedef AssociationDTO ComHomeawayHomeawayplacesDomainSyncDtosAssociationDTO;
