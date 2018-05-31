//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/homeaway/homeawayplaces/domain/sync/PlacesDAOFactory.java
//
//

@class AssociationDAO;
@class EntityJsonDAO;



#import <jVanila/jvanila.h>


@interface PlacesDAOFactory : DAOFactory {
 @public
  EntityJsonDAO *mEntityJsonDAO_;
  id<IGenericMap> mAssociationDAOMap_;
  id mLock_PlacesDAOFactory_;
}

@property (nonatomic, strong) EntityJsonDAO *mEntityJsonDAO;
@property (nonatomic, strong) id<IGenericMap> mAssociationDAOMap;
@property (nonatomic, strong) id mLock_PlacesDAOFactory;

- (id)init;
- (EntityJsonDAO *)getEntityJsonDAO;
- (EntityJsonDAO *)getEntityJsonDAOInternal;
- (AssociationDAO *)getAssociationDAOWithNSString:(NSString *)associationName;
- (AssociationDAO *)getAssociationDAOInternalWithNSString:(NSString *)lctName;
- (void)onSQLiteDatabaseOpenWithISqliteAccessor:(id<ISqliteAccessor>)sqliteAccessor;
- (BOOL)isDAOIntegrityOK;
- (void)nullify;
@end

typedef PlacesDAOFactory ComHomeawayHomeawayplacesDomainSyncPlacesDAOFactory;
