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

/**
 * @log
 */

#ifndef CYBER_COMMON_LOG_H_
#define CYBER_COMMON_LOG_H_

#include <stdarg.h>
#include <iostream>
#include "binary.h"
//#include "glog/logging.h"
//#include "glog/raw_logging.h"

#define LEFT_BRACKET "["
#define RIGHT_BRACKET "] "

#ifndef MODULE_NAME
#define MODULE_NAME apollo::cyber::Binary::GetName().c_str()
#endif

#define ADEBUG_MODULE(module) \
    std::cout << LEFT_BRACKET << MODULE_NAME << RIGHT_BRACKET << "[DEBUG] ";
   //VLOG(4) << LEFT_BRACKET << MODULE_NAME << RIGHT_BRACKET << "[DEBUG] "

#define ADEBUG ADEBUG_MODULE(MODULE_NAME)
#define AINFO ADEBUG_MODULE(MODULE_NAME)
#define AWARN ADEBUG_MODULE(MODULE_NAME)
#define AERROR ADEBUG_MODULE(MODULE_NAME)
#define AFATAL ADEBUG_MODULE(MODULE_NAME)

#endif 
