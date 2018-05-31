//
//  SqliteDataAccessObject.h
//  HelloVanila
//
//  Created by Pavan on 01/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "VanilaObject.h"
#import "ITransactionHandler.h"
#import "DAOFactory.h"
#import <sqlite3.h>

@interface SqliteDataAccessObject : VanilaObject <ITransactionHandler> {
    
    sqlite3 *sqlDB;
}

@property (nonatomic, assign) DAOFactory *mDaoFactory;

-(id)initWithSQLiteDatabase:(sqlite3*) argSQLDB;
-(BOOL)executeQuery:(const char*)query;
-(void)bindBlobAt:(int)index withId:(id)data to:(sqlite3_stmt *)stmt;
-(id)getBlobtAt:(int)index from:(sqlite3_stmt *)selectSt;

@end
