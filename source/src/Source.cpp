

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

//#include <windows.h>
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


const int WindowH = 1080;
const int WindowW = 1920; 
using namespace sf;

int main()
{
	srand(time(NULL));
	RenderWindow window(VideoMode(WindowW, WindowH), "MittSpel", Style::Fullscreen); //ritar föntstret
	window.setFramerateLimit(60);
	//instanser av olika klasser
	cPlayer* player = new cPlayer;
	cEnemy* enemy = new cEnemy;
	cMap* map = new cMap;
	cGUI* gui = new cGUI;
	cWave* wave = new cWave;
	
	

	int tmp = -1;
	bool temp = false;
	bool escape = false;
	bool prevScore = false;
	bool options = false;
	bool options1 = false;
	//för menyn loopen 
	while (temp == false) {
	
		int tmp = gui->chooseOption(window);

		if (tmp == 0) {
			temp = true;
			prevScore = true;

			player->init();
			enemy->init();
			wave->init();
			map->init();
			
			while (player->alive() && window.isOpen() && temp == true) //själva gameloopen som hela tiden tickar medans man har tryck start game
			{
				if (Keyboard::isKeyPressed(Keyboard::Escape)) //trycker man escape sätts en bool esape till true
					escape = true;
				if (Keyboard::isKeyPressed(Keyboard::Tab)) // trycker man tab försviner menyn
					escape = false;

				if (escape == false) {//gör detta då escape är false
					player->updateDeltaTime(); //tiden det tar för ett game tick 
					wave->updateTimer(*player);
					// map->detectCollison(*player); //hanterar collisions för kartan
					player->controls(); //hantera kontrollerna
					//player->handleInventory(window); //hanterar inventoryt
					player->pickUpitems();
					player->levelUp(); //hanterar om spelaren ska levla upp
					enemy->handleEarthquake(*player); //metod som hanterar om man använder earthquake
					wave->spawnEnemyWave(*enemy); //metoden som spawnar en ny wave
					enemy->moveEnemy(*player); //metod som updaterar enemy
					enemy->attack(*player);//metod som hanterar attack för fiende
				}
					if (escape == true) //om escape är aktivt
					{
						int tmpo = gui->chooseEscOption(window); //kollar om man trycker på nån av menyerna
						if (tmpo == 0)//resume 
							escape = false; 
						if (tmpo == 1)//options
						{
							escape = true;
							//temp = true;
							options1 = true;
							while (options1 == true)//om man är inne i options
							{

								int mtp = gui->backOption(window);
								if (mtp == 0)
								{
									/*for (int i = 0; i < 5000; i++)
									{
										window.clear();
									}*/
									options1 = false;
									escape = false;
								//	temp = true;


								}
							
								window.clear();
								gui->drawOptions(window);
								window.display();
							

							}
						}
						if (tmpo == 2) //exit 
						{	
							player->playerHP = -100.0f;
							player->alive();
							temp = false;
							escape = false;

							
									for (int i = 0; i < 5000; i++)
									{
										window.clear();
										
									}
								
						}
					}

					if (escape == false) {
						gui->updateHealthBar(*player);
						enemy->updateEnemy(player->bow, *player);
						map->getCollision(*player);
						map->spawnPowerUp();
						map->handlePowerUps(*player);
					
					}

				
						window.clear();
						//	map->draw(window,player);
						map->drawmap(window);
						if (escape == false) {

						player->updatePlayer(window); //updatera spelaren rita + projectiler
						enemy->draw(window, *player);
					}
					if (escape == true)
					{
						gui->drawEscMenu(window);
					}
			if (escape == false) {
					gui->drawHealthBar(window, *player);
					gui->drawTimer(*wave, window);
					map->drawPowerUps(window);
				}
				window.display();
		
				if (player->alive() != true)
					temp = false;
			}



		
		}

		if (tmp == 1)
		{
		
			    temp = true;
				options = true;
				while (options == true)
				{

					int ytp = gui->backOption(window);
					if (ytp == 0)
					{
						for (int i = 0; i < 5000; i++)
						{
							window.clear();
						}
						options = false;
						escape = false;
						temp = false;


					}

					window.clear();
					gui->drawOptions(window);
					window.display();


				}
			
		}

		if (tmp == 2&&temp==false) {

			window.close();
			return 0;
		}
          //hanterar event i sfml 

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear();
		if (temp == false) {
			gui->drawMenu(window);
		}
		if (prevScore == true)
		{
			gui->drawPreviousScore(window, *wave,*player);
		
		}
		window.display();
		
	}

	//### rensar objekten jag skapat på heapen ###
	delete player;
	player = 0;
	delete enemy;
	enemy = 0;
	delete map;
	map = 0;
	delete gui;
	gui = 0;
	delete wave;
	wave = 0;

		//while (player->alive() && window.isOpen()&&temp==true) //själva gameloopen som hela tiden tickar
		//{
		//
		//	player->updateDeltaTime(); //tiden det tar för ett game tick 
		//	wave->updateTimer(*player);
		//	// map->detectCollison(*player); //hanterar collisions för kartan
		//	player->controls(); //hantera kontrollerna
		//	//player->handleInventory(window); //hanterar inventoryt
		//	player->pickUpitems();
		//	player->levelUp(); //hanterar om spelaren ska levla upp
		//	enemy->handleEarthquake(*player);
		//	wave->spawnEnemyWave(*enemy);
		//	enemy->moveEnemy(*player);
		//	enemy->attack(*player);
		//	gui->updateHealthBar(*player);
		//	enemy->updateEnemy(player->bow,*player);
		//	map->getCollision(*player);
		//	map->spawnPowerUp();
		//	map->handlePowerUps(*player);

		//	

		//	sf::Event event; //hanterar event i sfml 
		//	while (window.pollEvent(event))
		//	{
		//		if (event.type == sf::Event::Closed)
		//		{
		//			window.close();
		//		}
		//	}
		//	window.clear();
		//	
		////	map->draw(window,player);
		//	map->drawmap(window);
		//	player->updatePlayer(window); //updatera spelaren rita + projectiler
		//	enemy->draw(window, *player);
		//	gui->drawHealthBar(window,*player);
		//	gui->drawTimer(*wave, window);
		//	map->drawPowerUps(window);
		//	window.display();

		//}
	
		//
		////### rensar objekten jag skapat på heapen ###
		//delete player;
		//player = 0;
		//delete enemy;
		//enemy = 0;
		//delete map;
		//map = 0;
		//delete gui;
		//gui = 0;
		//delete wave;
		//wave = 0;

	
}

