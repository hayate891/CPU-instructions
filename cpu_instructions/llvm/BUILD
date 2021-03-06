# Description:
#   Libraries for interacting with LLVM.

package(default_visibility = ["//visibility:public"])

licenses(["notice"])  # Apache 2.0

# Library for compiling inline assembly code.
cc_library(
    name = "inline_asm",
    srcs = ["inline_asm.cc"],
    hdrs = ["inline_asm.h"],
    deps = [
        "//base",
        "//cpu_instructions/llvm:llvm_utils",
        "//strings",
        "//util/gtl:map_util",
        "//util/gtl:ptr_util",
        "@gflags_git//:gflags",
        "@glog_git//:glog",
        "@llvm_git//:execution_engine",
        "@llvm_git//:ir",
        "@llvm_git//:mcjit",
        "@llvm_git//:support",
        "@protobuf_git//:protobuf_lite",
    ],
)

cc_test(
    name = "inline_asm_test",
    size = "small",
    srcs = ["inline_asm_test.cc"],
    deps = [
        ":inline_asm",
        "//base",
        "//cpu_instructions/llvm:llvm_utils",
        "//cpu_instructions/util:strings",
        "@gflags_git//:gflags",
        "@glog_git//:glog",
        "@googletest_git//:gtest",
        "@googletest_git//:gtest_main",
        "@llvm_git//:ir",
        "@llvm_git//:support",
        "@protobuf_git//:protobuf_lite",
    ],
)

# A library that contains all the LLVM targets necessary to initialize the LLVM
# subsystems.
cc_library(
    name = "llvm_targets",
    deps = [
        "@llvm_git//:x86_target",
        "@llvm_git//:x86_target_asm_parser",
        "@llvm_git//:x86_target_disassembler",
        "@llvm_git//:x86_target_info",
    ],
    alwayslink = 1,
)

# A target that contains a library of helper functions for initializing LLVM and
# that holds all dependencies on LLVM packages (for now, for simplicity).
cc_library(
    name = "llvm_utils",
    srcs = ["llvm_utils.cc"],
    hdrs = ["llvm_utils.h"],
    deps = [
        "//base",
        "//cpu_instructions/llvm:llvm_targets",
        "//strings",
        "//util/task:status",
        "//util/task:statusor",
        "@gflags_git//:gflags",
        "@glog_git//:glog",
        "@llvm_git//:analysis",  # buildcleaner: keep
        "@llvm_git//:codegen",
        "@llvm_git//:ir",
        "@llvm_git//:machine_code",
        "@llvm_git//:support",
        "@llvm_git//:target_base",
        "@protobuf_git//:protobuf_lite",
    ],
)
