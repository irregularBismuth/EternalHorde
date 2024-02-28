#include "GUI.h"


cGUI::cGUI()
{
	if (!font.loadFromFile("../Fonts/arial.ttf"))
	{
	   std::cout<<"Font loading off";
    // Error...
	}
	//text[0].setPosition(sf::Vector2f(150, 350));
	text[0].setString("Start Game");
	
	text[1].setString("Options");
	text[2].setString("Exit");

	for (int i = 0; i < MAX; i++)
	{

		menuBlocks[i].setOutlineColor(sf::Color::Magenta);
		menuBlocks[i].setSize(sf::Vector2f(200, 100));
		menuBlocks[i].setPosition(sf::Vector2f(800, 200 * i + 50));
		menuBlocks[i].setFillColor(sf::Color::Green);
		menuBlocks[i].setOutlineThickness(2);
		text[i].setFillColor(sf::Color::Red);
		text[i].setFont(font);
		text[i].setCharacterSize(18);
		text[i].setPosition(menuBlocks[i].getPosition().x + 50.0f, menuBlocks[i].getSize().y / 2+(200*i));
		menuEscBlocks[i] = menuBlocks[i];
	}


	healthBarOutline.setPosition(498.0f, (1080.0f-40.0f));
	healthBarOutline.setFillColor(sf::Color::Transparent);
	healthBarOutline.setSize(sf::Vector2f(202.0f, 34.0f));
	healthBarOutline.setOutlineThickness(2.0f);

	healthBar.setPosition(500.0f, 1080.0f-38.0f);
	healthBar.setFillColor(sf::Color::Red);


	textTimer.setPosition(sf::Vector2f(500.0f, 100.0f));
	textTimer.setFont(font);
	textTimer.setFillColor(sf::Color::Red);
	textTimer.setCharacterSize(24);

	textTimer.setStyle(sf::Text::Bold | sf::Text::Underlined);

	
	textEsc[0] = text[0];
	textEsc[0].setString("Resume");
	textEsc[1] = text[1];
	textEsc[2] = text[2];
	textEsc[2].setString("Exit to\nMenu");

	menuBackBlock = menuBlocks[2];
	textback = text[2];

	textback.setString("Back");


	for (int i = 0; i < MAX; i++)
	{
		//menuEscBlocks[i] = menuEscBlocks[i];
	}


}
cGUI::~cGUI()
{
}



void cGUI::drawMenu(sf::RenderWindow& window)
{

	//window.draw(text[0]);
	//window.clear();
	for (int i = 0; i < MAX; i++)
	{
		window.draw(menuBlocks[i]);
		window.draw(text[i]);
	}
	//window.display();

}

void cGUI::updateHealthBar(cPlayer& player)
{
	healthBar.setSize(sf::Vector2f(2*player.playerHP,32));
}

void cGUI::drawTimer(cWave& wave,sf::RenderWindow& window)
{
	textTimer.setPosition(sf::Vector2f(500.0f, 32.0f));
	timer = std::to_string((wave.returnTimer()));
	textTimer.setString(timer);
	window.draw(textTimer);
	textTimer.setString("Next Wave in:");
	textTimer.setPosition(sf::Vector2f(325.0f, 32.0f));
	window.draw(textTimer);
	textTimer.setPosition(670.0f, 32.0f);
	textTimer.setString("Wave:" + std::to_string(wave.returnwave()));
	window.draw(textTimer);

}
void cGUI::drawEscMenu(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX; i++)
	{
//		menuBlocks[i].setPosition(sf::Vector2f(800,200*i+500));
		window.draw(menuEscBlocks[i]);
		window.draw(text[i]);
	}
	//text[0].setString("Start Game");
}

void cGUI::drawPreviousScore(sf::RenderWindow& window, cWave& wavecheck,cPlayer& player)
{
	sf::Text prevScoreText;

	prevScoreText.setString("You got\nscore: " + std::to_string(player.returnScore())+"\nKills: " + std::to_string(player.returnScore()/50));
	prevScoreText.setPosition(sf::Vector2f(200.0f, 100.0f));
	prevScoreText.setFont(font);
	prevScoreText.setFillColor(sf::Color::Red);
	prevScoreText.setCharacterSize(24);
	prevScoreText.setStyle(sf::Text::Bold | sf::Text::Underlined);
	

	window.draw(prevScoreText);

	
}
void cGUI::drawOptions(sf::RenderWindow& window)
{
	sf::Text options;
	options.setString("Controls:\nMove with:    W\n                  ASD\n\nShoot with left mouse button\nPress Escape for menu\nrun on different powerups to pickup them up,\nthey spawn around the map with different icons\n\nPress E to use earthquake if avalible");
	options.setPosition(sf::Vector2f(800.0f, 200.0f));
	options.setFont(font);
	options.setFillColor(sf::Color::Red);
	options.setCharacterSize(24);
	options.setStyle(sf::Text::Bold);

	menuBackBlock.setPosition(sf::Vector2f(menuBackBlock.getPosition().x, 500));
	textback.setPosition(menuBackBlock.getPosition().x+50, menuBackBlock.getPosition().y + 20.0f);
	window.draw(options);
	window.draw(menuBackBlock);
	window.draw(textback);

	//options.setString





}
void cGUI::drawHealthBar(sf::RenderWindow& window,cPlayer& player)
{
	
	window.draw(healthBarOutline);
	window.draw(healthBar);
	textTimer.setString("HP");
	textTimer.setPosition(450.0f, (1080-32));
	window.draw(textTimer);

	textTimer.setPosition(800.0f, 32.0f);
	textTimer.setString("score: "+std::to_string(player.returnScore()));
	window.draw(textTimer);

	//sf::RectangleShape square;

	/*square.setSize(sf::Vector2f(64.0f, 64.0f));
	square.setFillColor(sf::Color::Transparent);
	square.setOutlineThickness(1.0f);
	square.setOutlineColor(sf::Color::White);
	square.setPosition(sf::Vector2f(1150.0f, 32.0f));*/

	//window.draw(square);
	
	textTimer.setString("Earthquake: " + std::to_string(player.earthQuake));
	textTimer.setPosition(950.0f, 32.0f);

	window.draw(textTimer);
	
}



int cGUI::chooseOption(sf::RenderWindow& window)
{
	sf::RectangleShape mouse;
	sf::Vector2f mus = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
	mouse.setSize(sf::Vector2f(1.0f,1.0f));
	mouse.setPosition(mus.x, mus.y);
	int tmp;

   for(int i=0; i<MAX; i++)
   { 
   
	   if (mouse.getGlobalBounds().intersects(menuBlocks[i].getGlobalBounds())&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
	   {
		   tmp = i;
		   return tmp;
	   }

   }


}


int cGUI::chooseEscOption(sf::RenderWindow& window)
{
	sf::RectangleShape mouse;
	sf::Vector2f mus = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
	mouse.setSize(sf::Vector2f(1.0f, 1.0f));
	mouse.setPosition(mus.x, mus.y);
	int tmp;

	for (int i = 0; i < MAX; i++)
	{
	
		if (mouse.getGlobalBounds().intersects(menuEscBlocks[i].getGlobalBounds()) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			tmp = i;
			return tmp;
		}

	}


}

int cGUI::backOption(sf::RenderWindow& window)
{
	sf::RectangleShape mouse;



	sf::Vector2f mus = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
	mouse.setSize(sf::Vector2f(1.0f, 1.0f));
	mouse.setPosition(mus.x, mus.y);
	int tmp;

	

		if (mouse.getGlobalBounds().intersects(menuBackBlock.getGlobalBounds()) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			tmp = 0;
			return tmp;
		}


}
