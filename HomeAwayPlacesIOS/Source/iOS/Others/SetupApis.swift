//
//  SetupApis.swift
//  FalconParent
//
//  Created by pavan on 06/10/17.
//  Copyright © 2017 Purnatva. All rights reserved.
//

import Foundation

class SetupApis : NSObject
{
    var application:IApplication? = nil
    
    init(with application:IApplication)
    {
        self.application = application;
    }
    
    func setupOnAppInit(with mpf:IMobilePlatformFactory) -> Void
    {
        setupJVanila(with: mpf)
        setupGoogleMaps()
        
        setupPlacesApiToFourSquare()
//        setupPlacesApiToGooglePlaces()
    }
    
    func setupJVanila(with mpf:IMobilePlatformFactory)
    {
//        let daoFactory = FSPlacesDAOFactory()
//        mpf.setDAOFactoryWithId(daoFactory)
        
        JobManager.setJobHandlerWith(JobHandler())
    }
    
    func setupGoogleMaps()
    {
//        GMSServices.provideAPIKey(googleMapsKey)
    }
    
    func setupPlacesApiToFourSquare() {
        
    }
    
    func setupPlacesApiToGooglePlaces() {
        
    }
}
