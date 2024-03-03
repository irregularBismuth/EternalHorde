#include "menu.h"
#include <cstdlib>

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Menu System");
  try {
    Menu menu(window);
    
    while (window.isOpen()) {
      sf::Event event;
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          window.close();
        }
        if (menu.get_current_state() == GameStates::MAIN_MENU) {
          menu.handleEvent(window, event);
        }
      }

      window.clear();
      switch (menu.get_current_state()) {
        case GameStates::MAIN_MENU:
          menu.draw(window);
          break;
        case GameStates::HELP_SCREEN:
          break;
        case GameStates::GAME:
          break;
        case GameStates::EXIT:
          window.close();
          return EXIT_SUCCESS;
          break;
        default:
          break;
      }
      window.display();
    }
  } catch (const std::exception& e) {
    std::cerr << "An error occurred: " << e.what() << std::endl;
    return EXIT_FAILURE;  
  }

  return EXIT_SUCCESS;
}
