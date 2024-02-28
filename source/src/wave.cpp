#include "wave.h"

cWave::cWave()
{
	timer = 0.0f;
	waveCount = 0;
}

cWave::~cWave()
{

}

void cWave::init()
{
	waveCount = 0;
	timer = 0.0f;

}

void cWave::spawnEnemyWave(cEnemy& enemy)
{
	if (timer > 5.0f)
	{
		timer = 0;
		if (waveCount < 50) {
		

			enemy.spawnEnemy(waveCount);
			waveCount++;
		}
		else {
			
			enemy.spawnEnemy(50);
			waveCount++;
		}
	}
	if (waveCount == 0)
	{

		enemy.spawnEnemy(1);
		waveCount++;
	}



	
}

void cWave::updateTimer(cPlayer player)
{

	timer += player.returnDt();


}

int cWave::returnwave()
{
	return waveCount;
}

float cWave::returnTimer()
{
	float time=5 - timer;
	return time;
}



