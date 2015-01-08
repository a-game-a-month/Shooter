#ifndef LEVEL_HPP
#define LEVEL_HPP 

#include <string>

#include <SFML/Graphics.hpp>

#include "TileMap.hpp"
#include <vector>
#include <tuple>

namespace shooter {


class Level : public sf::Drawable, public sf::Transformable {
public:
  Level() {};
  Level(const std::string& file_name, sf::Vector2u tile_size);

  void load_level(const std::string& file_name, sf::Vector2u tile_size);

  Level(const Level&) = delete;
  Level& operator=(const Level&) = delete;

private:
  TileMap tile_map;

  std::tuple<std::vector<int>, std::string, sf::Vector2u> 
    load_tiles(const std::string& file_name);
  void update_width(int&, int, std::size_t);
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};


}



#endif /* LEVEL_HPP */
