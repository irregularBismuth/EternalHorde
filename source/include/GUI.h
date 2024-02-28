#ifndef GRAPHICALUSERINTERFACE_H
#define GRAPHICALUSERINTERFACE_H


#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/System.hpp>
#include <string>
#include "player.h"
#include "wave.h"
const int MAX = 3;


class cGUI
{
public:
	cGUI();
	~cGUI();

	int chooseOption(sf::RenderWindow& window);
	int chooseEscOption(sf::RenderWindow& window);
	int backOption(sf::RenderWindow& window);
	void drawMenu(sf::RenderWindow& window);
	void drawHealthBar(sf::RenderWindow& window,cPlayer&);
	void updateHealthBar(cPlayer&);
	void drawTimer(cWave&,sf::RenderWindow&);
	void drawEscMenu(sf::RenderWindow& window);
	void drawPreviousScore(sf::RenderWindow& window,cWave&,cPlayer& );
	void drawOptions(sf::RenderWindow& window);




private:
	sf::RectangleShape healthBar;
	sf::RectangleShape healthBarOutline;
	sf::RectangleShape menuBlocks[MAX];
	sf::RectangleShape menuEscBlocks[MAX];
	sf::RectangleShape menuBackBlock;
	sf::Font font;
	sf::Text text[MAX];
	sf::Text textEsc[MAX];
	sf::Text textback;
	
	sf::Text textTimer;
	std::string timer;
	

};



#endif
