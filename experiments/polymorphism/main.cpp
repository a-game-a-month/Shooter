
#include "virtual.hpp"
#include "my_rand.hpp"
#include "ScopedTimer.hpp"

#include <vector>
  using std::vector;

#include <algorithm>
#include <functional>

void test_virtual(unsigned int nr, unsigned maximum_cmps) {
  using namespace virt;

  vector<Object> objs(nr);
  
  std::generate(objs.begin(), objs.end(), std::bind(generate_object, maximum_cmps));

  {
    ScopedTimer timer;

    for(auto o : objs) {
      o.update();
    }
  }

  std::cout << Object::int_a << ", " << Object::int_b << std::endl;

  for(auto o : objs) {
    o.clean_up();
  }
};


int main() {
  unsigned int nr = 50000;
  unsigned int maximum_cmps = 6;

  test_virtual(nr, maximum_cmps);


}



