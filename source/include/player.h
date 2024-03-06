#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics/Rect.hpp>

struct PowerUp;

class Player {
  public:
    Player() {};
    ~Player()=default;
    
  sf::Rect<float> get_camera() const {
    return _camera;
  }

  void pick_up_power_up(PowerUp effect) {

  }
  
  void active_power_up() {

  }

  void update() {
    update_camera();
  }

  void update_camera() {
    _camera.left = std::max(0.f, _player_pos.x - _camera.width / 2);
    _camera.top = std::max(0.f, _player_pos.y - _camera.height / 2);
  }
  public:
    sf::Rect<float> _camera;
    sf::Vector2f _player_pos;

};


#endif //PLAYER_H 
