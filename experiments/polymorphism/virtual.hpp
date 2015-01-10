
#include <iostream>
#include <initializer_list>
#include <vector>

#include "my_rand.hpp"

#include <boost/range/irange.hpp>
  using boost::irange;

namespace virt {

class BaseComponent {
public:
  virtual void update() = 0;
  virtual ~BaseComponent() = default;
};

class Object {
  std::vector<BaseComponent*> comps;
public:
  Object() = default;
  Object(std::initializer_list<BaseComponent*> list) : comps(list) {};

  Object(const Object& other) = default;

  Object& operator=(const Object&) = default;

  ~Object() = default;

  void clean_up() {
    for(BaseComponent* bc : comps) {
      delete bc;
    }
    comps.clear();
  };

  void add(BaseComponent* obj) {
    comps.push_back(obj);
  };

  void update() {
    for(BaseComponent* bc : comps) {
      bc->update();
    }
  };

  static int int_a;
  static int int_b;
};

int Object::int_a = 0;
int Object::int_b = 0;

class ComponentA : public BaseComponent {
public:
  virtual void update() {
    ++Object::int_a;
  };
};

class ComponentB : public BaseComponent {
public:
  virtual void update() {
    ++Object::int_b;
  };
};

Object generate_object(unsigned int maximum_cmps) {
  MyRand comps_rand(1,maximum_cmps);
  MyRand derive_rand(0,1);

  int nr_comps = comps_rand();

  Object obj;
  for(auto i : irange(0, nr_comps)) {
    i++;
    obj.add(derive_rand() ? (BaseComponent*)(new ComponentA) : 
                            (BaseComponent*)(new ComponentB));
  }

  return obj;
}; 

}

