#include "menu.h"
#include <cstdlib>

int main() {
  try {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu System");
    Menu menu(window); 
    sf::View view(sf::FloatRect(0.f, 0.f, window.getSize().x, window.getSize().y));
    while (window.isOpen()) {
      sf::Event event;
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          window.close();
        }
        if (event.type == sf::Event::Resized) {
         sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
        window.setView(sf::View(visibleArea));
        }
        menu.handleEvent(window, event);
      }

      window.clear();
      switch (menu.get_current_state()) {
        case GameStates::MAIN_MENU:
          menu.draw_menu(window);
          break;
        case GameStates::HELP_SCREEN:
          break;
        case GameStates::GAME:
          menu.render_game(window);       
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
