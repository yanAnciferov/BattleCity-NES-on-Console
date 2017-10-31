#pragma once
#include "Header.h"

class HighBullet : public bullet
{


public:

	HighBullet(int x, int y, int rotate, Tank* t);

	HighBullet(int x, int y, int rotate);

	

	bool IsPunchWall();



};