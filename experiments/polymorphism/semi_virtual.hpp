#ifndef SEMI_VIRTUAL_HPP
#define SEMI_VIRTUAL_HPP 

#include <iostream>
#include <tuple>

#include <boost/fusion/adapted/std_tuple.hpp>
#include <boost/fusion/algorithm/iteration/for_each.hpp>

#include "my_rand.hpp"

namespace semi {

struct BaseObject {
  virtual void update() = 0;
  virtual ~BaseObject() = default;
};

template<typename... Components>
class Object : public BaseObject {
  std::tuple<Components...> comps;
public:

  Object() = default;
  Object(Components... cs) {
    comps = std::make_tuple(cs...);
  };

  virtual void update() {
    using namespace boost::fusion;
    for_each(comps, [](auto& cmp) {
        cmp.update();
      });
  };

};

template<typename... Components>
Object<Components...>* new_object(Components... cs) {
  return new Object<Components...>(cs...);
};

int int_a = 0;
int int_b = 0;

struct ComponentA {
  void update() {
    ++int_a;
  };
};

struct ComponentB {
  void update() {
    ++int_b;
  };
};

// Ugly implementation for testing purpose only
BaseObject* generate_object(unsigned int maximum_cmps) {
  unsigned int r = MyRand(1,maximum_cmps)();

  switch(r) {
    case 1:
      return new_object(ComponentA());
      break;
    case 2:
      return new_object(ComponentA(), ComponentB());
      break;
    case 3:
      return new_object(ComponentA(), ComponentB(), 
                        ComponentA());
      break;
    case 4:
      return new_object(ComponentA(), ComponentB(), 
                        ComponentA(), ComponentB());
      break;
    case 5:
      return new_object(ComponentA(), ComponentB(), 
                        ComponentA(), ComponentB(),
                        ComponentA());
      break;
    case 6:
      return new_object(ComponentA(), ComponentB(), 
                        ComponentA(), ComponentB(),
                        ComponentA(), ComponentB());
      break;
    default:
      return new_object(ComponentA());
  }
};

}


#endif /* SEMI_VIRTUAL_HPP */
