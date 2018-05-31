//
//  JsonArrayWrapper.h
//  HelloVanila
//
//  Created by Pavan on 01/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "CloneableObject.h"
#import "IJsonArray.h"

@interface JsonArrayWrapper : CloneableObject <IJsonArray>

@property (nonatomic, retain) NSMutableArray *mJsonArray;

@end
