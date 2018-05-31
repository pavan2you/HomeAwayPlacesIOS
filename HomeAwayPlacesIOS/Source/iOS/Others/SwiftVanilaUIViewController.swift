//
//  SwiftVanilaUIViewController.swift
//  FalconParent
//
//  Created by Pavan on 11/12/15.
//  Copyright © 2015 Purnatva. All rights reserved.
//

import Foundation

class SwiftVanilaUIViewControler: VanilaUIViewController {
    
    var activeInBackground:Bool = false
    var vanilaChildViewControllers:[VanilaUIViewController] = []
    var subViewsLaidOut = false
    
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
    
    override func viewDidLoad() {
        
        super.viewDidLoad()
        self.navigationController?.isNavigationBarHidden = true
    }
    
    func addVanilaChildViewController(_ vanilaChildViewController:VanilaUIViewController) {
        vanilaChildViewControllers.append(vanilaChildViewController)
        self.addChildViewController(vanilaChildViewController)
    }
    
    override func performSegue(withIdentifier identifier: String, sender: Any?) {
        self.viewWillMoveOut()
        super.performSegue(withIdentifier: identifier, sender: sender)
    }
    
    func performSegueWithIdentifier(_ identifier: String, sender: AnyObject?, activeInBackground:Bool) {
        if !activeInBackground {
            self.viewWillMoveOut()
        }
        super.performSegue(withIdentifier: identifier, sender: sender)
    }
    
    override func present(_ viewControllerToPresent: UIViewController, animated flag: Bool, completion: (() -> Void)? = nil) {
        
        self.viewWillMoveOut()
        super.present(viewControllerToPresent, animated: flag, completion: completion)
    }
    
    override func dismiss(animated flag: Bool, completion: (() -> Void)?) {
        self.viewWillMoveOut()
        super.dismiss(animated: flag, completion: completion)
    }
    
    func pushViewController(_ viewController:SwiftVanilaUIViewControler,  activeInBackground:Bool)
    {
        if !activeInBackground {
            self.viewWillMoveOut()
        }
        self.navigationController?.pushViewController(viewController, animated: true)
    }
    
    func removeViewController(_ viewController:SwiftVanilaUIViewControler) {
        
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

}
