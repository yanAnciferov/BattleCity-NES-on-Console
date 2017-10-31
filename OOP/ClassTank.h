#pragma once

#include "Header.h"




class Tank
{
	
	
protected:

	bool _bonus = 0;

	bool _armor = 0;

	int x;
	int y;
	int rotation;
	int live = 1;
	int speed;

	bullet* _bul;
	Color _color;
	TypeCreate _type;


public:
	
	Tank(int _x, int _y, int rot);
	Tank(int _x, int _y, int rot, bool bonus);
	Tank(TypeCreate type);
	Tank(TypeCreate type, bool bonus);

	void GoToStart();


	virtual void Draw();
	virtual void Erase();

	virtual int GetSpeed() = 0;

	void ArmorOn();
	void ArmorOf();
	int GetArmor();


	void destroy();

	bool isBonusTank();
	void ofBonus();
	virtual void spawn(TypeCreate type);

	int getX();
	int getY();
	int getRotation();
	int getLive();
	bool getBulletLive()
	{
		if (_bul == nullptr)
			return 0;
		return 1;
	}
	virtual void downLive();
	

	void BullDestroy();


	void MoveRight();
	void MoveLeft();
	void MoveDown();
	void MoveUp();

	void Turn(Rotation rot);

	virtual bullet* Shoot() = 0;
	
	virtual bool isPunchWall() = 0;

	virtual ~Tank() = 0 {};
};

