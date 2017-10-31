#pragma once
#include "Header.h"


class Print
{
public:
	static void facilityPrint()
	{
		SetColor(White, 0);
		Cursor(18, 36);
		cout << char(201) << char(209) << char(187);
		Cursor(18, 37);
		cout << char(199);
		SetColor(Red, White);
		cout << char(3);
		SetColor(White, 0);
		cout << char(182);
		Cursor(18, 38);
		cout << char(200) << char(207) << char(188);
	}

	static void facilityPrintD()
	{
		SetColor(White, 0);
		Cursor(18, 36);
		cout << char(211) << char(208) << char(187);
		Cursor(18, 37);
		cout << char(199);
		SetColor(Red, White);
		cout << char(35);
		SetColor(White, 0);
		cout << char(216);
		Cursor(18, 38);
		cout << char(218) << char(207) << char(188);
	}

	static void printTank(Tank* tank2,Map& map)
	{
		int t2_x, t2_y;
		if (tank2->getRotation() == UP)
		{
			t2_x = tank2->getX();
			t2_y = tank2->getY() + 1;
		}
		else if (tank2->getRotation() == DOWN)
		{
			t2_x = tank2->getX();
			t2_y = tank2->getY() - 1;
		}
		else if (tank2->getRotation() == RIGHT)
		{
			t2_x = tank2->getX() - 1;
			t2_y = tank2->getY();
		}
		else if (tank2->getRotation() == LEFT)
		{
			t2_x = tank2->getX() + 1;
			t2_y = tank2->getY();
		}

		tank2->Draw();

		for (int i = 0; i < 9; i++)
		{
			if (map(t2_x + coord[0][i], t2_y + coord[1][i])->isShelter())
			{
				map(t2_x + coord[0][i], t2_y + coord[1][i])->print();
			}
		}

	}
	static void eraseTank(Tank* tank2,Map& map)
	{
		int t2_x, t2_y;
		if (tank2->getRotation() == UP)
		{
			t2_x = tank2->getX();
			t2_y = tank2->getY() + 1;
		}
		else if (tank2->getRotation() == DOWN)
		{
			t2_x = tank2->getX();
			t2_y = tank2->getY() - 1;
		}
		else if (tank2->getRotation() == RIGHT)
		{
			t2_x = tank2->getX() - 1;
			t2_y = tank2->getY();
		}
		else if (tank2->getRotation() == LEFT)
		{
			t2_x = tank2->getX() + 1;
			t2_y = tank2->getY();
		}

		tank2->Erase();

		for (int i = 0; i < 9; i++)
		{
			if (map(t2_x + coord[0][i], t2_y + coord[1][i])->isShelter())
			{
				map(t2_x + coord[0][i], t2_y + coord[1][i])->print();
			}
		}

	}


	static void printPlayer(Player& tank2, Map& map)
	{
		int t2_x, t2_y;
		if (tank2.GetRotate() == UP)
		{
			t2_x = tank2.GetX();
			t2_y = tank2.GetY() + 1;
		}
		else if (tank2.GetRotate() == DOWN)
		{
			t2_x = tank2.GetX();
			t2_y = tank2.GetY() - 1;
		}
		else if (tank2.GetRotate() == RIGHT)
		{
			t2_x = tank2.GetX() - 1;
			t2_y = tank2.GetY();
		}
		else if (tank2.GetRotate() == LEFT)
		{
			t2_x = tank2.GetX() + 1;
			t2_y = tank2.GetY();
		}

		tank2.Draw();

		for (int i = 0; i < 9; i++)
		{
			if (map(t2_x + coord[0][i], t2_y + coord[1][i])->isShelter())
			{
				map(t2_x + coord[0][i], t2_y + coord[1][i])->print();
			}
		}

	}
	static void erasePlayer(Player& tank2, Map& map)
	{
		int t2_x, t2_y;
		if (tank2.GetRotate() == UP)
		{
			t2_x = tank2.GetX();
			t2_y = tank2.GetY() + 1;
		}
		else if (tank2.GetRotate() == DOWN)
		{
			t2_x = tank2.GetX();
			t2_y = tank2.GetY() - 1;
		}
		else if (tank2.GetRotate() == RIGHT)
		{
			t2_x = tank2.GetX() - 1;
			t2_y = tank2.GetY();
		}
		else if (tank2.GetRotate() == LEFT)
		{
			t2_x = tank2.GetX() + 1;
			t2_y = tank2.GetY();
		}


		tank2.Erase();

		for (int i = 0; i < 9; i++)
		{
			if (map(t2_x + coord[0][i], t2_y + coord[1][i])->isShelter())
			{
				map(t2_x + coord[0][i], t2_y + coord[1][i])->print();
			}
		}

	}
};