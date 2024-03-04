#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include "SFML/Main.hpp"
#include <SFML/Graphics.hpp>

struct Tile {
  sf::RectangleShape tile_rect;
  sf::Sprite spr;
  bool is_blocked;
};

struct PowerUp {
  sf::Sprite spr;
  sf::RectangleShape powerup;
  uint8_t power_type;
  float time_accumilated;
};
  

class Map {
  public:
    Map();
    ~Map();
    

    void draw(sf::RenderWindow& window);
    void loadTexture(const std::string&);

  private:
    static constexpr int _TILE_WIDTH=32;
    static constexpr int _TILE_HEIGHT= 16;
    static constexpr double _TILE_SIZE=64.0f; //pixels
    sf::Texture _tile_texture;
    std::vector<Tile> _tile_map;
    std::vector<PowerUp> _power_ups;
};



#endif
