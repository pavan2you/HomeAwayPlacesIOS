//
//  Emulation.h
//  HelloVanila
//
//  Created by Pavan on 28/10/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import <Foundation/Foundation.h>

static inline id JreOperatorRetainedAssign(id *pIvar, id value)
{
    
#if __has_feature(objc_arc)
    * pIvar = value;
#else
    [* pIvar autorelease];
    * pIvar = [value retain];
#endif
    
    return value;
}
