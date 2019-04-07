load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "hiva",
    linkstatic = False,
    deps = [
        "//hiva:hiva_core",
    ],
)

cc_binary(
    name = "mainboard",
    srcs = [
        "mainboard/mainboard.cc",
        "mainboard/module_argument.cc",
        "mainboard/module_argument.h",
        "mainboard/module_controller.cc",
        "mainboard/module_controller.h",
    ],
    copts = [
        "-pthread",
    ],
    linkstatic = False,
    deps = [
        ":hiva_core",
        "//hiva/proto:dag_conf_cc_proto",
    ],
)

cc_library(
    name = "binary",
    hdrs = [
        "binary.h",
    ],
)

cc_library(
    name = "state",
    srcs = [
        "state.cc",
    ],
    hdrs = [
        "state.h",
    ],
    deps = [
        "//hiva/common",
    ],
)

cc_library(
    name = "init",
    srcs = [
        "init.cc",
    ],
    hdrs = [
        "init.h",
    ],
    deps = [
        "//hiva:state",
        "//hiva/logger:async_logger",
        "//hiva/node",
    ],
)

cc_library(
    name = "hiva_core",
    srcs = [
        "hiva.cc",
    ],
    hdrs = [
        "hiva.h",
    ],
    linkopts = [
        "-lglog",
        "-lgflags",
        "-lprotobuf",
        "-luuid",
    ],
    deps = [
        "//hiva:binary",
        "//hiva:init",
        "//hiva:state",
        "//hiva/base",
        "//hiva/blocker:blocker_manager",
        "//hiva/class_loader",
        "//hiva/class_loader:class_loader_manager",
        "//hiva/common",
        "//hiva/component",
        "//hiva/component:timer_component",
        "//hiva/croutine",
        "//hiva/data",
        "//hiva/event:perf_event_cache",
        "//hiva/io",
        "//hiva/logger",
        "//hiva/logger:async_logger",
        "//hiva/message:message_traits",
        "//hiva/message:protobuf_traits",
        "//hiva/message:py_message_traits",
        "//hiva/message:raw_message_traits",
        "//hiva/node",
        "//hiva/parameter:parameter_client",
        "//hiva/parameter:parameter_server",
        "//hiva/proto:run_mode_conf_cc_proto",
        "//hiva/record",
        "//hiva/scheduler",
        "//hiva/scheduler:scheduler_factory",
        "//hiva/service",
        "//hiva/service:client",
        "//hiva/service_discovery:topology_manager",
        "//hiva/task",
        "//hiva/time",
        "//hiva/time:duration",
        "//hiva/time:rate",
        "//hiva/timer",
        "//hiva/transport",
        "//hiva/transport:participant",
        "//hiva/transport:sub_listener",
        "//third_party/tf2",
        "@fastrtps",
    ],
)

cpplint()
