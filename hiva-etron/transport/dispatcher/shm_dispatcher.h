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

#ifndef HIVA_TRANSPORT_DISPATCHER_SHM_DISPATCHER_H_
#define HIVA_TRANSPORT_DISPATCHER_SHM_DISPATCHER_H_

#include <cstring>
#include <memory>
#include <string>
#include <thread>
#include <unordered_map>

#include "hiva/base/atomic_rw_lock.h"
#include "hiva/common/global_data.h"
#include "hiva/common/log.h"
#include "hiva/common/macros.h"
#include "hiva/message/message_traits.h"
#include "hiva/transport/dispatcher/dispatcher.h"
#include "hiva/transport/shm/notifier_factory.h"
#include "hiva/transport/shm/segment.h"

namespace etron {
namespace hiva {
namespace transport {

class ShmDispatcher;
using ShmDispatcherPtr = ShmDispatcher*;
using etron::hiva::base::AtomicRWLock;
using etron::hiva::base::ReadLockGuard;
using etron::hiva::base::WriteLockGuard;

class ShmDispatcher : public Dispatcher {
 public:
  // key: channel_id
  using SegmentContainer = std::unordered_map<uint64_t, SegmentPtr>;

  virtual ~ShmDispatcher();

  void Shutdown() override;

  template <typename MessageT>
  void AddListener(const RoleAttributes& self_attr,
                   const MessageListener<MessageT>& listener);

  template <typename MessageT>
  void AddListener(const RoleAttributes& self_attr,
                   const RoleAttributes& opposite_attr,
                   const MessageListener<MessageT>& listener);

 private:
  void AddSegment(const RoleAttributes& self_attr);
  void ReadMessage(uint64_t channel_id, uint32_t block_index);
  void OnMessage(uint64_t channel_id, const std::shared_ptr<ReadableBlock>& rb,
                 const MessageInfo& msg_info);
  void ThreadFunc();
  bool Init();

  uint64_t host_id_;
  SegmentContainer segments_;
  std::unordered_map<uint64_t, uint32_t> previous_indexes_;
  AtomicRWLock segments_lock_;
  std::thread thread_;
  NotifierPtr notifier_;

  DECLARE_SINGLETON(ShmDispatcher)
};

template <typename MessageT>
void ShmDispatcher::AddListener(const RoleAttributes& self_attr,
                                const MessageListener<MessageT>& listener) {
  // FIXME: make it more clean
  auto listener_adapter = [listener](const std::shared_ptr<ReadableBlock>& rb,
                                     const MessageInfo& msg_info) {
    auto msg = std::make_shared<MessageT>();
    RETURN_IF(!message::ParseFromArray(
        rb->buf, static_cast<int>(rb->block->msg_size()), msg.get()));
    listener(msg, msg_info);
  };

  Dispatcher::AddListener<ReadableBlock>(self_attr, listener_adapter);
  AddSegment(self_attr);
}

template <typename MessageT>
void ShmDispatcher::AddListener(const RoleAttributes& self_attr,
                                const RoleAttributes& opposite_attr,
                                const MessageListener<MessageT>& listener) {
  // FIXME: make it more clean
  auto listener_adapter = [listener](const std::shared_ptr<ReadableBlock>& rb,
                                     const MessageInfo& msg_info) {
    auto msg = std::make_shared<MessageT>();
    RETURN_IF(!message::ParseFromArray(
        rb->buf, static_cast<int>(rb->block->msg_size()), msg.get()));
    listener(msg, msg_info);
  };

  Dispatcher::AddListener<ReadableBlock>(self_attr, opposite_attr,
                                         listener_adapter);
  AddSegment(self_attr);
}

}  // namespace transport
}  // namespace hiva
}  // namespace etron

#endif  // HIVA_TRANSPORT_DISPATCHER_SHM_DISPATCHER_H_
