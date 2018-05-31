//
//  DateTimeWrapper.h
//  HelloVanila
//
//  Created by Pavan on 01/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "CloneableObject.h"
#import "IDateTime.h"
#import "ITimeZone.h"

@interface DateTimeWrapper : CloneableObject <IDateTime>

@property (nonatomic, retain) NSDate *mDate;

-(id)initWithMillis:(long long)dateTimeInMillis;
-(id)initWithDateTimeLabel:(NSString *)label
           withDatePattern:(NSString *)pattern
              withTimeZone:(id<ITimeZone>)timeZone;

@end
