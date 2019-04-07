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

#ifndef HIVA_HIVA_H_
#define HIVA_HIVA_H_

#include <memory>
#include <string>
#include <utility>

#include "hiva/common/log.h"
#include "hiva/component/component.h"
#include "hiva/init.h"
#include "hiva/node/node.h"
//#include "hiva/task/task.h"
#include "hiva/time/time.h"
#include "hiva/timer/timer.h"

namespace etron {
namespace hiva {

std::unique_ptr<Node> CreateNode(const std::string& node_name,
                                 const std::string& name_space = "");

}  // namespace hiva
}  // namespace etron

#endif  // HIVA_HIVA_H_
