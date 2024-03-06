#ifndef GAME_HANDLER_H
#define GAME_HANDLER_H
#include "map.h"
#include "player.h"
#include "enemy.h"

#include "SFML/Main.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

class GameHandler {
  public:
    GameHandler() {
      init_game();
    }
    ~GameHandler() = default;
    
    void init_game() {
      _player = Player();
      _enemy = Enemy();
      _map = Map();
    }

    void draw(sf::RenderWindow& window) {
      _player.update();
      _enemy.update();
      _map.update();
      _map.draw(window,_player.get_camera());
      _enemy.draw();
      _player.draw();
    }
    
  private:
    sf::RectangleShape a;
    Player _player;
    Enemy _enemy; 
    Map _map;
};

#endif
