#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>

using namespace std;

#define FAST


enum class TypeCreate
{
	LEFT,
	MID,
	RIGHT,
	PLAYER
};

enum Color {
	Black,
	Blue,
	Green,
	Cyan,
	Red,
	Magenta,
	Brown,
	LightGray,
	DarkGray,
	LightBlue,
	LightGreen,
	LightCyan,
	LightRed,
	LightMagenta,
	Yellow,
	White
};
enum Rotation
{
	UP,
	DOWN,
	RIGHT,
	LEFT
};

enum Graphics
{
	BLOK = 219
};

enum Keys {
	RIGHTKEY = 77,
	LEFTKEY = 75,
	UPKEY = 72,
	DOWNKEY = 80
};

void set_cursor_visible(bool visible);

void Cursor(int x, int y);


void SetColor(int text, int background);








//#include "Bullet.h"
//#include "LowBullet.h"
//#include "MidleBullet.h"
//#include "HighBullet.h"
//
//
//#include "Frame.h"
//#include "ClassTank.h"
//#include "EazyTank.h"
//#include "ShooterTank.h"
//#include "DoubleShooterTank.h"
//#include "SuperPowerTank.h"
//#include "SpeedTank.h"
//#include "ArmorTank.h"
//
//#include "Array.h"
//
//#include "Block.h"
//#include "Road.h"
//#include "brick.h"
//#include "Wall.h"
//#include "Water.h"
//#include "Forest.h"
//#include "BlockFacility.h"
//#include "Map.h"
//#include "Facility.h"
//
//
//#include "Player.h"
//
//#include "Bonus.h"
//
//#include "Collision.h"
//
//
//#include "Print.h"
//
//#include "Game.h"
