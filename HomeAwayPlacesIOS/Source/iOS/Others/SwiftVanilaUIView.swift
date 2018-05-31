//
//  SwiftVanilaUIView.swift
//  FalconTrack
//
//  Created by pavan on 17/03/17.
//  Copyright © 2017 pavan. All rights reserved.
//

import Foundation

class SwiftVanilaUIView: VanilaUIView {
    
    var activeInBackground:Bool = false
    var vanilaChildViewControllers:[VanilaUIViewController] = []
    var subViewsLaidOut = false
    let animationDuration = 0.1
    
    override func viewWillAppear(_ animated: Bool) {
        if (self.mController.isDestroying()) {
            self.mController = createController()
            self.mController.onCreate()
        }
        else {
            self.mController.setViewWithId(self)
        }
        super.viewWillAppear(animated)
        viewDidMoveIn()
    }
    
    override func viewDidLoad(_ parentController: Presenter!) {
        super.viewDidLoad(parentController)
    }
    
    func addVanilaChildViewController(vanilaChildViewController:VanilaUIViewController) {
        vanilaChildViewControllers.append(vanilaChildViewController)
    }
    
    func performSegue(withIdentifier identifier: String, sender: Any?) {
        
        self.viewWillMoveOut()
        let parent = mParentView as! SwiftVanilaUIViewControler
        parent.performSegue(withIdentifier: identifier, sender: sender)
    }
    
    func performSegueWithIdentifier(identifier: String, sender: AnyObject?, activeInBackground:Bool) {
        if !activeInBackground {
            self.viewWillMoveOut()
        }
        let parent = mParentView as! SwiftVanilaUIViewControler
        parent.performSegue(withIdentifier: identifier, sender: sender)
    }
    
    func dismiss(animated flag: Bool, completion: (() -> Void)?) {
        self.viewWillMoveOut()
        let parent = mParentView as! SwiftVanilaUIViewControler
        parent.dismiss(animated: flag, completion: completion)
    }
    
    func pushViewController(viewController:SwiftVanilaUIViewControler,  activeInBackground:Bool) {
        if !activeInBackground {
            self.viewWillMoveOut()
        }
        let parent = mParentView as! SwiftVanilaUIViewControler
        parent.navigationController?.pushViewController(viewController, animated: true)
    }
    
    func removeViewController(viewController:SwiftVanilaUIViewControler) {
        
        self.viewWillMoveOut()
        viewController.navigationController?.popViewController(animated: true)
    }
    
    override func viewDidMoveIn() {
        self.isMovingOut = false
        for vanilaChildViewController in self.vanilaChildViewControllers {
            vanilaChildViewController.isMovingOut = false
        }
    }
    
    override func viewWillMoveOut() {
        self.isMovingOut = true
        for vanilaChildViewController in self.vanilaChildViewControllers {
            vanilaChildViewController.isMovingOut = true
        }
    }
    
    func refresh(sender: AnyObject?) {
        
    }
    
}
