//
//  KeychainWrapper.h
//  HelloVanila
//
//  Created by Pavan on 28/10/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import <Security/Security.h>
#import <Foundation/Foundation.h>

@interface KeychainWrapper : NSObject

+ (NSMutableDictionary *)searchDictionary:(NSString *)identifier;
+ (NSData *)searchKeychainCopyMatching:(NSString *)identifier;
+ (BOOL)saveKeychainValue:(NSData *)data forIdentifier:(NSString *)identifier;
+ (void)deleteKeychainValue:(NSString *)identifier;

@end
