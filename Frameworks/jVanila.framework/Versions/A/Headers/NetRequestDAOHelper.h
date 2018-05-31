//
//  NetRequestDAOHelper.h
//  Compile
//
//  Created by Pavan on 02/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "IGenericList.h"
#import "ISqliteOpenListener.h"
#import "ISqliteAccessor.h"
#import "VanilaObject.h"

@class NetRequestDTO;
@class NetRequestQueue;

@interface NetRequestDAOHelper : VanilaObject <ISqliteOpenListener>

-(id)initWithSQLiteAccessor:(id<ISqliteAccessor>) sqliteAccessor withSecretKey:(NSString *)secretKey withNetRequestQueue:(NetRequestQueue *)netRequestQueue;
- (void)CreateNetRequestWithNetRequestDTO:(NetRequestDTO *)netRequest;
- (id<IGenericList>)GetNetRequestListWithBOOL:(BOOL)isSync withInt:(int)priority;
- (void)DeleteAsyncRequests;
- (void)DeleteNetRequestWithNSString:(NSString *)uniqueId;
- (void)DeleteAllNetRequests;
- (id<IGenericList>)GetSyncRequestPriorityList;
-(void)EncrpytedNetRequestDTO:(NetRequestDTO *) netRequest;
-(void) DecryptNetRequestWithNetRequestDTO:(NetRequestDTO *)netRequest;
-(id<IGenericList>)getCUDNetRequestList;

@end
