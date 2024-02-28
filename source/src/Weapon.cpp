#include "Weapon.h"
#include <iostream>

weapons::weapons(){

}
weapons::~weapons() {

}




cBow::cBow()
{
	/*fArrowSpeed = 3.0f;
	arrow.setFillColor(sf::Color::Red);
	arrow.setSize(sf::Vector2f(32.0f, 10.0f));
	arrow.setPosition(sf::Vector2f(32, 84));*/
	fBaseBow = 0.25f;
	iProjectile.projectile.setRadius(5.0f);
	iProjectile.projectile.setFillColor(sf::Color::Green);
	iProjectile.projectileSpeed = 5.0f;
	fDmg = 75.0f;
	iProjectile.hit = false;
}

cBow::~cBow()
{

}



void cBow::updateArrow(sf::RenderWindow& window,sf::Vector2f player)
{
	this->player.x = player.x+16.0f;
	this->player.y = player.y+16.0f;
	sf::Vector2f mus = sf::Vector2f(sf::Mouse::getPosition(window));
	projectileDir = mus-this->player;

	for (int i = 0; i < projectileVec.size(); i++)
	{
		projectileVec[i].projectile.move(projectileVec[i].fProjectileTimesSpeed);

		window.draw(projectileVec[i].projectile);
	}

	for (int i = 0; i < projectileVec.size(); i++)
	{
		if (projectileVec[i].projectile.getPosition().x < 0.0f || projectileVec[i].projectile.getPosition().y < 0.0f|| projectileVec[i].projectile.getPosition().x > window.getSize().x || projectileVec[i].projectile.getPosition().y > window.getSize().y||projectileVec[i].hit)
		   projectileVec.erase(projectileVec.begin() + i);
		//om projektilen är utanför fönstret 
		
	}


}


void cBow::pressattack()
{

	projectileDir = projectileDir* (1 / sqrt((projectileDir.x * projectileDir.x) + (projectileDir.y * projectileDir.y)));
	iProjectile.fProjectileTimesSpeed = projectileDir*iProjectile.projectileSpeed;
	iProjectile.projectile.setPosition(player);
	projectileVec.push_back(iProjectile);
}

void cBow::drawArrow(sf::RenderWindow& window)
{

	//for (int i = 0; i < varrow.size(); i++)
	//{
	//	window.draw(varrow[i]);
	//}
}

void cBow::init()
{
		projectileVec.clear();
}

