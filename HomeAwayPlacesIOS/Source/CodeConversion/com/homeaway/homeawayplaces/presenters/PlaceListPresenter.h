//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/homeaway/homeawayplaces/presenters/PlaceListPresenter.java
//
//

@class AsyncToken;

@class Place;
@class PlaceModifiedEvent;
@class PlaceSearchResultEvent;



@protocol IPlaceListView;

#import <jVanila/jvanila.h>


@interface PlaceListPresenter : Presenter {
 @public
  VanilaLocation *mCurrentPointOfInterest_;
  int mFetchLimit_;
  id<IGenericList> mSearchedPlaceList_;
  id<IGenericList> mFavoritePlaceList_;
  id<IGenericList> mCurrentPlaceList_;
  NSString *mTitle_;
  NSString *mSearchFieldHint_;
  NSString *mSearchPlacesTip_;
  NSString *mNoFavPlacesMessage_;
  NSString *mNoResultsMessage_;
  NSString *mNoInternetMessage_;
  NSString *mUnrecoverableMessage_;
  NSString *mCurrentNoDataMessage_;
  AsyncToken *mReadFavoritesToken_;
  BOOL mIsSearchInProgress_;
  NSString *mCurrentSearchPhrase_;
  NSString *mRetriableSearchPhrase_;
  BOOL mShowFavorites_;
  NSString *mLoadedSearchPhrase_;
}

@property (nonatomic, strong) VanilaLocation *mCurrentPointOfInterest;
@property (nonatomic, assign) int mFetchLimit;
@property (nonatomic, strong) id<IGenericList> mSearchedPlaceList;
@property (nonatomic, strong) id<IGenericList> mFavoritePlaceList;
@property (nonatomic, strong) id<IGenericList> mCurrentPlaceList;
@property (nonatomic, copy) NSString *mTitle;
@property (nonatomic, copy) NSString *mSearchFieldHint;
@property (nonatomic, copy) NSString *mSearchPlacesTip;
@property (nonatomic, copy) NSString *mNoFavPlacesMessage;
@property (nonatomic, copy) NSString *mNoResultsMessage;
@property (nonatomic, copy) NSString *mNoInternetMessage;
@property (nonatomic, copy) NSString *mUnrecoverableMessage;
@property (nonatomic, copy) NSString *mCurrentNoDataMessage;
@property (nonatomic, strong) AsyncToken *mReadFavoritesToken;
@property (nonatomic, assign) BOOL mIsSearchInProgress;
@property (nonatomic, copy) NSString *mCurrentSearchPhrase;
@property (nonatomic, copy) NSString *mRetriableSearchPhrase;
@property (nonatomic, assign) BOOL mShowFavorites;
@property (nonatomic, copy) NSString *mLoadedSearchPhrase;

- (id)initWithIPlaceListView:(id<IPlaceListView>)view;
- (void)onCreate;
- (void)loadWithWithNSString:(NSString *)searchPhrase;
- (void)onDependenciesResolved;
- (void)loadPlaceContext;
- (void)loadModel;
- (void)loadFavourites;
- (void)showListOrInfoWithIGenericList:(id<IGenericList>)list;
- (void)onChangePoiMenuItemClick;
- (void)onUseMyLocationAsPoiMenuItemClick;
- (void)onMyFavPlacesMenuItemClick;
- (void)showFavoritesList;
- (void)onSearchPlacesWithNSString:(NSString *)searchPhrase;
- (void)onCancelSearchIconClick;
- (void)onPlaceItemClickWithPlace:(Place *)item;
- (void)onPlaceItemFavIconClickWithPlace:(Place *)place;
- (void)switchToSearchResultsIfFavoritesAreEmpty;
- (void)onMapIconClick;
- (void)syncChangeToDatabaseWithPlace:(Place *)place;
- (BOOL)isReadFavoritesTokenWithAsyncToken:(AsyncToken *)asyncToken;
- (void)onFetchingFavouritePlacesCompleteWithIGenericList:(id<IGenericList>)result;
- (void)onPlaceSearchResultEventWithPlaceSearchResultEvent:(PlaceSearchResultEvent *)event;
- (void)onPlaceSearchSuccessWithPlaceSearchResultEvent:(PlaceSearchResultEvent *)event;
- (void)onPlaceSearchFailureWithPlaceSearchResultEvent:(PlaceSearchResultEvent *)event;
- (void)onAsyncTokenJobCompleteWithAsyncToken:(AsyncToken *)asyncToken;
- (void)cancelIfReadFavoritesJobIsWaiting;
- (void)onPlaceModifiedEventWithPlaceModifiedEvent:(PlaceModifiedEvent *)event;
- (void)updateItemInListWithPlace:(Place *)modifiedPlace
                 withIGenericList:(id<IGenericList>)list
                                                  withBOOL:(BOOL)refreshList;
- (void)onNetworkAvailabilityEventWithNetworkAvailabilityEvent:(NetworkAvailabilityEvent *)event;
- (void)subscribeToEvents;
- (void)onEventWithIEvent:(id<IEvent>)event;
- (void)unsubscribeToEvents;
- (void)onBackPressed;
- (void)onDestroy;
- (void)onUseFoursquarePlacesMenuItemClick;
- (void)onUseGooglePlacesMenuItemClick;
@end

typedef PlaceListPresenter ComHomeawayHomeawayplacesPresentersPlaceListPresenter;
