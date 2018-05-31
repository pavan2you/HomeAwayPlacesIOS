//
//  NetworkHandler.h
///  HelloVanila
//
//  Created by Pavan on 28/10/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NetRequestDTO;
@class NetResponseDTO;

@interface NetworkHandler : NSObject

@property(nonatomic, retain) NSMutableData *responseBuffer;
@property(nonatomic, retain) NSString *latestBuildId;
@property(nonatomic, retain) NetRequestDTO *netRequest;
@property(nonatomic, retain) NetResponseDTO *netResponse;
@property(nonatomic, assign) BOOL isSuccess;
@property(nonatomic, assign) long bytesReadInChunk;
@property(nonatomic, assign) int connCount;


-(id)initWithNetRequest:(NetRequestDTO *)netReq;
-(void)doRequest;

@end
