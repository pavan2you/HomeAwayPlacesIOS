//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/jvanila/mobile/MobilePlatformInfo.java
//
//

#import "Emulation.h"
#import "PlatformInfo.h"

@interface MobilePlatformInfo : PlatformInfo {
 @public
  NSString *deviceResolution_;
  float deviceResolutionDpi_;
  float deviceResolutionDpiBucket_;
  NSString *deviceIdentifier_;
  int deviceWidthInPx_;
  int deviceHeightInPx_;
  float deviceWidthInDpi_;
  float deviceHeightInDpi_;
}

@property (nonatomic, copy) NSString *deviceResolution;
@property (nonatomic, assign) float deviceResolutionDpi;
@property (nonatomic, assign) float deviceResolutionDpiBucket;
@property (nonatomic, copy) NSString *deviceIdentifier;
@property (nonatomic, assign) int deviceWidthInPx;
@property (nonatomic, assign) int deviceHeightInPx;
@property (nonatomic, assign) float deviceWidthInDpi;
@property (nonatomic, assign) float deviceHeightInDpi;

+ (NSString *)CLASS_NAME;
- (NSString *)getDeviceMakeModel;
- (NSString *)stringify;
@end

typedef MobilePlatformInfo ComJvanilaMobileMobilePlatformInfo;
