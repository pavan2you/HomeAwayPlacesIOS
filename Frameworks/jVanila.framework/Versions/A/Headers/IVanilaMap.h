//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/jvanila/mobile/location/IVanilaMap.java
//
//

@class VanilaLocation;
@protocol ICircle;
@protocol ICircleOptions;
@protocol ILatLngBounds;
@protocol IMarker;
@protocol IMarkerOptions;
@protocol IPolygon;
@protocol IPolygonOptions;
@protocol IPolyline;
@protocol IPolylineOptions;
@protocol IVanilaMapCallbacks;

#import "Emulation.h"
#import "IVanilaObject.h"

#define IVanilaMap_MAP_TYPE_HYBRID 4
#define IVanilaMap_MAP_TYPE_NONE 0
#define IVanilaMap_MAP_TYPE_NORMAL 1
#define IVanilaMap_MAP_TYPE_SATELLITE 2
#define IVanilaMap_MAP_TYPE_TERRAIN 3

@protocol IVanilaMap < IVanilaObject, NSObject >
- (void)setCallbacksListenerWithIVanilaMapCallbacks:(id<IVanilaMapCallbacks>)listener;
- (void)setUpMapWithTypeWithInt:(int)mapType;
- (void)animateCameraWithVanilaLocation:(VanilaLocation *)latLng
                                                       withFloat:(float)zoomLevel;
- (void)animateCameraBoundsWithILatLngBounds:(id<ILatLngBounds>)bounds
                                                              withInt:(int)padding;
- (void)animateCameraToLocationWithVanilaLocation:(VanilaLocation *)location;
- (void)handleAnyNativeChangesDueToAnimationCancel;
- (void)stopAnimation;
- (void)clearMap;
- (id<IPolygon>)addPolygonWithIPolygonOptions:(id<IPolygonOptions>)polygonOptions;
- (id<IPolyline>)addPolylineWithIPolylineOptions:(id<IPolylineOptions>)polylineOptions;
- (id<IMarker>)addMarkerWithIMarkerOptions:(id<IMarkerOptions>)markerOptions;
- (id<ICircle>)addCircleWithICircleOptions:(id<ICircleOptions>)circleOptions;
@end

@interface IVanilaMap : NSObject {
}
+ (int)MAP_TYPE_NONE;
+ (int)MAP_TYPE_NORMAL;
+ (int)MAP_TYPE_SATELLITE;
+ (int)MAP_TYPE_TERRAIN;
+ (int)MAP_TYPE_HYBRID;
@end

#define ComJvanilaMobileLocationIVanilaMap IVanilaMap
