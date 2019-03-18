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

#ifndef CYBER_TRANSPORT_SHM_NOTIFIER_FACTORY_H_
#define CYBER_TRANSPORT_SHM_NOTIFIER_FACTORY_H_

#include <memory>

#include "hiva/transport/shm/notifier_base.h"

namespace apollo {
namespace hiva {
namespace transport {

class NotifierFactory {
 public:
  static NotifierPtr CreateNotifier();

 private:
  static NotifierPtr CreateConditionNotifier();
  static NotifierPtr CreateMulticastNotifier();
};

}  // namespace transport
}  // namespace hiva
}  // namespace apollo

#endif  // CYBER_TRANSPORT_SHM_NOTIFIER_FACTORY_H_
