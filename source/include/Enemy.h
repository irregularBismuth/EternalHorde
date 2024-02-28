#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Weapon.h"
#include "player.h"



class cEnemy
{
public:
	struct sEnemy
	{
		float eHP;
		float eDMG;
		float eSPEED;
		sf::RectangleShape eShape;
		sf::Sprite eSprite_L;
		sf::Sprite eSprite_R;
		sf::Sprite drawSprite;
		float attackTimer;
		float accumilatedTime;
	};
	sEnemy enemy;
	std::vector<sEnemy> svEnemy;

	cEnemy();
	~cEnemy();

	sf::CircleShape detectArea;
	sf::CircleShape attackRNG;
	

	void draw(sf::RenderWindow& window,cPlayer);
	void moveEnemy(cPlayer& player);
	void updateEnemy(cBow& bow,cPlayer&);
	void spawnEnemy(int);
	void attack(cPlayer&);
	//void attack(float,cPlayer&);
	void handleEarthquake(cPlayer&);
	bool earthquake;

	
	void init();
	sf::Texture textureEnemy;
	sf::Sprite sprenemy;

private:
	float x;
	float y;

};




#endif // !ENEMY_H
