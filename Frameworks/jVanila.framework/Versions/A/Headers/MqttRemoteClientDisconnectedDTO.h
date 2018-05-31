//
//  MqttRemoteClientDisconnectedDTO.h
//  jVanila
//
//  Created by pavan on 11/01/17.
//  Copyright © 2017 jVanila. All rights reserved.
//

#import <jVanila/jVanila.h>

@interface MqttRemoteClientDisconnectedDTO : DataObject

@property (nonatomic, retain) NSString *CRUDOperation;

@property (nonatomic, retain) NSString *clientid;
@property (nonatomic, retain) NSString *reason;
@property (nonatomic, assign) long long int ts;

@end
