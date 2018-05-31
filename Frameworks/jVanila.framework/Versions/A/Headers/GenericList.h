//
//  GenericList.h
//  HelloVanila
//
//  Created by Pavan on 30/10/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IGenericList.h"
#import "CloneableObject.h"
#import "ListBehaviorType.h"

@interface GenericList : CloneableObject <NSCoding, IGenericList>

@property (nonatomic, retain) NSMutableArray *mObjectList;

-(id)initWithListBehaviorType:(ListBehaviorType *)listBehaviorType withObjects:(id)firstObj, ... NS_REQUIRES_NIL_TERMINATION;

@end
