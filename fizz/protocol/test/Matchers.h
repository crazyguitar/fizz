/*
 *  Copyright (c) 2018-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace fizz {
namespace test {

MATCHER_P(BufMatches, expected, "") {
  return folly::IOBufEqualTo()(folly::IOBuf::copyBuffer(expected), arg);
}

MATCHER_P(RangeMatches, expected, "") {
  folly::StringPiece exp(expected);
  return exp.size() == arg.size() &&
      (exp.size() == 0 || memcmp(exp.data(), arg.data(), exp.size()) == 0);
}
} // namespace test
} // namespace fizz
