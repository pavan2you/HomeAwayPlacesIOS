//
//  JsonFileDTO.h
//  FalconParent
//
//  Created by Pavan on 11/11/15.
//  Copyright (c) 2015 Purnatva. All rights reserved.
//

#import <jVanila/jVanila.h>

@interface JsonFileDTO : DataObject

@property (nonatomic, retain) NSString *CRUDOperation;

@property (nonatomic, retain) NSString *entity_type;
@property (nonatomic, retain) NSString *entity_uuid;
@property (nonatomic, retain) NSString *picture_in_base64;
@property (nonatomic, retain) NSString *url;

@end
