//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/jvanila/mobile/location/IVanilaMapCallbacks.java
//
//

#import "Emulation.h"
#import "IVanilaObject.h"

@protocol IVanilaMapCallbacks < IVanilaObject, NSObject >
- (void)onMapAvailable;
- (void)onMapNotAvailable;
- (void)onMapLoaded;
- (void)onAnimationComplete;
- (void)onAnimationCancel;
- (void)onCameraMoveStarted;
- (void)onCameraPositionChangeWithFloat:(float)zoom;
@end

#define ComJvanilaMobileLocationIVanilaMapCallbacks IVanilaMapCallbacks
