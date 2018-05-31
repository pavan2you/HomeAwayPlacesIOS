//
//  VanilaUIViewController.h
//  jVanila
//
//  Created by Pavan on 14/11/15.
//  Copyright (c) 2015 jVanila. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Presenter.h"
#import "IView.h"

@interface VanilaUIViewController : UIViewController <IView>

@property(nonatomic, retain)Presenter *mController;
@property(nonatomic, assign)BOOL isMovingOut;
@property(nonatomic, retain)NSMutableArray *mLifeCylceViews;

-(Presenter *)createController;
-(void)createLifeCycleViews;
-(void)viewDidMoveIn;
-(void)viewWillMoveOut;

@end

