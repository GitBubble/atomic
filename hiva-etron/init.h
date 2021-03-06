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

#ifndef HIVA_INIT_H_
#define HIVA_INIT_H_

#include "hiva/common/log.h"
#include "hiva/state.h"

namespace etron {
namespace hiva {

bool Init(const char* binary_name);
void Clear();

}  // namespace hiva
}  // namespace etron

#endif  // HIVA_INIT_H_
