PRAGMA foreign_keys = ON;

CREATE TABLE IF NOT EXISTS NetRequest(
UniqueId TEXT PRIMARY KEY NOT NULL,
RequestType TEXT,
ResponseType TEXT,
NetworkOperationType INTEGER,
ClearCacheFlag INTEGER,
CurrentDataFormat INTEGER,
Url TEXT,
IsSynchronousRequest INTEGER,
DelegateClassName TEXT,
RequestString TEXT,
FailureCount INTEGER,
CreatedDateTime BIGINT,
ProtocolVersion TEXT,
Priority INTEGER,
CRUDType INTEGER,
PollingIntervalInMillis BIGINT,
TreatAnyKindOfResponseAsSuccess INTEGER,
SubscribedFailureTypeNotifyingList TEXT,
ContainedObjectUniqueId TEXT,
RetryLimitOnFailure INTEGER
);

CREATE TABLE IF NOT EXISTS MqttMessage(
mqtt_message_uuid TEXT PRIMARY KEY NOT NULL,
topic TEXT,
message BLOB,
qos INTEGER,
retained INTEGER,
duplicate INTEGER,
created_at BIGINT
);

PRAGMA foreign_keys = OFF;
