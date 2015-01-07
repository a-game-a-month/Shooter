

#include "Game.hpp"

namespace shooter {

Game::Game(unsigned int width, unsigned int height, const std::string& title)
  : window(sf::VideoMode(width, height), title) {

};

void Game::run() {

  while(window.isOpen()) {

    sf::Event event;
    while(window.pollEvent(event)) {
      if(event.type == sf::Event::Closed)
        window.close();
    }

    // update
    // physics

    window.clear();
    
    // render
    
    window.display();
  }

};

}



