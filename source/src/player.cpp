#include "player.h"
#include <iostream>
cPlayer::cPlayer()
{
	if (!Playertexture.loadFromFile("../images/enemy.png"))
	{

	}

	fDeltaTime = 0;
	int yy = 0;
	int xx = 0;
	sInventoryI a;
	a.itemType = 3;
	a.sfRecInventoryInner.setSize(sf::Vector2f(stdScale, stdScale));
	a.sfRecInventoryInner.setFillColor(sf::Color::Magenta);
	svInventoryI.push_back(a);
	a.itemType = 2;
	a.sfRecInventoryInner.setSize(sf::Vector2f(stdScale, stdScale));
	a.sfRecInventoryInner.setFillColor(sf::Color::Green);
	svInventoryI.push_back(a);
	//#########################
	x = rand() % 1000 + 200; //sätter spelarens position från början 
	y = rand() %500 +300;
	//##################
	player.setPosition(x, y);
	sInventoryO tempo;
	score = 0;

	

	//###################################################### //hanterar rutorna som inventory skapas med
	for (int i = 0; i < 34; i++)
	{
		if (i % 10 == 0 && i != 0) {
			yy++;
		}
		if (xx % 10 == 0 && xx != 0)
		{
			xx = 0;

		}
		tempo.sfRecInventoryOuter.setSize(sf::Vector2f(64.0f, 64.0f));
		tempo.sfRecInventoryOuter.setPosition(sf::Vector2f(68.0f * xx + 60.0f, 68.0f * yy + 10.0f));
		tempo.sfRecInventoryOuter.setOutlineThickness(2.0f);
		tempo.sfRecInventoryOuter.setFillColor(sf::Color::Transparent);
		tempo.bOccupied = false;
		tempo.number = i;
		if (i < 34)
		{
		
			tempo.itemType = 0;
		}
		
		if (i == 30)
		{
			tempo.itemType = 1;
			tempo.sfRecInventoryOuter.setPosition(sf::Vector2f(265.0f, 300.0f));
		}
		if (i == 31)
		{
			tempo.itemType = 2;
			tempo.sfRecInventoryOuter.setPosition(sf::Vector2f(300.0f, 380.0f));
		}
		if (i == 32)
		{
			tempo.itemType = 3;
			tempo.sfRecInventoryOuter.setPosition(sf::Vector2f(200.0f, 380.0f));
		}
		if (i == 33)
		{
			tempo.itemType = 4;
			tempo.sfRecInventoryOuter.setPosition(sf::Vector2f(250.0f, 450.0f));

		}
		svInventoryO.push_back(tempo);
		xx++;

	}
	//######################################################


	fArrowDelay = bow.fBaseBow; 
	//;

	fAccumilatedTime = 0;

	activate = false;
	for (int i = 0; i < svInventoryI.size(); i++)
	{
		svInventoryI[i].sfRecInventoryInner.setPosition(svInventoryO[i].sfRecInventoryOuter.getPosition().x + 16.0f, svInventoryO[i].sfRecInventoryOuter.getPosition().y + 16.0f);
	}

	/*for (int i = 0; i < inventoryInner.size(); i++)
	{
		inventoryInner[i].setPosition(sf::Vector2f(inventoryOuter[i].getPosition().x, inventoryOuter[i].getPosition().y));
	}*/


	player.setSize(sf::Vector2f(stdScale, stdScale));
	player.setFillColor(sf::Color::Blue);
	

}

cPlayer::~cPlayer()
{
	
}

void cPlayer::init()
{
	x = rand() % 1000 + 200; //sätter spelarens position från början 
	y = rand() % 500 + 300;
	fArrowDelay = bow.fBaseBow;
	//;
	fAccumilatedTime = 0;
	player.setSize(sf::Vector2f(stdScale, stdScale));
	player.setFillColor(sf::Color::Blue);
	player.setPosition(x, y);
	fDeltaTime = 0;
	playerHP = 100.0f;
	earthQuake = 0;
	score = 0;
	bow.init();
	

}

void cPlayer::updateDeltaTime()
{
	//tar ut tiden per game tick
	fDeltaTime = sfClock.restart().asSeconds();
}

void cPlayer::controls()
{
	fArrowDelay = bow.fBaseBow;
	playerPos = player.getPosition();
	
		pSprite.setTextureRect(sf::IntRect(0, 32 * 3, 32, 32));
		//### y led ###
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			player.move(0,-Speed);
			//pSprite.setTextureRect(sf::IntRect(0, 32*3, 32, 32));
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			player.move(0,Speed);
			//pSprite.setTextureRect(sf::IntRect(0, 32 * 3, 32, 32));
		}
		//### x led ###
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			player.move(Speed,0);
			//pSprite.setTextureRect(sf::IntRect(0, 32 * 3, 32, 32));
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			 player.move(-Speed,0);
			//pSprite.setTextureRect(sf::IntRect(0, 32 * 3, 32, 32));
		}

		pSprite.setPosition(player.getPosition());
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (fAccumilatedTime > fArrowDelay) { //för att jag ska kunna skjuta pilen måste 
				bow.pressattack();
				fAccumilatedTime = 0.0f;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			//fiende.svEnemy.clear();
			if (earthQuake == 1) {
				earthQuake--;
				activate = true;
			}
			else
				activate = false;
			
		}
	


	//kollar om inventory är öppet / stängt
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	//{
	//	if (fAccumilatedTime > 0.5f) { //sätter en delay så att man inte kan spamma upp och ned inventory

	//		inventoryOpen = true;
	//		fAccumilatedTime = 0.0f;
	//	}
 //   }
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) && pickedUp == false)
	//{
	//	if (fAccumilatedTime > 0.5f) { //sätter en delay så att man inte kan spamma upp och ned inventory

	//		inventoryOpen = false;
	//		fAccumilatedTime = 0.0f;
	//	}
	//}
	//playerpos.x = x;
	//playerpos.y = y;

	//player.setPosition(x, y);
}


void cPlayer::updatePlayer(sf::RenderWindow& window)
{
	//bEarthQuake;

	playerSprite.setTexture(Playertexture);
	playerSprite.setTextureRect(sf::IntRect(0, 7 * 32, 32, 32));
	fAccumilatedTime += fDeltaTime;

	playerSprite.setPosition(player.getPosition());
	if (inventoryOpen == false) {
	
		bow.updateArrow(window,playerPos);
		bow.drawArrow(window);
		//window.draw(pSprite);
		//window.draw(player);

		window.draw(playerSprite);

	}
	if (inventoryOpen == true) {

		for (int i = 0; i < svInventoryO.size(); i++)
		{
			window.draw(svInventoryO[i].sfRecInventoryOuter);
		}

		for (int i = 0; i < svInventoryI.size(); i++)
		{
			window.draw(svInventoryI[i].sfRecInventoryInner);
			window.draw(svInventoryI[tmp].sfRecInventoryInner); //rita den vi håller i sist för att man annars kan det se ut som items är under andra 
		}
	}

}

void cPlayer::levelUp()
{
	fExpCap = (50 * pow(1.1, fLevel));

	if (fExp > fExpCap)  //från lvl 1 -> lvl N krävs = 12.5 * N^2 + 62.5 * N - 75 xp
 	{
		fLevel += 1;
	}
}

float cPlayer::returnDt()
{
	return fDeltaTime;
}

bool cPlayer::alive()
{
	if (playerHP <= 0.0f) {
		return false;
	}
	else
		return true;
}

float cPlayer::returnHP()
{
	return playerHP;
}

void cPlayer::addScore()
{
	score += 50;
}

int cPlayer::returnScore()
{
	return score;
}


sf::Vector2f cPlayer::returnPlayerpos()
{


	return playerpos;
}


void cPlayer::handleInventory(sf::RenderWindow& window) //hanterar inventory
{
	
	if (inventoryOpen == true)
	{
		sf::RectangleShape mus(sf::Vector2f(1.0f, 1.0f));
		mus.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);                

		//kontrollerar om jag plockar upp ett item
		if (pickedUp == false)
		{
			
			for (int j = 0; j < svInventoryO.size(); j++)
			{
				for (int i = 0; i < svInventoryI.size(); i++)
				{
					if (mus.getGlobalBounds().intersects(svInventoryI[i].sfRecInventoryInner.getGlobalBounds()) && sf::Mouse::isButtonPressed(sf::Mouse::Left))//&&pickedUp!=true)
					{
						if (svInventoryO[j].sfRecInventoryOuter.getGlobalBounds().contains(svInventoryI[i].sfRecInventoryInner.getPosition().x, svInventoryI[i].sfRecInventoryInner.getPosition().y))
						{
							svInventoryO[j].bOccupied = false;
						}
						tmp = i;
						pickedUp = true;
					}

				}
			}

			
		
		}

		//kollar om jag plockar upp item isf set item t musen pos
		if (pickedUp == true)
		{ 
			svInventoryI[tmp].sfRecInventoryInner.setPosition(mus.getPosition().x, mus.getPosition().y);
		}

		// hamterar med vart man kan droppa ett items som är uppplockad
		if (pickedUp == true)
		{
			for (int i = 0; i < svInventoryO.size(); i++)
			{
				for (int j = 0; j < svInventoryI.size(); j++)
				{
				
					if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && svInventoryO[i].sfRecInventoryOuter.getGlobalBounds().contains(svInventoryI[j].sfRecInventoryInner.getPosition().x, svInventoryI[j].sfRecInventoryInner.getPosition().y))
					{
	                    
						if (svInventoryO[i].bOccupied == false && (svInventoryO[i].itemType==0 || svInventoryO[i].itemType==svInventoryI[j].itemType) ) { 
							svInventoryI[j].sfRecInventoryInner.setPosition(sf::Vector2f(svInventoryO[i].sfRecInventoryOuter.getPosition().x + 16.0f, svInventoryO[i].sfRecInventoryOuter.getPosition().y + 16.0f));
							pickedUp = false;
						}
					}
				}
			}
		}

		//hanterar så att rutorna inte blir occuperad 
		if (pickedUp == false)
		{

			for (int j = 0; j < svInventoryI.size(); j++)
			{
				for (int i = 0; i < svInventoryO.size(); i++)
				{
					if (!(svInventoryO[i].sfRecInventoryOuter.getGlobalBounds().contains(svInventoryI[j].sfRecInventoryInner.getPosition().x, svInventoryI[j].sfRecInventoryInner.getPosition().y)))
					{
						svInventoryO[i].bOccupied = false;
					}

				}
			}
			//nt tmp=0;
		}

		//håller koll så att bOccupied blir true
		if (pickedUp == false)
		{

			for (int j = 0; j < svInventoryI.size(); j++)
			{
				for (int i = 0; i < svInventoryO.size(); i++)
				{
					if (svInventoryO[i].sfRecInventoryOuter.getGlobalBounds().contains(svInventoryI[j].sfRecInventoryInner.getPosition().x, svInventoryI[j].sfRecInventoryInner.getPosition().y))
					{
						svInventoryO[i].bOccupied = true;
					}

					if (svInventoryO[i].bOccupied == true)
					{
						//std::cout << svInventoryO[i].number << " true ";

						svInventoryO[i].sfRecInventoryOuter.setOutlineColor(sf::Color::Red);
					}
					if (svInventoryO[i].bOccupied == false)
					{
						//6	std::cout << svInventoryO[i].number;
						svInventoryO[i].sfRecInventoryOuter.setOutlineColor(sf::Color::White);
					}
				}
			}


		}
		
		
	}
}

void cPlayer::pickUpitems()//std::vector<sf::RectangleShape>& inventoryInner, std::vector<int>& inventory, sf::RectangleShape dropdItem, int itemId)
{
	
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		sInventoryI a;
		a.sfRecInventoryInner.setFillColor(sf::Color::Blue);
		a.sfRecInventoryInner.setSize(sf::Vector2f(stdScale, stdScale));
		if(svInventoryI.size() < 30)
		svInventoryI.push_back(a);
		if (svInventoryI.size() > 30)
		{
			for (int i = svInventoryI.size(); i> 30; i--)
			{
				svInventoryI.erase(svInventoryI.begin()+i);
			}
		}


		int tempo = 0;


		for (int j = 0; j < svInventoryO.size(); j++)
		{

			if (svInventoryO[j].bOccupied == false)
			{
				tempo = j;
				break;
			}
		}
		svInventoryI[svInventoryI.size() - 1].sfRecInventoryInner.setPosition(svInventoryO[tempo].sfRecInventoryOuter.getPosition().x + 16.0f, svInventoryO[tempo].sfRecInventoryOuter.getPosition().y + 16.0f);

	}
}


void cPlayer::setSprite(sf::Sprite sprite)
{
	this->pSprite = sprite;
}