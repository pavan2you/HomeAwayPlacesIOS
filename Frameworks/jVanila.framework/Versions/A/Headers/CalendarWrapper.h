//
//  CalendarWrapper.h
//  HelloVanila
//
//  Created by Pavan on 01/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "CloneableObject.h"
#import "ICalendar.h"
#import "ITimeZone.h"
#import "IDateTime.h"

@interface CalendarWrapper : CloneableObject <ICalendar>

@property (nonatomic, retain) NSDate *mDate;
@property (nonatomic, retain) NSCalendar *mCalendar;

-(id)initWithDateTime:(id<IDateTime>)dateTime withTimeZone:(id<ITimeZone>)timeZone;

@end
