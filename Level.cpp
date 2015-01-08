
#include "Level.hpp"

#include "utility.hpp"

#include <vector>
#include <fstream>
#include <exception>

#include <boost/algorithm/string.hpp>


namespace shooter {

Level::Level(const std::string& file_name, sf::Vector2u tile_size) {
  load_level(file_name, tile_size);
};

void Level::load_level(const std::string& file_name, sf::Vector2u tile_size) {
  std::vector<int> tiles;
  std::string      texture_file;
  sf::Vector2u     size;
  std::tie(tiles, texture_file, size) = load_tiles(file_name);

  tile_map.load(texture_file, tile_size, tiles.data(), size.x, size.y);
};

std::tuple<std::vector<int>, std::string, sf::Vector2u> 
Level::load_tiles(const std::string& file_name) {
  using namespace std;

  ifstream level_file(file_name);

  if(level_file.is_open()) {
    string texture_file;
    getline(level_file, texture_file);
    
    string line;
    int width = 0;
    int height = 0;
    vector<int> tiles;
    while(getline(level_file, line)) {
      vector<int> tile_line = split_convert_to<int>(line, ',');

      update_width(width, height, tile_line.size());
      ++height;
      tiles.insert(end(tiles), begin(tile_line), end(tile_line));
    }

    level_file.close();
    return make_tuple(tiles, texture_file, sf::Vector2u(width, height));

  } else {
    throw std::runtime_error("Level::load_tiles - Unable to open file: " + file_name);
  }

};

void Level::update_width(int& width, int height, std::size_t size) {
  if(width == 0) {
    width = size;
  } else {
    if(std::size_t(width) != size) {
      throw std::runtime_error(
          "Level::load_tiles - Width of line " + std::to_string(height) + 
          " are not same widht as first line.");
    }
  }
};

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform *= getTransform();

  target.draw(tile_map, states);
};



}





