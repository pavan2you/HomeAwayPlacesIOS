#import "SqliteDataAccessObject.h"
#import "IGenericList.h"

@class NetRequestDTO;

@interface NetRequestDAO: SqliteDataAccessObject

- (int) CreateRecordWithNetRequestDTO:(NetRequestDTO *) dto;
-(int) UpdateRecordWithNetRequestDTO:(NetRequestDTO *)dto;
-(BOOL) DeleteNetRequestByIdWithNSString:(NSString *)uniqueId;
- (BOOL) DeleteNetRequestByIdAndPublishWithNSString:(NSString *)uniqueId withBOOL:(BOOL)isPublishable;
-(NetRequestDTO *)GetRecordWithNSString:(NSString *)uniqueId;
- (BOOL) DeleteAll;
-(id<IGenericList>)GetAllRecords;

-(id<IGenericList>) GetNetRequestDTOListQueryDTOWithInt:(int)IsSynchronousRequest withInt:(int)priority;
-(id<IGenericList>) GetSyncRequestPriorityListQueryDTO;
-(BOOL)  DeleteAsyncNetRequestDTOsQueryDTO;
-(id<IGenericList>) GetCUDNetRequestList;

@end

