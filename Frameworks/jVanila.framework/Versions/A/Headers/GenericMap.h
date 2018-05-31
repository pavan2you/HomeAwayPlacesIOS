//
//  GenericMap.h
//  HelloVanila
//
//  Created by Pavan on 01/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "IGenericMap.h"
#import "CloneableObject.h"
#import "MapBehaviorType.h"
#include <CoreFoundation/CoreFoundation.h>

@interface GenericMap : CloneableObject <IGenericMap> {

    CFMutableDictionaryRef mDictionary;
}

-(id)initWithMapBehaviorType:(MapBehaviorType *)mapBehaviorType;

@end
