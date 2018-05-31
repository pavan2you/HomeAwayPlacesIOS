//
//  MqttRemoteClientConnectedDTO.h
//  jVanila
//
//  Created by pavan on 11/01/17.
//  Copyright © 2017 jVanila. All rights reserved.
//

#import <jVanila/jVanila.h>

@interface MqttRemoteClientConnectedDTO : DataObject

@property (nonatomic, retain) NSString *CRUDOperation;

@property (nonatomic, retain) NSString *clientid;
@property (nonatomic, retain) NSString *username;
@property (nonatomic, retain) NSString *ipaddress;
@property (nonatomic, assign) BOOL session;
@property (nonatomic, assign) int protocol;
@property (nonatomic, assign) int connack;
@property (nonatomic, assign) long long int ts;

@end
