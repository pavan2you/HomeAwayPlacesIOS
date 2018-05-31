//
//  NSData+AES.h
//  EncryptionAES
//
//  Created by Pavan on 02/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import <CommonCrypto/CommonCryptor.h>
#import <Foundation/Foundation.h>

@interface NSData (AES256)
- (NSData *)AES256EncryptWithKey:(NSData *)key;
- (NSData *)AES256DecryptWithKey:(NSData *)key;
@end
