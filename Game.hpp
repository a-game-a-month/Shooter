#ifndef GAME_HPP
#define GAME_HPP 

#include <SFML/Graphics.hpp>

#include <string>

#include "utility.hpp"

namespace shooter {

class Game {
public:
  Game(unsigned int width, unsigned int height, const std::string& title);

  void run();

private:
  sf::RenderWindow window;

  const sf::Time ms_per_update = 16_ms;

  void process_input();
  void update();
  void render(const sf::Time& left_over);

};

}


#endif /* GAME_HPP */
