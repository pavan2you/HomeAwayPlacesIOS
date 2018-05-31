//
//  DataEncryptionDecryption.h
//  HelloVanila
//
//  Created by Pavan on 28/10/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DataEncryptionDecryption : NSObject
+ (NSData *) getRandomSaltBytes:(int)noOfBytes;
+ (NSData *) getKeyToEncryptEncryptionKeyWithPinToUse:(NSString *)pin fileName:(NSString*)fileName;
+ (NSData *) getKeyToDecryptEncryptionKeyWithPin:(NSString *)pin fileName:(NSString*)fileName;
+ (NSData *) get128BitEncryptionKeyByCombining4DigitPin:(NSString *)pin salt96Bit:(NSData *)salt;
@end
