
#include "utility.hpp"


namespace shooter {


  sf::Time operator "" _ms(unsigned long long ms) {
    return sf::milliseconds(ms);
  };


}




