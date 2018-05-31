//
//  TimeZoneWrapper.h
//  HelloVanila
//
//  Created by Pavan on 01/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "CloneableObject.h"
#import "ITimeZone.h"

@interface TimeZoneWrapper : CloneableObject <ITimeZone>

-(id)initWithOlsonIdOrGmtOffset:(NSString *)olsonIdOrGmtOffset withOffsetInMins:(int)offsetInMins;

@end
