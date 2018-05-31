//
//  ToDataObjectConverter.h
//  FalconParent
//
//  Created by pavan on 04/10/17.
//  Copyright © 2017 Purnatva. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <jVanila/jVanila.h>

@protocol ToDataObjectConverter < NSObject >

-(id)toDataObject:(sqlite3_stmt *)selectSt withInt:(int)childPolicy;

@end
