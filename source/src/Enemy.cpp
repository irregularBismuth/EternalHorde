#include "Enemy.h"


cEnemy::cEnemy()
{
	if (!textureEnemy.loadFromFile("../images/enemy.png"))
	{

	}
	srand(time(NULL));
	detectArea.setRadius(150.0f);
	attackRNG.setRadius(10.0f);
	//RSenemy.setSize(sf::Vector2f(64.0f, 64.0f));
	//RSenemy.setFillColor(sf::Color::Magenta);
	//eHP = 100.0f;
	
	
//	svEnemy.push_back(enemy);

}

cEnemy::~cEnemy()
{
}
void cEnemy::init()
{
	svEnemy.clear();
	
}
void cEnemy::draw(sf::RenderWindow& window,cPlayer a)
{
	if (!a.inventoryOpen) {
		//window.draw(detectArea);
		//window.draw(attackRNG);
		//window.draw(RSenemy);

		for (int i = 0; i < svEnemy.size(); i++)
		{
			svEnemy[i].drawSprite.setTexture(textureEnemy);
			svEnemy[i].drawSprite.setTextureRect(sf::IntRect(0, 6*32, 32, 32));
		//	window.draw(svEnemy[i].eShape);
			window.draw(svEnemy[i].drawSprite);
		}
	}

}

void cEnemy::moveEnemy(cPlayer& player)
{

	for (int i = 0; i < svEnemy.size(); i++)
	{
	
		 if (player.player.getPosition().x > svEnemy[i].eShape.getPosition().x)
		 {
		
			svEnemy[i].eShape.move(svEnemy[i].eSPEED, 0);

		 }
		 if (player.player.getPosition().x < svEnemy[i].eShape.getPosition().x)
		 {
				
				svEnemy[i].eShape.move(-svEnemy[i].eSPEED, 0);
				
		 }
		 if (player.player.getPosition().y > svEnemy[i].eShape.getPosition().y)
		 {
		
			 svEnemy[i].eShape.move(0,svEnemy[i].eSPEED);
		
		 }
		 if (player.player.getPosition().y < svEnemy[i].eShape.getPosition().y)
		 {
			 svEnemy[i].eShape.move(0, -svEnemy[i].eSPEED);
		 }

		
	
		svEnemy[i].drawSprite.setPosition(svEnemy[i].eShape.getPosition());
		
	}

	

}

void cEnemy::updateEnemy(cBow& bow,cPlayer& player)
{

	
		for (int i = 0; i < bow.projectileVec.size(); i++)
		{
			for (int j = 0; j < svEnemy.size(); j++) {
				if (bow.projectileVec[i].projectile.getGlobalBounds().intersects(svEnemy[j].eShape.getGlobalBounds()))
				{
					svEnemy[j].eHP -= bow.fDmg;
					svEnemy[j].eShape.setFillColor(sf::Color::Red);
					bow.projectileVec[i].hit = true;

				}
				if (svEnemy[j].eHP <= 0.0f) {
					player.addScore();
					svEnemy.erase(svEnemy.begin() + j);
				}
				
			}
			
	    }

		//for (int i = 0; i < svEnemy.size(); i++)
		//{
		//	

		//}
	
	
}


void cEnemy::spawnEnemy(int number)
{
	static int numberAfterRound50 = 0;
	static int numberSpawned = 0;
	numberSpawned+= number;
	enemy.eDMG = 7.5f;// +(pow((numberSpawned - 5), 1.2));
	enemy.eShape.setSize(sf::Vector2f(32.0f, 32.0f));
	enemy.attackTimer = 2.0f;
	enemy.accumilatedTime = 0;
	enemy.eShape.setFillColor(sf::Color::Green);

	if (number < 50) {
		enemy.eHP = 100;//+(pow(numberSpawned-5,2));
		enemy.eSPEED = .5;// +((0.01 * (numberSpawned - 5)));//+pow((.01*numberSpawned),2);
	}
	else
	{
		numberAfterRound50++;
		enemy.eSPEED = .5+.015*numberAfterRound50;//(pow((numberSpawned * (numberSpawned + 1) / 2), 1.15)) / 10000;
		enemy.eHP = 150+numberAfterRound50*1.5;//((numberSpawned * (numberSpawned + 1)) / 2) / 10;
	}
	int x, y;
	int tempNum = rand() % 4;
	for (int i = 0; i < number; i++)
	{
		if (tempNum == 0)
		{
			y = 1080 - 64;
			x = 1920 - 64;
		}
		else if (tempNum == 1)
		{
			x = 64;
			y = 1080 - 64;
		}
		else if (tempNum == 2)
		{
			x = 1920 - 64;
			y = 64;
		}
		else {
			x = 64;
			y = 64;
		}

		if (x > 800.0f) {
			x += (-rand() % 200);
		}
		else
			x += rand() % 200;
		if (y > 500) {
			y += rand() % 220;
		}
		else
			y += -(rand() % 120);
		enemy.eShape.setPosition(sf::Vector2f(x, y));
		svEnemy.push_back(enemy);
	}
}

void cEnemy::attack(cPlayer& player)
{
	
	for (int i = 0; i < svEnemy.size(); i++)
	{
		svEnemy[i].accumilatedTime += player.returnDt();

		if (svEnemy[i].accumilatedTime > svEnemy[i].attackTimer)
		{
			if(svEnemy[i].eShape.getGlobalBounds().intersects(player.player.getGlobalBounds()))
			{
				player.playerHP -= svEnemy[i].eDMG;
				svEnemy[i].accumilatedTime = 0;
				//svEnemy[i].e
			}
		}
	}


}

//void cEnemy::attack(float dmg, cPlayer& player)
//{
//	
//	player.playerHP -= dmg;
//
//}

void cEnemy::handleEarthquake(cPlayer& player)
{

	if (player.activate==true)
	{

			svEnemy.clear();

			player.activate = false;

	}
}
