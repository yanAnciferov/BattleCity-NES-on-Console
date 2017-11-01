#pragma once
#include "Header.h"

int coord[2][9] =
{
	{ 0,0, 0,1, 1,1,-1,-1,-1 },
	{ 0,1,-1,0,-1,1,-1, 0,	1 }
};

class Collision
{
public:
#pragma region(Collision)
	static bool isNotGoAway(int x, int y)
	{
		if (x == 0 || y == 0 || x == 38 || y == 38)
		{
			return 1;
		}
		return 0;
	}
	static bool isNotGoAway(bullet* bl)
	{
		switch (bl->getRotation())
		{
		case UP:
			if (bl->getY() == 0)
				return 1;
		case DOWN:
			if (bl->getY() == 38)
				return 1;
		case RIGHT:
			if (bl->getX() == 38)
				return 1;
		case LEFT:
			if (bl->getX() == 0)
				return 1;
		default:
			break;
		}
		return 0;
	}

	static bool PlayerOnBlock(Map& map, Player& pl, Rotation rot)
	{
		switch (rot)
		{
		case UP:
			if (map(pl.GetX(), pl.GetY() - 1)->isMoveTank() == 1 && map(pl.GetX() - 1, pl.GetY() - 1)->isMoveTank() == 1 && map(pl.GetX() + 1, pl.GetY() - 1)->isMoveTank() == 1)
				return 1;
			return 0;
			break;
		case DOWN:
			if (map(pl.GetX(), pl.GetY() + 1)->isMoveTank() == 1 && map(pl.GetX() + 1, pl.GetY() + 1)->isMoveTank() == 1 && map(pl.GetX() - 1, pl.GetY() + 1)->isMoveTank() == 1)
				return 1;
			return 0;
			break;
		case RIGHT:
			if (map(pl.GetX() + 1, pl.GetY())->isMoveTank() == 1 && map(pl.GetX() + 1, pl.GetY() - 1)->isMoveTank() == 1 && map(pl.GetX() + 1, pl.GetY() + 1)->isMoveTank() == 1)
				return 1;
			return 0;
			break;
		case LEFT:
			if (map(pl.GetX() - 1, pl.GetY())->isMoveTank() == 1 && map(pl.GetX() - 1, pl.GetY() - 1)->isMoveTank() == 1 && map(pl.GetX() - 1, pl.GetY() + 1)->isMoveTank() == 1)
				return 1;
			return 0;
			break;
		default:
			break;
		}

	}

	static bool PlayerOnBonus(Player& _player, Bonus* _bonus)
	{

		if (_player.GetX() == _bonus->getX() && _player.GetY() == _bonus->getY())
		{
			return 1;
		}
		if (_player.GetRotate() == UP || _player.GetRotate() == DOWN)
		{
			if (_player.GetX() - 1 == _bonus->getX() && _player.GetY() == _bonus->getY() || _player.GetX() + 1 == _bonus->getX() && _player.GetY() == _bonus->getY())
			{
				return 1;
			}
		}
		if (_player.GetRotate() == LEFT || _player.GetRotate() == RIGHT)
		{
			if (_player.GetX() == _bonus->getX() && _player.GetY() - 1 == _bonus->getY() || _player.GetX() == _bonus->getX() && _player.GetY() + 1 == _bonus->getY())
			{
				return 1;
			}
		}
		return 0;
	}

	static bool BulletOnBlock(Map& map, bullet* pl)
	{
		switch (pl->getRotation())
		{
		case UP:
			if (map(pl->getX(), pl->getY() - 1)->isMoveBullet() == 1)
				return 1;
			return 0;
			break;
		case DOWN:
			if (map(pl->getX(), pl->getY() + 1)->isMoveBullet() == 1)
				return 1;
			return 0;
			break;
		case RIGHT:
			if (map(pl->getX() + 1, pl->getY())->isMoveBullet() == 1)
				return 1;
			return 0;
			break;
		case LEFT:
			if (map(pl->getX() - 1, pl->getY())->isMoveBullet() == 1)
				return 1;
			return 0;
			break;
		default:
			break;
		}

	}

	
	static bool enterTankOnTank(Tank* tank1, Tank* tank2)
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


		int t1_x, t1_y;
		if (tank1->getRotation() == UP)
		{

			t1_x = tank1->getX();
			t1_y = tank1->getY() - 1;
			if (t1_x == t2_x && t2_y == t1_y + 2)
				return 0;


			if ((tank1->getX() - 1 == t2_x + 1 || tank1->getX() - 1 == t2_x || tank1->getX() - 1 == t2_x - 1)
				&& (tank1->getY() - 1 == t2_y + 1 || tank1->getY() - 1 == t2_y || tank1->getY() - 1 == t2_y - 1))
			{
				return 1;
			}
			if ((tank1->getX() + 1 == t2_x + 1 || tank1->getX() + 1 == t2_x || tank1->getX() + 1 == t2_x - 1)
				&& (tank1->getY() - 1 == t2_y + 1 || tank1->getY() - 1 == t2_y || tank1->getY() - 1 == t2_y - 1))
			{
				return 1;
			}

		}
		else if (tank1->getRotation() == DOWN)
		{

			t1_x = tank1->getX();
			t1_y = tank1->getY() + 1;

			if (t1_x == t2_x && t2_y == t1_y - 2)
				return 0;

			if ((tank1->getX() - 1 == t2_x + 1 || tank1->getX() - 1 == t2_x || tank1->getX() - 1 == t2_x - 1)
				&& (tank1->getY() + 1 == t2_y + 1 || tank1->getY() + 1 == t2_y || tank1->getY() + 1 == t2_y - 1))
			{
				return 1;
			}
			if ((tank1->getX() + 1 == t2_x + 1 || tank1->getX() + 1 == t2_x || tank1->getX() + 1 == t2_x - 1)
				&& (tank1->getY() + 1 == t2_y + 1 || tank1->getY() + 1 == t2_y || tank1->getY() + 1 == t2_y - 1))
			{
				return 1;
			}

		}
		else if (tank1->getRotation() == RIGHT)
		{

			t1_x = tank1->getX() + 1;
			t1_y = tank1->getY();

			if (t1_x - 2 == t2_x && t2_y == t1_y)
				return 0;

			if ((tank1->getX() + 1 == t2_x + 1 || tank1->getX() + 1 == t2_x || tank1->getX() + 1 == t2_x - 1)
				&& (tank1->getY() - 1 == t2_y + 1 || tank1->getY() - 1 == t2_y || tank1->getY() - 1 == t2_y - 1))
			{
				return 1;
			}
			if ((tank1->getX() + 1 == t2_x + 1 || tank1->getX() + 1 == t2_x || tank1->getX() + 1 == t2_x - 1)
				&& (tank1->getY() + 1 == t2_y + 1 || tank1->getY() + 1 == t2_y || tank1->getY() + 1 == t2_y - 1))
			{
				return 1;
			}

		}
		else if (tank1->getRotation() == LEFT)
		{

			t1_x = tank1->getX() - 1;
			t1_y = tank1->getY();

			if (t1_x + 2 == t2_x && t2_y == t1_y)
				return 0;

			if ((tank1->getX() - 1 == t2_x + 1 || tank1->getX() - 1 == t2_x || tank1->getX() - 1 == t2_x - 1)
				&& (tank1->getY() - 1 == t2_y + 1 || tank1->getY() - 1 == t2_y || tank1->getY() - 1 == t2_y - 1))
			{
				return 1;
			}
			if ((tank1->getX() - 1 == t2_x + 1 || tank1->getX() - 1 == t2_x || tank1->getX() - 1 == t2_x - 1)
				&& (tank1->getY() + 1 == t2_y + 1 || tank1->getY() + 1 == t2_y || tank1->getY() + 1 == t2_y - 1))
			{
				return 1;
			}

		}



		if ((tank1->getX() == t2_x + 1 || tank1->getX() == t2_x || tank1->getX() == t2_x - 1)
			&& (tank1->getY() == t2_y + 1 || tank1->getY() == t2_y || tank1->getY() == t2_y - 1))
		{
			return 1;
		}


		return 0;
	}

	static bool enterTankOnArrTank(Tank* tank1, int index, Array<Tank*>& tanks)
	{
		for (int i = 0; i < tanks.getCount(); i++)
		{
			if (i == index)
				continue;
			if (enterTankOnTank(tank1, tanks[i]) == 1)
			{
				return 1;
			}
		}
	}

	static bool enterBulletOnPlayer(bullet* bul, Player& tank2)
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


		if ((bul->getX() == t2_x + 1 || bul->getX() == t2_x || bul->getX() == t2_x - 1) && (bul->getY() == t2_y + 1 || bul->getY() == t2_y || bul->getY() == t2_y - 1))
		{
			return 1;
		}
		return 0;
	}






	static bool enterPlayerOnTank(Player& tank1, Tank* tank2)
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


		int t1_x, t1_y;
		if (tank1.GetRotate() == UP)
		{

			t1_x = tank1.GetX();
			t1_y = tank1.GetY() - 1;


			if (t1_x == t2_x && t2_y == t1_y + 2)
				return 0;


			if ((tank1.GetX() - 1 == t2_x + 1 || tank1.GetX() - 1 == t2_x || tank1.GetX() - 1 == t2_x - 1)
				&& (tank1.GetY() - 1 == t2_y + 1 || tank1.GetY() - 1 == t2_y || tank1.GetY() - 1 == t2_y - 1))
			{
				return 1;
			}
			if ((tank1.GetX() + 1 == t2_x + 1 || tank1.GetX() + 1 == t2_x || tank1.GetX() + 1 == t2_x - 1)
				&& (tank1.GetY() - 1 == t2_y + 1 || tank1.GetY() - 1 == t2_y || tank1.GetY() - 1 == t2_y - 1))
			{
				return 1;
			}

		}
		else if (tank1.GetRotate() == DOWN)
		{

			t1_x = tank1.GetX();
			t1_y = tank1.GetY() + 1;

			if (t1_x == t2_x && t2_y == t1_y - 2)
				return 0;

			if ((tank1.GetX() - 1 == t2_x + 1 || tank1.GetX() - 1 == t2_x || tank1.GetX() - 1 == t2_x - 1)
				&& (tank1.GetY() + 1 == t2_y + 1 || tank1.GetY() + 1 == t2_y || tank1.GetY() + 1 == t2_y - 1))
			{
				return 1;
			}
			if ((tank1.GetX() + 1 == t2_x + 1 || tank1.GetX() + 1 == t2_x || tank1.GetX() + 1 == t2_x - 1)
				&& (tank1.GetY() + 1 == t2_y + 1 || tank1.GetY() + 1 == t2_y || tank1.GetY() + 1 == t2_y - 1))
			{
				return 1;
			}

		}
		else if (tank1.GetRotate() == RIGHT)
		{

			t1_x = tank1.GetX() + 1;
			t1_y = tank1.GetY();

			if (t1_x - 2 == t2_x && t2_y == t1_y)
				return 0;

			if ((tank1.GetX() + 1 == t2_x + 1 || tank1.GetX() + 1 == t2_x || tank1.GetX() + 1 == t2_x - 1)
				&& (tank1.GetY() - 1 == t2_y + 1 || tank1.GetY() - 1 == t2_y || tank1.GetY() - 1 == t2_y - 1))
			{
				return 1;
			}
			if ((tank1.GetX() + 1 == t2_x + 1 || tank1.GetX() + 1 == t2_x || tank1.GetX() + 1 == t2_x - 1)
				&& (tank1.GetY() + 1 == t2_y + 1 || tank1.GetY() + 1 == t2_y || tank1.GetY() + 1 == t2_y - 1))
			{
				return 1;
			}

		}
		else if (tank1.GetRotate() == LEFT)
		{

			t1_x = tank1.GetX() - 1;
			t1_y = tank1.GetY();

			if (t1_x + 2 == t2_x && t2_y == t1_y)
				return 0;

			if ((tank1.GetX() - 1 == t2_x + 1 || tank1.GetX() - 1 == t2_x || tank1.GetX() - 1 == t2_x - 1)
				&& (tank1.GetY() - 1 == t2_y + 1 || tank1.GetY() - 1 == t2_y || tank1.GetY() - 1 == t2_y - 1))
			{
				return 1;
			}
			if ((tank1.GetX() - 1 == t2_x + 1 || tank1.GetX() - 1 == t2_x || tank1.GetX() - 1 == t2_x - 1)
				&& (tank1.GetY() + 1 == t2_y + 1 || tank1.GetY() + 1 == t2_y || tank1.GetY() + 1 == t2_y - 1))
			{
				return 1;
			}

		}



		if ((tank1.GetX() == t2_x + 1 || tank1.GetX() == t2_x || tank1.GetX() == t2_x - 1)
			&& (tank1.GetY() == t2_y + 1 || tank1.GetY() == t2_y || tank1.GetY() == t2_y - 1))
		{
			return 1;
		}


		return 0;
	}


	static bool enterTankOnPlayer(Tank* tank1, Player& tank2)
	{

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


			int t1_x, t1_y;
			if (tank1->getRotation() == UP)
			{

				t1_x = tank1->getX();
				t1_y = tank1->getY() - 1;

				if (t1_x == t2_x && t2_y == t1_y + 2)
					return 0;

				if ((tank1->getX() - 1 == t2_x + 1 || tank1->getX() - 1 == t2_x || tank1->getX() - 1 == t2_x - 1)
					&& (tank1->getY() - 1 == t2_y + 1 || tank1->getY() - 1 == t2_y || tank1->getY() - 1 == t2_y - 1))
				{
					return 1;
				}
				if ((tank1->getX() + 1 == t2_x + 1 || tank1->getX() + 1 == t2_x || tank1->getX() + 1 == t2_x - 1)
					&& (tank1->getY() - 1 == t2_y + 1 || tank1->getY() - 1 == t2_y || tank1->getY() - 1 == t2_y - 1))
				{
					return 1;
				}

			}
			else if (tank1->getRotation() == DOWN)
			{

				t1_x = tank1->getX();
				t1_y = tank1->getY() + 1;

				if (t1_x == t2_x && t2_y == t1_y - 2)
					return 0;

				if ((tank1->getX() - 1 == t2_x + 1 || tank1->getX() - 1 == t2_x || tank1->getX() - 1 == t2_x - 1)
					&& (tank1->getY() + 1 == t2_y + 1 || tank1->getY() + 1 == t2_y || tank1->getY() + 1 == t2_y - 1))
				{
					return 1;
				}
				if ((tank1->getX() + 1 == t2_x + 1 || tank1->getX() + 1 == t2_x || tank1->getX() + 1 == t2_x - 1)
					&& (tank1->getY() + 1 == t2_y + 1 || tank1->getY() + 1 == t2_y || tank1->getY() + 1 == t2_y - 1))
				{
					return 1;
				}

			}
			else if (tank1->getRotation() == RIGHT)
			{

				t1_x = tank1->getX() + 1;
				t1_y = tank1->getY();

				if (t1_x - 2 == t2_x && t2_y == t1_y)
					return 0;

				if ((tank1->getX() + 1 == t2_x + 1 || tank1->getX() + 1 == t2_x || tank1->getX() + 1 == t2_x - 1)
					&& (tank1->getY() - 1 == t2_y + 1 || tank1->getY() - 1 == t2_y || tank1->getY() - 1 == t2_y - 1))
				{
					return 1;
				}
				if ((tank1->getX() + 1 == t2_x + 1 || tank1->getX() + 1 == t2_x || tank1->getX() + 1 == t2_x - 1)
					&& (tank1->getY() + 1 == t2_y + 1 || tank1->getY() + 1 == t2_y || tank1->getY() + 1 == t2_y - 1))
				{
					return 1;
				}

			}
			else if (tank1->getRotation() == LEFT)
			{

				t1_x = tank1->getX() - 1;
				t1_y = tank1->getY();

				if (t1_x + 2 == t2_x && t2_y == t1_y)
					return 0;

				if ((tank1->getX() - 1 == t2_x + 1 || tank1->getX() - 1 == t2_x || tank1->getX() - 1 == t2_x - 1)
					&& (tank1->getY() - 1 == t2_y + 1 || tank1->getY() - 1 == t2_y || tank1->getY() - 1 == t2_y - 1))
				{
					return 1;
				}
				if ((tank1->getX() - 1 == t2_x + 1 || tank1->getX() - 1 == t2_x || tank1->getX() - 1 == t2_x - 1)
					&& (tank1->getY() + 1 == t2_y + 1 || tank1->getY() + 1 == t2_y || tank1->getY() + 1 == t2_y - 1))
				{
					return 1;
				}

			}



			if ((tank1->getX() == t2_x + 1 || tank1->getX() == t2_x || tank1->getX() == t2_x - 1)
				&& (tank1->getY() == t2_y + 1 || tank1->getY() == t2_y || tank1->getY() == t2_y - 1))
			{
				return 1;
			}


			return 0;
		}
	}

	static bool enterPlayerOnEnemyes(Player tank1, Array<Tank*>& enemy)
	{
		for (int i = 0; i < enemy.getCount(); i++)
		{
			if (enterPlayerOnTank(tank1, enemy[i]) == 1)
			{
				return 1;
			}
		}
		return 0;
	}

	static bool TankOnBlock(Map& map, Tank* pl)
	{
		switch (pl->getRotation())
		{
		case UP:
			if (map(pl->getX(), pl->getY() - 1)->isMoveTank() == 1 && map(pl->getX() - 1, pl->getY() - 1)->isMoveTank() == 1 && map(pl->getX() + 1, pl->getY() - 1)->isMoveTank() == 1)
				return 1;
			return 0;
			break;
		case DOWN:
			if (map(pl->getX(), pl->getY() + 1)->isMoveTank() == 1 && map(pl->getX() + 1, pl->getY() + 1)->isMoveTank() == 1 && map(pl->getX() - 1, pl->getY() + 1)->isMoveTank() == 1)
				return 1;
			return 0;
			break;
		case RIGHT:
			if (map(pl->getX() + 1, pl->getY())->isMoveTank() == 1 && map(pl->getX() + 1, pl->getY() - 1)->isMoveTank() == 1 && map(pl->getX() + 1, pl->getY() + 1)->isMoveTank() == 1)
				return 1;
			return 0;
			break;
		case LEFT:
			if (map(pl->getX() - 1, pl->getY())->isMoveTank() == 1 && map(pl->getX() - 1, pl->getY() - 1)->isMoveTank() == 1 && map(pl->getX() - 1, pl->getY() + 1)->isMoveTank() == 1)
				return 1;
			return 0;
			break;
		default:
			break;
		}

	}

	static bool TankGoAway(Tank* _enemy)
	{
		if (_enemy->getRotation() == UP && _enemy->getY() == 0)
			return 0;
		if (_enemy->getRotation() == DOWN && _enemy->getY() == 38)
			return 0;
		if (_enemy->getRotation() == LEFT && _enemy->getX() == 0)
			return 0;
		if (_enemy->getRotation() == RIGHT && _enemy->getX() == 38)
			return 0;

		return 1;
	}

	static bool enterBulletOnTank(bullet* bul, Tank* enemy)
	{

		int x, y;
		if (enemy->getRotation() == UP)
		{
			x = enemy->getX();
			y = enemy->getY() + 1;
		}
		else if (enemy->getRotation() == DOWN)
		{
			x = enemy->getX();
			y = enemy->getY() - 1;
		}
		else if (enemy->getRotation() == RIGHT)
		{
			x = enemy->getX() - 1;
			y = enemy->getY();
		}
		else if (enemy->getRotation() == LEFT)
		{
			x = enemy->getX() + 1;
			y = enemy->getY();
		}


		if ((bul->getX() == x + 1 || bul->getX() == x || bul->getX() == x - 1) && (bul->getY() == y + 1 || bul->getY() == y || bul->getY() == y - 1))
		{
			return 1;
		}
		return 0;
	}

	static int indexTankDestroy(bullet* bul, Array<Tank*>& enemy)
	{
		for (int i = 0; i < enemy.getCount(); i++)
		{
			if (enterBulletOnTank(bul, enemy[i]) == 1)
			{
				return i;
			}
		}
		return -1;
	}
#pragma endregion 

	static bool destroyFacility(bullet* bl)
	{
		int x = 19;
		int y = 37;

		for (int i = 1; i < 9; i++)
		{
			if (bl->getX() == x + coord[0][i] && bl->getY() == y + coord[1][i])
			{
				return 1;
			}
		}
		return 0;

	}

	static bool enterBulletOnBullet(bullet* bul, bullet* bul1)
	{

		return bul->getX() == bul1->getX() && bul->getY() == bul1->getY();
	}

	static int indexBulletOnArrBull(bullet* bul, Array<bullet*>& arr)
	{
		for (int i = 0; i < arr.getCount(); i++)
		{
			if (enterBulletOnBullet(bul, arr[i]))
				return i;
		}
		return -1;
	}

	static int indexArrBulletOnTank(Player& pl, Array<bullet*>& bl)
	{
		for (int i = 0; i < bl.getCount(); i++)
		{
			if (enterBulletOnPlayer(bl[i], pl))
				return i;
		}
		return -1;
	}

	static int indexBulletOnArrBull(Array<bullet*> ar, int index)
	{
		for (size_t i = 0; i < ar.getCount(); i++)
		{
			if (i == index)
			{
				i++;
			}
			else if (enterBulletOnBullet(ar[i], ar[index]))
				return i;
		}
		

		return -1;
	}

};