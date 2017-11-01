#pragma once
#pragma once
#pragma once
#include "Header.h"

class DoubleShooterTank : public Tank
{
	

	void ColorArmor()
	{
		if (_armor)
			SetColor(Green, 0);
		else SetColor(_color, 0);
	}

public:


	
	DoubleShooterTank(int x, int y, int rotate);

	virtual void Draw();

	virtual int GetSpeed();


	virtual bullet* Shoot();

	virtual bool isPunchWall();
	


	virtual ~DoubleShooterTank()
	{

	};
};