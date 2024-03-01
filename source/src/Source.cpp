

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

//#include <windows.h>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <vector>
//#include <conio.h>
#include "Enemy.h"
#include "Weapon.h"
#include "player.h"
#include "Map.h"
#include "GUI.h"
#include "wave.h"
#include "gamestate.h"

const int WindowH = 600;
const int WindowW = 800; 

void setupMenuItem(sf::Text& menuItem,sf::RectangleShape& menuRect, sf::Font& font, const std::string& text, float x, float y) {
    menuItem.setFont(font);
    menuItem.setString(text);
    menuItem.setCharacterSize(24); 
    menuItem.setFillColor(sf::Color::White);
    menuItem.setPosition(x, y);
    float padding = 10.0f; 
    sf::FloatRect textRect = menuItem.getLocalBounds();
    menuItem.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    menuItem.setPosition(x, y);

    menuRect.setSize(sf::Vector2f(textRect.width + 2 * padding, textRect.height + 2 * padding));
    menuRect.setOrigin(menuRect.getSize().x / 2.0f, menuRect.getSize().y / 2.0f);
    menuRect.setPosition(x, y);
    menuRect.setFillColor(sf::Color::Blue); 
    menuRect.setOutlineColor(sf::Color::White);
    menuRect.setOutlineThickness(2.0f); 

}


int main()
{
	srand(time(NULL));
  sf::RenderWindow window(sf::VideoMode(WindowW, WindowH), "eternal_horde", sf::Style::Default); //ritar föntstret
	window.setFramerateLimit(144);
  
  
    sf::Font font;
    if (!font.loadFromFile("../Fonts/arial.ttf")) { 
        std::cerr << "Error loading font\n";
        return -1;
    }

    sf::Text loadingText;
    loadingText.setFont(font);
    loadingText.setString("Loading...");
    loadingText.setCharacterSize(24); // in pixels
    loadingText.setFillColor(sf::Color::White);
    loadingText.setPosition(WindowW / 2 - loadingText.getLocalBounds().width / 2, WindowH / 2 - loadingText.getLocalBounds().height / 2);

    sf::Text playText, helpText, quitText;
   sf::RectangleShape playRect, helpRect, quitRect;
    setupMenuItem(playText,playRect, font, "Play", 350, 200);
    setupMenuItem(helpText,helpRect, font, "Help", 350, 250);
    setupMenuItem(quitText,quitRect, font, "Quit", 350, 300);
    GameState currentState = MainMenu;
   while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (currentState == MainMenu) {
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        if (helpRect.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                            currentState = HelpScreen; 
                        }
                        if(quitRect.getGlobalBounds().contains(mousePos.x,mousePos.y)) {
                          window.clear();
                          window.close();
                          return EXIT_SUCCESS;
                      }
                    }
                }
            } else if (currentState == HelpScreen) {
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Escape) { // Press Esc to go back
                        currentState = MainMenu;
                    }
                }
            } 
        }

        window.clear();

        if (currentState == MainMenu) {
            window.draw(helpRect);
            window.draw(playRect);
            window.draw(quitRect);
            window.draw(playText);
            window.draw(helpText);
            window.draw(quitText);
        } else if (currentState == HelpScreen) {
            sf::Text helpContent("Help Information\nPress Esc to go back", font, 20);
            sf::Text ControlContent("Move with \n w \na s d \n, ",font, 20);
            helpContent.setPosition(100, 100);
        window.draw(ControlContent);      
        window.draw(helpContent);
            
        }
        // Draw other states as needed
        window.display();
    }    
    return 0;

}


