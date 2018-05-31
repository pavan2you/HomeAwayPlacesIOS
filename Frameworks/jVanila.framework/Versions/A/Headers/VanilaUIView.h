//
//  VanilaUIView.h
//  jVanila
//
//  Created by pavan on 17/03/17.
//  Copyright © 2017 jVanila. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Presenter.h"
#import "IFragmentView.h"

@interface VanilaUIView : UIView <IFragmentView>

@property(nonatomic, retain)Presenter *mController;
@property(nonatomic, assign)BOOL isMovingOut;
@property(nonatomic, assign)id<IView> mParentView;

- (void)setParentView:(id<IView>)parentView;
-(Presenter *)createController;

- (void)viewDidLoad:(Presenter *)parentController;
-(void)viewWillAppear:(BOOL)animated;
-(void)viewDidAppear:(BOOL)animated;
-(void)viewWillDisappear:(BOOL)animated;
-(void)viewDidDisappear:(BOOL)animated;

-(void)viewDidMoveIn;
-(void)viewWillMoveOut;

@end
