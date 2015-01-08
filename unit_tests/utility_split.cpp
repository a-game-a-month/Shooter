
#include "utility.hpp"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace shooter {

class UtilitySplitTest : public ::testing::Test {
protected:
  UtilitySplitTest(){};
  ~UtilitySplitTest(){};

  virtual void SetUp() {};
  virtual void TearDown() {};

};

TEST_F(UtilitySplitTest, dummy) {
  int q = 5;

  ASSERT_THAT(5, ::testing::Eq(q));
};




}





