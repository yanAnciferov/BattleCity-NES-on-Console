#pragma once
#include "Header.h"

class ArmorTank : public Tank
{

	void ColorArmor()
	{
		
		SetColor(_color, 0);
	}

public:


	ArmorTank(TypeCreate type);
	ArmorTank(TypeCreate type, bool bonus);

	virtual int GetSpeed();


	virtual bullet* Shoot();

	virtual bool isPunchWall();
	void Draw();

	void Erase();

	virtual void downLive();

	virtual ~ArmorTank()
	{

	};



};