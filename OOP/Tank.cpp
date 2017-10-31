#pragma once
#include "Header.h"
#include "Player.h"
#include "ClassTank.h"
#include "EazyTank.h"
#include "ShooterTank.h"
#include "DoubleShooterTank.h"
#include "SuperPowerTank.h"
#include "SpeedTank.h"
#include "ArmorTank.h"
#include "Bullet.h"
#include "LowBullet.h"
#include "MidleBullet.h"
#include "HighBullet.h"



#pragma region(Tank)

Tank::Tank(int _x, int _y, int rot)
{
	x = _x;
	y = _y;
	if (rot != UP && rot != RIGHT && rot != LEFT && rot != DOWN)
	{
		rotation = RIGHT;
	}
	else
	{
		rotation = rot;
	}

}
Tank::Tank(int _x, int _y, int rot, bool bonus) : Tank(_x, _y, rot)
{
	_bonus = bonus;
}
Tank::Tank(TypeCreate type)
{
	_type = type;
	rotation = DOWN;
	y = 2;

	switch (type)
	{
	case TypeCreate::LEFT:
		x = 1;
		break;
	case TypeCreate::MID:
		x = 19;
		break;
	case TypeCreate::RIGHT:
		x = 37;
		break;
	case TypeCreate::PLAYER:
		x = 13;
		y = 36;
		rotation = UP;
		break;
	default:
		break;
	}
}
Tank::Tank(TypeCreate type, bool bonus)
{
	_bonus = bonus;
	rotation = DOWN;
	y = 2;
	_type = type;
	switch (type)
	{
	case TypeCreate::LEFT:
		x = 1;
		break;
	case TypeCreate::MID:
		x = 19;
		break;
	case TypeCreate::RIGHT:
		x = 37;
		break;
	case TypeCreate::PLAYER:
		x = 13;
		y = 36;
		rotation = UP;
		break;
	default:
		break;
	}
}

void Tank::GoToStart()
{
	if (_type != TypeCreate::PLAYER)
		return;

	x = 13;
	y = 36;
	rotation = UP;
	_armor = 0;
}


void Tank::Draw()
{

	if (rotation == RIGHT)
	{

		Cursor(x - 2, y);
		cout << (char)219 << (char)219 << (char)219;
		Cursor(x - 2, y - 1);
		cout << (char)219 << (char)219;
		Cursor(x - 2, y + 1);
		cout << (char)219 << (char)219;

	}
	else if (rotation == LEFT)
	{

		Cursor(x, y);
		cout << (char)219 << (char)219 << (char)219;
		Cursor(x + 1, y - 1);
		cout << (char)219 << (char)219;
		Cursor(x + 1, y + 1);
		cout << (char)219 << (char)219;

	}
	else if (rotation == DOWN)
	{


		Cursor(x, y);
		cout << (char)219;
		Cursor(x - 1, y - 1);
		cout << (char)219 << (char)219 << (char)219;
		Cursor(x - 1, y - 2);
		cout << (char)219 << (char)219 << (char)219;

	}
	else if (rotation == UP)
	{

		Cursor(x, y);
		cout << (char)219;
		Cursor(x - 1, y + 1);
		cout << (char)219 << (char)219 << (char)219;
		Cursor(x - 1, y + 2);
		cout << (char)219 << (char)219 << (char)219;

	}
	SetColor(White, 0);
}
void Tank::Erase()
{
	SetColor(0, 0);
	if (rotation == RIGHT)
	{
		Cursor(x - 2, y);
		cout << "   ";
		Cursor(x - 2, y - 1);
		cout << "  ";
		Cursor(x - 2, y + 1);
		cout << "  ";

	}
	else if (rotation == LEFT)
	{
		Cursor(x, y);
		cout << ' ' << ' ' << ' ';
		Cursor(x + 1, y - 1);
		cout << ' ' << ' ';
		Cursor(x + 1, y + 1);
		cout << ' ' << ' ';
	}
	else if (rotation == DOWN)
	{


		Cursor(x, y);
		cout << ' ';
		Cursor(x - 1, y - 1);
		cout << "   ";
		Cursor(x - 1, y - 2);
		cout << "   ";

	}
	else if (rotation == UP)
	{

		Cursor(x, y);
		cout << ' ';
		Cursor(x - 1, y + 1);
		cout << "   ";
		Cursor(x - 1, y + 2);
		cout << "   ";

	}

}



void Tank::ArmorOn()
{
	_armor = 1;
}
void Tank::ArmorOf()
{
	_armor = 0;
}
int Tank::GetArmor()
{
	return _armor;
}


void Tank::destroy()
{
	
	if (_bul != nullptr)
		_bul->TankDestroy();
}

bool Tank::isBonusTank()
{
	return _bonus;
}
void Tank::ofBonus()
{
	_bonus = 0;
}
void Tank::spawn(TypeCreate type)
{

	rotation = DOWN;
	y = 2;

	switch (type)
	{
	case TypeCreate::LEFT:
		x = 1;
		break;
	case TypeCreate::MID:
		x = 19;
		break;
	case TypeCreate::RIGHT:
		x = 36;
		break;
	case TypeCreate::PLAYER:
		x = 16;
		y = 2;
		rotation = UP;
		break;
	default:
		break;
	}
}

int Tank::getX()
{
	return x;
}
int Tank::getY()
{
	return y;
}
int Tank::getRotation()
{
	return rotation;
}
int Tank::getLive()
{
	return live;
}
void Tank::downLive()
{
	if (live != 1)
	{
		live--;
	}

}


void Tank::BullDestroy()
{
	_bul = nullptr;
}


void Tank::MoveRight()
{

	if (rotation != RIGHT)
		Turn(RIGHT);
	else
	{
		x++;

	}

}
void Tank::MoveLeft()
{

	if (rotation != LEFT)
		Turn(LEFT);
	else
	{
		x--;

	}
	/*	Erase();
	if (rotation != LEFT)
	{
	if (rotation == RIGHT)
	{

	x -= 2;
	}
	else if (rotation == DOWN)
	{
	x--;
	y--;
	}
	else if (rotation == UP)
	{
	x--;
	y++;
	}

	rotation = LEFT;

	}
	else
	{
	x--;
	}
	Draw();*/
}
void Tank::MoveDown()
{

	if (rotation != DOWN)
		Turn(DOWN);
	else
	{
		y++;

	}
	/*Erase();
	if (rotation != DOWN)
	{
	if (rotation == RIGHT)
	{
	x--;
	y++;
	}
	else if (rotation == LEFT)
	{
	x++;
	y++;
	}
	else if (rotation == UP)
	{
	if (y < 1)
	{
	y = 2;
	}
	else
	y += 2;
	}
	rotation = DOWN;

	}
	else
	{
	y++;
	}
	Draw();*/

}
void Tank::MoveUp()
{

	if (rotation != UP)
		Turn(UP);
	else
	{
		y--;

	}
	/*Erase();
	if (rotation != UP)
	{
	if (rotation == RIGHT)
	{
	x--;
	y--;
	}
	else if (rotation == LEFT)
	{
	x++;
	y--;
	}
	else if (rotation == DOWN)
	{
	if (y < 1)
	{
	y = 3;
	}
	else
	y -= 2;
	}
	rotation = UP;

	}
	else
	{
	y--;
	}
	Draw();*/

}

void Tank::Turn(Rotation rot)
{


	if (rot == RIGHT && rotation != RIGHT)
	{
		if (rotation == LEFT)
		{
			if (x < 1)
			{
				x = 2;
			}
			else
				x += 2;
		}
		else if (rotation == DOWN)
		{
			x++;
			y--;
		}
		else if (rotation == UP)
		{
			x++;
			y++;
		}
		rotation = RIGHT;

	}
	else if (rot == LEFT && rotation != LEFT)
	{
		if (rotation == RIGHT)
		{

			x -= 2;
		}
		else if (rotation == DOWN)
		{
			x--;
			y--;
		}
		else if (rotation == UP)
		{
			x--;
			y++;
		}

		rotation = LEFT;

	}
	else if (rot == DOWN && rotation != DOWN)
	{
		if (rotation == RIGHT)
		{
			x--;
			y++;
		}
		else if (rotation == LEFT)
		{
			x++;
			y++;
		}
		else if (rotation == UP)
		{
			if (y < 1)
			{
				y = 2;
			}
			else
				y += 2;
		}
		rotation = DOWN;

	}
	else if (rot == UP && rotation != UP)
	{
		if (rotation == RIGHT)
		{
			x--;
			y--;
		}
		else if (rotation == LEFT)
		{
			x++;
			y--;
		}
		else if (rotation == DOWN)
		{
			if (y < 1)
			{
				y = 3;
			}
			else
				y -= 2;
		}
		rotation = UP;

	}
	rotation = rot;


}

#pragma endregion

#pragma region(EazyTank)

EazyTank::EazyTank(TypeCreate type) : Tank(type)
{
	if (type == TypeCreate::PLAYER)
	{
		speed = 2500;
#ifdef FAST
		speed *= 2;
#endif 
		_color = Brown;
	}
	else
	{
		speed = 4000;
#ifdef FAST
		speed *= 2;
#endif 
		_color = LightGray;
	}
}

EazyTank::EazyTank(int x, int y, int rot) : Tank(x, y, rot)
{
	_color = Brown;
}

EazyTank::EazyTank(TypeCreate type, bool bonus) : EazyTank(type)
{
	_bonus = bonus;
}

int EazyTank::GetSpeed()
{
	return speed;
}

bullet* EazyTank::Shoot()
{
	if (_type == TypeCreate::PLAYER)
	{
		if (rotation == RIGHT)
			return _bul = new LowBullet(x + 1, y, rotation);
		if (rotation == LEFT)
			return _bul = new LowBullet(x - 1, y, rotation);
		if (rotation == UP)
			return _bul = new LowBullet(x, y - 1, rotation);
		if (rotation == DOWN)
			return _bul = new LowBullet(x, y + 1, rotation);
	}
	else
	{
		if (rotation == RIGHT)
			return _bul = new LowBullet(x + 1, y, rotation, this);
		if (rotation == LEFT)
			return _bul = new LowBullet(x - 1, y, rotation, this);
		if (rotation == UP)
			return _bul = new LowBullet(x, y - 1, rotation, this);
		if (rotation == DOWN)
			return _bul = new LowBullet(x, y + 1, rotation, this);
	}
}

bool EazyTank::isPunchWall()
{
	return false;
}
void EazyTank::Draw()
{

	if (rotation == RIGHT)
	{
		ColorArmor();
		Cursor(x - 2, y - 1);
		cout << (char)219 << (char)219 << (char)219;
		Cursor(x - 1, y);

		if (_bonus)
			SetColor(Magenta, 0);

		cout << (char)219;
		ColorArmor();
		cout << char(16);
		Cursor(x - 2, y + 1);
		cout << (char)219 << (char)219 << (char)219;

	}
	else if (rotation == LEFT)
	{
		ColorArmor();
		Cursor(x, y - 1);
		cout << (char)219 << (char)219 << (char)219;
		Cursor(x, y);
		cout << (char)17;
		if (_bonus)
			SetColor(Magenta, 0);
		cout << char(219);
		ColorArmor();
		Cursor(x, y + 1);
		cout << (char)219 << (char)219 << (char)219;

	}
	else if (rotation == DOWN)
	{
		ColorArmor();
		Cursor(x - 1, y - 2);
		cout << (char)219 << ' ' << (char)219;
		Cursor(x - 1, y - 1);
		cout << (char)219;
		if (_bonus)
			SetColor(Magenta, 0);
		cout << (char)219;
		ColorArmor();
		cout << (char)219;
		Cursor(x - 1, y);
		cout << (char)219 << char(31) << (char)219;

	}
	else if (rotation == UP)
	{
		ColorArmor();
		Cursor(x - 1, y);
		cout << (char)219 << char(30) << (char)219;
		Cursor(x - 1, y + 1);
		cout << (char)219;
		if (_bonus)
			SetColor(Magenta, 0);
		cout << (char)219;
		ColorArmor();
		cout << (char)219;
		Cursor(x - 1, y + 2);
		cout << (char)219 << ' ' << (char)219;
	}

	SetColor(White, 0);
}

void EazyTank::Erase()
{
	SetColor(0, 0);
	if (rotation == RIGHT)
	{

		Cursor(x - 2, y - 1);
		cout << "   ";
		Cursor(x - 1, y);
		cout << "  ";
		Cursor(x - 2, y + 1);
		cout << "   ";

	}
	else if (rotation == LEFT)
	{

		Cursor(x, y - 1);
		cout << "   ";
		Cursor(x, y);
		cout << "  ";
		Cursor(x, y + 1);
		cout << "   ";

	}
	else if (rotation == DOWN)
	{

		Cursor(x - 1, y - 2);
		cout << "   ";
		Cursor(x - 1, y - 1);
		cout << "   ";
		Cursor(x - 1, y);
		cout << "   ";

	}
	else if (rotation == UP)
	{

		Cursor(x - 1, y);
		cout << "   ";
		Cursor(x - 1, y + 1);
		cout << "   ";
		Cursor(x - 1, y + 2);
		cout << "   ";
	}
	SetColor(White, 0);
}


#pragma endregion

#pragma region(ShooterTank)

ShooterTank::ShooterTank(TypeCreate type) : Tank(type)
{
	_color = LightGray;
	speed = 4000;
#ifdef FAST
	speed *= 2;
#endif 
}
ShooterTank::ShooterTank(int x, int y, int rotate) : Tank(x, y, rotate)
{

	speed = 2500;
	_color = Brown;
	_type = TypeCreate::PLAYER;
#ifdef FAST
	speed *= 2;
#endif 

}
ShooterTank::ShooterTank(TypeCreate type, bool bonus) : ShooterTank(type)
{
	_bonus = bonus;
}

void ShooterTank::Draw()
{
	ColorArmor();
	if (rotation == RIGHT)
	{
		ColorArmor();
		Cursor(x - 2, y);
		cout << ' ';
		if (_bonus)
			SetColor(Magenta, 0);
		cout << (char)219;
		ColorArmor();
		cout << (char)219;
		Cursor(x - 2, y - 1);
		cout << (char)219 << (char)219;
		Cursor(x - 2, y + 1);
		cout << (char)219 << (char)219;

	}
	else if (rotation == LEFT)
	{
		ColorArmor();
		Cursor(x, y);
		cout << (char)219;
		if (_bonus)
			SetColor(Magenta, 0);
		cout << (char)219;
		ColorArmor();
		cout << ' ';
		Cursor(x + 1, y - 1);
		cout << (char)219 << (char)219;
		Cursor(x + 1, y + 1);
		cout << (char)219 << (char)219;

	}
	else if (rotation == DOWN)
	{


		Cursor(x, y);
		cout << (char)219;
		Cursor(x - 1, y - 1);
		cout << (char)219;
		if (_bonus)
			SetColor(Magenta, 0);
		cout << (char)219;
		ColorArmor();
		cout << (char)219;
		Cursor(x - 1, y - 2);
		cout << (char)219 << ' ' << (char)219;

	}
	else if (rotation == UP)
	{

		Cursor(x, y);
		cout << (char)219;
		Cursor(x - 1, y + 1);
		cout << (char)219;
		if (_bonus)
			SetColor(Magenta, 0);
		cout << (char)219;
		ColorArmor();
		cout << (char)219;
		Cursor(x - 1, y + 2);
		cout << (char)219 << ' ' << (char)219;

	}
	SetColor(White, 0);
}

int ShooterTank::GetSpeed()
{
	return speed;
}

bullet* ShooterTank::Shoot()
{
	if (_type == TypeCreate::PLAYER)
	{
		if (rotation == RIGHT)
			return _bul = new MidleBullet(x + 1, y, rotation);
		if (rotation == LEFT)
			return _bul = new MidleBullet(x - 1, y, rotation);
		if (rotation == UP)
			return _bul = new MidleBullet(x, y - 1, rotation);
		if (rotation == DOWN)
			return _bul = new MidleBullet(x, y + 1, rotation);
	}
	else
	{
		if (rotation == RIGHT)
			return _bul = new MidleBullet(x + 1, y, rotation, this);
		if (rotation == LEFT)
			return _bul = new MidleBullet(x - 1, y, rotation, this);
		if (rotation == UP)
			return _bul = new MidleBullet(x, y - 1, rotation, this);
		if (rotation == DOWN)
			return _bul = new MidleBullet(x, y + 1, rotation, this);
	}
}

bool ShooterTank::isPunchWall()
{
	return false;
}

#pragma endregion

#pragma region(DoubleShooterTank)
DoubleShooterTank::DoubleShooterTank(int x, int y, int rotate) : Tank(x, y, rotate)
{
	speed = 2500;
	_type = TypeCreate::PLAYER;
	_color = Brown;
#ifdef FAST
	speed *= 2;
#endif 
}

void DoubleShooterTank::Draw()
{
	SetColor(_color, 0);
	if (rotation == RIGHT)
	{
		ColorArmor();
		Cursor(x - 2, y);
		cout << (char)219;
		if (_bonus)
			SetColor(Magenta, 0);
		cout << (char)219;
		ColorArmor();
		cout << (char)219;
		Cursor(x - 2, y - 1);
		cout << (char)219 << (char)219;
		Cursor(x - 2, y + 1);
		cout << (char)219 << (char)219;

	}
	else if (rotation == LEFT)
	{
		ColorArmor();
		Cursor(x, y);
		cout << (char)219;
		if (_bonus)
			SetColor(Magenta, 0);
		cout << (char)219;
		ColorArmor();
		cout << (char)219;
		Cursor(x + 1, y - 1);
		cout << (char)219 << (char)219;
		Cursor(x + 1, y + 1);
		cout << (char)219 << (char)219;

	}
	else if (rotation == DOWN)
	{

		ColorArmor();
		Cursor(x, y);
		cout << (char)219;
		Cursor(x - 1, y - 1);
		cout << (char)219;
		if (_bonus)
			SetColor(Magenta, 0);
		cout << (char)219;
		ColorArmor();
		cout << (char)219;
		Cursor(x - 1, y - 2);
		cout << (char)219 << (char)219 << (char)219;

	}
	else if (rotation == UP)
	{
		ColorArmor();
		Cursor(x, y);
		cout << (char)219;
		Cursor(x - 1, y + 1);
		cout << (char)219;
		if (_bonus)
			SetColor(Magenta, 0);
		cout << (char)219;
		ColorArmor();
		cout << (char)219;
		Cursor(x - 1, y + 2);
		cout << (char)219 << (char)219 << (char)219;

	}
	SetColor(White, 0);
}

int DoubleShooterTank::GetSpeed()
{
	return speed;
}


bullet* DoubleShooterTank::Shoot()
{
	if (rotation == RIGHT)
		return new MidleBullet(x + 1, y, rotation);
	if (rotation == LEFT)
		return new MidleBullet(x - 1, y, rotation);
	if (rotation == UP)
		return new MidleBullet(x, y - 1, rotation);
	if (rotation == DOWN)
		return new MidleBullet(x, y + 1, rotation);
}

bool DoubleShooterTank::isPunchWall()
{
	return false;
}

#pragma endregion

#pragma region(SpeedTank)
SpeedTank::SpeedTank(TypeCreate type) : Tank(type)
{

	speed = 1900;
	_color = LightGray;
#ifdef FAST
	speed *= 2;
#endif 

}
SpeedTank::SpeedTank(TypeCreate type, bool bonus) : SpeedTank(type)
{
	_bonus = bonus;
}

int SpeedTank::GetSpeed()
{
	return speed;
}


bullet* SpeedTank::Shoot()
{
	if (rotation == RIGHT)
		return _bul = new LowBullet(x + 1, y, rotation,this);
	if (rotation == LEFT)
		return _bul = new LowBullet(x - 1, y, rotation, this);
	if (rotation == UP)
		return _bul = new LowBullet(x, y - 1, rotation, this);
	if (rotation == DOWN)
		return _bul = new LowBullet(x, y + 1, rotation, this);
}

bool SpeedTank::isPunchWall()
{
	return false;
}
void SpeedTank::Draw()
{
	SetColor(_color, 0);
	if (rotation == RIGHT)
	{
		ColorArmor();
		Cursor(x - 2, y - 1);
		cout << (char)219 << (char)220 << (char)219;
		Cursor(x - 2, y);
		cout << (char)219;
		if (_bonus)
			SetColor(Magenta, 0);
		cout << (char)219;
		ColorArmor();
		cout << char(16);
		Cursor(x - 2, y + 1);
		cout << (char)219 << (char)223 << (char)219;

	}
	else if (rotation == LEFT)
	{
		ColorArmor();
		Cursor(x, y - 1);
		cout << (char)219 << (char)220 << (char)219;
		Cursor(x, y);
		cout << (char)17;
		if (_bonus)
			SetColor(Magenta, 0);
		cout << char(219);
		ColorArmor();
		cout << char(219);
		Cursor(x, y + 1);
		cout << (char)219 << (char)223 << (char)219;

	}
	else if (rotation == DOWN)
	{
		ColorArmor();
		Cursor(x - 1, y - 2);
		cout << (char)219 << (char)219 << (char)219;
		Cursor(x - 1, y - 1);
		cout << (char)222;
		if (_bonus)
			SetColor(Magenta, 0);
		cout << (char)219;
		ColorArmor();
		cout << (char)221;
		Cursor(x - 1, y);
		cout << (char)219 << char(31) << (char)219;

	}
	else if (rotation == UP)
	{
		ColorArmor();
		Cursor(x - 1, y);
		cout << (char)219 << char(30) << (char)219;
		Cursor(x - 1, y + 1);
		cout << (char)222;
		if (_bonus)
			SetColor(Magenta, 0);
		cout << (char)219;
		ColorArmor();
		cout << (char)221;
		Cursor(x - 1, y + 2);
		cout << (char)219 << (char)219 << (char)219;
	}
	SetColor(White, 0);
}

void SpeedTank::Erase()
{
	SetColor(0, 0);
	if (rotation == RIGHT)
	{

		Cursor(x - 2, y - 1);
		cout << "   ";
		Cursor(x - 2, y);
		cout << "   ";
		Cursor(x - 2, y + 1);
		cout << "   ";

	}
	else if (rotation == LEFT)
	{

		Cursor(x, y - 1);
		cout << "   ";
		Cursor(x, y);
		cout << "   ";
		Cursor(x, y + 1);
		cout << "   ";

	}
	else if (rotation == DOWN)
	{

		Cursor(x - 1, y - 2);
		cout << "   ";
		Cursor(x - 1, y - 1);
		cout << "   ";
		Cursor(x - 1, y);
		cout << "   ";

	}
	else if (rotation == UP)
	{

		Cursor(x - 1, y);
		cout << "   ";
		Cursor(x - 1, y + 1);
		cout << "   ";
		Cursor(x - 1, y + 2);
		cout << "   ";
	}
	SetColor(White, 0);
}


#pragma endregion

#pragma region(ArmorTank)

ArmorTank::ArmorTank(TypeCreate type) : Tank(type)
{

	speed = 4000;
	_color = LightGray;
	live = 4;
#ifdef FAST
	speed *= 2;
#endif 

}
ArmorTank::ArmorTank(TypeCreate type, bool bonus) : ArmorTank(type)
{
	speed = 4000;
	_bonus = bonus;
	live = 4;
#ifdef FAST
	speed *= 2;
#endif 
}

int ArmorTank::GetSpeed()
{
	return speed;
}


bullet* ArmorTank::Shoot()
{
	if (rotation == RIGHT)
		return _bul = new LowBullet(x + 1, y, rotation, this);
	if (rotation == LEFT)
		return _bul = new LowBullet(x - 1, y, rotation, this);
	if (rotation == UP)
		return _bul = new LowBullet(x, y - 1, rotation, this);
	if (rotation == DOWN)
		return _bul = new LowBullet(x, y + 1, rotation, this);
}

bool ArmorTank::isPunchWall()
{
	return false;
}
void ArmorTank::Draw()
{
	if (live > 1)
		_color = Green;
	else _color = LightGray;

	ColorArmor();
	if (rotation == RIGHT)
	{
		ColorArmor();
		Cursor(x - 2, y - 1);
		cout << (char)219 << (char)219 << (char)219;
		Cursor(x - 2, y);
		cout << (char)219;
		if (_bonus)
			SetColor(Magenta, 0);
		cout << (char)219;
		ColorArmor();
		cout << char(16);
		Cursor(x - 2, y + 1);
		cout << (char)219 << (char)219 << (char)219;

	}
	else if (rotation == LEFT)
	{
		ColorArmor();
		Cursor(x, y - 1);
		cout << (char)219 << (char)219 << (char)219;
		Cursor(x, y);
		cout << (char)17;
		if (_bonus)
			SetColor(Magenta, 0);
		cout << char(219);
		ColorArmor();
		cout << (char)219;
		Cursor(x, y + 1);
		cout << (char)219 << (char)219 << (char)219;

	}
	else if (rotation == DOWN)
	{
		ColorArmor();
		Cursor(x - 1, y - 2);
		cout << (char)219 << (char)219 << (char)219;
		Cursor(x - 1, y - 1);
		cout << (char)219;
		if (_bonus)
			SetColor(Magenta, 0);
		cout << (char)219;
		ColorArmor();
		cout << (char)219;
		Cursor(x - 1, y);
		cout << (char)219 << char(31) << (char)219;

	}
	else if (rotation == UP)
	{
		ColorArmor();
		Cursor(x - 1, y);
		cout << (char)219 << char(30) << (char)219;
		Cursor(x - 1, y + 1);
		cout << (char)219;
		if (_bonus)
			SetColor(Magenta, 0);
		cout << (char)219;
		ColorArmor();
		cout << (char)219;
		Cursor(x - 1, y + 2);
		cout << (char)219 << (char)219 << (char)219;
	}
	SetColor(White, 0);
}

void ArmorTank::Erase()
{
	SetColor(0, 0);
	if (rotation == RIGHT)
	{

		Cursor(x - 2, y - 1);
		cout << "   ";
		Cursor(x - 2, y);
		cout << "   ";
		Cursor(x - 2, y + 1);
		cout << "   ";

	}
	else if (rotation == LEFT)
	{

		Cursor(x, y - 1);
		cout << "   ";
		Cursor(x, y);
		cout << "   ";
		Cursor(x, y + 1);
		cout << "   ";

	}
	else if (rotation == DOWN)
	{

		Cursor(x - 1, y - 2);
		cout << "   ";
		Cursor(x - 1, y - 1);
		cout << "   ";
		Cursor(x - 1, y);
		cout << "   ";

	}
	else if (rotation == UP)
	{

		Cursor(x - 1, y);
		cout << "   ";
		Cursor(x - 1, y + 1);
		cout << "   ";
		Cursor(x - 1, y + 2);
		cout << "   ";
	}
	SetColor(White, 0);
}

void ArmorTank::downLive()
{
	if (live != 1)
	{
		live--;
	}
	if (live == 1)
	{
		Draw();
	}

}
#pragma endregion

#pragma region(SuperPowerTank)
SuperPowerTank::SuperPowerTank(int x, int y, int rotate) : Tank(x, y, rotate)
{
	speed = 2500;
	_type = TypeCreate::PLAYER;
	_color = Brown;
#ifdef FAST
	speed *= 2;
#endif 
}

int SuperPowerTank::GetSpeed()
{
	return speed;
}


bullet* SuperPowerTank::Shoot()
{
	if (rotation == RIGHT)
		return new HighBullet(x + 1, y, rotation);
	if (rotation == LEFT)
		return new HighBullet(x - 1, y, rotation);
	if (rotation == UP)
		return new HighBullet(x, y - 1, rotation);
	if (rotation == DOWN)
		return new HighBullet(x, y + 1, rotation);
}

bool SuperPowerTank::isPunchWall()
{
	return true;
}
void SuperPowerTank::Draw()
{
	SetColor(_color, 0);
	if (rotation == RIGHT)
	{
		ColorArmor();
		Cursor(x - 2, y - 1);
		cout << (char)219 << (char)219 << (char)219;
		Cursor(x - 2, y);
		cout << (char)219 << (char)219 << char(16);
		Cursor(x - 2, y + 1);
		cout << (char)219 << (char)219 << (char)219;

	}
	else if (rotation == LEFT)
	{
		ColorArmor();
		Cursor(x, y - 1);
		cout << (char)219 << (char)219 << (char)219;
		Cursor(x, y);
		cout << (char)17 << char(219) << (char)219;
		Cursor(x, y + 1);
		cout << (char)219 << (char)219 << (char)219;

	}
	else if (rotation == DOWN)
	{
		ColorArmor();
		Cursor(x - 1, y - 2);
		cout << (char)219 << (char)219 << (char)219;
		Cursor(x - 1, y - 1);
		cout << (char)219 << (char)219 << (char)219;
		Cursor(x - 1, y);
		cout << (char)219 << char(31) << (char)219;

	}
	else if (rotation == UP)
	{
		ColorArmor();
		Cursor(x - 1, y);
		cout << (char)219 << char(30) << (char)219;
		Cursor(x - 1, y + 1);
		cout << (char)219 << (char)219 << (char)219;
		Cursor(x - 1, y + 2);
		cout << (char)219 << (char)219 << (char)219;
	}
	SetColor(White, 0);
}

void SuperPowerTank::Erase()
{
	SetColor(0, 0);
	if (rotation == RIGHT)
	{

		Cursor(x - 2, y - 1);
		cout << "   ";
		Cursor(x - 2, y);
		cout << "   ";
		Cursor(x - 2, y + 1);
		cout << "   ";

	}
	else if (rotation == LEFT)
	{

		Cursor(x, y - 1);
		cout << "   ";
		Cursor(x, y);
		cout << "   ";
		Cursor(x, y + 1);
		cout << "   ";

	}
	else if (rotation == DOWN)
	{

		Cursor(x - 1, y - 2);
		cout << "   ";
		Cursor(x - 1, y - 1);
		cout << "   ";
		Cursor(x - 1, y);
		cout << "   ";

	}
	else if (rotation == UP)
	{

		Cursor(x - 1, y);
		cout << "   ";
		Cursor(x - 1, y + 1);
		cout << "   ";
		Cursor(x - 1, y + 2);
		cout << "   ";
	}
	SetColor(White, 0);
}
#pragma endregion

#pragma region(Player)

void Player::Spawn()
{
	pl = new EazyTank(TypeCreate::PLAYER);
}

void Player::Start()
{
	pl = new EazyTank(TypeCreate::PLAYER);
	live = 3;
	lvl = 1;
	BonusArm = 0;
}

void Player::Draw()
{
	pl->Draw();
}
void Player::Erase()
{
	pl->Erase();
}


void Player::GoToStart()
{
	pl->GoToStart();
}

int Player::getLvl()
{
	return lvl;
}
int Player::GetSpeed()
{
	return pl->GetSpeed();
}
int Player::GetX()
{
	return pl->getX();
}
int Player::GetY()
{
	return pl->getY();
}
int Player::GetRotate()
{
	return pl->getRotation();
}
bool Player::GetBonusArmor()
{
	return BonusArm;
}
int Player::GetLive()
{
	return live;
}

void Player::ArmorOn()
{
	pl->ArmorOn();
	BonusArm = 1;
}
void Player::ArmorOf()
{
	pl->ArmorOf();
	BonusArm = 0;
}

void Player::Destroy()
{
	live--;
	lvl = 1;
	BonusArm = 0;
	delete pl;
}

void Player::Turn(Rotation rot)
{

	pl->Turn(rot);

}

void Player::BonusLive()
{
	live++;
}



bool Player::isPunchWall()
{
	return pl->isPunchWall();
}

void Player::MoveLeft()
{
	pl->MoveLeft();
}
void Player::MoveUp()
{
	pl->MoveUp();
}
void Player::MoveRight()
{
	pl->MoveRight();
}
void Player::MoveDown()
{
	pl->MoveDown();
}



bullet* Player::Shoot()
{
	return pl->Shoot();
}

void Player::NextLvl()
{
	if (lvl != 4)
	{
		int x = pl->getX(), y = pl->getY(), rot = pl->getRotation();
		pl->Erase();
		delete pl;
		if (lvl == 1)
			pl = new ShooterTank(x, y, rot);
		else if (lvl == 2)
			pl = new DoubleShooterTank(x, y, rot);
		else if (lvl == 3)
			pl = new SuperPowerTank(x, y, rot);
		if (BonusArm)
			pl->ArmorOn();
		pl->Draw();
		lvl++;
	}

}

#pragma endregion