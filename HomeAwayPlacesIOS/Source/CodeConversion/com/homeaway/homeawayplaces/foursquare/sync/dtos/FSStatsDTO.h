//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/homeaway/homeawayplaces/foursquare/sync/dtos/FSStatsDTO.java
//
//

#import <jVanila/jvanila.h>


#define FSStatsDTO_serialVersionUID 1

@interface FSStatsDTO : DataObject {
 @public
  NSString *CRUDOperation_;
  int checkinsCount_;
  int usersCount_;
  int tipCount_;
}

@property (nonatomic, copy) NSString *CRUDOperation;
@property (nonatomic, assign) int checkinsCount;
@property (nonatomic, assign) int usersCount;
@property (nonatomic, assign) int tipCount;

+ (NSString *)CLASS_NAME;
- (id)init;
@end

typedef FSStatsDTO ComHomeawayHomeawayplacesFoursquareSyncDtosFSStatsDTO;
