//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/homeaway/homeawayplaces/foursquare/sync/dtos/FSTipDTO.java
//
//

#import <jVanila/jvanila.h>


#define FSTipDTO_serialVersionUID 1

@interface FSTipDTO : DataObject {
 @public
  NSString *CRUDOperation_;
  long long int createdAt_;
  NSString *text_;
  NSString *type_;
  NSString *canonicalUrl_;
}

@property (nonatomic, copy) NSString *CRUDOperation;
@property (nonatomic, assign) long long int createdAt;
@property (nonatomic, copy) NSString *text;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *canonicalUrl;

+ (NSString *)CLASS_NAME;
- (id)init;
@end

typedef FSTipDTO ComHomeawayHomeawayplacesFoursquareSyncDtosFSTipDTO;
