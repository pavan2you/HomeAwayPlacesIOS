//
//  MapEntry.h
//  HelloVanila
//
//  Created by Pavan on 03/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "CloneableObject.h"
#import "IMapEntity.h"

@interface MapEntry : CloneableObject <IMapEntity>

@property (nonatomic, retain) id key;
@property (nonatomic, retain) id value;

-(id)initWithKey:(id)key withValue:(id)value;

@end
