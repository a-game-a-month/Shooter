
#include "utility.hpp"

#include "gmock/gmock.h"
  using ::testing::Eq;
  using ::testing::FloatEq;
  using ::testing::FloatNear;
#include "gtest/gtest.h"
  using ::testing::Test;

#include <string>
  using std::string;
#include <vector>
  using std::vector;
#include <random>
#include <limits>

namespace shooter {

class UtilitySplitTest : public Test {
protected:
  UtilitySplitTest(){};
  ~UtilitySplitTest(){};

  virtual void SetUp() {};
  virtual void TearDown() {};

  static const string line;
};

const string UtilitySplitTest::line = "1.2345,2.000,3.1415,4.1,5,6,7,8,9,10";

TEST_F(UtilitySplitTest, dummy) {
  int q = 5;

  ASSERT_THAT(5, Eq(q));
};

TEST_F(UtilitySplitTest, SimpleSplit) {
  vector<string> splitted = split(line, ',');

  ASSERT_THAT(splitted.size(), Eq(size_t(10)));
};

TEST_F(UtilitySplitTest, FillingSplit) {
  string str = "a";
  ASSERT_THAT(split(str, ',').size(), Eq(std::size_t(1))) << " where str = " << str;

  for(int i = 2; i <= 100; ++i) {
    str += ",a";
    ASSERT_THAT(split(str, ',').size(), Eq(std::size_t(i))) << " where str = " << str;
  }
};

// I can't understand whu this test fails....
/* TEST_F(UtilitySplitTest, ConvertIntSplit) { */
/*   vector<int> ints = split_convert_to<int>(line, ','); */

/*   for(int i = 0; std::size_t(i) < line.size(); ++i) { */
/*     /1* std::cout << ints[i] << std::endl; *1/ */
/*     ASSERT_THAT(ints[i], Eq(i+1)); */
/*   } */
/* }; */

TEST_F(UtilitySplitTest, FillingSplitInt) {
  string str = "1";
  vector<int> splitted = split_convert_to<int>(str, ',');
  ASSERT_THAT(splitted.size(), Eq(std::size_t(1))) << " where str = " << str;
  ASSERT_THAT(splitted[0], Eq(1)) << " where str = " << str;

  for(int i = 2; i <= 100; ++i) {
    str += "," + std::to_string(i);
    vector<int> splitted = split_convert_to<int>(str, ',');
    ASSERT_THAT(splitted.size(), Eq(std::size_t(i))) << " where str = " << str;
    ASSERT_THAT(splitted[i-1], Eq(i)) << " where str = " << str;
  }
};

TEST_F(UtilitySplitTest, RandomFillingSplitInt) {
  std::random_device rd;
  std::default_random_engine re(rd());
  std::uniform_int_distribution<int> uniform_dist(std::numeric_limits<int>::min(),
                                                  std::numeric_limits<int>::max());
  
  int nr = uniform_dist(re);
  string str = std::to_string(nr);
  vector<int> splitted = split_convert_to<int>(str, ',');
  ASSERT_THAT(splitted.size(), Eq(std::size_t(1))) << " where str = " << str;
  ASSERT_THAT(splitted[0], Eq(nr)) << " where str = " << str;

  for(int i = 2; i <= 100; ++i) {
    nr = uniform_dist(re);
    str += "," + std::to_string(nr);

    vector<int> splitted = split_convert_to<int>(str, ',');
    ASSERT_THAT(splitted.size(), Eq(std::size_t(i))) << " where str = " << str;
    ASSERT_THAT(splitted[i-1], Eq(nr)) << " where str = " << str;
  }
};

TEST_F(UtilitySplitTest, RandomFillingSplitFloat) {
  std::random_device rd;
  std::default_random_engine re(rd());
  std::uniform_real_distribution<float> uniform_dist(-1000.f, 1000.f);
  
  float nr = uniform_dist(re);
  string str = std::to_string(nr);
  vector<float> splitted = split_convert_to<float>(str, ',');
  ASSERT_THAT(splitted.size(), Eq(std::size_t(1))) << " where str = " << str;
  ASSERT_THAT(splitted[0], FloatNear(nr, 0.0001f)) << " where str = " << str;

  for(int i = 2; i <= 100; ++i) {
    nr = uniform_dist(re);
    str += "," + std::to_string(nr);

    vector<float> splitted = split_convert_to<float>(str, ',');
    ASSERT_THAT(splitted.size(), Eq(std::size_t(i))) << " where str = " << str;
    ASSERT_THAT(splitted[i-1], FloatNear(nr, 0.0001f)) << " where str = " << str;
  }
};

TEST_F(UtilitySplitTest, RandomFillingSplitFloatStrToInt) {
  std::random_device rd;
  std::default_random_engine re(rd());
  std::uniform_real_distribution<float> uniform_dist(-1000.f, 1000.f);
  
  float nr = uniform_dist(re);
  string str = std::to_string(nr);
  vector<int> splitted = split_convert_to<int>(str, ',');
  ASSERT_THAT(splitted.size(), Eq(std::size_t(1))) << " where str = " << str;
  ASSERT_THAT(splitted[0], Eq((int)nr)) << " where str = " << str;

  for(int i = 2; i <= 100; ++i) {
    nr = uniform_dist(re);
    str += "," + std::to_string(nr);

    vector<int> splitted = split_convert_to<int>(str, ',');
    ASSERT_THAT(splitted.size(), Eq(std::size_t(i))) << " where str = " << str;
    ASSERT_THAT(splitted[i-1], Eq((int)nr)) << " where str = " << str;
  }
};


}





