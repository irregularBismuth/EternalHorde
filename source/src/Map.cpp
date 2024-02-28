#include "Map.h"

cMap::cMap()
{

	if (!text.loadFromFile("../images/tilemap.png"))
	{
	
	}

	tile tiles;
	tiles.tiles.setSize(sf::Vector2f(64.0f, 64.0f));

	//tiles.spr.setTexture(text);
	//tiles.spr.setTextureRect(sf::IntRect(64, 64,128, 128));

	tiles.bMovable= false;
	m_Mapsize = 510;
	int offSet_X=0;
	int offSet_Y=0;
	for (int i = 0; i < m_Mapsize; i++)
	{
		if (i % 30 == 0&& i != 0)
			offSet_X = 0;
		else
			offSet_X++;

		if (i == 0)
			offSet_X--;


		if (i % 30 == 0 && i != 0)
		{
			offSet_Y+=1;
		

		}
		tiles.tiles.setPosition(sf::Vector2f(64*offSet_X,64*offSet_Y));
		tiles.spr.setPosition(tiles.tiles.getPosition());
		map.push_back(tiles);
		
	}


	if (!texturePowerUp[0].loadFromFile("../images/tilemap.png"))
	{

	}
	if (!texturePowerUp[1].loadFromFile("../images/tilemap.png"))
	{

	}
	if (!texturePowerUp[2].loadFromFile("../images/tilemap.png"))
	{

	}
	if (!texturePowerUp[3].loadFromFile("../images/tilemap.png"))
	{

	}

	int tmp = 0;



}

cMap::~cMap()
{
}

void cMap::drawmap(sf::RenderWindow& window)
{
	for (auto x : map)
	{
		window.draw(x.spr);
	}
}

void cMap::getCollision(cPlayer& player)
{
	int tmp = 0;
	for (int i = 0; i < map.size(); i++)
	{
		map[i].spr.setTexture(text);
		if (i % 30 == 0 && i != 0)
			tmp++;
		if (map[i].tiles.getGlobalBounds().intersects(player.player.getGlobalBounds()))
		{

		}
		else
		{
	
		}

		if (i > 0 && i < 60)
		{
			map[i].spr.setTextureRect(sf::IntRect(64, 0, 64, 64));
		}

	


		if ((i - tmp) % 29 == 0||i>=0&&i<=30||i>=m_Mapsize-30&&i<=m_Mapsize)//i <= 29 && i >= 0||i%30==0)
		{
			
			//map[i].tiles.setFillColor(sf::Color::Blue);

			if (map[i].tiles.getGlobalBounds().intersects(player.player.getGlobalBounds()))
			{
				//player.player.setPosition();
				player.player.setPosition(player.playerPos);
			}

			if((i+1)%30==0)
				map[i].spr.setTextureRect(sf::IntRect(128, 0, 64, 64));

			if (i % 30 == 0)
			{
				map[i].spr.setTextureRect(sf::IntRect(192, 0, 64, 64));
			}

			if (i >= m_Mapsize - 30 && i <= m_Mapsize)
				map[i].spr.setTextureRect(sf::IntRect(256, 0, 64, 64));
		}
		else
		{
			
			map[i].spr.setTextureRect(sf::IntRect(0,0, 64, 64));
		}
		
		
		/*if 
		{
			map[i].tiles.setFillColor(sf::Color::Blue);
		}*/

	}


}

void cMap::spawnPowerUp()
{
	powerUp pow;

	pow.kindOfPowerUp = 0;//double speed;
	pow.kindOfPowerUp = 1;//rapid fire;
	pow.kindOfPowerUp = 2;//double up //dmg x2
	pow.kindOfPowerUp = 3;//
	pow.erase = false;

	pow.kindOfPowerUp = rand() % 3;

	if (rand() % 10 == 0)
	{
		pow.kindOfPowerUp = 4;
	}

	pow.timeAccumilated = 0;
	pow.powerup.setSize(sf::Vector2f(32.0f, 32.0f));
	pow.powerup.setPosition(sf::Vector2f(rand() % (1820-100) + 100, rand() % (980-100) + 100));
	

	if (pow.kindOfPowerUp == 0) {
		pow.powerup.setFillColor(sf::Color::Magenta);
		pow.sprite.setTexture(texturePowerUp[0]);
		pow.sprite.setTextureRect(sf::IntRect(64, 64, 32, 32));
	}
	if (pow.kindOfPowerUp == 1) {
		pow.powerup.setFillColor(sf::Color::Blue);
		pow.sprite.setTexture(texturePowerUp[1]);
		pow.sprite.setTextureRect(sf::IntRect(0, 64, 32, 32));
	}

	if (pow.kindOfPowerUp == 2) {
		pow.powerup.setFillColor(sf::Color::Yellow);
		pow.sprite.setTexture(texturePowerUp[2]);
		pow.sprite.setTextureRect(sf::IntRect(32, 64, 32, 32));
	}
	if (pow.kindOfPowerUp == 4)
	{
		pow.sprite.setTexture(texturePowerUp[3]);
		pow.sprite.setTextureRect(sf::IntRect(96, 64, 32, 32));
	}

	if (pow.kindOfPowerUp == 4)
	{
		pow.powerup.setFillColor(sf::Color::Cyan);
		
	}

	pow.sprite.setPosition(pow.powerup.getPosition());
	
	

	if (rand() % 650==0)
	{
		powerUpVec.push_back(pow);
	}

}

void cMap::handlePowerUps(cPlayer& player)
{

	for (int i=0; i< powerUpVec.size(); i++)
	{
		powerUpVec[i].timeAccumilated += player.returnDt();
		if (powerUpVec[i].timeAccumilated >= 25.0f)
		{
			powerUpVec[i].erase = true;
			//powerUpVec.erase(powerUpVec.begin() + i);
		}

		if (player.player.getGlobalBounds().intersects(powerUpVec[i].powerup.getGlobalBounds()))
		{
			powerUpVec[i].erase = true;
			effect effekt;
			effekt.kindOfEffect = powerUpVec[i].kindOfPowerUp;
			if (effekt.kindOfEffect == 0) {
				effekt.timer = 15.0f;
			}
			if (effekt.kindOfEffect == 1)
			{
				effekt.timer = 25.0f;
			}
			if (effekt.kindOfEffect == 2)
			{
				effekt.timer = 10.0f;
			}
			if (effekt.kindOfEffect == 4)
			{
				if(player.earthQuake ==0 )
				player.earthQuake = 1;
			}

		

			effectVec.push_back(effekt);

		//	powerUpVec.erase(powerUpVec.begin() + i);
		}

		if (powerUpVec[i].erase)
		{
			powerUpVec.erase(powerUpVec.begin() + i);
		}

		//skriv funktion för powerUpvec[i].accumilatedTime att den returnerar den och sedan i player har en funktion som handle effekt av powerUp structvector?
		//hela tiden tickar ner? sätt acumilateted time till typ 15 sen varje game tick minska för i effekter aktiv; ?
		//en till struct vector i map?

	}


	for (int i = 0; i < effectVec.size(); i++)
	{
		effectVec[i].timer -= player.returnDt();

		if (effectVec[i].timer > 0 && effectVec[i].kindOfEffect == 0) //om effekten är igång
		{
			//player.Speed = 2.5f;
		
			player.playerHP += 25;
			if (player.playerHP > 100)
			{
				player.playerHP = 100;
			}
			effectVec[i].timer = 0.0f;
		}
		//if (effectVec[i].timer <= 0 && effectVec[i].kindOfEffect == 0) // om effekten är av så att det fungerar att stacka powerups alltså ha 2x dmg och 2x speed samtidigt
		//	//player.Speed = 1.9f;

		if (effectVec[i].timer > 0 && effectVec[i].kindOfEffect == 1)
		{
			player.bow.fDmg = player.bow.fDmg * 2;
			player.bow.iProjectile.projectile.setFillColor(sf::Color::Magenta);
		}
		if (effectVec[i].timer <= 0 && effectVec[i].kindOfEffect == 1)
		{ player.bow.iProjectile.projectile.setFillColor(sf::Color::Green);
			player.bow.fDmg=75;
		}
		
		if (effectVec[i].timer > 0 && effectVec[i].kindOfEffect == 2)
		{
			player.bow.fBaseBow = 0.05f;
		}
		if(effectVec[i].timer <=0 &&effectVec[i].kindOfEffect==2)
			player.bow.fBaseBow = 0.25f;

	
		if (effectVec[i].timer <= 0)
		{
			effectVec.erase(effectVec.begin() + i); //tar bort effekten då tiden <=0 
		}
	}


}

void cMap::drawPowerUps(sf::RenderWindow& window)
{
	for (int i = 0; i < powerUpVec.size(); i++) {
	
		window.draw(powerUpVec[i].sprite); //ritar ut powerupsen

	}
}

void cMap::init()
{
	effectVec.clear();
	powerUpVec.clear();
}
