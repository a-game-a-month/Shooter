

#include "Game.hpp"

#include "TileMap.hpp"

namespace shooter {

Game::Game(unsigned int width, unsigned int height, const std::string& title)
  : window(sf::VideoMode(width, height), title) {

  window.setFramerateLimit(60);

};

void Game::run() {

  const int tiles[] = {
    0, 0, 1,
    1, 0, 0
  };

  TileMap tm;
  tm.load("bin/tilemap.png", sf::Vector2u(16,16), tiles, 3, 2);

  sf::View view = window.getView();
  view.setRotation(45.f);

  while(window.isOpen()) {

    sf::Event event;
    while(window.pollEvent(event)) {
      if(event.type == sf::Event::Closed)
        window.close();
    }

    // update
    // physics

    window.clear();

    window.setView(view);
    
    tm.setPosition(400.f, 300.f);
    window.draw(tm);
    // render
    
    window.display();
  }

};

}



