#import "DataObject.h"
#import "ICloneableObject.h"
#import "IComparableObject.h"
#import "IGenericList.h"

@class NetRequestDTO;

@interface NetResponseDTO : DataObject <NSCoding, NSCopying, ICloneableObject>

+(NSString *) CLASS_NAME;

@property (nonatomic, retain) NSData *Response;
@property (nonatomic, retain) NSData *Error;
@property (nonatomic, retain) NSString *SuggestedFileName;
@property (nonatomic, retain) NetRequestDTO *NetRequest;
@property (nonatomic, retain) id<IGenericList> ResponseHttpHeaderList;
@property (nonatomic, retain) NSString *CRUDOperation;

@end

