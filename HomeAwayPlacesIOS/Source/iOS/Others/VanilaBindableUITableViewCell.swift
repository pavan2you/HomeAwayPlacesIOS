//
//  VanilaBindableUITableViewCell.swift
//  FalconParent
//
//  Created by pavan on 23/08/17.
//  Copyright © 2017 Purnatva. All rights reserved.
//

import Foundation

class VanilaBindableUITableViewCell: UITableViewCell, IBindableView {
    
    var dataBinder:DataBinder?
    var bindArray:[Any]?
    
    var dataObject:DataObject!
    var weakSelf: WeakReferenceWrapper!
    
    override func awakeFromNib() {
        
        super.awakeFromNib()
        dataBinder = onCreateDataBinder()
        dataBinder?.onCreate()
    }
    
    func onCreateDataBinder() -> DataBinder! {
        
        //TODO : every subclass should override this
        return nil
    }
    
    func onBind(args:[Any]!) -> Bool {
        
        bindArray = args
        self.dataBinder?.onBind(with: args)
        return true
    }
    
    func onRebind() {
        
        _ = self.onBind(args: bindArray)
    }
    
    func show() {
        //NA
    }
    
    func hide() {
        //NA
    }
    
    func setTagWithId(_ tag: Any!) {
        
        self.addTag(withId: tag)
    }
    
    func addTag(withId tag: Any!) {
        
        if let item = tag as? DataObject {
            
            self.dataObject = item
            var tagList = item.tagList
            
            if tagList == nil {
                
                tagList = GenericList()
            }
            
            if tagList!.contains(withId: self.weakSelf) {
                
                return
            }
            
            tagList!.add(withId: self.weakSelf)
            item.tagList = tagList
            item.tag = self.weakSelf
        }
    }
    
    func getTag() -> Any! {
        
        return self.dataObject
    }
    
    func refresh() {
        
        self.onRebind()
    }
    
    func getDataBinder() -> DataBinder! {
        
        return self.dataBinder
    }
    
    func getClassName() -> String! {
        
        return String(describing: type(of: self))
    }
    
    func stringify() -> String! {
        
        return self.description
    }
}
