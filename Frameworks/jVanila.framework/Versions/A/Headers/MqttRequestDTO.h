//
//  MqttRequestDTO.h
//  jVanila
//
//  Created by Pavan on 11/04/16.
//  Copyright © 2016 jVanila. All rights reserved.
//

#import <jVanila/jVanila.h>

@class MqttMessageDTO;

@interface MqttRequestDTO : DataObject <NSCoding, NSCopying, ICloneableObject>

@property (nonatomic, retain) NSString *CRUDOperation;

@property (nonatomic, retain) NSString *clientId;
@property (nonatomic, retain) NSString *username;
@property (nonatomic, retain) NSString *password;

// last will message
@property (nonatomic, retain) MqttMessageDTO *last_will_message;

@property (nonatomic, retain) id<IGenericList> mqtt_message_list;
@property (nonatomic, retain) id<IGenericList> mqtt_topic_list;
@property (nonatomic, assign) int mqtt_message_type;
@property (nonatomic, assign) BOOL fireAndForget;

//transient
@property (nonatomic, retain) NSString *enclosedObjectUuid;
@property (nonatomic, assign) BOOL isSynchronous;
@property (nonatomic, assign) BOOL overwriteEarlierRequests;

+ (NSString *)CLASS_NAME;

+(NSString *)stringifyMqttMessageTypeWithInt:(int)mqtt_message_type;

@end
