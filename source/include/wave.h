#ifndef WAVE_H
#define WAVE_H

#include "Enemy.h"


class cWave
{
public:
	cWave();
	~cWave();


	void spawnEnemyWave(cEnemy&);
	void updateTimer(cPlayer);
	int returnwave();
	float returnTimer();
	void init();
	
private:
	float timer;
	int waveCount;
};




#endif // !WAVE_H
