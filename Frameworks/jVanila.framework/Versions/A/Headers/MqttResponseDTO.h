//
//  MqttResponseDTO.h
//  jVanila
//
//  Created by Pavan on 11/04/16.
//  Copyright © 2016 jVanila. All rights reserved.
//

#import <jVanila/jVanila.h>

#define STATE_IDLE 0
#define STATE_PROCESSING 1
#define STATE_CONNECTED 2
#define STATE_SENT 3
#define STATE_FAILED 4
#define STATE_DELIVERED 5
#define STATE_RECEIVED 6
#define STATE_CONNECTION_LOST 7

@interface MqttResponseDTO : DataObject <NSCoding, NSCopying, ICloneableObject>

@property (nonatomic, retain) NSString *CRUDOperation;

@property (nonatomic, retain) NSData *response;
@property (nonatomic, assign) int responseState;
@property (nonatomic, assign) int sessionPresent;
@property (nonatomic, assign) int isComplete;
@property (nonatomic, retain) id<IGenericList> grantedQosList;
@property (nonatomic, retain) id<IGenericList> topicList;

@property (nonatomic, retain) MqttRequestDTO *request;

+ (NSString *)CLASS_NAME;

@end
