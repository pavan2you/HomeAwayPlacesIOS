//
//  AppDelegate.swift
//  HomeAwayPlacesIOS
//
//  Created by pavan on 31/05/18.
//  Copyright © 2018 pavan. All rights reserved.
//

import UIKit

@UIApplicationMain
class AppDelegate: VanilaAppDelegate {

    override init() {
        super.init()
    }
    
    override func init__() -> Bool {
        super.init__()
        
        let documentPath = FileSystemAccessor.getApplicationDocumentsDirectory()
        print("document path\(String(describing: documentPath))")
        
        let setupApis = SetupApis(with: self)
        setupApis.setupOnAppInit(with: MobilePlatformFactoryLocator.getMobilePlatformFactory())
        
        return true;
    }
    
    func prepareBuildInfo() {
        let mobilePlatformFactory = MobilePlatformFactoryLocator.getMobilePlatformFactory()
        let mobileBuildInfo = mobilePlatformFactory?.getBuildInfo() as! MobileBuildInfo;
        mobileBuildInfo.appPublishedStoreUrl = appPublishedStoreUrl;
        mobileBuildInfo.appVersion = appVersion;
        mobileBuildInfo.currentBuildId = currentBuildId;
        mobileBuildInfo.currentBuildName = currentBuildName;
        mobileBuildInfo.currentAppDataVersion = CURRENT_APP_DATA_VERSION;
        
        #if DEBUG
        mobileBuildInfo.serverBaseUrl = DevServerBaseUrl;
        #else
        mobileBuildInfo.serverBaseUrl = ProdServerBaseUrl;
        #endif
        
        mobileBuildInfo.serverApiBaseUrl = mobileBuildInfo.serverBaseUrl + serverApiBaseUrl;
        mobileBuildInfo.vcsRevisionNumber = vcsRevisionNumber;
    }
    
    override func loadSQLAccessor()
    {
        let daoFactory = MobilePlatformFactoryLocator.getMobilePlatformFactory().getDAOFactory() as! ISqliteOpenListener
        let mobileBuildInfo = MobilePlatformFactoryLocator.getMobilePlatformFactory().getBuildInfo() as! MobileBuildInfo;
        super.loadSQLAccessor(withName: "homeaway_places_database.db", version: mobileBuildInfo.currentAppDataVersion, createSchema: getCreateSchemas(), deleteSchemaName: getDeleteSchemas(), sqlOpenListener: daoFactory)
    }
    
    override func loadSQLAccessorSynchronously(with sqliteOpenListener: ISqliteOpenListener)
    {
        let mobileBuildInfo = MobilePlatformFactoryLocator.getMobilePlatformFactory().getBuildInfo() as! MobileBuildInfo;
        super.loadSQLAccessor(withName: "homeaway_places_database", version: mobileBuildInfo.currentAppDataVersion, createSchema: getCreateSchemas(), deleteSchemaName: getDeleteSchemas(), sqlOpenListener: sqliteOpenListener)
    }
    
    func getCreateSchemas() -> IGenericList {
        let createList = MobilePlatformFactoryLocator.getMobilePlatformFactory().newList()
        createList?.add(withId: "create_schema.sql")
        return createList!
    }
    
    func getDeleteSchemas() -> IGenericList {
        let deleteList = MobilePlatformFactoryLocator.getMobilePlatformFactory().newList()
        deleteList?.add(withId: "delete_schema.sql")
        return deleteList!
    }
    
    override func loadSyncAdapter(with httpHeaderBuilder: HttpHeaderBuilder!, with pushActivityListener: IPubSubTransceiver!) {
        super.loadSyncAdapter(with: httpHeaderBuilder, with: nil)
    }
    
    override func loadSyncAdapterSynchronously(with callback: ISyncAdapterLoadCallback!, with httpHeaderBuilder: HttpHeaderBuilder!, with pushActivityListener: IPubSubTransceiver!) {
        super.loadSyncAdapterSynchronously(with: callback, with: httpHeaderBuilder, with: nil)
    }
}

