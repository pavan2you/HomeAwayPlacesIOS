//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/homeaway/homeawayplaces/domain/MarkerModel.java
//
//

@class Place;




#import <jVanila/jvanila.h>

@interface MarkerModel : NSObject {
 @public
  Place *mPlace_;
  id<ILocationApi> mLocationApi_;
}

@property (nonatomic, strong) Place *mPlace;
@property (nonatomic, strong) id<ILocationApi> mLocationApi;

- (id)initWithPlace:(Place *)place;
- (id)initWithVanilaLocation:(VanilaLocation *)location;
- (void)init__WithPlace:(Place *)place ;
- (Place *)getPlace;
- (VanilaLocation *)getLocation;
- (id<IMarkerOptions>)newMarkerOptions ;
- (id<IMarkerOptions>)newStillMarkerOptionsWithVanilaLocation:(VanilaLocation *)location ;
@end

typedef MarkerModel ComHomeawayHomeawayplacesDomainMarkerModel;