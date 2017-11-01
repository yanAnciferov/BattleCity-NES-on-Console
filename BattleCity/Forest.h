#pragma once
#include "Header.h"

class Forest : public Block
{

public:

	Forest(int x, int y);

	virtual bool isHardArmor();
	virtual bool isShelter();

	virtual void print();

	virtual void erase();

	virtual bool isMoveTank();

	virtual bool isMoveBullet();

	virtual ~Forest()
	{

	}

};