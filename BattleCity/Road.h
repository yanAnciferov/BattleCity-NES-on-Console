#pragma once
#include "Header.h"

class Road : public Block
{

public:

	Road(int x, int y);

	virtual void print();

	virtual void erase();

	virtual bool isMoveTank();

	virtual bool isMoveBullet();

	virtual bool isHardArmor();

	virtual ~Road()
	{

	}
};