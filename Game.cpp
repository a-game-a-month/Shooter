

#include "Game.hpp"

#include "TileMap.hpp"

namespace shooter {

Game::Game(unsigned int width, unsigned int height, const std::string& title)
  : window(sf::VideoMode(width, height), title) {

  window.setFramerateLimit(60);

};

void Game::run() {

  sf::Clock clock;

  sf::Time lag = sf::milliseconds(0);
  while(window.isOpen()) {
    sf::Time elapsed = clock.restart();
    lag += elapsed;

    process_input();

    while(lag >= sf::milliseconds(ms_per_update)) {
      update();
      lag -= sf::milliseconds(ms_per_update);
    }

    render(lag);
    
  }

};

void Game::process_input() {
  sf::Event event;
  while(window.pollEvent(event)) {
    if(event.type == sf::Event::Closed)
      window.close();
  }
};

void Game::update() {

};

void Game::render(const sf::Time& left_over) {
  window.clear();

  

  window.display();
};

}



