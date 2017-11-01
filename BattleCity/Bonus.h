#pragma once
#include "Header.h"


enum BonusType
{
	TIME,
	LVLUP,
	ARMOR,
	DEFENS,
	LIVE,
	KILLING

};


class Bonus
{


	
	BonusType _type;
	int _x;
	int _y;
	
	

public:

	Bonus(int x, int y)
	{
		_x = x;
		_y = y;
		srand(time(0));
		int tmp = rand() % 8;
		switch (tmp)
		{
		case 0:
		case 1: _type = LVLUP;
			break;
		case 2: _type = ARMOR;
			break;
		case 3: _type = DEFENS;
			break;
		case 4: _type = KILLING;
			break;
		case 5: _type = TIME;
			break;
		default:
			_type = LIVE;
			break;
		}
	}

	void print()
	{
		SetColor(White, 0);
		switch (_type)
		{
		case TIME:
			Cursor(_x,_y);
			cout << "T";
			break;
		case LVLUP:
			Cursor(_x, _y);
			cout << char(24);
			break;
		case ARMOR:
			Cursor(_x, _y);
			cout << "A";
			break;
		case DEFENS:
			Cursor(_x, _y);
			cout << char(4);
			break;
		case LIVE:
			Cursor(_x, _y);
			cout << char(3);
			break;
		case KILLING:
			Cursor(_x, _y);
			cout << "*";
			break;
		default:
			break;
		}
	}

	~Bonus()
	{
		Cursor(_x, _y);
		cout << " ";
	}

	int getX()
	{
		return _x;
	}
	BonusType getBonusType()
	{
		return _type;
	}
	int getY()
	{
		return _y;
	}

};

