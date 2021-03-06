load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "intra_message",
    srcs = [
        "intra_message.cc",
    ],
    hdrs = [
        "intra_message.h",
    ],
)

cc_library(
    name = "message_traits",
    hdrs = [
        "message_traits.h",
    ],
    deps = [
        "intra_message",
        "protobuf_traits",
        "py_message_traits",
        "raw_message_traits",
        "//hiva/base:macros",
    ],
)

cc_test(
    name = "message_traits_test",
    size = "small",
    srcs = [
        "message_traits_test.cc",
    ],
    deps = [
        "//hiva",
        "//hiva/proto:unit_test_cc_proto",
        "@gtest//:main",
    ],
)

cc_library(
    name = "protobuf_factory",
    srcs = [
        "protobuf_factory.cc",
    ],
    hdrs = [
        "protobuf_factory.h",
    ],
    deps = [
        "//hiva/common:log",
        "//hiva/common:macros",
        "//hiva/proto:proto_desc_cc_proto",
    ],
)

cc_library(
    name = "protobuf_traits",
    hdrs = [
        "protobuf_traits.h",
    ],
    deps = [
        "protobuf_factory",
    ],
)

cc_library(
    name = "py_message",
    hdrs = [
        "py_message.h",
    ],
    deps = [
        "protobuf_factory",
    ],
)

cc_library(
    name = "py_message_traits",
    hdrs = [
        "py_message_traits.h",
    ],
    deps = [
        "protobuf_factory",
        "py_message",
    ],
)

cc_library(
    name = "raw_message",
    hdrs = [
        "raw_message.h",
    ],
    deps = [
        "protobuf_factory",
    ],
)

cc_test(
    name = "raw_message_test",
    size = "small",
    srcs = [
        "raw_message_test.cc",
    ],
    deps = [
        "//hiva",
        "@gtest//:main",
    ],
)

cc_test(
    name = "protobuf_factory_test",
    size = "small",
    srcs = [
        "protobuf_factory_test.cc",
    ],
    deps = [
        "//hiva",
        "//hiva/proto:unit_test_cc_proto",
        "@gtest//:main",
    ],
)

cc_library(
    name = "raw_message_traits",
    hdrs = [
        "raw_message_traits.h",
    ],
    deps = [
        "protobuf_factory",
        "raw_message",
    ],
)

cpplint()
