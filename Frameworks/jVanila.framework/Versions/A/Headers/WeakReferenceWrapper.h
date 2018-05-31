//
//  WeakReferenceWrapper.h
//  HelloVanila
//
//  Created by Pavan on 01/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "VanilaObject.h"
#import "IWeakReference.h"

@interface WeakReferenceWrapper : VanilaObject <IWeakReference>

-(id)initWithType:(id)type;

@end
