//
//  Sha1Hash.h
//  HelloVanila
//
//  Created by Pavan on 01/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#include <CommonCrypto/CommonDigest.h>
#import <Foundation/Foundation.h>

@interface NSData (Sha1Hashing) 
-(NSData *)sha1HashData;
@end
