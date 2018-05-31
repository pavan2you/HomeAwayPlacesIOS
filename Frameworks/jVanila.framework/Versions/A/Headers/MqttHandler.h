//
//  MqttHandler.h
//  jVanila
//
//  Created by Pavan on 11/04/16.
//  Copyright © 2016 jVanila. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MQTTSessionManager.h"

@class NetRequestDTO;
@protocol IPubSubTransceiver;

@interface MqttHandler : NSObject <MQTTSessionManagerDelegate>

@property(nonatomic, retain) id<IPubSubTransceiver> pubSubTransceiver;

-(id)initWithIPubSubTransceiver:(id<IPubSubTransceiver>)pubSubTransceiver;
-(void)setPubSubTransceiverWithIPubSubTransceiver:(id<IPubSubTransceiver>)pushActivityListener;
-(void)setCustomSslCertificateWith:(NSString *)pathToCertFile ofType:(NSString *)fileType;
-(void)doRequest:(NetRequestDTO *)netRequest;

@end
