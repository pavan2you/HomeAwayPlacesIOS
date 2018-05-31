//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/homeaway/homeawayplaces/domain/PlaceSearchResultEvent.java
//
//




#import <jVanila/jvanila.h>


@interface PlaceSearchResultEvent : DataObject {
 @public
  NSString *query_;
  id<IGenericList> placeList_;
  FailureResponseDTO *failureResponse_;
}

@property (nonatomic, copy) NSString *query;
@property (nonatomic, strong) id<IGenericList> placeList;
@property (nonatomic, strong) FailureResponseDTO *failureResponse;

+ (NSString *)CLASS_NAME;
- (id)initWithNSString:(NSString *)query
withIGenericList:(id<IGenericList>)placeList
withFailureResponseDTO:(FailureResponseDTO *)failureResponse;
@end

typedef PlaceSearchResultEvent ComHomeawayHomeawayplacesDomainPlaceSearchResultEvent;