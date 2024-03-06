#include "map.h"

Map::Map() {
  _tile_map.reserve(_TILE_WIDTH*_TILE_HEIGHT);
  Tile tile;
  tile.is_blocked = false;  
  for(size_t i=0; i<_TILE_WIDTH; ++i) {
    for(size_t j=0; j<_TILE_HEIGHT; ++j) { 
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
  for (size_t y = 0; y<_TILE_HEIGHT; ++y) {
    for (size_t x = 0; x<_TILE_WIDTH; ++x) {
      Tile curr_tile = _tile_map[y*_TILE_WIDTH + x]; 
      
    }
  }
}
