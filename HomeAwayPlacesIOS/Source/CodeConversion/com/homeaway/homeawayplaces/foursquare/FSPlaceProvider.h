//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/homeaway/homeawayplaces/foursquare/FSPlaceProvider.java
//
//

@class AsyncToken;
@class FSContext;
@class FSVenueDTO;
@class FSVenueListDTO;

@class Place;
@class PlacesContext;
@class PlacesProvider_SearchOptions;





#import <jVanila/jvanila.h>
#import "PlacesProvider.h"


@interface FSPlaceProvider : PlacesProvider < IEventSubscriber > {
 @public
  id<IStringUtils> mStringUtils_;
  id<IGenericMap> mVenueCache_;
  FSContext *mFSContext_;
}

@property (nonatomic, strong) id<IStringUtils> mStringUtils;
@property (nonatomic, strong) id<IGenericMap> mVenueCache;
@property (nonatomic, strong) FSContext *mFSContext;

- (id)initWithFSContext:(FSContext *)fsContext;
- (PlacesContext *)getContext;
- (AsyncToken *)fetchByIdAsyncWithNSString:(NSString *)id_;
- (AsyncToken *)fetchAllAsync;
- (AsyncToken *)fetchFavoritesAsync;
- (AsyncToken *)updateAsyncWithPlace:(Place *)place;
- (AsyncToken *)deleteAsyncWithPlace:(Place *)place;
- (void)notifyFetchVenueListResultWithAsyncToken:(AsyncToken *)token
                          withIGenericList:(id<IGenericList>)venueList;
- (void)notifyFetchVenueResultWithAsyncToken:(AsyncToken *)token
                        withFSVenueDTO:(FSVenueDTO *)venue;
- (void)searchWithNSString:(NSString *)query
withPlacesProvider_SearchOptions:(PlacesProvider_SearchOptions *)options;
- (void)onVenueSearchResultFailureEventWithNSString:(NSString *)query
    withFailureResponseDTO:(FailureResponseDTO *)failureResponse;
- (void)onVenueSearchResultSuccessEventWithNSString:(NSString *)query
        withFSVenueListDTO:(FSVenueListDTO *)venueList;
- (id<IGenericList>)toPlaceListWithIGenericList:(id<IGenericList>)venueList
                                                                                         withBOOL:(BOOL)applyLocalState;
- (Place *)toPlaceAndCacheVenueWithFSVenueDTO:(FSVenueDTO *)venue
                                                                                       withBOOL:(BOOL)applyLocalState;
- (void)subscribe;
- (void)unsubscribe;
- (void)onEventWithIEvent:(id<IEvent>)event;
@end

typedef FSPlaceProvider ComHomeawayHomeawayplacesFoursquareFSPlaceProvider;

@interface FSPlaceProvider_ListTokenCallback : NSObject < IAsyncTokenResultCallback > {
 @public
  FSPlaceProvider *this$0_;
}

@property (nonatomic, strong) FSPlaceProvider *this$0;

- (void)onTokenResultWithAsyncToken:(AsyncToken *)token
                                                withId:(id<IGenericList>)venueList;
- (id)initWithFSPlaceProvider:(FSPlaceProvider *)outer$0;
@end

@interface FSPlaceProvider_ItemTokenCallback : NSObject < IAsyncTokenResultCallback > {
 @public
  FSPlaceProvider *this$0_;
}

@property (nonatomic, strong) FSPlaceProvider *this$0;

- (void)onTokenResultWithAsyncToken:(AsyncToken *)token
                                                withId:(FSVenueDTO *)venue;
- (id)initWithFSPlaceProvider:(FSPlaceProvider *)outer$0;
@end
