# Contains functions and data structures that concern specifically the
# x86 and x86-64 platforms.

package(default_visibility = ["//:internal_users"])

licenses(["notice"])  # Apache 2.0

# A collection of utilities used by the instruction set cleanup library.
cc_library(
    name = "cleanup_instruction_set_utils",
    srcs = ["cleanup_instruction_set_utils.cc"],
    hdrs = ["cleanup_instruction_set_utils.h"],
    deps = [
        "//base",
        "//cpu_instructions/base:cleanup_instruction_set",
        "//cpu_instructions/proto:instructions_proto",
        "//cpu_instructions/proto/x86:encoding_specification_proto",
        "//strings",
        "@gflags_git//:gflags",
        "@glog_git//:glog",
        "@protobuf_git//:protobuf_lite",
    ],
)

cc_test(
    name = "cleanup_instruction_set_utils_test",
    size = "small",
    srcs = ["cleanup_instruction_set_utils_test.cc"],
    deps = [
        ":cleanup_instruction_set_utils",
        "//cpu_instructions/proto:instructions_proto",
        "//cpu_instructions/testing:test_util",
        "@googletest_git//:gtest",
        "@googletest_git//:gtest_main",
        "@protobuf_git//:protobuf",
    ],
)

# A collection of libraries that implement the different cleanups of the
# instruction set. To make maintenance easier, each file has its own cc_library
# target and a separate test.
# The target cleanup_instruction_set_all integrates all the cleanup libraries
# into a single target.
cc_library(
    name = "cleanup_instruction_set_all",
    visibility = ["//visibility:public"],
    deps = [
        ":cleanup_instruction_set_alternatives",
        ":cleanup_instruction_set_asm_syntax",
        ":cleanup_instruction_set_encoding",
        ":cleanup_instruction_set_evex",
        ":cleanup_instruction_set_fix_operands",
        ":cleanup_instruction_set_operand_info",
        ":cleanup_instruction_set_operand_size_override",
        ":cleanup_instruction_set_properties",
        ":cleanup_instruction_set_removals",
        ":cleanup_instruction_set_utils",
    ],
    alwayslink = 1,
)

cc_library(
    name = "cleanup_instruction_set_alternatives",
    srcs = ["cleanup_instruction_set_alternatives.cc"],
    hdrs = ["cleanup_instruction_set_alternatives.h"],
    deps = [
        "//base",
        "//cpu_instructions/base:cleanup_instruction_set",
        "//cpu_instructions/proto:instructions_proto",
        "//strings",
        "//util/gtl:map_util",
        "//util/task:status",
        "@gflags_git//:gflags",
        "@glog_git//:glog",
        "@protobuf_git//:protobuf_lite",
    ],
    alwayslink = 1,
)

cc_test(
    name = "cleanup_instruction_set_alternatives_test",
    size = "small",
    srcs = ["cleanup_instruction_set_alternatives_test.cc"],
    deps = [
        ":cleanup_instruction_set_alternatives",
        "//cpu_instructions/base:cleanup_instruction_set_test_utils",
        "@googletest_git//:gtest",
        "@googletest_git//:gtest_main",
    ],
)

cc_library(
    name = "cleanup_instruction_set_asm_syntax",
    srcs = ["cleanup_instruction_set_asm_syntax.cc"],
    hdrs = ["cleanup_instruction_set_asm_syntax.h"],
    deps = [
        "//base",
        "//cpu_instructions/base:cleanup_instruction_set",
        "//cpu_instructions/proto:instructions_proto",
        "//strings",
        "//util/gtl:map_util",
        "//util/task:status",
        "@gflags_git//:gflags",
        "@glog_git//:glog",
        "@protobuf_git//:protobuf_lite",
    ],
    alwayslink = 1,
)

cc_test(
    name = "cleanup_instruction_set_asm_syntax_test",
    size = "small",
    srcs = ["cleanup_instruction_set_asm_syntax_test.cc"],
    deps = [
        ":cleanup_instruction_set_asm_syntax",
        "//cpu_instructions/base:cleanup_instruction_set_test_utils",
        "@googletest_git//:gtest",
        "@googletest_git//:gtest_main",
    ],
)

cc_library(
    name = "cleanup_instruction_set_encoding",
    srcs = ["cleanup_instruction_set_encoding.cc"],
    hdrs = ["cleanup_instruction_set_encoding.h"],
    deps = [
        ":cleanup_instruction_set_utils",
        "//base",
        "//cpu_instructions/base:cleanup_instruction_set",
        "//cpu_instructions/proto:instructions_proto",
        "//cpu_instructions/proto/x86:encoding_specification_proto",
        "//cpu_instructions/util:status_util",
        "//cpu_instructions/x86:encoding_specification",
        "//strings",
        "//util/gtl:map_util",
        "//util/task:status",
        "@com_googlesource_code_re2//:re2",
        "@gflags_git//:gflags",
        "@glog_git//:glog",
        "@protobuf_git//:protobuf",
        "@protobuf_git//:protobuf_lite",
    ],
    alwayslink = 1,
)

cc_test(
    name = "cleanup_instruction_set_encoding_test",
    size = "small",
    srcs = ["cleanup_instruction_set_encoding_test.cc"],
    deps = [
        ":cleanup_instruction_set_encoding",
        "//cpu_instructions/base:cleanup_instruction_set_test_utils",
        "//util/task:status",
        "@googletest_git//:gtest",
        "@googletest_git//:gtest_main",
        "@protobuf_git//:protobuf",
    ],
)

cc_library(
    name = "cleanup_instruction_set_evex",
    srcs = ["cleanup_instruction_set_evex.cc"],
    hdrs = ["cleanup_instruction_set_evex.h"],
    deps = [
        "//base",
        "//cpu_instructions/base:cleanup_instruction_set",
        "//cpu_instructions/proto:instructions_proto",
        "//cpu_instructions/proto/x86:encoding_specification_proto",
        "//strings",
        "//util/gtl:map_util",
        "//util/task:status",
        "@gflags_git//:gflags",
        "@glog_git//:glog",
        "@protobuf_git//:protobuf_lite",
    ],
    alwayslink = 1,
)

cc_test(
    name = "cleanup_instruction_set_evex_test",
    size = "small",
    srcs = ["cleanup_instruction_set_evex_test.cc"],
    deps = [
        ":cleanup_instruction_set_evex",
        "//base",
        "//cpu_instructions/base:cleanup_instruction_set_test_utils",
        "@gflags_git//:gflags",
        "@glog_git//:glog",
        "@googletest_git//:gtest",
        "@googletest_git//:gtest_main",
        "@protobuf_git//:protobuf_lite",
    ],
)

cc_library(
    name = "cleanup_instruction_set_fix_operands",
    srcs = ["cleanup_instruction_set_fix_operands.cc"],
    hdrs = ["cleanup_instruction_set_fix_operands.h"],
    deps = [
        ":cleanup_instruction_set_utils",
        "//base",
        "//cpu_instructions/base:cleanup_instruction_set",
        "//cpu_instructions/proto:instructions_proto",
        "//strings",
        "//util/gtl:map_util",
        "//util/task:status",
        "@gflags_git//:gflags",
        "@glog_git//:glog",
        "@protobuf_git//:protobuf",
        "@protobuf_git//:protobuf_lite",
    ],
    alwayslink = 1,
)

cc_test(
    name = "cleanup_instruction_set_fix_operands_test",
    size = "small",
    srcs = ["cleanup_instruction_set_fix_operands_test.cc"],
    deps = [
        ":cleanup_instruction_set_fix_operands",
        "//cpu_instructions/base:cleanup_instruction_set_test_utils",
        "//util/task:status",
        "@googletest_git//:gtest",
        "@googletest_git//:gtest_main",
        "@protobuf_git//:protobuf",
    ],
)

cc_library(
    name = "cleanup_instruction_set_operand_info",
    srcs = ["cleanup_instruction_set_operand_info.cc"],
    hdrs = ["cleanup_instruction_set_operand_info.h"],
    deps = [
        ":encoding_specification",
        "//base",
        "//cpu_instructions/base:cleanup_instruction_set",
        "//cpu_instructions/proto:instructions_proto",
        "//cpu_instructions/proto/x86:encoding_specification_proto",
        "//cpu_instructions/util:status_util",
        "//strings",
        "//util/gtl:map_util",
        "//util/task:status",
        "//util/task:statusor",
        "@gflags_git//:gflags",
        "@glog_git//:glog",
        "@protobuf_git//:protobuf_lite",
    ],
    alwayslink = 1,
)

cc_test(
    name = "cleanup_instruction_set_operand_info_test",
    size = "small",
    srcs = ["cleanup_instruction_set_operand_info_test.cc"],
    deps = [
        ":cleanup_instruction_set_operand_info",
        "//cpu_instructions/base:cleanup_instruction_set_test_utils",
        "//util/task:status",
        "@googletest_git//:gtest",
        "@googletest_git//:gtest_main",
        "@protobuf_git//:protobuf",
    ],
)

cc_library(
    name = "cleanup_instruction_set_operand_size_override",
    srcs = ["cleanup_instruction_set_operand_size_override.cc"],
    hdrs = ["cleanup_instruction_set_operand_size_override.h"],
    deps = [
        ":cleanup_instruction_set_utils",
        ":encoding_specification",
        "//base",
        "//cpu_instructions/base:cleanup_instruction_set",
        "//cpu_instructions/proto:instructions_proto",
        "//cpu_instructions/util:instruction_syntax",
        "//strings",
        "//util/gtl:map_util",
        "//util/task:status",
        "@gflags_git//:gflags",
        "@glog_git//:glog",
        "@protobuf_git//:protobuf_lite",
    ],
    alwayslink = 1,
)

cc_test(
    name = "cleanup_instruction_set_operand_size_override_test",
    size = "small",
    srcs = ["cleanup_instruction_set_operand_size_override_test.cc"],
    deps = [
        ":cleanup_instruction_set_operand_size_override",
        "//cpu_instructions/base:cleanup_instruction_set_test_utils",
        "@googletest_git//:gtest",
        "@googletest_git//:gtest_main",
    ],
)

cc_library(
    name = "cleanup_instruction_set_properties",
    srcs = ["cleanup_instruction_set_properties.cc"],
    hdrs = ["cleanup_instruction_set_properties.h"],
    deps = [
        "//base",
        "//cpu_instructions/base:cleanup_instruction_set",
        "//cpu_instructions/proto:instructions_proto",
        "//util/gtl:map_util",
        "//util/task:status",
        "@gflags_git//:gflags",
        "@glog_git//:glog",
        "@protobuf_git//:protobuf_lite",
    ],
    alwayslink = 1,
)

cc_test(
    name = "cleanup_instruction_set_properties_test",
    size = "small",
    srcs = ["cleanup_instruction_set_properties_test.cc"],
    deps = [
        ":cleanup_instruction_set_properties",
        "//cpu_instructions/base:cleanup_instruction_set_test_utils",
        "@googletest_git//:gtest",
        "@googletest_git//:gtest_main",
    ],
)

cc_library(
    name = "cleanup_instruction_set_removals",
    srcs = ["cleanup_instruction_set_removals.cc"],
    hdrs = ["cleanup_instruction_set_removals.h"],
    deps = [
        "//base",
        "//cpu_instructions/base:cleanup_instruction_set",
        "//cpu_instructions/proto:instructions_proto",
        "//strings",
        "//util/gtl:container_algorithm",
        "//util/gtl:map_util",
        "//util/task:status",
        "@gflags_git//:gflags",
        "@glog_git//:glog",
        "@protobuf_git//:protobuf",
        "@protobuf_git//:protobuf_lite",
    ],
    alwayslink = 1,
)

cc_test(
    name = "cleanup_instruction_set_removals_test",
    size = "small",
    srcs = ["cleanup_instruction_set_removals_test.cc"],
    deps = [
        ":cleanup_instruction_set_removals",
        "//cpu_instructions/base:cleanup_instruction_set_test_utils",
        "@googletest_git//:gtest",
        "@googletest_git//:gtest_main",
    ],
)

# Utilities to represent to CPU state.
cc_library(
    name = "cpu_state",
    srcs = ["cpu_state.cc"],
    hdrs = ["cpu_state.h"],
    deps = [
        "//base",
        "//cpu_instructions/util:bits",
        "//strings",
        "@gflags_git//:gflags",
        "@glog_git//:glog",
        "@protobuf_git//:protobuf_lite",
    ],
)

cc_test(
    name = "cpu_state_test",
    srcs = ["cpu_state_test.cc"],
    deps = [
        ":cpu_state",
        "//base",
        "//strings",
        "@gflags_git//:gflags",
        "@glog_git//:glog",
        "@googletest_git//:gtest",
        "@googletest_git//:gtest_main",
        "@protobuf_git//:protobuf_lite",
    ],
)

# A library for working with the instruction encoding specification used in the
# Intel x86-64 reference manual.
cc_library(
    name = "encoding_specification",
    srcs = ["encoding_specification.cc"],
    hdrs = ["encoding_specification.h"],
    visibility = ["//visibility:public"],
    deps = [
        "//base",
        "//cpu_instructions/proto:instructions_proto",
        "//cpu_instructions/proto/x86:encoding_specification_proto",
        "//cpu_instructions/proto/x86:instruction_encoding_proto",
        "//strings",
        "//util/gtl:map_util",
        "//util/task:status",
        "//util/task:statusor",
        "@com_googlesource_code_re2//:re2",
        "@gflags_git//:gflags",
        "@glog_git//:glog",
        "@protobuf_git//:protobuf_lite",
    ],
)

cc_test(
    name = "encoding_specification_test",
    size = "small",
    srcs = ["encoding_specification_test.cc"],
    deps = [
        ":encoding_specification",
        "//base",
        "//cpu_instructions/base:cleanup_instruction_set",
        "//cpu_instructions/testing:test_util",
        "//strings",
        "//util/task:status",
        "//util/task:statusor",
        "@gflags_git//:gflags",
        "@glog_git//:glog",
        "@googletest_git//:gtest",
        "@googletest_git//:gtest_main",
        "@protobuf_git//:protobuf_lite",
    ],
)
