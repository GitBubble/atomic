load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "croutine",
    srcs = [
        "croutine.cc",
    ],
    hdrs = [
        "croutine.h",
    ],
    linkopts = ["-latomic"],
    deps = [
        "//hiva/base:atomic_hash_map",
        "//hiva/base:atomic_rw_lock",
        "//hiva/base:bounded_queue",
        "//hiva/base:concurrent_object_pool",
        "//hiva/base:macros",
        "//hiva/base:wait_strategy",
        "//hiva/common",
        "//hiva/croutine:routine_context",
        "//hiva/croutine:routine_factory",
        "//hiva/croutine:swap",
        "//hiva/event:perf_event_cache",
        "//hiva/time",
    ],
)

cc_library(
    name = "routine_context",
    srcs = [
        "detail/routine_context.cc",
    ],
    hdrs = [
        "detail/routine_context.h",
    ],
    deps = [
        "//hiva/common",
    ],
)

cc_library(
    name = "routine_factory",
    hdrs = [
        "routine_factory.h",
    ],
    deps = [
        "//hiva/common",
        "//hiva/event:perf_event_cache",
    ],
)

cc_library(
    name = "swap",
    srcs = [
        "detail/swap.S",
    ],
)

cc_test(
    name = "croutine_test",
    size = "small",
    srcs = [
        "croutine_test.cc",
    ],
    deps = [
        "//hiva",
        "@gtest//:main",
    ],
)

cpplint()
