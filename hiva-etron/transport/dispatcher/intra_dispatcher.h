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

#ifndef HIVA_TRANSPORT_DISPATCHER_INTRA_DISPATCHER_H_
#define HIVA_TRANSPORT_DISPATCHER_INTRA_DISPATCHER_H_

#include <iostream>
#include <memory>
#include <string>

#include "hiva/common/global_data.h"
#include "hiva/common/log.h"
#include "hiva/common/macros.h"
#include "hiva/message/message_traits.h"
#include "hiva/message/raw_message.h"
#include "hiva/transport/dispatcher/dispatcher.h"

namespace etron {
namespace hiva {
namespace transport {

class IntraDispatcher;
using IntraDispatcherPtr = IntraDispatcher*;

class IntraDispatcher : public Dispatcher {
 public:
  virtual ~IntraDispatcher();

  template <typename MessageT>
  void OnMessage(uint64_t channel_id, const std::shared_ptr<MessageT>& message,
                 const MessageInfo& message_info);

  DECLARE_SINGLETON(IntraDispatcher)
};

template <typename MessageT>
void IntraDispatcher::OnMessage(uint64_t channel_id,
                                const std::shared_ptr<MessageT>& message,
                                const MessageInfo& message_info) {
  if (is_shutdown_.load()) {
    return;
  }
  ADEBUG << "intra on message, channel:"
         << common::GlobalData::GetChannelById(channel_id);
  ListenerHandlerBasePtr* handler_base = nullptr;
  if (msg_listeners_.Get(channel_id, &handler_base)) {
    if ((*handler_base)->IsRawMessage()) {
      auto handler =
          std::dynamic_pointer_cast<ListenerHandler<message::RawMessage>>(
              *handler_base);
      auto msg = std::make_shared<message::RawMessage>();
      message::SerializeToString(*message, &msg->message);
      handler->Run(msg, message_info);
    } else {
      auto handler =
          std::dynamic_pointer_cast<ListenerHandler<MessageT>>(*handler_base);
      if (handler == nullptr) {
        AERROR << "please ensure that readers with the same channel["
               << common::GlobalData::GetChannelById(channel_id)
               << "] in the same process have the same message type";
        return;
      }
      handler->Run(message, message_info);
    }
  }
}

}  // namespace transport
}  // namespace hiva
}  // namespace etron

#endif  // HIVA_TRANSPORT_DISPATCHER_INTRA_DISPATCHER_H_