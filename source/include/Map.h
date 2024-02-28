#ifndef MAP_H
#define MAP_H

#include "player.h"
#include "SFML/Graphics.hpp"
#include "SFML/Main.hpp"


class cMap
{
public:
	cMap();
	~cMap();

//	void createMap();
//	void draw(sf::RenderWindow&,cPlayer*);
//	void detectCollison(cPlayer&);
//	std::vector<int> generateMap(); //skapar kartorna
//	
//private:
//	float mapH = 980.0f;
//	float mapW = 1820.0f;
//	float stdScale = 32.0f;
//
//	struct map {
//		sf::RectangleShape room;
//		int typeOfRoom; 
//     //	typeofroom beror på dörrar till nästa rum så 0 = 4 dörrar  
//
//
//
//	};
//
//	map sMap;
//	std::vector<map> mapVector;
//	

	sf::Texture text;

	struct tile
	{
		sf::RectangleShape tiles;
		sf::Sprite spr;
		bool bMovable;
	};

	int m_Mapsize;
	std::vector<tile> map;

	void drawmap(sf::RenderWindow&);
	void getCollision(cPlayer&);
	void spawnPowerUp();
	void handlePowerUps(cPlayer&);
	void drawPowerUps(sf::RenderWindow&);
	void init();
	sf::Texture texturePowerUp[4];
	struct powerUp
	{
		sf::Sprite sprite;
		sf::RectangleShape powerup;
		int kindOfPowerUp;
		float timeAccumilated;
		bool erase;
    };

	struct effect
	{
		float timer;
		int kindOfEffect;
	
	};

	std::vector<powerUp> powerUpVec;
	std::vector<effect> effectVec;
	

};




#endif // !MAP_H
