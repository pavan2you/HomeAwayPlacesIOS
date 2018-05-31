//
//  SpannableStringBuilderWrapper.h
//  HelloVanila
//
//  Created by Pavan on 01/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "CloneableObject.h"
#import "ISpannableStringBuilder.h"

@interface SpannableStringBuilderWrapper : CloneableObject <ISpannableStringBuilder>

@property (nonatomic, retain) NSMutableAttributedString *mBuilder;

@end
