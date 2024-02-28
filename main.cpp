#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>

std::int32_t main(std::int32_t argc, char** argv) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
  sf::RectangleShape a(sf::Vector2f(120.f,130.f));
  while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);
        
        window.draw(a);
        // draw everything here...
        // window.draw(...);
  
        // end the current frame
        window.display();
    } 
  return 0;
}
