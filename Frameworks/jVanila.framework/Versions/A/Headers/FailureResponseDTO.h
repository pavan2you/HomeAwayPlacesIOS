#import "DataObject.h"
#import "ICloneableObject.h"
#import "IComparableObject.h"
#import "NetRequestStatsDTO.h"

#define ERROR_TYPE_INTERNAL 0
#define ERROR_TYPE_AUTH_FAILURE 1
#define ERROR_TYPE_BUSINESS_EXCEPTION 2
#define ERROR_TYPE_SERVER_EXCEPTION 3
#define ERROR_TYPE_NO_NETWORK 4
#define ERROR_TYPE_API_EXCEPTION 5

@interface FailureResponseDTO : DataObject <NSCoding, NSCopying, ICloneableObject>

+(NSString *) CLASS_NAME;

@property (nonatomic, assign) int type;
@property (nonatomic, retain) NSString *message;
@property (nonatomic, retain) NSString *RequestType;
@property (nonatomic, retain) NSString *ContainedObjectUniqueId;
@property (nonatomic, retain) NSString *CRUDOperation;
@property (nonatomic, retain) DataObject * dataObject;
@property (nonatomic, assign) int failureCount;
@property (nonatomic, retain) NetRequestStatsDTO* processingStats;

@end

