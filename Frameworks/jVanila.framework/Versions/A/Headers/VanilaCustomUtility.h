//
//  DMCustomUtility.h
//  HelloVanila
//
//  Created by Pavan on 28/10/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import "IDateTime.h"
#import <UIKit/UIKit.h>

#define HELVETIC_NEUE				@"HelveticaNeue"
#define HELVETIC_NEUE_BOLD		@"HelveticaNeue-Bold"
#define AVANT_GARDE_BOLD		@"AvantGarde-Bold"


@interface VanilaCustomUtility : NSObject

+ (CAGradientLayer*) cyanGradient;
+ (UIImage *) imageWithView:(UIView *)view;
+ (NSString*) getStrictFormattedStringFromDate:(NSDate*)aDate withFormat:(NSString*)aFormat;
+ (float) getHeightFromText:(NSString *)text withFont:(UIFont *)font maxWidth:(float)aWidth;
+ (float) getHeightFromAttributedText:(NSAttributedString *)attributedString withFont:(UIFont *)font maxWidth:(float)aWidth;
+ (float) getWidthFromText:(NSString *)text withFont:(UIFont *)font maxHeight:(float)height;
+(NSString *) getScreenResolutionInString;
+(NSDate *) NSDateFromIDateObject:(id<IDateTime>)dateObject;
+(BOOL) stringIsNumeric:(NSString*)str;
+ (UIColor *)getUIColorObjectFromHexString:(NSString *)hexStr alpha:(CGFloat)alpha;
+ (unsigned int)intFromHexString:(NSString *)hexStr;
+(NSString *)getNSStringFromUTF8String:(char *)utf8String;
+(NSString *)getJsonStringForObject:(id)object;
+(void) hideGradientBackground:(UIView*)theView;

@end
