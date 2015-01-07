#ifndef GAME_HPP
#define GAME_HPP 

#include <SFML/Graphics.hpp>

#include <string>

namespace shooter {

class Game {
public:
  Game(unsigned int width, unsigned int height, const std::string& title);

  void run();

private:
  sf::RenderWindow window;

};

}


#endif /* GAME_HPP */
