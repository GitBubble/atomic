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

#ifndef HIVA_SERVICE_DISCOVERY_SPECIFIC_MANAGER_MANAGER_H_
#define HIVA_SERVICE_DISCOVERY_SPECIFIC_MANAGER_MANAGER_H_

#include <atomic>
#include <functional>
#include <mutex>
#include <string>

#include "fastrtps/Domain.h"
#include "fastrtps/attributes/PublisherAttributes.h"
#include "fastrtps/attributes/SubscriberAttributes.h"
#include "fastrtps/participant/Participant.h"
#include "fastrtps/publisher/Publisher.h"
#include "fastrtps/subscriber/Subscriber.h"

#include "hiva/base/signal.h"
#include "hiva/proto/topology_change.pb.h"
#include "hiva/service_discovery/communication/subscriber_listener.h"

namespace etron {
namespace hiva {
namespace service_discovery {

using proto::ChangeMsg;
using proto::ChangeType;
using proto::OperateType;
using proto::RoleAttributes;
using proto::RoleType;

class Manager {
 public:
  using ChangeSignal = base::Signal<const ChangeMsg&>;
  using ChangeFunc = std::function<void(const ChangeMsg&)>;
  using ChangeConnection = base::Connection<const ChangeMsg&>;

  using RtpsParticipant = eprosima::fastrtps::Participant;
  using RtpsPublisherAttr = eprosima::fastrtps::PublisherAttributes;
  using RtpsSubscriberAttr = eprosima::fastrtps::SubscriberAttributes;

  Manager();
  virtual ~Manager();

  bool StartDiscovery(RtpsParticipant* participant);
  void StopDiscovery();
  virtual void Shutdown();

  bool Join(const RoleAttributes& attr, RoleType role,
            bool need_publish = true);
  bool Leave(const RoleAttributes& attr, RoleType role);

  ChangeConnection AddChangeListener(const ChangeFunc& func);
  void RemoveChangeListener(const ChangeConnection& conn);

  virtual void OnTopoModuleLeave(const std::string& host_name,
                                 int process_id) = 0;

 protected:
  bool CreatePublisher(RtpsParticipant* participant);
  bool CreateSubscriber(RtpsParticipant* participant);

  virtual bool Check(const RoleAttributes& attr) = 0;
  virtual void Dispose(const ChangeMsg& msg) = 0;
  virtual bool NeedPublish(const ChangeMsg& msg) const;

  void Convert(const RoleAttributes& attr, RoleType role, OperateType opt,
               ChangeMsg* msg);

  void Notify(const ChangeMsg& msg);
  bool Publish(const ChangeMsg& msg);
  void OnRemoteChange(const std::string& msg_str);
  bool IsFromSameProcess(const ChangeMsg& msg);

  std::atomic<bool> is_shutdown_;
  std::atomic<bool> is_discovery_started_;
  int allowed_role_;
  ChangeType change_type_;
  std::string host_name_;
  int process_id_;
  std::string channel_name_;
  eprosima::fastrtps::Publisher* publisher_;
  eprosima::fastrtps::Subscriber* subscriber_;
  SubscriberListener* listener_;

  ChangeSignal signal_;
};

}  // namespace service_discovery
}  // namespace hiva
}  // namespace etron

#endif  // HIVA_SERVICE_DISCOVERY_SPECIFIC_MANAGER_MANAGER_H_
