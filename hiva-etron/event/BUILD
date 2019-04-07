load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "perf_event_cache",
    srcs = [
        "perf_event_cache.cc",
    ],
    hdrs = [
        "perf_event_cache.h",
    ],
    deps = [
        "perf_event",
        "//hiva:state",
        "//hiva/base:bounded_queue",
        "//hiva/common:global_data",
        "//hiva/common:log",
        "//hiva/common:macros",
        "//hiva/time",
    ],
)

cc_library(
    name = "perf_event",
    hdrs = ["perf_event.h"],
    deps = [
        "//hiva/common:global_data",
    ],
)

cpplint()
