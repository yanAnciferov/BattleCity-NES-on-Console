#pragma once
#pragma once
#include "Header.h"

class ShooterTank : public Tank
{
	

	void ColorArmor()
	{
		if (_armor)
			SetColor(Green, 0);
		else SetColor(_color, 0);
	}

public:


	ShooterTank(TypeCreate type);
	ShooterTank(int x, int y, int rotate);
	ShooterTank(TypeCreate type, bool bonus);

	virtual void Draw();

	virtual int GetSpeed();

	virtual bullet* Shoot();

	virtual bool isPunchWall();
	


	virtual ~ShooterTank()
	{

	};
};