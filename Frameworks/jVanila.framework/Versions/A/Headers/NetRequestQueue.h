//
//  NetRequestQueue.h
//  HelloVanila
//
//  Created by Pavan on 01/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "VanilaObject.h"
#import "INetRequestQueue.h"
#import "ISqliteAccessor.h"

@class NetRequestDAOHelper;
@protocol IPubSubTransceiver;

@interface NetRequestQueue : VanilaObject <INetRequestQueue>

-(id)initWithISqliteAccessor:(id<ISqliteAccessor>)frameworkSqliteAccessor withPubSubTransceiver:(id<IPubSubTransceiver>)pubSubTransceiver;

-(void)setCustomSslCertificateToWithIGenericList:(id<IGenericList>)schemes withNSString:(NSString *)pathToCertFile withNSString:(NSString *)certFileType;

-(void)setPubSubTransceiverWithIPubSubTransceiver:(id<IPubSubTransceiver>)pubSubTransceiver;

-(void)onNetRequestDBOpened:(NetRequestDAOHelper *)netRequestDAOHelper;

@end
