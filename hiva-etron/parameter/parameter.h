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

#ifndef HIVA_PARAMETER_PARAMETER_H_
#define HIVA_PARAMETER_PARAMETER_H_

#include <string>

#include "hiva/common/log.h"
#include "hiva/proto/parameter.pb.h"

/**
 * @namespace hiva.parameter
 */
namespace etron {
namespace hiva {

using etron::hiva::proto::Param;
using etron::hiva::proto::ParamType;

/**
 * @class Parameter
 */
class Parameter {
 public:
  Parameter();
  explicit Parameter(const Parameter& parameter);
  explicit Parameter(const std::string& name);
  Parameter(const std::string& name, const bool bool_value);
  Parameter(const std::string& name, const int int_value);
  Parameter(const std::string& name, const int64_t int_value);
  Parameter(const std::string& name, const float double_value);
  Parameter(const std::string& name, const double double_value);
  Parameter(const std::string& name, const std::string& string_value);
  Parameter(const std::string& name, const char* string_value);
  Parameter(const std::string& name, const std::string& msg_str,
            const std::string& full_name, const std::string& proto_desc);
  Parameter(const std::string& name, const google::protobuf::Message& msg);

  /**
   * @brief Parse a hiva::proto::Param object to
   * hiva::parameter::Parameter object
   * @param param The hiva::proto::Param object parse from
   * @param parameter A pointer to the target Parameter object
   * @return True if parse ok, otherwise False
   */
  void FromProtoParam(const Param& param);

  /**
   * @brief Parse a hiva::parameter::Parameter object to
   * hiva::proto::Param object
   * @return The target hiva::proto::Param object
   */
  Param ToProtoParam() const;

  /**
   * @brief Get the hiva:parameter::ParameterType of this object
   * @return hiva:parameter::ParameterType
   */
  inline ParamType Type() const;
  inline std::string TypeName() const;
  inline std::string Descriptor() const;
  inline const std::string Name() const;
  inline bool AsBool() const;
  inline int64_t AsInt64() const;
  inline double AsDouble() const;
  inline const std::string AsString() const;
  std::string DebugString() const;

  template <typename ValueType>
  typename std::enable_if<
      std::is_base_of<google::protobuf::Message, ValueType>::value,
      ValueType>::type
  value() const;

  template <typename ValueType>
  typename std::enable_if<std::is_integral<ValueType>::value &&
                              !std::is_same<ValueType, bool>::value,
                          ValueType>::type
  value() const;

  template <typename ValueType>
  typename std::enable_if<std::is_floating_point<ValueType>::value,
                          ValueType>::type
  value() const;

  template <typename ValueType>
  typename std::enable_if<std::is_convertible<ValueType, std::string>::value,
                          const std::string&>::type
  value() const;

  template <typename ValueType>
  typename std::enable_if<std::is_same<ValueType, bool>::value, bool>::type
  value() const;

 private:
  Param param_;
};

template <typename ValueType>
typename std::enable_if<
    std::is_base_of<google::protobuf::Message, ValueType>::value,
    ValueType>::type
Parameter::value() const {
  ValueType message;
  if (!message.ParseFromString(param_.string_value())) {
    AERROR << "The type of parameter \"" << param_.name() << "\" is "
           << TypeName() << ", not " << ValueType::descriptor()->full_name();
  }
  return message;
}

template <typename ValueType>
typename std::enable_if<std::is_integral<ValueType>::value &&
                            !std::is_same<ValueType, bool>::value,
                        ValueType>::type
Parameter::value() const {
  if (param_.type() != proto::ParamType::INT) {
    AERROR << "The type of parameter \"" << param_.name() << "\" is "
           << TypeName() << ", not INT";
  }
  return static_cast<ValueType>(param_.int_value());
}

template <typename ValueType>
typename std::enable_if<std::is_floating_point<ValueType>::value,
                        ValueType>::type
Parameter::value() const {
  if (param_.type() != proto::ParamType::DOUBLE) {
    AERROR << "The type of parameter \"" << param_.name() << "\" is "
           << TypeName() << ", not DOUBLE";
  }
  return static_cast<ValueType>(param_.double_value());
}

template <typename ValueType>
typename std::enable_if<std::is_convertible<ValueType, std::string>::value,
                        const std::string&>::type
Parameter::value() const {
  if (param_.type() != proto::ParamType::STRING &&
      param_.type() != proto::ParamType::PROTOBUF) {
    AERROR << "The type of parameter \"" << param_.name() << "\" is "
           << TypeName() << ", not STRING";
  }
  return param_.string_value();
}

template <typename ValueType>
typename std::enable_if<std::is_same<ValueType, bool>::value, bool>::type
Parameter::value() const {
  if (param_.type() != proto::ParamType::BOOL) {
    AERROR << "The type of parameter \"" << param_.name() << "\" is "
           << TypeName() << ", not BOOL";
  }
  return param_.bool_value();
}

inline ParamType Parameter::Type() const { return param_.type(); }

inline std::string Parameter::TypeName() const { return param_.type_name(); }

inline std::string Parameter::Descriptor() const { return param_.proto_desc(); }

inline const std::string Parameter::Name() const { return param_.name(); }

inline bool Parameter::AsBool() const { return value<bool>(); }

inline int64_t Parameter::AsInt64() const { return value<int64_t>(); }

inline double Parameter::AsDouble() const { return value<double>(); }

const std::string Parameter::AsString() const { return value<std::string>(); }

}  // namespace hiva
}  // namespace etron

#endif  // HIVA_PARAMETER_PARAMETER_H_
