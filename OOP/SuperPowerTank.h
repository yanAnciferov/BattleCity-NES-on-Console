#pragma once
#include "Header.h"

class SuperPowerTank : public Tank
{
	
	void ColorArmor()
	{
		if (_armor)
			SetColor(Green, 0);
		else SetColor(_color, 0);
	}

public:


	SuperPowerTank(int x, int y, int rotate);

	virtual int GetSpeed();


	virtual bullet* Shoot();

	virtual bool isPunchWall();
	void Draw();

	void Erase();



	virtual ~SuperPowerTank()
	{

	};
};