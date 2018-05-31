//
//  MqttMessageDTO.h
//  jVanila
//
//  Created by Pavan on 11/04/16.
//  Copyright © 2016 jVanila. All rights reserved.
//

#import <jVanila/jVanila.h>

#define MESSAGE_TYPE_CONNECT 1
#define MESSAGE_TYPE_CONNACK 2
#define MESSAGE_TYPE_PUBLISH 3
#define MESSAGE_TYPE_PUBACK 4
#define MESSAGE_TYPE_PUBREC 5
#define MESSAGE_TYPE_PUBREL 6
#define MESSAGE_TYPE_PUBCOMP 7
#define MESSAGE_TYPE_SUBSCRIBE 8
#define MESSAGE_TYPE_SUBACK 9
#define MESSAGE_TYPE_UNSUBSCRIBE 10
#define MESSAGE_TYPE_UNSUBACK 11
#define MESSAGE_TYPE_PINGREQ 12
#define MESSAGE_TYPE_PINGRESP 13
#define MESSAGE_TYPE_DISCONNECT 14

@interface MqttMessageDTO : DataObject <NSCoding, NSCopying, ICloneableObject>

@property (nonatomic, retain) NSString *CRUDOperation;

@property (nonatomic, retain) NSData *message;
@property (nonatomic, retain) NSString *messageString;
@property (nonatomic, retain) NSString *topic;
@property (nonatomic, assign) int qos;
@property (nonatomic, assign) int retained;
@property (nonatomic, assign) int duplicate;
@property (nonatomic, assign) BOOL fireAndForget;

//transient
@property (nonatomic, retain) NSString *enclosedObjectUuid;
@property (nonatomic, assign) BOOL isProcessing;
@property (nonatomic, assign) BOOL overwriteMessagesWithSameIdentity;

@property (nonatomic, assign) int outProcessingUid;
@property (nonatomic, assign) BOOL belongsToCurrentTopic;
@property (nonatomic, assign) BOOL belongsToCurrentContext;

+ (NSString *)CLASS_NAME;

@end
