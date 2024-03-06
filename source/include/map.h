#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include "SFML/Main.hpp"
#include <SFML/Graphics.hpp>
#include "player.h"

struct Tile {
  sf::RectangleShape tile_rect;
  sf::Sprite spr;
  sf::RectangleShape tile_shape;
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
    ~Map() = default;
    

    void draw(sf::RenderWindow& window, const sf::Rect<float> camera);
    void loadTexture(const std::string&);
    void update(Player& player) {
    }

  private:
    static constexpr int _TILE_WIDTH=128;
    static constexpr int _TILE_HEIGHT= 64;
    static constexpr double _TILE_SIZE=64.0f; //pixels
    sf::Texture _tile_texture;
    std::vector<Tile> _tile_map;
    std::vector<PowerUp> _power_ups;
};



#endif
