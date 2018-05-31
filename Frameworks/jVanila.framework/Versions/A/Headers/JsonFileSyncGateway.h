//
//  JsonFileSyncGateway.h
//  FalconParent
//
//  Created by Pavan on 11/11/15.
//  Copyright (c) 2015 Purnatva. All rights reserved.
//

#import <jVanila/jVanila.h>
#import "JsonFileDTO.h"

@interface JsonFileSyncGateway : SyncGateway

+(NSString *)CLASS_NAME;
+(NSString *)RT_UPLOAD_IMAGE;
+(NSString *)RT_DOWNLOAD_IMAGE;

-(void)fireFileUploadRequestWithJsonFileDTO:(JsonFileDTO *)dto;

@end
