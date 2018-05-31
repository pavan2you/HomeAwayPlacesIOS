//
//  JobHandler.swift
//  FalconTrack
//
//  Created by pavan on 27/02/17.
//  Copyright © 2017 pavan. All rights reserved.
//

import Foundation

class JobHandler : VanilaObject, IJobHandler {
    
    let bgQueue = DispatchQueue.main
    
    func doJob(withId job: Any!) {
        if let bgJob = job as? AsyncJob {
            if bgJob.mDelay > 0 {
                let afterMillis : DispatchTimeInterval = .milliseconds(Int(bgJob.mDelay))
                bgQueue.asyncAfter(deadline: .now() + afterMillis) {
                    self.doAsyncJob(with: bgJob)
                }
            }
            else {
                bgQueue.async {
                    self.doAsyncJob(with: bgJob)
                }
            }
        }
    }
    
    internal func doAsyncJob(with asyncJob:AsyncJob) {
        asyncJob.execute()
        
        DispatchQueue.main.async {
            asyncJob.finish()
        }
    }
    
    func doCancelledJob(withId job: Any!) {
        //TODO : NEXT RELEASE
    }
    
    func cancelJobsByFamily(with tag: String!) {
        //TODO : NEXT RELEASE
    }
    
    func cancelJob(withId job: Any!) {
        //TODO : NEXT RELEASE
    }
    
    func doQuit() {
        //TODO : NEXT RELEASE
    }
}
