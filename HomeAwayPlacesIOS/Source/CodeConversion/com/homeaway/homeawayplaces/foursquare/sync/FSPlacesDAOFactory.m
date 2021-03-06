//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/homeaway/homeawayplaces/foursquare/sync/FSPlacesDAOFactory.java
//
//

#import "FSPlacesDAOFactory.h"
#import "FSCategoryDAO.h"
#import "FSLocationDAO.h"
#import "FSVenueDAO.h"

@implementation FSPlacesDAOFactory

@synthesize mFSVenueDAO = mFSVenueDAO_;
@synthesize mFSLocationDAO = mFSLocationDAO_;
@synthesize mFSCategoryDAO = mFSCategoryDAO_;
@synthesize mLock_FSPlacesDAOFactory = mLock_FSPlacesDAOFactory_;

- (id)init {
  if ((self = [super init])) {
    mLock_FSPlacesDAOFactory_ = [[NSObject alloc] init];
  }
  return self;
}

- (FSVenueDAO *)getFSVenueDAO {
  @synchronized (mLock_FSPlacesDAOFactory_) {
    return [self getFSVenueDAOInternal];
  }
}

- (FSVenueDAO *)getFSVenueDAOInternal {
  if (mFSVenueDAO_ == nil) {
    mFSVenueDAO_ = [[FSVenueDAO alloc] initWithISqliteAccessor:mSqliteAccessor_];
  }
  return mFSVenueDAO_;
}

- (FSCategoryDAO *)getFSCategoryDAO {
  @synchronized (mLock_FSPlacesDAOFactory_) {
    return [self getFSCategoryDAOInternal];
  }
}

- (FSCategoryDAO *)getFSCategoryDAOInternal {
  if (mFSCategoryDAO_ == nil) {
    mFSCategoryDAO_ = [[FSCategoryDAO alloc] initWithISqliteAccessor:mSqliteAccessor_];
  }
  return mFSCategoryDAO_;
}

- (FSLocationDAO *)getFSLocationDAO {
  @synchronized (mLock_FSPlacesDAOFactory_) {
    return [self getFSLocationDAODAOInternal];
  }
}

- (FSLocationDAO *)getFSLocationDAODAOInternal {
  if (mFSLocationDAO_ == nil) {
    mFSLocationDAO_ = [[FSLocationDAO alloc] initWithISqliteAccessor:mSqliteAccessor_];
  }
  return mFSLocationDAO_;
}

- (void)onSQLiteDatabaseOpenWithISqliteAccessor:(id<ISqliteAccessor>)sqliteAccessor {
  [super onSQLiteDatabaseOpenWithISqliteAccessor:sqliteAccessor];
  @synchronized (mLock_FSPlacesDAOFactory_) {
    [[self getFSVenueDAOInternal] setSQLiteAccessorWithISqliteAccessor:sqliteAccessor];
    [[self getFSLocationDAODAOInternal] setSQLiteAccessorWithISqliteAccessor:sqliteAccessor];
    [[self getFSCategoryDAOInternal] setSQLiteAccessorWithISqliteAccessor:sqliteAccessor];
  }
}

- (BOOL)isDAOIntegrityOK {
  @synchronized (mLock_FSPlacesDAOFactory_) {
    BOOL check = [super isDAOIntegrityOK] && [[self getFSVenueDAOInternal] isSQLiteDatabaseOpen] && [[self getFSLocationDAODAOInternal] isSQLiteDatabaseOpen]&& [[self getFSCategoryDAOInternal] isSQLiteDatabaseOpen];
    return check;
  }
}

- (void)nullify {
  [super nullify];
  @synchronized (mLock_FSPlacesDAOFactory_) {
    mFSVenueDAO_ = nil;
    mFSLocationDAO_ = nil;
    mFSCategoryDAO_ = nil;
  }
}

- (void)copyAllPropertiesTo:(id)copy {
  
  FSPlacesDAOFactory *typedCopy = (FSPlacesDAOFactory *) copy;
  typedCopy.mFSVenueDAO = mFSVenueDAO_;
  typedCopy.mFSLocationDAO = mFSLocationDAO_;
  typedCopy.mFSCategoryDAO = mFSCategoryDAO_;
  typedCopy.mLock_FSPlacesDAOFactory = mLock_FSPlacesDAOFactory_;
}

@end
