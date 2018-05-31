//
//  GcmRegistrySyncOutDTO.h
//  jVanila
//
//  Created by Pavan on 11/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "DataObject.h"

@interface GcmRegistrySyncOutDTO : DataObject

+(NSString *)CLASS_NAME;

@property (nonatomic, retain) NSString *CRUDOperation;
@property (nonatomic, retain) NSString *registration_id;
@property (nonatomic, retain) NSString *url;

@end
