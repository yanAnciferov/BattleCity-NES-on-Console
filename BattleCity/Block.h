#pragma once
#include "Header.h"


class Block
{
protected:
	int _x;
	int _y;

	char _symbol;
	Color _back;
	Color _obj;

public:

	Block() = default;
	Block(int x, int y);


	virtual bool isMoveTank() = 0;
	virtual bool isMoveBullet() = 0;

	int getColor();

	virtual bool isFacility();

	virtual bool isShelter();
	virtual bool isHardArmor() = 0;

	virtual void erase() = 0;
	virtual void print() = 0;

	virtual ~Block() = 0 {};
};