
#include "utility.hpp"

#include "gmock/gmock.h"
  using ::testing::Eq;
#include "gtest/gtest.h"
  using ::testing::Test;

#include <string>
#include <vector>

namespace shooter {

class UtilitySplitTest : public Test {
protected:
  UtilitySplitTest(){};
  ~UtilitySplitTest(){};

  virtual void SetUp() {};
  virtual void TearDown() {};

};

TEST_F(UtilitySplitTest, dummy) {
  int q = 5;

  ASSERT_THAT(5, Eq(q));
};

TEST_F(UtilitySplitTest, SimpleSplit) {
  using namespace std;

  string line = "1,2,3,4,5,6,7,8,9,0";

  vector<string> splitted = split(line, ',');

  ASSERT_THAT(splitted.size(), Eq(size_t(10)));
};



}





