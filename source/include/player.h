#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Main.hpp"
#include "SFML/System.hpp";
#include "SFML/Graphics.hpp";
#include "SFML/Config.hpp"
#include "SFML/Window.hpp"

#include <vector> // dynamisk array
#include <cmath>

#include "Weapon.h"





class cPlayer
{
	
private:
	struct sInventoryO 
	{
		sf::RectangleShape sfRecInventoryOuter;
		int number;
		bool bOccupied;

		int itemType;
	
	};
	struct sInventoryI
	{
		sf::RectangleShape sfRecInventoryInner;
		sf::Sprite itemSPR;
		int itemID;
		int itemType;

	};
	


	std::vector<sInventoryO> svInventoryO; //vector av structen sInventory
	std::vector<sInventoryI> svInventoryI; //vector av structen sInventory

public:
	cPlayer();
	~cPlayer();
	float fDeltaTime;

	cBow bow;
	sf::Texture Playertexture;
	sf::Sprite playerSprite;
	float fAccumilatedTime;
	bool inventoryOpen;
	sf::RectangleShape player;
	float playerHP = 100.0f;
	//metoder i klassen
	//void performAttack();
	void setSprite(sf::Sprite);
	void updateDeltaTime();
	void controls();
	void updatePlayer(sf::RenderWindow& window);
	void handleInventory(sf::RenderWindow& window);
	void pickUpitems();//std::vector<sf::RectangleShape>&, std::vector<int>&,sf::RectangleShape,int);
	void levelUp();
	float returnDt();
    bool alive();
	float returnHP();
	void addScore();

	int returnScore();
	sf::Vector2f returnPlayerpos();
	sf::Vector2f playerPos;
	float Speed = 1.5f;
	//combat
	int earthQuake;
	bool activate;

	void init();
protected:
	
	


	//privata 
private:
	//##### variabler  ####
	sf::Sprite pSprite;
	float x;
	float y;
	float stdScale = 32.0f;
	bool pickedUp;
	int tmp;
	sf::Clock sfClock;
	int score;


	////std::vector<sf::RectangleShape> inventoryOuter; 
	//std::vector<sf::RectangleShape> inventoryInner;
	////std::vector<int> inventory;
	//sf::RectangleShape z;
	//sf::RectangleShape item;

	float fExp; //mängden xp
	float fExpCap; //xp cap per level
	float fPrevXp;
	float fLevel;
	float fTotXp;
	float fHp;
	float fHpCap;
	float fArrowDelay;
	sf::Vector2f playerpos;

	//attributes
	int strength;
	int agility;
	int dexterity;
	int vitality;

//	float fStamina;

	//####    #####   #####


	/*
	//player stats
	int level;
	float fExp;
	float fExpCap;
	float fHp;
	float fHpCap;
	float fStamina;
	float fStaminaCap;

	//attributes
	int strength;
	int agility;
	int dexterity;
	int vitality;*/

};

#endif