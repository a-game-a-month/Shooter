#ifndef STATIC_HPP
#define STATIC_HPP 

#include <vector>
#include <tuple>

#include <iostream>

#include <boost/fusion/adapted/std_tuple.hpp>
#include <boost/fusion/algorithm/iteration/for_each.hpp>

#include "my_rand.hpp"

namespace stat {

template<typename... Components>
class Object {
  std::tuple<Components...> comps;
public:

  Object() = default;
  Object(Components... cs) {
    comps = std::make_tuple(cs...);
  };

  void update() {
    using namespace boost::fusion;
    for_each(comps, [](auto& cmp) {
        cmp.update();
      });
  };
};

template<typename... Components>
Object<Components...> make_object(Components... cs) {
  return Object<Components...>(cs...);
};

template<typename... Components>
Object<Components...> make_from_type() {
  return make_object(Components()...);
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

template<typename... ObjectTypes>
class ObjectManager {
  std::tuple<std::vector<ObjectTypes>...> objs;
public:

  template<typename ObjectType>
  void add(ObjectType o) {
    auto& cont = std::get<std::vector<ObjectType>>(objs);
    cont.push_back(o);
  };

  void update() {
    using namespace boost::fusion;
    for_each(objs, [](auto& cont) {
        for(auto& o : cont) {
          o.update();
        };
      });
  };
};

using A      = Object<ComponentA>;
using AB      = Object<ComponentA, ComponentB>;
using ABA    = Object<ComponentA, ComponentB,
                      ComponentA>;
using ABAB   = Object<ComponentA, ComponentB,
                      ComponentA, ComponentB>;
using ABABA  = Object<ComponentA, ComponentB,
                      ComponentA, ComponentB,
                      ComponentA>;
using ABABAB = Object<ComponentA, ComponentB,
                      ComponentA, ComponentB,
                      ComponentA, ComponentB>;

template<typename Container>
void generate_object(Container& c, unsigned int maximum_cmps) {
  int r = MyRand(1,maximum_cmps)();
  
  switch(r) {
    case 1:
      c.add(A());
      break;
    case 2:
      c.add(AB());
      break;
    case 3:
      c.add(ABA());
      break;
    case 4:
      c.add(ABAB());
      break;
    case 5:
      c.add(ABABA());
      break;
    case 6:
      c.add(ABABAB());
      break;
    default:
      c.add(A());
  }
};

}

#endif /* STATIC_HPP */
