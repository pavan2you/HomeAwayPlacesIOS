//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/jvanila/mobile/storage/DAOFactory.java
//
//

@class LookUpDAO;
@protocol IGenericMap;
@protocol IPlatformFactory;
@protocol ISqliteAccessor;
@protocol ISyncStatsDAO;

#import "Emulation.h"
#import "IComparableObject.h"
#import "VanilaObject.h"
#import "IDAOFactory.h"

@interface DAOFactory : VanilaObject < IDAOFactory, IComparableObject > {
 @public
  id<IPlatformFactory> mPlatformFactory_;
  id<IGenericMap> mClassLookUp_;
  id<IGenericMap> mLookUpLookUp_;
  id<ISqliteAccessor> mSqliteAccessor_;
  id mLock_;
}

@property (nonatomic, strong) id<IPlatformFactory> mPlatformFactory;
@property (nonatomic, strong) id<IGenericMap> mClassLookUp;
@property (nonatomic, strong) id<IGenericMap> mLookUpLookUp;
@property (nonatomic, strong) id<ISqliteAccessor> mSqliteAccessor;
@property (nonatomic, strong) id mLock;

+ (NSString *)CLASS_NAME;
- (id)init;
- (void)init__ ;
- (LookUpDAO *)getLookUpDAOWithNSString:(NSString *)classOfT
                                                    withNSString:(NSString *)optionalFileName;
- (void)onSQLiteDatabaseFailedToOpenWithISqliteAccessor:(id<ISqliteAccessor>)sqliteAccessor;
- (void)onSQLiteDatabaseOpenWithISqliteAccessor:(id<ISqliteAccessor>)sqliteAccessor;
- (void)onSQLiteDatabaseCloseWithISqliteAccessor:(id<ISqliteAccessor>)sqliteAccessor;
- (BOOL)isSqliteAccessible;
- (id<ISyncStatsDAO>)getSyncStatsDAO;
- (BOOL)isDAOIntegrityOK;
- (void)nullify;
- (void)reset;
- (NSString *)stringify;
- (BOOL)isDebugBuild;
- (BOOL)isEqualsToWithIComparableObject:(id<IComparableObject>)object;
- (NSUInteger)hashOfObject;
- (BOOL)isInstanceOfWithClass:(Class )clazz;
@end

typedef DAOFactory ComJvanilaMobileStorageDAOFactory;
