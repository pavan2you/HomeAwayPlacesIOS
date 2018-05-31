//
//  VanilaAppDelegate.h
//  HelloVanila
//
//  Created by Pavan on 01/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IApplication.h"
#import "MobilePlatformFactory.h"
#import "IGenericList.h"
#import "ApplicationController.h"

@interface VanilaAppDelegate : UIResponder <UIApplicationDelegate, IApplication>

@property (strong, nonatomic) UIWindow *window;
@property (assign, nonatomic) BOOL mIsInInitialization;
@property (assign, nonatomic) BOOL mIsInForeground;
@property (nonatomic, retain) ApplicationController *mController;

-(void)loadSQLAccessorWithName:(NSString *)dbName version:(int)dbVersion createSchema:(id<IGenericList>)createSchemaNames deleteSchemaName:(id<IGenericList>)deleteSchemaNames sqlOpenListener:(id<ISqliteOpenListener>) sqliteOpenListener;

-(void)loadSecureSQLAccessorWithName:(NSString *)dbName version:(int)dbVersion createSchema:(id<IGenericList>)createSchemaNames deleteSchemaName:(id<IGenericList>)deleteSchemaNames sqlOpenListener:(id<ISqliteOpenListener>) sqliteOpenListener defualtKey:(NSString *)defaultKey;

@end
