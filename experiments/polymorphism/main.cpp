
#include "ScopedTimer.hpp"

#include "virtual.hpp"
#include "semi_virtual.hpp"
#include "static.hpp"

#include <vector>
  using std::vector;

#include <algorithm>
#include <functional>

void test_virtual(unsigned int nr, unsigned maximum_cmps) {
  using namespace virt;

  vector<Object> objs(nr);
  
  std::generate(objs.begin(), objs.end(), std::bind(generate_object, maximum_cmps));

  std::cout << "virtual: ";
  {
    ScopedTimer timer;

    for(auto o : objs) {
      o.update();
    }
  }

  /* std::cout << Object::int_a << ", " << Object::int_b << std::endl; */

  for(auto o : objs) {
    o.clean_up();
  }
};

void test_semi(unsigned int nr, unsigned maximum_cmps) {
  using namespace semi; 

  vector<BaseObject*> objs(nr);

  std::generate(objs.begin(), objs.end(), std::bind(generate_object, maximum_cmps));

  std::cout << "semi:    ";
  {
    ScopedTimer timer;

    for(auto o : objs) {
      o->update();
    }
  }

  /* std::cout << int_a << ", " << int_b << std::endl; */

  for(auto o : objs) {
    delete o;
  }
};

void test_static(unsigned int nr, unsigned int maximum_cmps) {
  using namespace stat;
  
  using ObjectCollection = ObjectManager<A, AB, ABA, ABAB, ABABA, ABABAB>;

  ObjectCollection objs;

  for(unsigned int i = 0; i < nr; ++i) {
    generate_object(objs, maximum_cmps);
  }

  std::cout << "static:  ";
  {
    ScopedTimer t;
    objs.update();
  }

  /* std::cout << int_a << ", " << int_b << std::endl; */
};

int main() {
  unsigned int nr = 50000;
  unsigned int maximum_cmps = 6;

  test_virtual(nr, maximum_cmps);
  test_semi(nr, maximum_cmps);
  test_static(nr, maximum_cmps);


}



