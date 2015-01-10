#ifndef SCOPEDTIMER_HPP
#define SCOPEDTIMER_HPP 

#include <iostream>
#include <iomanip>

#include <chrono>
  using std::chrono::time_point;
  using std::chrono::high_resolution_clock;
  using std::chrono::duration;

class ScopedTimer {
  time_point<high_resolution_clock> start;
public:
  ScopedTimer() {
    start = high_resolution_clock::now();
  };

  ~ScopedTimer() {
    time_point<high_resolution_clock> stop = high_resolution_clock::now();

    std::cout << std::fixed << std::setprecision(10) << duration<double>(stop-start).count() << std::endl;
  };

};


#endif /* SCOPEDTIMER_HPP */
