#pragma once
#include "Header.h"

class Tank;

class bullet
{

	int _x = 0;
	int _y = 0;
	int _rotation = 0;
	Tank* _shooter = nullptr;
protected:

	int _speed;

public:
	

	void destroy();
	bullet() = default;
	bullet(int x, int y, int rotation);
	bullet(int x, int y, int rotation, Tank* shooter);

	void goAndPrint();
	void go();
	void print();
	void erase();
	void print(Color BackGround);
	void erase(Color BackGround);

	

	void TankDestroy();

	virtual int GetSpeed();

	virtual bool IsPunchWall()
	{
		return false;
	};

	int getRotation();
	int getX();
	int getY();

};


