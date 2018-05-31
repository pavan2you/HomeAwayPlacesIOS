//
//  SecureSqliteAccessor.h
//  HelloVanila
//
//  Created by Pavan on 01/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "VanilaObject.h"
#import "ISecureSqliteAccessor.h"

@interface SecureSqliteAccessor : VanilaObject <ISecureSqliteAccessor>

-(id)initWithDefaultKey:(NSString *)defaultKey;

@end
