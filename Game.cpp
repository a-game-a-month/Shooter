

#include "Game.hpp"

#include "Level.hpp"
#include "TileMap.hpp"

#include "utility.hpp"

namespace shooter {

Game::Game(unsigned int window_width, unsigned int window_height, const std::string& title)
  : window(sf::VideoMode(window_width, window_height), title) {

  window.setFramerateLimit(60);

  level.load_level("data/level1.txt", sf::Vector2u(16, 16));

};

void Game::run() {

  sf::Clock clock;

  sf::Time lag = 0_ms;
  while(window.isOpen()) {
    sf::Time elapsed = clock.restart();
    lag += elapsed;

    process_input();

    while(lag >= ms_per_update) {
      update();
      lag -= ms_per_update;
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

void Game::render(const sf::Time& ) {
  window.clear();

  window.draw(level);

  window.display();
};

}



