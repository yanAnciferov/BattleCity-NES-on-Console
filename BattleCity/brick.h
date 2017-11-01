#pragma once
#include "Header.h"

class Brick : public Block
{

public:

	Brick(int x, int y);

	virtual void print();

	virtual void erase();

	virtual bool isMoveTank();

	virtual bool isMoveBullet();

	virtual bool isHardArmor();

	virtual ~Brick()
	{

	}
};