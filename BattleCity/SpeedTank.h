#pragma once
#include "Header.h"


class SpeedTank : public Tank
{
	
	void ColorArmor()
	{
		if (_armor)
			SetColor(Green, 0);
		else SetColor(_color, 0);
	}

public:


	SpeedTank(TypeCreate type);
	SpeedTank(TypeCreate type, bool bonus);

	virtual int GetSpeed();


	virtual bullet* Shoot();

	virtual bool isPunchWall();
	void Draw();

	void Erase();



	virtual ~SpeedTank()
	{

	};
};