//
//  SqliteAccesor.h
//  HelloVanila
//
//  Created by Pavan on 01/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "VanilaObject.h"
#import "ISqliteAccessor.h"
#import <sqlite3.h>

@interface SqliteAccessor : VanilaObject <ISqliteAccessor>

@property (nonatomic, assign) id<ISqliteOpenListener> mCallback;

- (sqlite3 *)getSqliteDatabase;
- (void)createTableSchema;
-(void)dropAllTables;
- (void)deleteDB;

@end
