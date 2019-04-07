load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "common",
    deps = [
        "//hiva/common:environment",
        "//hiva/common:file",
        "//hiva/common:global_data",
        "//hiva/common:log",
        "//hiva/common:macros",
        "//hiva/common:time_conversion",
        "//hiva/common:types",
        "//hiva/common:util",
    ],
)

cc_library(
    name = "file",
    srcs = [
        "file.cc",
    ],
    hdrs = [
        "file.h",
    ],
    deps = [
        "//hiva/common:log",
    ],
)

cc_test(
    name = "file_test",
    size = "small",
    srcs = [
        "file_test.cc",
    ],
    deps = [
        "//hiva",
        "//hiva/proto:unit_test_cc_proto",
        "@gtest//:main",
    ],
)

cc_library(
    name = "log",
    hdrs = [
        "log.h",
    ],
    linkopts = [
        "-lglog",
    ],
    deps = [
        "//hiva:binary",
    ],
)

cc_test(
    name = "log_test",
    size = "small",
    srcs = [
        "log_test.cc",
    ],
    deps = [
        "//hiva",
        "@gtest//:main",
    ],
)

cc_library(
    name = "environment",
    hdrs = [
        "environment.h",
    ],
    deps = [
        #"//hiva/common:log",
    ],
)

cc_library(
    name = "global_data",
    srcs = [
        "global_data.cc",
    ],
    hdrs = [
        "global_data.h",
    ],
    deps = [
        "//hiva/base:atomic_hash_map",
        "//hiva/base:atomic_rw_lock",
        "//hiva/common:environment",
        "//hiva/common:file",
        "//hiva/common:macros",
        "//hiva/common:util",
        "//hiva/proto:hiva_conf_cc_proto",
    ],
)

cc_test(
    name = "macros_test",
    size = "small",
    srcs = [
        "macros_test.cc",
    ],
    deps = [
        "//hiva",
        "@gtest//:main",
    ],
)

cc_library(
    name = "macros",
    hdrs = [
        "macros.h",
    ],
    deps = [
        "//hiva/base:macros",
    ],
)

cc_library(
    name = "time_conversion",
    hdrs = [
        "time_conversion.h",
    ],
)

cc_library(
    name = "types",
    hdrs = [
        "types.h",
    ],
)

cc_library(
    name = "util",
    hdrs = [
        "util.h",
    ],
)

cpplint()
