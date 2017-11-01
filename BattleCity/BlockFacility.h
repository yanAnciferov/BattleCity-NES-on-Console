#pragma once
#include "Header.h"

class Facility : public Block
{

public:

	Facility(int x, int y);

	virtual void print();

	virtual bool isFacility();

	virtual void erase();

	virtual bool isMoveTank();

	virtual bool isMoveBullet();

	virtual bool isHardArmor();

	virtual ~Facility()
	{

	}
};