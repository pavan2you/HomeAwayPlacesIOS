//
//  MqttTopicDTO.h
//  jVanila
//
//  Created by Pavan on 11/04/16.
//  Copyright © 2016 jVanila. All rights reserved.
//

#import <jVanila/jVanila.h>

@interface MqttTopicDTO : DataObject <NSCoding, NSCopying, ICloneableObject>

@property (nonatomic, retain) NSString *CRUDOperation;

@property (nonatomic, retain) NSString *topic;
@property (nonatomic, assign) int qos;

+ (NSString *)CLASS_NAME;

@end
