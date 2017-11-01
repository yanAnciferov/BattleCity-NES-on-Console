#pragma once
#pragma once
#pragma once
#include "Header.h"

class Water : public Block
{

public:

	Water(int x, int y);

	virtual void print();

	virtual void erase();

	virtual bool isMoveTank();

	virtual bool isMoveBullet();
	virtual bool isHardArmor();
	virtual ~Water()
	{

	}
};