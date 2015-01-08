#ifndef TILEMAP_HPP
#define TILEMAP_HPP 

#include <SFML/Graphics.hpp>

#include <string>
#include <exception>

// Implementation of sfml TileMap example
class TileMap : public sf::Drawable, public sf::Transformable {
public:
  void load(const std::string& file_name, sf::Vector2u tile_size, const int* tiles, 
            unsigned int width, unsigned int height) {

    if(!tileset.loadFromFile(file_name)) {
      throw std::runtime_error("TileMap::load - Unable to load from file: " + file_name);
    }

    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(width * height * 4);

    for(unsigned int i = 0; i < width; ++i) {
      for(unsigned int j = 0; j < height; ++j) {

        int tile_number = tiles[i + j * width];

        int tu = tile_number % (tileset.getSize().x / tile_size.x);
        int tv = tile_number / (tileset.getSize().x / tile_size.x);

        sf::Vertex* quad = &vertices[(i + j * width) * 4];

        quad[0].position = sf::Vector2f(i * tile_size.x, j * tile_size.y);
        quad[1].position = sf::Vector2f((i + 1) * tile_size.x, j * tile_size.y);
        quad[2].position = sf::Vector2f((i + 1) * tile_size.x, (j + 1) * tile_size.y);
        quad[3].position = sf::Vector2f(i * tile_size.x, (j + 1) * tile_size.y);

        quad[0].texCoords = sf::Vector2f(tu * tile_size.x, tv * tile_size.y);
        quad[1].texCoords = sf::Vector2f((tu + 1) * tile_size.x, tv * tile_size.y);
        quad[2].texCoords = sf::Vector2f((tu + 1) * tile_size.x, (tv + 1) * tile_size.y);
        quad[3].texCoords = sf::Vector2f(tu * tile_size.x, (tv + 1) * tile_size.y);
 
      }
    }
  };

private:

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = &tileset;
    target.draw(vertices, states);
  };

  sf::VertexArray vertices;
  sf::Texture tileset;
};


#endif /* TILEMAP_HPP */
