/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef HIVA_TRANSPORT_TRANSPORT_H_
#define HIVA_TRANSPORT_TRANSPORT_H_

#include <atomic>
#include <memory>
#include <string>

#include "hiva/common/macros.h"
#include "hiva/proto/transport_conf.h"
//#include "hiva/transport/dispatcher/intra_dispatcher.h"
//#include "hiva/transport/dispatcher/rtps_dispatcher.h"
#include "hiva/transport/dispatcher/shm_dispatcher.h"
//#include "hiva/transport/qos/qos_profile_conf.h"
//#include "hiva/transport/receiver/hybrid_receiver.h"
//#include "hiva/transport/receiver/intra_receiver.h"
#include "hiva/transport/receiver/receiver.h"
//#include "hiva/transport/receiver/rtps_receiver.h"
#include "hiva/transport/receiver/shm_receiver.h"
//#include "hiva/transport/rtps/participant.h"
#include "hiva/transport/shm/notifier_factory.h"
//#include "hiva/transport/transmitter/hybrid_transmitter.h"
//#include "hiva/transport/transmitter/intra_transmitter.h"
//#include "hiva/transport/transmitter/rtps_transmitter.h"
#include "hiva/transport/transmitter/shm_transmitter.h"
#include "hiva/transport/transmitter/transmitter.h"

namespace etron {
namespace hiva {
namespace transport {


class Transport {
 public:
  virtual ~Transport();

  void Shutdown();

  template <typename M>
  auto CreateTransmitter(const RoleAttributes& attr,
                         const OptionalMode& mode = SHM) ->
      typename std::shared_ptr<Transmitter<M>>;

  template <typename M>
  auto CreateReceiver(const RoleAttributes& attr,
                      const typename Receiver<M>::MessageListener& msg_listener,
                      const OptionalMode& mode = SHM) ->
      typename std::shared_ptr<Receiver<M>>;

  ParticipantPtr participant() const { return participant_; }

 private:
  //void CreateParticipant();

  std::atomic<bool> is_shutdown_;
  //ParticipantPtr participant_;
  NotifierPtr notifier_;
  //IntraDispatcherPtr intra_dispatcher_;
  ShmDispatcherPtr shm_dispatcher_;
  //RtpsDispatcherPtr rtps_dispatcher_;

  DECLARE_SINGLETON(Transport)
};

template <typename M>
auto Transport::CreateTransmitter(const RoleAttributes& attr,
                                  const OptionalMode& mode) ->
    typename std::shared_ptr<Transmitter<M>> {
  if (is_shutdown_.load()) {
    AINFO << "transport has been shut down.";
    return nullptr;
  }

  std::shared_ptr<Transmitter<M>> transmitter = nullptr;
  
  // need to add a class RoleAttributes  
  RoleAttributes modified_attr = attr;
//  if (!modified_attr.has_qos_profile()) {
//    modified_attr.mutable_qos_profile()->CopyFrom(
//        QosProfileConf::QOS_PROFILE_DEFAULT);
//  }
//
//  switch (mode) {
//    case OptionalMode::INTRA:
//      transmitter = std::make_shared<IntraTransmitter<M>>(modified_attr);
//      break;
//
//    case OptionalMode::SHM:
      transmitter = std::make_shared<ShmTransmitter<M>>(modified_attr);
//      break;
//
//    case OptionalMode::RTPS:
//      transmitter =
//          std::make_shared<RtpsTransmitter<M>>(modified_attr, participant());
//      break;
//
//    default:
//      transmitter =
//          std::make_shared<HybridTransmitter<M>>(modified_attr, participant());
//      break;
//  }
//
  RETURN_VAL_IF_NULL(transmitter, nullptr);
  if (mode != HYBRID) {
    transmitter->Enable();
  }
  return transmitter;
}

template <typename M>
auto Transport::CreateReceiver(
    const RoleAttributes& attr,
    const typename Receiver<M>::MessageListener& msg_listener,
    const OptionalMode& mode) -> typename std::shared_ptr<Receiver<M>> {
  if (is_shutdown_.load()) {
    AINFO << "transport has been shut down.";
    return nullptr;
  }

  std::shared_ptr<Receiver<M>> receiver = nullptr;
  RoleAttributes modified_attr = attr;
//  if (!modified_attr.has_qos_profile()) {
//    modified_attr.mutable_qos_profile()->CopyFrom(
//        QosProfileConf::QOS_PROFILE_DEFAULT);
//  }
//
//  switch (mode) {
//    case OptionalMode::INTRA:
//      receiver =
//          std::make_shared<IntraReceiver<M>>(modified_attr, msg_listener);
//      break;
//
//    case OptionalMode::SHM:
      receiver = std::make_shared<ShmReceiver<M>>(modified_attr, msg_listener);
//      break;
//
//    case OptionalMode::RTPS:
//      receiver = std::make_shared<RtpsReceiver<M>>(modified_attr, msg_listener);
//      break;
//
//    default:
//      receiver = std::make_shared<HybridReceiver<M>>(
//          modified_attr, msg_listener, participant());
//      break;
//  }

  RETURN_VAL_IF_NULL(receiver, nullptr);
  if (mode != HYBRID) {
    receiver->Enable();
  }
  return receiver;
}

}  // namespace transport
}  // namespace hiva
}  // namespace etron

#endif  // HIVA_TRANSPORT_TRANSPORT_H_
