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

  static const unsigned int ms_per_update = 16;

  void process_input();
  void update();
  void render(const sf::Time& left_over);

};

}


#endif /* GAME_HPP */
