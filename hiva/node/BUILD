load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "node",
    srcs = ["node.cc"],
    hdrs = ["node.h"],
    deps = [
        "node_channel_impl",
        "node_service_impl",
    ],
)

cc_library(
    name = "node_channel_impl",
    hdrs = ["node_channel_impl.h"],
    deps = [
        "reader",
        "writer",
        "//hiva/blocker:intra_reader",
        "//hiva/blocker:intra_writer",
        "//hiva/common:global_data",
        "//hiva/message:message_traits",
        "//hiva/proto:run_mode_conf_cc_proto",
    ],
)

cc_library(
    name = "node_service_impl",
    hdrs = ["node_service_impl.h"],
    deps = [
        "reader",
        "writer",
        "//hiva/common:global_data",
        "//hiva/service",
        "//hiva/service:client",
        "//hiva/service_discovery:topology_manager",
    ],
)

cc_test(
    name = "node_test",
    size = "small",
    srcs = [
        "node_test.cc",
    ],
    deps = [
        "//hiva",
        "//hiva/proto:unit_test_cc_proto",
        "@gtest//:main",
    ],
)

cc_library(
    name = "reader",
    hdrs = ["reader.h"],
    deps = [
        "reader_base",
        "//hiva/blocker",
        "//hiva/common:global_data",
        "//hiva/croutine:routine_factory",
        "//hiva/data:data_visitor",
        "//hiva/proto:topology_change_cc_proto",
        "//hiva/scheduler",
        "//hiva/service_discovery:topology_manager",
        "//hiva/time",
        "//hiva/transport",
    ],
)

cc_library(
    name = "reader_base",
    hdrs = ["reader_base.h"],
    deps = [
        "//hiva/event:perf_event_cache",
        "//hiva/transport",
    ],
)

cc_library(
    name = "writer",
    hdrs = ["writer.h"],
    deps = [
        "writer_base",
        "//hiva/common:log",
        "//hiva/proto:topology_change_cc_proto",
        "//hiva/service_discovery:topology_manager",
        "//hiva/transport",
    ],
)

cc_library(
    name = "writer_base",
    hdrs = ["writer_base.h"],
    deps = [
        "//hiva/common:macros",
        "//hiva/common:util",
        "//hiva/proto:role_attributes_cc_proto",
    ],
)

cc_test(
    name = "writer_reader_test",
    size = "small",
    srcs = ["writer_reader_test.cc"],
    deps = [
        "//hiva",
        "//hiva/proto:unit_test_cc_proto",
        "@gtest",
    ],
)

cpplint()
