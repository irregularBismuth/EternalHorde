#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cstdlib>
#include <vector>
#include <functional>
#include <iostream>
#include "game_handler.h"
enum class GameStates {
  MAIN_MENU,
  HELP_SCREEN,
  GAME,
  EXIT,
};

struct Button {
    sf::RectangleShape shape;
    sf::Text label;
    std::function<void()> onClick;
    
    Button(const sf::Vector2f& position, const sf::Vector2f& size, const std::string& text, sf::Font& font, const std::function<void()>& onClickFunc) {
        shape.setSize(size);
        shape.setPosition(position);
        shape.setFillColor(sf::Color::Blue);

        label.setFont(font);
        label.setString(text);
        label.setCharacterSize(24); 
        label.setFillColor(sf::Color::White);

        sf::FloatRect textRect = label.getLocalBounds();
        label.setOrigin(textRect.width / 2, textRect.height / 2);
        label.setPosition(position.x + size.x / 2, position.y + size.y / 2);

        onClick = onClickFunc;
    }

    bool isHovered(sf::RenderWindow& window) const {
        return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
    }
};


class Menu {
public:
    Menu(sf::RenderWindow& window) {
        state = GameStates::MAIN_MENU;
        if (!font.loadFromFile("../Fonts/arial.ttf")) {
            throw std::runtime_error("Failed to load font");
        }

        sf::Vector2f buttonSize(200, 50);
        float offsetY = 100.0f; 
        float spacing = 60.0f; 

        auto createButton = [&](const std::string& label, const std::function<void()>& action) {
            sf::Vector2f position((window.getSize().x - buttonSize.x) / 2, offsetY);
            buttons.emplace_back(position, buttonSize, label, font, action);
            offsetY += buttonSize.y + spacing; 
        };

        createButton("Play", [&]() { state = GameStates::GAME; });
        createButton("Help", [&]() { state = GameStates::HELP_SCREEN; });
        createButton("Quit", [&]() { state = GameStates::EXIT; });
    }

    void handleEvent(sf::RenderWindow& window, sf::Event& event) {
      if (state==GameStates::MAIN_MENU) {   
      if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            for (auto& button : buttons) {
                if (button.isHovered(window)) {
                    button.onClick(); 
                }
            }
        }
      }
      if (state==GameStates::HELP_SCREEN) {
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            state=GameStates::MAIN_MENU;
        }
      }
      
      if (state==GameStates::GAME) {
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            state=GameStates::MAIN_MENU;
            _handler = GameHandler();
        }
      }
    }
    
    void draw_menu(sf::RenderWindow& window) {  
        for (auto& button : buttons) {
            window.draw(button.shape);
            window.draw(button.label);
        }
    }

    void render_game(sf::RenderWindow& window) {
        _handler.draw(window);  
    }

    GameStates& get_current_state() {
      return state;
    }
    
    void update() {
      
    }

private:
    sf::Font font;
    std::vector<Button> buttons;
    GameStates state;
    GameHandler _handler;
};


#endif
