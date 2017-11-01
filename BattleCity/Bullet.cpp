#pragma once
#include "Header.h"
#include "Bullet.h"
#include "LowBullet.h"
#include "MidleBullet.h"
#include "HighBullet.h"
#include "ClassTank.h"

#pragma region(bullet)
void bullet::destroy()
{
	if (_shooter != nullptr)
	{
		_shooter->BullDestroy();
	}

}

bullet::bullet(int x, int y, int rotation)
{
	_x = x;
	_y = y;
	_rotation = rotation;


}
bullet::bullet(int x, int y, int rotation, Tank* shooter) : bullet(x, y, rotation)
{
	_shooter = shooter;

}

void bullet::goAndPrint()
{
	erase();
	go();
	print();


}
void bullet::go()
{
	if (_rotation == RIGHT)
	{
		_x++;
		return;
	}
	else
		if (_rotation == LEFT)
		{
			_x--;
			return;
		}
		else
			if (_rotation == UP)
			{
				_y--;
				return;
			}
			else
				if (_rotation == DOWN)
				{
					_y++;
					return;
				}
}
void bullet::print()
{
	SetColor(White, 0);
	Cursor(_x, _y);
	cout << char(249);
}
void bullet::erase()
{
	SetColor(0, 0);
	Cursor(_x, _y);
	cout << " ";
}
void bullet::print(Color BackGround)
{
	SetColor(White, BackGround);
	Cursor(_x, _y);
	cout << char(249);
}
void bullet::erase(Color BackGround)
{
	SetColor(White, BackGround);
	Cursor(_x, _y);
	cout << " ";
}

void bullet::TankDestroy()
{
	_shooter = nullptr;
}

int bullet::GetSpeed()
{
	return _speed;
}

int bullet::getRotation()
{
	return _rotation;
}
int bullet::getX()
{
	return _x;
}
int bullet::getY()
{
	return _y;
}

#pragma endregion


#pragma region(HightBullet)

HighBullet::HighBullet(int x, int y, int rotate, Tank* t) : bullet(x, y, rotate, t)
{
	_speed = 600;
#ifdef FAST
	_speed *= 2;
#endif // FAST

}

HighBullet::HighBullet(int x, int y, int rotate) : bullet(x, y, rotate)
{
	_speed = 600;
#ifdef FAST
	_speed *= 2;
#endif 
}


bool HighBullet::IsPunchWall()
{
	return true;
}

#pragma endregion

#pragma region(LowBullet)

LowBullet::LowBullet(int x, int y, int rotate, Tank* t) : bullet(x, y, rotate, t)
{
	_speed = 1000;
#ifdef FAST
	_speed *= 2;
#endif 
}

LowBullet::LowBullet(int x, int y, int rotate) : bullet(x, y, rotate)
{
	_speed = 1000;
#ifdef FAST
	_speed *= 2;
#endif 
}


#pragma endregion

#pragma region(MidleBullet)
MidleBullet::MidleBullet(int x, int y, int rotate, Tank* t) : bullet(x, y, rotate, t)
{
	_speed = 600;
#ifdef FAST
	_speed *= 2;
#endif 
}

MidleBullet::MidleBullet(int x, int y, int rotate) : bullet(x, y, rotate)
{
	_speed = 600;
#ifdef FAST
	_speed *= 2;
#endif 
}

#pragma endregion