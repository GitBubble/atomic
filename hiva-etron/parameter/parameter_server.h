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

#ifndef HIVA_PARAMETER_PARAMETER_SERVER_H_
#define HIVA_PARAMETER_PARAMETER_SERVER_H_

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "hiva/parameter/parameter.h"
#include "hiva/proto/parameter.pb.h"
#include "hiva/service/service.h"

namespace etron {
namespace hiva {

class Node;

class ParameterServer {
 public:
  using Param = etron::hiva::proto::Param;
  using NodeName = etron::hiva::proto::NodeName;
  using ParamName = etron::hiva::proto::ParamName;
  using BoolResult = etron::hiva::proto::BoolResult;
  using Params = etron::hiva::proto::Params;
  /**
   * @brief Construct a new ParameterServer object
   *
   * @param node shared_ptr of the node handler
   */
  explicit ParameterServer(const std::shared_ptr<Node>& node);

  /**
   * @brief Set the Parameter object
   *
   * @param parmeter parameter to be set
   */
  void SetParameter(const Parameter& parmeter);

  /**
   * @brief Get the Parameter object
   *
   * @param parameter_name name of the parameer want to get
   * @param parameter pointer to store parameter want to get
   * @return true get parameter success
   * @return false parameter not exists
   */
  bool GetParameter(const std::string& parameter_name, Parameter* parameter);

  /**
   * @brief get all the parameters
   *
   * @param parameters
   */
  void ListParameters(std::vector<Parameter>* parameters);

 private:
  std::shared_ptr<Node> node_;
  std::shared_ptr<Service<ParamName, Param>> get_parameter_service_;
  std::shared_ptr<Service<Param, BoolResult>> set_parameter_service_;
  std::shared_ptr<Service<NodeName, Params>> list_parameters_service_;

  std::mutex param_map_mutex_;
  std::unordered_map<std::string, Param> param_map_;
};

}  // namespace hiva
}  // namespace etron

#endif  // HIVA_PARAMETER_PARAMETER_SERVER_H_
