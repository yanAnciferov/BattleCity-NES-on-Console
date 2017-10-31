#pragma once
#include "Header.h"

#include "Bullet.h"
#include "LowBullet.h"
#include "MidleBullet.h"
#include "HighBullet.h"


#include "Frame.h"
#include "ClassTank.h"
#include "EazyTank.h"
#include "ShooterTank.h"
#include "DoubleShooterTank.h"
#include "SuperPowerTank.h"
#include "SpeedTank.h"
#include "ArmorTank.h"


class Player 
{

	Tank* pl;
	int lvl = 1;
	int live = 3;

	bool BonusArm = 0;

	

public:

	void Spawn();

	void Start();

	void Draw();
	void Erase();


	void GoToStart();

	int getLvl();
	int GetSpeed();
	int GetX();
	int GetY();
	int GetRotate();
	bool GetBonusArmor();
	int GetLive();

	void ArmorOn();
	void ArmorOf();

	void Destroy();

	void Turn(Rotation rot);

	void BonusLive();



	bool isPunchWall();

	void MoveLeft();
	void MoveUp();
	void MoveRight();
	void MoveDown();

	

	bullet* Shoot();

	void NextLvl();
};