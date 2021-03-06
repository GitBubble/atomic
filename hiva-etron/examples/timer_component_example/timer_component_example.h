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
#include <memory>

#include "hiva/class_loader/class_loader.h"
#include "hiva/component/component.h"
#include "hiva/component/timer_component.h"
#include "hiva/examples/proto/examples.pb.h"

using etron::hiva::examples::proto::Driver;
using etron::hiva::Component;
using etron::hiva::ComponentBase;
using etron::hiva::TimerComponent;
using etron::hiva::Writer;

class TimerComponentSample : public TimerComponent {
 public:
  bool Init() override;
  bool Proc() override;

 private:
  std::shared_ptr<Writer<Driver>> driver_writer_ = nullptr;
};
HIVA_REGISTER_COMPONENT(TimerComponentSample)
