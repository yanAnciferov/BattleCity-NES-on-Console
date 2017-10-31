#pragma once
#pragma once
#include "Header.h"

class Wall : public Block
{

public:

	Wall(int x, int y);

	virtual bool isHardArmor();

	virtual void print();

	virtual void erase();

	virtual bool isMoveTank();

	virtual bool isMoveBullet();

	virtual ~Wall()
	{

	}
};