//
//  SQLiteTableInfo.m
//  FalconParent
//
//  Created by pavan on 04/10/17.
//  Copyright © 2017 Purnatva. All rights reserved.
//

#import "SQLiteTableInfo.h"

@implementation SQLiteTableInfo

-(id)initWith:(NSString *)name withPrimaryKey:(NSString *)priaryKey withForeignKey:(NSString *)foreignKey withCompositePrimaryKey:(NSArray *)compositePrimaryKey withCompositeForeignKey:(NSArray *)compositeForeignKey
{
    if ([super init])
    {
        _name = name;
        _primaryKey = priaryKey;
        _foreignKey = foreignKey;
        _compositePrimaryKey = compositePrimaryKey;
        _compositeForeignKey = compositeForeignKey;
    }
    
    return self;
}

-(BOOL)isHavingPrimaryKey
{
    return self.primaryKey != nil;
}

-(BOOL)isComposite
{
    return self.compositePrimaryKey != nil;
}

-(BOOL)isDependsOnComposite
{
    return self.compositeForeignKey != nil;
}

-(BOOL)isHavingForeignKey
{
    return self.foreignKey != nil;
}

-(NSString *)getValueOfId:(id)dto withColumnName:(NSString *)key
{
    //subclasses should implement
    return nil;
}

-(NSArray *)getCompositeValueOf:(id)dto withColumnName:(NSArray *)compositeKey
{
    //subclasses should implement
    return nil;
}

@end
