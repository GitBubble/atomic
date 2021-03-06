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

#ifndef HIVA_SERVICE_DISCOVERY_SPECIFIC_MANAGER_NODE_MANAGER_H_
#define HIVA_SERVICE_DISCOVERY_SPECIFIC_MANAGER_NODE_MANAGER_H_

#include <memory>
#include <string>
#include <vector>

#include "hiva/service_discovery/container/single_value_warehouse.h"
#include "hiva/service_discovery/role/role.h"
#include "hiva/service_discovery/specific_manager/manager.h"

namespace etron {
namespace hiva {
namespace service_discovery {

class TopologyManager;

class NodeManager : public Manager {
  friend class TopologyManager;

 public:
  using RoleAttrVec = std::vector<RoleAttributes>;
  using NodeWarehouse = SingleValueWarehouse;

  NodeManager();
  virtual ~NodeManager();

  bool HasNode(const std::string& node_name);
  void GetNodes(RoleAttrVec* nodes);

 private:
  bool Check(const RoleAttributes& attr) override;
  void Dispose(const ChangeMsg& msg) override;
  void OnTopoModuleLeave(const std::string& host_name, int process_id) override;

  void DisposeJoin(const ChangeMsg& msg);
  void DisposeLeave(const ChangeMsg& msg);

  NodeWarehouse nodes_;
};

}  // namespace service_discovery
}  // namespace hiva
}  // namespace etron

#endif  //  HIVA_SERVICE_DISCOVERY_SPECIFIC_MANAGER_NODE_MANAGER_H_
