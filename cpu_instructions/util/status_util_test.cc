// Copyright 2017 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "cpu_instructions/util/status_util.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "util/task/canonical_errors.h"
#include "util/task/status.h"

namespace cpu_instructions {
namespace {

using ::cpu_instructions::util::InvalidArgumentError;
using ::cpu_instructions::util::FailedPreconditionError;
using ::cpu_instructions::util::OkStatus;
using ::cpu_instructions::util::Status;
using ::cpu_instructions::util::error::FAILED_PRECONDITION;
using ::cpu_instructions::util::error::INVALID_ARGUMENT;

TEST(UpdateStatusTest, UpdateOkWithOk) {
  Status overall_status;
  UpdateStatus(&overall_status, OkStatus());
  EXPECT_OK(overall_status);
}

TEST(UpdateStatusTest, UpdateOkWithError) {
  constexpr char kErrorMessage[] = "An error!";
  Status overall_status;
  UpdateStatus(&overall_status, FailedPreconditionError(kErrorMessage));
  EXPECT_EQ(overall_status.error_code(), FAILED_PRECONDITION);
  EXPECT_EQ(overall_status.error_message(), kErrorMessage);
}

TEST(UpdateStatusTest, UpdateErrorWithOk) {
  constexpr char kErrorMessage[] = "There was already an error";
  Status overall_status = FailedPreconditionError(kErrorMessage);
  UpdateStatus(&overall_status, OkStatus());
  EXPECT_EQ(overall_status.error_code(), FAILED_PRECONDITION);
  EXPECT_EQ(overall_status.error_message(), kErrorMessage);
}

TEST(UpdateStatusTest, UpdateErrorWithError) {
  constexpr char kFirstErrorMessage[] = "This is the first error message";
  constexpr char kSecondErrorMessage[] = "This is the second error message";
  Status overall_status = InvalidArgumentError(kFirstErrorMessage);
  UpdateStatus(&overall_status, FailedPreconditionError(kSecondErrorMessage));
  EXPECT_EQ(overall_status.error_code(), INVALID_ARGUMENT);
  EXPECT_EQ(overall_status.error_message(), kFirstErrorMessage);
}

}  // namespace
}  // namespace cpu_instructions
