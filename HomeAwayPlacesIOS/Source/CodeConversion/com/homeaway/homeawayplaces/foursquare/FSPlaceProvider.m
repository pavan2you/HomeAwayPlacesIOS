//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/homeaway/homeawayplaces/foursquare/FSPlaceProvider.java
//
//

#import "Place.h"
#import "PlacesContext.h"
#import "PlacesProvider.h"
#import "FSPlaceProvider.h"
#import "FSContext.h"
#import "FSPlacesDAOFactory.h"
#import "FSVenueDAO.h"
#import "FSCategoryDTO.h"
#import "FSIconDTO.h"
#import "FSLocationDTO.h"
#import "FSRequestDTO.h"
#import "FSVenueDTO.h"
#import "FSVenueListDTO.h"
#import "FSVenueSearchGateway.h"

@implementation FSPlaceProvider

@synthesize mStringUtils = mStringUtils_;
@synthesize mVenueCache = mVenueCache_;
@synthesize mFSContext = mFSContext_;

- (id)initWithFSContext:(FSContext *)fsContext {
  if ((self = [super init])) {
    mFSContext_ = fsContext;
    mStringUtils_ = [mMobilePlatformFactory_ getStringUtils];
    mVenueCache_ = ((id<IGenericMap>) [mMobilePlatformFactory_ newMap]);
  }
  return self;
}

- (PlacesContext *)getContext {
  return mFSContext_;
}

- (AsyncToken *)fetchByIdAsyncWithNSString:(NSString *)id_ {
  AsyncToken *placeToken = [[AsyncToken alloc] init];
  FSPlacesDAOFactory *daoFactory = ((FSPlacesDAOFactory *) [mMobilePlatformFactory_ getDAOFactory]);
  AsyncToken *venueToken = [[daoFactory getFSVenueDAO] getRecordByColumnAsyncWithNSString:@"venue_id" withNSString:id_];
  venueToken.hook = placeToken;
  placeToken.hook = venueToken;
  [venueToken addCallbackWithIAsyncTokenResultCallback:[[FSPlaceProvider_ItemTokenCallback alloc] initWithFSPlaceProvider:self]];
  return placeToken;
}

- (AsyncToken *)fetchAllAsync {
  AsyncToken *placeToken = [[AsyncToken alloc] init];
  FSPlacesDAOFactory *daoFactory = ((FSPlacesDAOFactory *) [mMobilePlatformFactory_ getDAOFactory]);
  AsyncToken *venueToken = [[daoFactory getFSVenueDAO] getAllRecordsAsync];
  venueToken.hook = placeToken;
  placeToken.hook = venueToken;
  [venueToken addCallbackWithIAsyncTokenResultCallback:[[FSPlaceProvider_ListTokenCallback alloc] initWithFSPlaceProvider:self]];
  return placeToken;
}

- (AsyncToken *)fetchFavoritesAsync {
  AsyncToken *placeToken = [[AsyncToken alloc] init];
  FSPlacesDAOFactory *daoFactory = ((FSPlacesDAOFactory *) [mMobilePlatformFactory_ getDAOFactory]);
  AsyncToken *venueToken = [[daoFactory getFSVenueDAO] getRecordListByColumnAsyncWithNSString:@"isFavorite" withNSString:@"1"];
  venueToken.hook = placeToken;
  placeToken.hook = venueToken;
  [venueToken addCallbackWithIAsyncTokenResultCallback:[[FSPlaceProvider_ListTokenCallback alloc] initWithFSPlaceProvider:self]];
  return placeToken;
}

- (AsyncToken *)updateAsyncWithPlace:(Place *)place {
  FSVenueDTO *venue = ((FSVenueDTO *) [mVenueCache_ getWithId:place.placeId]);
  if (venue == nil) {
    venue = [[FSVenueDTO alloc] init];
    venue.id_ = place.placeId;
  }
  venue.isFavorite = place.isFavorite;
  FSPlacesDAOFactory *daoFactory = ((FSPlacesDAOFactory *) [mMobilePlatformFactory_ getDAOFactory]);
  return [[daoFactory getFSVenueDAO] updateRecordAsyncWithFSVenueDTO:venue];
}

- (AsyncToken *)deleteAsyncWithPlace:(Place *)place {
  AsyncToken *venueToken = nil;
  FSVenueDTO *venue = ((FSVenueDTO *) [mVenueCache_ getWithId:place.placeId]);
  if (venue != nil) {
    venue.isFavorite = place.isFavorite;
    FSPlacesDAOFactory *daoFactory = ((FSPlacesDAOFactory *) [mMobilePlatformFactory_ getDAOFactory]);
    venueToken = [[daoFactory getFSVenueDAO] deleteRecordByIdAsyncWithNSString:venue.id_];
  }
  return venueToken;
}

- (void)notifyFetchVenueListResultWithAsyncToken:(AsyncToken *)token
                          withIGenericList:(id<IGenericList>)venueList {
  AsyncToken *redirectToken = ((AsyncToken *) token.hook);
  [redirectToken setResultWithId:[self toPlaceListWithIGenericList:venueList withBOOL:NO]];
  [((id<IEventBus>) [((id<IPlatformFactory>) [PlatformFactoryLocator getPlatformFactory]) getEventBus]) publishWithIEvent:redirectToken];
}

- (void)notifyFetchVenueResultWithAsyncToken:(AsyncToken *)token
                        withFSVenueDTO:(FSVenueDTO *)venue {
  AsyncToken *redirectToken = ((AsyncToken *) token.hook);
  [redirectToken setResultWithId:[self toPlaceAndCacheVenueWithFSVenueDTO:venue withBOOL:NO]];
  [((id<IEventBus>) [((id<IPlatformFactory>) [PlatformFactoryLocator getPlatformFactory]) getEventBus]) publishWithIEvent:redirectToken];
}

- (void)searchWithNSString:(NSString *)query
withPlacesProvider_SearchOptions:(PlacesProvider_SearchOptions *)options {
  if ([self isCacheHavingResultsWithNSString:query]) {
    [self searchCompleteWithNSString:query withIGenericList:((id<IGenericList>) [mRecentSearchResultsMap_ getWithId:query]) withFailureResponseDTO:nil];
  }
  else {
    FSRequestDTO *request = [mFSContext_ buildVenueRequestWithNSString:query withPlacesProvider_SearchOptions:options];
    FSVenueSearchGateway *gateway = ((FSVenueSearchGateway *) [[mMobilePlatformFactory_ getSyncAdapter] getSyncGatewayWithNSString:[FSVenueSearchGateway CLASS_NAME]]);
    [gateway fireReadVenueListRequestWithFSRequestDTO:request];
  }
}

- (void)onVenueSearchResultFailureEventWithNSString:(NSString *)query
    withFailureResponseDTO:(FailureResponseDTO *)failureResponse {
  [self searchCompleteWithNSString:query withIGenericList:nil withFailureResponseDTO:failureResponse];
}

- (void)onVenueSearchResultSuccessEventWithNSString:(NSString *)query
        withFSVenueListDTO:(FSVenueListDTO *)venueList {
  id<IGenericList> placeList = [self toPlaceListWithIGenericList:venueList.venus withBOOL:YES];
  [self searchCompleteWithNSString:query withIGenericList:placeList withFailureResponseDTO:nil];
}

- (id<IGenericList>)toPlaceListWithIGenericList:(id<IGenericList>)venueList
                                                                                         withBOOL:(BOOL)applyLocalState {
  id<IGenericList> placeList = ((id<IGenericList>) [mMobilePlatformFactory_ newList]);
  if (venueList != nil) {
    {
      for (NSObject* loopObj in venueList) {
      
        FSVenueDTO *venue = ((FSVenueDTO *) loopObj);
        [placeList addWithId:[self toPlaceAndCacheVenueWithFSVenueDTO:venue withBOOL:applyLocalState]];
      }
    }
  }
  return placeList;
}

- (Place *)toPlaceAndCacheVenueWithFSVenueDTO:(FSVenueDTO *)venue
                                                                                       withBOOL:(BOOL)applyLocalState {
  if (applyLocalState) {
    FSVenueDTO *cachedVenue = ((FSVenueDTO *) [mVenueCache_ getWithId:venue.id_]);
    if (cachedVenue != nil) {
      venue.isFavorite = cachedVenue.isFavorite;
    }
  }
  Place *place = [[Place alloc] init];
  place.placeId = venue.id_;
  place.name = venue.name;
  place.address = venue.location.address;
  place.latLng = [[VanilaLocation alloc] init];
  place.latLng.latitude = venue.location.lat;
  place.latLng.longitude = venue.location.lng;
  {
    for (NSObject* loopObj in venue.categories) {
    
      FSCategoryDTO *category = ((FSCategoryDTO *) loopObj);
      if (category.primary) {
        place.categoryId = category.id_;
        place.category = category.name;
        if (category.icon != nil) {
          place.imageUrl = [NSString stringWithFormat:@"%@32%@", category.icon.prefix, category.icon.suffix];
        }
      }
    }
  }
  place.websiteUrl = venue.url;
  if (venue.location.distance == 0) {
    id<ILocationApi> locationApi = [mMobilePlatformFactory_ getLocationApi];
    venue.location.distance = (int) [locationApi distanceBetweenWithDouble:venue.location.lat withDouble:venue.location.lng withDouble:mFSContext_.poi.latitude withDouble:mFSContext_.poi.longitude];
  }
  place.distanceToInterest = venue.location.distance;
  place.rating = venue.rating;
  place.isFavorite = venue.isFavorite;
  [mVenueCache_ putWithId:venue.id_ withId:venue];
  return place;
}

- (void)subscribe {
  [mEventBus_ subscribeWithNSString:[NetResponseProcessingCompletedEvent CLASS_NAME] withIEventSubscriber:self];
  [mEventBus_ subscribeWithNSString:[FailureResponseDTO CLASS_NAME] withIEventSubscriber:self];
}

- (void)unsubscribe {
  [mEventBus_ subscribeWithNSString:[NetResponseProcessingCompletedEvent CLASS_NAME] withIEventSubscriber:self];
  [mEventBus_ subscribeWithNSString:[FailureResponseDTO CLASS_NAME] withIEventSubscriber:self];
}

- (void)onEventWithIEvent:(id<IEvent>)event {
  if ([event isInstanceOfWithClass:[NetResponseProcessingCompletedEvent class]]) {
    NetResponseProcessingCompletedEvent *nrpce = (NetResponseProcessingCompletedEvent *) event;
    if (nrpce.processingStats != nil) {
        //TODO : FIX : [nrpce.processingStats printStats];
    }
    if ([mStringUtils_ areXAndYEqualWithNSString:nrpce.mRequestType withNSString:[FSVenueDTO CLASS_NAME]]) {
      [self onVenueSearchResultSuccessEventWithNSString:nrpce.mContainedObjectUniqueId withFSVenueListDTO:(FSVenueListDTO *) nrpce.mProcessedResultDTO];
    }
  }
  else if ([event isInstanceOfWithClass:[FailureResponseDTO class]]) {
    FailureResponseDTO *failureEvent = (FailureResponseDTO *) event;
    if (failureEvent.processingStats != nil) {
      //TODO : FIX : [failureEvent.processingStats printStats];
    }
    if ([mStringUtils_ areXAndYEqualWithNSString:failureEvent.RequestType withNSString:[FSVenueDTO CLASS_NAME]]) {
      [self onVenueSearchResultFailureEventWithNSString:failureEvent.ContainedObjectUniqueId withFailureResponseDTO:failureEvent];
    }
  }
}

- (void)copyAllPropertiesTo:(id)copy {
  
  FSPlaceProvider *typedCopy = (FSPlaceProvider *) copy;
  typedCopy.mStringUtils = mStringUtils_;
  typedCopy.mVenueCache = mVenueCache_;
  typedCopy.mFSContext = mFSContext_;
}

@end
@implementation FSPlaceProvider_ListTokenCallback

@synthesize this$0 = this$0_;

- (void)onTokenResultWithAsyncToken:(AsyncToken *)token
                                                withId:(id<IGenericList>)venueList {
  [this$0_ notifyFetchVenueListResultWithAsyncToken:token withIGenericList:venueList];
}

- (id)initWithFSPlaceProvider:(FSPlaceProvider *)outer$0 {
  if ((self = [super init])) {
    this$0_ = outer$0;
  }
  return self;
}

- (void)copyAllPropertiesTo:(id)copy {
  
  FSPlaceProvider_ListTokenCallback *typedCopy = (FSPlaceProvider_ListTokenCallback *) copy;
  typedCopy.this$0 = this$0_;
}

@end
@implementation FSPlaceProvider_ItemTokenCallback

@synthesize this$0 = this$0_;

- (void)onTokenResultWithAsyncToken:(AsyncToken *)token
                                                withId:(FSVenueDTO *)venue {
  [this$0_ notifyFetchVenueResultWithAsyncToken:token withFSVenueDTO:venue];
}

- (id)initWithFSPlaceProvider:(FSPlaceProvider *)outer$0 {
  if ((self = [super init])) {
    this$0_ = outer$0;
  }
  return self;
}

- (void)copyAllPropertiesTo:(id)copy {
  
  FSPlaceProvider_ItemTokenCallback *typedCopy = (FSPlaceProvider_ItemTokenCallback *) copy;
  typedCopy.this$0 = this$0_;
}

@end