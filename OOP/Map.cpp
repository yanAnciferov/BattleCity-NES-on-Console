#pragma once
#include "Header.h"



#include "Block.h"
#include "Road.h"
#include "brick.h"
#include "Wall.h"
#include "Water.h"
#include "Forest.h"
#include "BlockFacility.h"
#include "Map.h"


#pragma region(Block)

Block::Block(int x, int y)
{
	_x = x;
	_y = y;
}

int Block::getColor()
{
	return _obj;
}

bool Block::isFacility()
{
	return false;
}

bool Block::isShelter()
{
	return false;
}

#pragma endregion

#pragma region(Brick)

Brick::Brick(int x, int y) : Block(x, y)
{
	_symbol = 176;
	_obj = DarkGray;
	_back = Red;
}

void Brick::print()
{
	Cursor(_x, _y);
	SetColor(_obj, _back);
	cout << _symbol;
}

void Brick::erase()
{
	Cursor(_x, _y);
	SetColor(Black, Black);
	cout << ' ';
}

bool Brick::isMoveTank()
{
	return false;
}

bool Brick::isMoveBullet()
{
	return false;
}

bool Brick::isHardArmor()
{
	return false;
}

#pragma endregion

#pragma region(Forest)

Forest::Forest(int x, int y) : Block(x, y)
{
	_symbol = 177;
	_back = Green;
	_obj = LightGreen;
}

bool Forest::isHardArmor()
{
	return false;
}
bool Forest::isShelter()
{
	return true;
}

void Forest::print()
{
	Cursor(_x, _y);
	SetColor(_obj, _back);
	cout << _symbol;
}

void Forest::erase()
{
	Cursor(_x, _y);
	SetColor(Black, Black);
	cout << ' ';
}

bool Forest::isMoveTank()
{
	return true;
}

bool Forest::isMoveBullet()
{
	return true;
}


#pragma endregion


#pragma region(Facility)

Facility::Facility(int x, int y) : Block(x, y)
{
	_symbol = ' ';
	_obj = Black;
	_back = Black;
}

void Facility::print()
{
	Cursor(_x, _y);
	SetColor(_obj, _back);
	cout << _symbol;
}

bool Facility::isFacility()
{
	return true;
}

void Facility::erase()
{
	Cursor(_x, _y);
	SetColor(Black, Black);
	cout << ' ';
}

bool Facility::isMoveTank()
{
	return false;
}

bool Facility::isMoveBullet()
{
	return false;
}

bool Facility::isHardArmor()
{
	return false;
}

#pragma endregion

#pragma region(Map)

Map::Map(char map[39][39])
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			switch (map[i][j])
			{
			case 'R':
				blocks[i][j] = new Road(j, i);
				break;
			case 'W':
				blocks[i][j] = new Wall(j, i);
				break;
			case 'S':
				blocks[i][j] = new Water(j, i);
				break;
			case 'B':
				blocks[i][j] = new Brick(j, i);
				break;
			default:
				break;
			}
		}
	}
}


void Map::create(char map[39][39])
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			switch (map[i][j])
			{
			case 'R':
				blocks[i][j] = new Road(j, i);
				break;
			case 'C':
				blocks[i][j] = new Facility(j, i);
				break;
			case 'W':
				blocks[i][j] = new Wall(j, i);
				break;
			case 'S':
				blocks[i][j] = new Water(j, i);
				break;
			case 'B':
				blocks[i][j] = new Brick(j, i);
				break;
			case 'F':
				blocks[i][j] = new Forest(j, i);
				break;
			default:
				break;
			}
		}
	}
}

void Map::print()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			blocks[i][j]->print();
		}
	}
}

Block* Map::operator() (int i, int j)
{
	if (i < 0 || j < 0 || j > 39 || j > 39)
	{
		return nullptr;
	}
	return blocks[j][i];
}

int Map::destroy(int y, int x, int rotation, bool isPunchWall)
{
	if (blocks[x][y]->isMoveBullet() == 1)
	{
		return 0;
	}
	if (blocks[x][y]->isMoveBullet() == 0 && (blocks[x][y]->isHardArmor() == 1 && isPunchWall == 1) || blocks[x][y]->isHardArmor() == 0)
	{
		if (blocks[x][y]->isFacility())
			return -1;
		delete blocks[x][y];
		blocks[x][y] = new Road(y, x);
		blocks[x][y]->print();
		if (rotation == UP || rotation == DOWN)
		{
			y--;
			if (blocks[x][y]->isMoveBullet() == 0 && (blocks[x][y]->isHardArmor() == 1 && isPunchWall == 1) || blocks[x][y]->isHardArmor() == 0)
			{
				if (blocks[x][y]->isFacility())
					return -1;
				if (!blocks[x][y]->isMoveBullet() && !blocks[x][y]->isMoveTank())
				{
					delete blocks[x][y];
					blocks[x][y] = new Road(y, x);
					blocks[x][y]->print();
				}
			}
			y += 2;
			if (blocks[x][y]->isMoveBullet() == 0 && (blocks[x][y]->isHardArmor() == 1 && isPunchWall == 1) || blocks[x][y]->isHardArmor() == 0)
			{
				if (blocks[x][y]->isFacility())
					return -1;
				if (!blocks[x][y]->isMoveBullet() && !blocks[x][y]->isMoveTank())
				{
					delete blocks[x][y];
					blocks[x][y] = new Road(y, x);
					blocks[x][y]->print();
				}
			}
		}
		else if (rotation == LEFT || rotation == RIGHT)
		{
			x--;
			if (blocks[x][y]->isMoveBullet() == 0 && (blocks[x][y]->isHardArmor() == 1 && isPunchWall == 1) || blocks[x][y]->isHardArmor() == 0)
			{
				if (blocks[x][y]->isFacility())
					return -1;
				if (!blocks[x][y]->isMoveBullet() && !blocks[x][y]->isMoveTank())
				{
					delete blocks[x][y];
					blocks[x][y] = new Road(y, x);
					blocks[x][y]->print();
				}
			}
			x += 2;
			if (blocks[x][y]->isMoveBullet() == 0 && (blocks[x][y]->isHardArmor() == 1 && isPunchWall == 1) || blocks[x][y]->isHardArmor() == 0)
			{
				if (blocks[x][y]->isFacility())
					return -1;
				if (!blocks[x][y]->isMoveBullet() && !blocks[x][y]->isMoveTank())
				{
					delete blocks[x][y];
					blocks[x][y] = new Road(y, x);
					blocks[x][y]->print();
				}
			}
		}
		return 1;
	}
}

void Map::onDefensBonus()
{
	for (int i = 34; i < 36; i++)
	{
		for (int j = 16; j < 23; j++)
		{
			delete blocks[i][j];
			blocks[i][j] = new Wall(j, i);
			blocks[i][j]->print();
		}
	}
	for (int i = 36; i < 39; i++)
	{
		for (int j = 16; j < 23; j++)
		{
			if (j != 20 && j != 18 && j != 19)
			{
				delete blocks[i][j];
				blocks[i][j] = new Wall(j, i);
				blocks[i][j]->print();
			}
		}
	}

}

void Map::printShelter()
{
	for (int i = 0; i < 39; i++)
	{
		for (int j = 0; j < 39; j++)
		{
			if (blocks[i][j]->isShelter())
			{
				blocks[i][j]->print();
			}
		}
	}
}

void Map::ofDefensBonus()
{
	for (int i = 34; i < 36; i++)
	{
		for (int j = 16; j < 23; j++)
		{
			delete blocks[i][j];
			blocks[i][j] = new Brick(j, i);
			blocks[i][j]->print();
		}
	}
	for (int i = 36; i < 39; i++)
	{
		for (int j = 16; j < 23; j++)
		{
			if (j != 20 && j != 18 && j != 19)
			{
				delete blocks[i][j];
				blocks[i][j] = new Brick(j, i);
				blocks[i][j]->print();
			}
		}
	}
}

#pragma endregion

#pragma region(Road)
Road::Road(int x, int y) : Block(x, y)
{
	_symbol = ' ';
	_back = Black;
	_obj = Black;
}

void Road::print()
{
	Cursor(_x, _y);
	SetColor(_obj, _back);
	cout << _symbol;
}

void Road::erase()
{
	Cursor(_x, _y);
	SetColor(_back, _back);
	cout << _symbol;
}

bool Road::isMoveTank()
{
	return true;
}

bool Road::isMoveBullet()
{
	return true;
}

bool Road::isHardArmor()
{
	return false;
}


#pragma endregion

#pragma region(Wall)

Wall::Wall(int x, int y) : Block(x, y)
{
	_symbol = 178;
	_back = White;
	_obj = LightGray;
}

bool Wall::isHardArmor()
{
	return true;
}

void Wall::print()
{
	Cursor(_x, _y);
	SetColor(_obj, _back);
	cout << _symbol;
}

void Wall::erase()
{
	Cursor(_x, _y);
	SetColor(Black, Black);
	cout << ' ';
}

bool Wall::isMoveTank()
{
	return false;
}

bool Wall::isMoveBullet()
{
	return false;
}

#pragma endregion

#pragma region(Water)
Water::Water(int x, int y) : Block(x, y)
{
	_symbol = 219;
	_back = Black;
	_obj = LightBlue;
}

void Water::print()
{
	Cursor(_x, _y);
	SetColor(_obj, _back);
	cout << _symbol;
}

void Water::erase()
{
	Cursor(_x, _y);
	SetColor(Black, Black);
	cout << ' ';
}

bool Water::isMoveTank()
{
	return false;
}

bool Water::isMoveBullet()
{
	return true;
}
bool Water::isHardArmor()
{
	return false;
}

#pragma endregion

#pragma region()


#pragma endregion