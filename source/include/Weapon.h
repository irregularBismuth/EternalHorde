#ifndef WEAPON_H
#define WEAPON_H

#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <cmath>
#include <math.h>

#include <vector>

class weapons {

	weapons();
	~weapons();
	
public:
	int a;
};

class cBow
{

public:
	cBow();
	~cBow();
	void pressattack();
	void updateArrow(sf::RenderWindow&,sf::Vector2f);
	void drawArrow(sf::RenderWindow&);
	void init();
	sf::RectangleShape arrow;
	std::vector<int> tmp;
	float fBaseBow;
	float fDmg;
	sf::Vector2f player;
	sf::Vector2f projectileDir;

	struct projectiles
	{
		sf::CircleShape projectile;
		sf::Vector2f fProjectileTimesSpeed;
		float projectileSpeed;
		bool hit;
	};
	projectiles iProjectile;
	std::vector<projectiles> projectileVec;
protected:
	//float fArrowSpeed;

	//std::vector<sf::RectangleShape> varrow;
	



private:


	
};




#endif // !WEAPON_H
