//
//  SynchronisedList.h
//  jVanila
//
//  Created by pavan on 26/12/17.
//  Copyright © 2017 jVanila. All rights reserved.
//

#import "CloneableObject.h"
#import "IGenericList.h"
#import "ISynchronizedList.h"

@interface SynchronizedList : CloneableObject < ISynchronizedList >

- (id)initWithIGenericList:(id<IGenericList>)list;

@property (nonatomic, retain) id<IGenericList> mList;
@property (nonatomic, retain) NSObject *mLock;

@end
