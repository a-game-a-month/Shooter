#ifndef UTILITY_HPP
#define UTILITY_HPP 

#include <SFML/System.hpp>

#include <vector>
#include <string>
#include <functional>
#include <iterator>

namespace shooter {

  sf::Time operator "" _ms(unsigned long long ms);

  std::vector<std::string> split(const std::string& str, char delim);

  template<typename T, typename F>
  std::vector<T> split_convert_to(const std::string& str, char delim, F converter) {
    using namespace std;

    vector<string> splitted = split(str, delim);

    vector<T> result;
    transform(begin(splitted), end(splitted), inserter(result, begin(result)), converter);

    return result;
  };

  template<typename T> std::vector<T>
    split_convert_to(const std::string& str, char delim);
  template<> std::vector<int> 
    split_convert_to<int>(const std::string& str, char delim);
  template<> std::vector<float> 
    split_convert_to<float>(const std::string& str, char delim);


}



#endif /* UTILITY_HPP */
