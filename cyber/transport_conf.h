
typedef enum OptionalMode {
  HYBRID = 0;
  INTRA = 1;
  SHM = 2;
  RTPS = 3;
}OptionalMode;

 //message ShmMulticastLocator {
 //    optional string ip = 1;
 //    optional uint32 port = 2;
 //};
 //
 //message ShmConf {
 //    optional string notifier_type = 1;
 //    optional ShmMulticastLocator shm_locator = 2;
 //};
 //
 //message RtpsParticipantAttr {
 //    optional int32 lease_duration = 1 [default = 12];
 //    optional int32 announcement_period = 2 [default = 3];
 //    optional uint32 domain_id_gain = 3 [default = 200];
 //    optional uint32 port_base = 4 [default = 10000];
 //};
 //
 //message CommunicationMode {
 //    optional OptionalMode same_proc = 1 [default = INTRA];  // INTRA SHM RTPS
 //    optional OptionalMode diff_proc = 2 [default = SHM];    // SHM RTPS
 //    optional OptionalMode diff_host = 3 [default = RTPS];   // RTPS
 //};
 //
 //message ResourceLimit {
 //    optional uint32 max_history_depth = 1 [default = 1000];
 //};
 //
 //message TransportConf {
 //    optional ShmConf shm_conf = 1;
 //    optional RtpsParticipantAttr participant_attr = 2;
 //    optional CommunicationMode  communication_mode = 3;
 //    optional ResourceLimit resource_limit = 4;
 //};
