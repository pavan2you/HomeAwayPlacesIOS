//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/jvanila/mobile/mvp/IView.java
//
//

@class Presenter;

#import "Emulation.h"
#import "IComparableObject.h"
#import "IPermissionChecker.h"

@protocol IView < IComparableObject, IPermissionChecker, NSObject >
- (Presenter *)getController;
@end

#define ComJvanilaMobileMvpIView IView
