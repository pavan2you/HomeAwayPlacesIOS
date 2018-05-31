//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/jvanila/mobile/sync/ISyncAdapter.java
//
//

@class HttpHeaderBuilder;
@class NetRequestDTO;
@class NetResponseDTO;
@class RemoveNetRequestByQueryDTO;
@class SyncGateway;
@protocol IGenericList;
@protocol INetRequestQueue;
@protocol IPeriodicPollingPool;
@protocol IPubSubTransceiver;
@protocol ISyncAdapterLoadCallback;

#import "Emulation.h"
#import "IVanilaObject.h"

@protocol ISyncAdapter < IVanilaObject, NSObject >
- (void)setCustomSslCertificateToWithIGenericList:(id<IGenericList>)schemes
                                                              withNSString:(NSString *)pathToCertFile
                                                              withNSString:(NSString *)certFileType;
- (id<ISyncAdapterLoadCallback>)getCallback;
- (void)setCallbackWithISyncAdapterLoadCallback:(id<ISyncAdapterLoadCallback>)callback;
- (void)downloadApplication;
- (id<IPeriodicPollingPool>)getPeriodicPollingPool;
- (SyncGateway *)getSyncGatewayWithNSString:(NSString *)syncGatewayClassName;
- (id<INetRequestQueue>)getNetRequestQueue;
- (void)fireNetRequestWithNetRequestDTO:(NetRequestDTO *)netRequest;
- (void)removeNetRequestByQueryWithRemoveNetRequestByQueryDTO:(RemoveNetRequestByQueryDTO *)queryDTO;
- (void)notifyNetResponseWithNetResponseDTO:(NetResponseDTO *)netResponseDTO;
- (HttpHeaderBuilder *)getHttpHeaderBuilder;
- (void)setHttpHeaderBuilderWithHttpHeaderBuilder:(HttpHeaderBuilder *)httpHeaderBuilder;
- (id<IPubSubTransceiver>)getPubSubTransceiver;
- (void)setPubSubTransceiverWithIPubSubTransceiver:(id<IPubSubTransceiver>)pubSubTransceiver;
- (BOOL)isNetworkAvailable;
- (int)getConnectedNetworkType;
@end

#define ComJvanilaMobileSyncISyncAdapter ISyncAdapter
