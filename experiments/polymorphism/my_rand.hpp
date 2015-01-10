#ifndef MY_RAND_HPP
#define MY_RAND_HPP 

#include <random>

class MyRand {
public:
  std::random_device rd;
  std::default_random_engine re;
  std::uniform_int_distribution<int> dist;

  MyRand(int from, int to) {
    re = std::default_random_engine(rd());
    dist = std::uniform_int_distribution<int>(from, to);
  };

  int operator()() {
    return dist(re);
  };

};

#endif /* MY_RAND_HPP */
