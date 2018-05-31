//
//  DeviceUtils.h
//  HelloVanila
//
//  Created by Pavan on 06/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DeviceUtils : NSObject

+(NSString *)osName;

+(NSString *)osVersion;

+(NSString *)deviceIdentifier;

+(NSString *)deviceManufacturer;

+(NSString *)deviceModel;

+(NSString *)deviceResolution;

+(float)deviceResolutionDpi;

+(float)deviceResolutionDpiBucket;

+(int)deviceWidthInPx;

+(int)deviceHeightInPx;

+(int)deviceWidthInDpi;

+(int)deviceHeightInDpi;

@end
