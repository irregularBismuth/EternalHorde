#include "map.h"

Map::Map() {
  _tile_map.reserve(_TILE_WIDTH*_TILE_HEIGHT);
  Tile tile;
  tile.is_blocked = false;
  tile.tile_shape.setFillColor(sf::Color::Green);
  for(size_t i=0; i<_TILE_WIDTH; i++) {
    for(size_t j=0; j<_TILE_HEIGHT; j++) { 
      if(i == 1 || i==_TILE_WIDTH-1) {
        tile.is_blocked = true;
      }
      tile.tile_shape.setSize(sf::Vector2f(_TILE_SIZE, _TILE_SIZE));
      tile.tile_shape.setPosition(i * _TILE_SIZE, j * _TILE_SIZE);
      tile.tile_shape.setFillColor(tile.is_blocked ? sf::Color::Red : sf::Color::Green);
      _tile_map.push_back(tile);
    }
  }
}

void Map::loadTexture(const std::string& filename) {
  if(!_tile_texture.loadFromFile("../images/tilemap.png")) {
    std::cout<<"error loading tileset"<<std::endl;
  }
}


void Map::draw(sf::RenderWindow& window, const sf::Rect<float> camera) {
  for(auto it=_tile_map.begin(); it!=_tile_map.end(); ++it) {
    window.draw(it->tile_shape);
  }  
}
