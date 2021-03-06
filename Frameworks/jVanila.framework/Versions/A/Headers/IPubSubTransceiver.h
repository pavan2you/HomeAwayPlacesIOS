//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: com/jvanila/mobile/sync/IPubSubTransceiver.java
//
//

@class MqttMessageDTO;
@class MqttRequestDTO;
@class MqttResponseDTO;
@class VanilaException;
@protocol IGenericList;
@protocol IGenericMap;
@protocol IMqttInQueue;

#import "Emulation.h"

@protocol IPubSubTransceiver < NSObject >
- (void)setMqttInQueueWithIMqttInQueue:(id<IMqttInQueue>)mqttInQueue;
- (id<IMqttInQueue>)getMqttInQueue;
- (void)onMessageArrivedWithMqttMessageDTO:(MqttMessageDTO *)messageDTO
                                                            withInt:(int)noOfPendingItemsToProcess;
- (void)onConnectionLostWithVanilaException:(VanilaException *)exception;
- (void)connect;
- (void)disconnect;
- (BOOL)isConnected;
- (void)subscribeWithNSString:(NSString *)topic
                      withInt:(int)qos;
- (void)subscribeWithIGenericMap:(id<IGenericMap>)topicWithQosMap;
- (void)unsubscribeWithNSString:(NSString *)topic;
- (void)unsubscribeWithIGenericList:(id<IGenericList>)topics;
- (void)publishWithMqttMessageDTO:(MqttMessageDTO *)mqttMessageDTO;
- (void)onConnectedWithMqttResponseDTO:(MqttResponseDTO *)mqttResponseDTO;
- (void)onSubscribedWithMqttResponseDTO:(MqttResponseDTO *)mqttResponseDTO;
- (void)onUnsubscribedWithMqttResponseDTO:(MqttResponseDTO *)mqttResponseDTO;
- (void)onDisconnectedWithMqttResponseDTO:(MqttResponseDTO *)mqttResponseDTO;
- (void)onPublishedWithMqttResponseDTO:(MqttResponseDTO *)mqttResponseDTO;
- (void)onPublishAcknowledgedWithMqttResponseDTO:(MqttResponseDTO *)mqttResponseDTO;
- (void)onPublishReceivedWithMqttResponseDTO:(MqttResponseDTO *)mqttResponseDTO;
- (void)onPublishCompletedWithMqttResponseDTO:(MqttResponseDTO *)mqttResponseDTO;
- (void)onFailureWithMqttRequestDTO:(MqttRequestDTO *)mqttRequestDTO
                withVanilaException:(VanilaException *)throwable;
- (void)onMessageDeliveredWithMqttMessageDTO:(MqttMessageDTO *)mqttMessageDTO;
- (void)onReconnect;
- (void)setIsTransceiverReadyWithBOOL:(BOOL)ready;
- (BOOL)isTransceiverReady;
@end

#define ComJvanilaMobileSyncIPubSubTransceiver IPubSubTransceiver
