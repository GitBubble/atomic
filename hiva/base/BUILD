load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "base",
    deps = [
        "//hiva/base:atomic_fifo",
        "//hiva/base:atomic_hash_map",
        "//hiva/base:atomic_rw_lock",
        "//hiva/base:bounded_queue",
        "//hiva/base:concurrent_object_pool",
        "//hiva/base:for_each",
        "//hiva/base:macros",
        "//hiva/base:object_pool",
        "//hiva/base:reentrant_rw_lock",
        "//hiva/base:rw_lock_guard",
        "//hiva/base:signal",
        "//hiva/base:thread_pool",
        "//hiva/base:thread_safe_queue",
        "//hiva/base:unbounded_queue",
        "//hiva/base:wait_strategy",
    ],
)

cc_library(
    name = "atomic_fifo",
    hdrs = [
        "atomic_fifo.h",
    ],
)

cc_library(
    name = "atomic_hash_map",
    hdrs = [
        "atomic_hash_map.h",
    ],
)

cc_test(
    name = "atomic_hash_map_test",
    size = "small",
    srcs = [
        "atomic_hash_map_test.cc",
    ],
    deps = [
        "//hiva/base:atomic_hash_map",
        "@gtest//:main",
    ],
)

cc_library(
    name = "atomic_rw_lock",
    hdrs = [
        "atomic_rw_lock.h",
    ],
    deps = [
        "//hiva/base:rw_lock_guard",
    ],
)

cc_test(
    name = "atomic_rw_lock_test",
    size = "small",
    srcs = [
        "atomic_rw_lock_test.cc",
    ],
    deps = [
        "//hiva/base:atomic_rw_lock",
        "//hiva/base:reentrant_rw_lock",
        "@gtest//:main",
    ],
)

cc_library(
    name = "bounded_queue",
    hdrs = [
        "bounded_queue.h",
    ],
    deps = [
        "//hiva/base:macros",
        "//hiva/base:wait_strategy",
    ],
)

cc_test(
    name = "bounded_queue_test",
    size = "small",
    srcs = [
        "bounded_queue_test.cc",
    ],
    deps = [
        "//hiva/base:bounded_queue",
        "@gtest//:main",
    ],
)

cc_library(
    name = "concurrent_object_pool",
    hdrs = [
        "concurrent_object_pool.h",
    ],
    deps = [
        "//hiva/base:for_each",
    ],
)

cc_library(
    name = "for_each",
    hdrs = [
        "for_each.h",
    ],
    deps = [
        "//hiva/base:macros",
    ],
)

cc_test(
    name = "for_each_test",
    size = "small",
    srcs = [
        "for_each_test.cc",
    ],
    deps = [
        "//hiva/base:for_each",
        "@gtest//:main",
    ],
)

cc_library(
    name = "macros",
    hdrs = [
        "macros.h",
    ],
)

cc_library(
    name = "object_pool",
    hdrs = [
        "object_pool.h",
    ],
    deps = [
        "//hiva/base:for_each",
        "//hiva/base:macros",
    ],
)

cc_test(
    name = "object_pool_test",
    size = "small",
    srcs = [
        "object_pool_test.cc",
    ],
    linkopts = [
        "-latomic",
    ],
    deps = [
        "//hiva/base:concurrent_object_pool",
        "//hiva/base:object_pool",
        "@gtest//:main",
    ],
)

cc_library(
    name = "reentrant_rw_lock",
    hdrs = [
        "reentrant_rw_lock.h",
    ],
)

cc_library(
    name = "rw_lock_guard",
    hdrs = [
        "rw_lock_guard.h",
    ],
)

cc_library(
    name = "signal",
    hdrs = [
        "signal.h",
    ],
)

cc_test(
    name = "signal_test",
    size = "small",
    srcs = [
        "signal_test.cc",
    ],
    deps = [
        "//hiva/base:signal",
        "@gtest//:main",
    ],
)

cc_library(
    name = "thread_pool",
    hdrs = [
        "thread_pool.h",
    ],
)

cc_library(
    name = "thread_safe_queue",
    hdrs = [
        "thread_safe_queue.h",
    ],
)

cc_library(
    name = "unbounded_queue",
    hdrs = [
        "unbounded_queue.h",
    ],
)

cc_library(
    name = "wait_strategy",
    hdrs = [
        "wait_strategy.h",
    ],
)

cpplint()
