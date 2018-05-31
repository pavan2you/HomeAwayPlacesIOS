//
//  StringBuilder.h
//  HelloVanila
//
//  Created by Pavan on 01/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "CloneableObject.h"
#import "IStringBuilder.h"

@interface StringBuilderWrapper : CloneableObject <IStringBuilder>

@property (nonatomic, retain) NSMutableString *mBuilder;

@end
