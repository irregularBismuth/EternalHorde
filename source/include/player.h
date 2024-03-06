#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Main.hpp>
struct PowerUp;

class Player {
  public:
    Player() {};
    ~Player()=default;
    
  sf::Rect<float> get_camera() const {
    return _camera;
  }


  void update() {
    update_camera();
  }

  void update_camera() {
    _camera.left = std::max(0.f, _player_pos.x - _camera.width / 2);
    _camera.top = std::max(0.f, _player_pos.y - _camera.height / 2);
  }
  
  void handle_input(sf::Event& event) {
     

  }

  void draw(sf::RenderWindow& window) {

  }
  
  public:
    sf::Rect<float> _camera;
    sf::Vector2f _player_pos;
    unsigned int _health;
     

};


#endif //PLAYER_H 
