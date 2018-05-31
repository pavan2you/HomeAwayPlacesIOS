//
//  JsonObjectWrapper.h
//  HelloVanila
//
//  Created by Pavan on 01/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "CloneableObject.h"
#import "IJsonObject.h"

@interface JsonObjectWrapper : CloneableObject <IJsonObject>

@property (nonatomic, retain) NSMutableDictionary *mJsonDictionary;

@end
