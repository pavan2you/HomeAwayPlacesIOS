#import "DataObject.h"
#import "ICloneableObject.h"
#import "IComparableObject.h"
#import "IGenericList.h"
#import "NetRequestStatsDTO.h"

#define NETWORK_OPERATION_HTTP_GET 0
#define NETWORK_OPERATION_HTTP_POST 1
#define NETWORK_OPERATION_HTTP_PUT 2
#define NETWORK_OPERATION_HTTP_PATCH 3
#define NETWORK_OPERATION_HTTP_DELETE 4
#define NETWORK_OPERATION_MQTT 5

#define CLEAR_CACHE_NOT_REQUIRED 0
#define CLEAR_CACHE_REQUIRED 1

#define SERVE_MODE_QUEUE 0
#define SERVE_MODE_IMMEDIATE 1

#define DATAFORMAT_PLAIN 0
#define DATAFORMAT_ENCRYPTED 1

#define CRUD_OPERATION_CREATE 'C'
#define CRUD_OPERATION_READ 'R'
#define CRUD_OPERATION_UPDATE 'U'
#define CRUD_OPERATION_DELETE 'D'

@interface NetRequestDTO : DataObject <NSCoding, NSCopying, ICloneableObject>

+(NSString *) CLASS_NAME;

@property (nonatomic, retain) NSString *UniqueId;
@property (nonatomic, retain) NSString *RequestType;
@property (nonatomic, retain) NSString *ResponseType;
@property (nonatomic, assign) int NetworkOperationType;
@property (nonatomic, assign) int ClearCacheFlag;
@property (nonatomic, assign) int CurrentDataFormat;
@property (nonatomic, retain) NSString *Url;
@property (nonatomic, assign) int IsSynchronousRequest;
@property (nonatomic, assign) int IsPersistable;
@property (nonatomic, retain) NSString *DelegateClassName;
@property (nonatomic, retain) NSString *RequestString;
@property (nonatomic, assign) int FailureCount;
@property (nonatomic, assign) long long int CreatedDateTime;
@property (nonatomic, retain) NSString *ProtocolVersion;
@property (nonatomic, assign) int Priority;
@property (nonatomic, assign) int IsProcessing;
@property (nonatomic, retain) NSString *CRUDType;
@property (nonatomic, assign) long long int PollingIntervalInMillis;
@property (nonatomic, assign) int TreatAnyKindOfResponseAsSuccess;
@property (nonatomic, retain) id<IGenericList> SubscribedFailureTypeNotifyingList;
@property (nonatomic, retain) NSString *ContainedObjectUniqueId;
@property (nonatomic, assign) int RetryLimitOnFailure;
@property (nonatomic, retain) id<IGenericList> RequestHttpHeaderList;
@property (nonatomic, retain) NSString *CRUDOperation;

@property (nonatomic, assign) int ServeMode;

//For MQTT
@property (nonatomic, retain) DataObject* EnclosedDto;
@property (nonatomic, assign) int OverwriteEarlierRequests;

@property (nonatomic, retain) NetRequestStatsDTO* Stats;

@end

