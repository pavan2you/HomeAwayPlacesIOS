//
//  Constants.swift
//  HomeAwayPlacesIOS
//
//  Created by pavan on 31/05/18.
//  Copyright © 2018 pavan. All rights reserved.
//

import Foundation

let appPublishedStoreUrl:String? = nil;
let appVersion = Bundle.main.infoDictionary!["CFBundleShortVersionString"] as! String
let currentBuildId = Bundle.main.infoDictionary!["CFBundleVersion"] as! String
let currentBuildName = Bundle.main.infoDictionary!["CurrentBuildVersion"] as! String
let CURRENT_APP_DATA_VERSION = Int32(1);
let PREVIOUS_APP_DATA_VERSION = Int32(0);
let DevServerBaseUrl = "https://api.foursquare.com";
let ProdServerBaseUrl = "https://api.foursquare.com";
let serverApiBaseUrl = "https://api.foursquare.com";
let vcsRevisionNumber:String? = nil;

