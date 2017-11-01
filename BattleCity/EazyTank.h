#pragma once
#include "Header.h"

class EazyTank : public Tank
{
	

	void ColorArmor()
	{
		if (_armor)
			SetColor(Green, 0);
		else SetColor(_color, 0);
	}

public:


	EazyTank(TypeCreate type);

	EazyTank(int x, int y, int rot);

	EazyTank(TypeCreate type, bool bonus);

	virtual int GetSpeed();


	virtual bullet* Shoot();

	virtual bool isPunchWall();
	void Draw();

	void Erase();



	virtual ~EazyTank()
	{

	};
};