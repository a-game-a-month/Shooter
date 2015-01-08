
#include "utility.hpp"

#include <algorithm>
#include <boost/algorithm/string.hpp>

namespace shooter {


  sf::Time operator "" _ms(unsigned long long ms) {
    return sf::milliseconds(ms);
  };

  std::vector<std::string> split(const std::string& str, char delim) {
    using namespace std;

    vector<string> splitted;
    boost::split(splitted, str, boost::is_any_of(string(1, delim)), boost::token_compress_on);

    return splitted;
  };

  template<>
  std::vector<int> split_convert_to<int>(const std::string& str, char delim) {
    return split_convert_to<int>(str, delim, 
        [](const std::string& s) { return std::stoi(s); } );
  };
  template<>
  std::vector<float> split_convert_to<float>(const std::string& str, char delim) {
    return split_convert_to<float>(str, delim, 
        [](const std::string& s) { return std::stof(s); } );
  };
}




