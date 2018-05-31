//
//  SQLiteTableInfo.h
//  FalconParent
//
//  Created by pavan on 04/10/17.
//  Copyright © 2017 Purnatva. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SQLiteTableInfo : NSObject

@property(nonatomic, retain) NSString* name;
@property(nonatomic, retain) NSString* primaryKey;
@property(nonatomic, retain) NSString* foreignKey;
@property(nonatomic, retain) NSArray* compositePrimaryKey;
@property(nonatomic, retain) NSArray* compositeForeignKey;

-(id)initWith:(NSString *)name withPrimaryKey:(NSString *)priaryKey withForeignKey:(NSString *)foreignKey withCompositePrimaryKey:(NSArray *)compositePrimaryKey withCompositeForeignKey:(NSArray *)compositeForeignKey;

-(BOOL)isHavingPrimaryKey;

-(BOOL)isComposite;

-(BOOL)isDependsOnComposite;

-(BOOL)isHavingForeignKey;

-(NSString *)getValueOfId:(id)dto withColumnName:(NSString *)key;

-(NSArray *)getCompositeValueOf:(id)dto withColumnName:(NSArray *)compositeKey;

@end
