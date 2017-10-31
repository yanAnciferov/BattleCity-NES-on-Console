#pragma once
#include "Header.h"

#include "HeaderClass.h"

class Game
{
	int key;
	int tiks = 0;
	int BonusDefens = 0;
	int BonusTime = 0;
	int BonusArmor = 0;
	int enemyLive = 20;
	int startArm = 0;
	Bonus* _bonus;
	Array<Tank*> _enemy;
	Array<bullet*> _enemyBul;
	Array<bullet*> _playerBul;
	Map _map;
	Map _construction;
	TypeCreate spawnPosition = TypeCreate::MID;
	Player _player;

	void createBonus()
	{
		if (_bonus != nullptr)
			_bonus->~Bonus();

		int x = rand() % 38, y = rand() % 38;
		while (1)
		{
			x = rand() % 38, y = rand() % 38;
			if (_map(x, y)->isMoveTank() == 1 && _map(x, y)->isShelter() == 0)
				break;
		}
		_bonus = new Bonus(x, y);
		_bonus->print();
	}

	void printMenu()
	{
		system("cls");
		system("color 00");
		_map.create(main_menu);
		_map.print();
		SetColor(White, 0);
		Cursor(17, 26);
		cout << "New game";
		Cursor(17, 29);
		cout << "Constuction";
		Cursor(17, 32);
		cout << "Exit";
	}

	void menu()
	{
		printMenu();
		Tank* cursor = new EazyTank(15, 26, RIGHT);
		cursor->Draw();
		while (1)
		{
			key = _getch();
			if (key == UPKEY && cursor->getY() != 26)
			{
				cursor->Erase();
				for (size_t i = 0; i < 4; i++)
					cursor->MoveUp();
				cursor->Turn(RIGHT);
				cursor->Draw();
			}
			else if (key == DOWNKEY && cursor->getY() != 32)
			{
				cursor->Erase();
				for (size_t i = 0; i < 4; i++)
					cursor->MoveDown();
				cursor->Turn(RIGHT);
				cursor->Draw();
			}
			else if (key == 13)
			{
				if (cursor->getY() == 26)
				{
					game();
					key = 0;
					printMenu();
					cursor->Draw();
				}
				else if (cursor->getY() == 32)
				{
					system("cls");
					return;
				}
				else if (cursor->getY() == 29)
				{
					system("color 80");
					system("cls");
					_construction.constructionMode();
					SetColor(0, 0);
					system("cls");
					printMenu();
					cursor->Draw();
				}


			}

		}
	}

	void nextStep()
	{


#ifdef FAST
		if (startArm != 0 && tiks == startArm && BonusArmor == 0)
		{
			_player.ArmorOf();
			startArm = 0;
		}

		if (BonusDefens != 0)
			BonusDefens += (3500 / 2);
		if (BonusTime != 0)
			BonusTime += (8000 / 2);
		if (BonusArmor != 0)
			BonusArmor += (5000 / 2);

		if (BonusDefens < 0)
		{
			_map.ofDefensBonus();
			BonusDefens = 0;
		}
		if (BonusArmor < 0)
		{
			_player.ArmorOf();
			BonusArmor = 0;
		}
		if (BonusTime < 0)
		{
			BonusTime = 0;
		}
#else

		if (startArm != 0 && tiks == startArm && BonusArmor == 0)
		{
			_player.ArmorOf();
			startArm = 0;
		}

		if (BonusDefens != 0)
			BonusDefens += 3500;
		if (BonusTime != 0)
			BonusTime += 8000;
		if (BonusArmor != 0)
			BonusArmor += 5000;

		if (BonusDefens < 0)
		{
			_map.ofDefensBonus();
			BonusDefens = 0;
		}
		if (BonusArmor < 0)
		{
			_player.ArmorOf();
			BonusArmor = 0;
		}
		if (BonusTime < 0)
		{
			BonusTime = 0;
		}
#endif 

	}

	void playerBonusUpdate()
	{
		if (_bonus != nullptr && Collision::PlayerOnBonus(_player, _bonus) == 1)
		{
			bool tmp = 0;
			switch (_bonus->getBonusType())
			{

			case DEFENS:
				_map.onDefensBonus();
				BonusDefens = 1;
				break;
			case LIVE:
				_player.BonusLive();
				printInterface();
				break;
			case ARMOR:
				_player.ArmorOn();
				BonusArmor = 1;
				break;
			case KILLING:
			{

				int tmp = _enemy.getCount();
				for (int i = 0; i < tmp; i++)
				{
					Print::eraseTank(_enemy[i], _map);
					if (_enemy[i]->isBonusTank())
						tmp = 1;
				}
				for (int i = 0; i < tmp; i++)
				{
					_enemy.removeOnIndex(0);
				}
			}
			break;
			case LVLUP:
				_player.NextLvl();
				break;
			case TIME:
				BonusTime = 1;
				break;
			default:
				break;
			}


			_bonus->~Bonus();
			_bonus = nullptr;
			if (tmp == 1)
				createBonus();
			Print::printPlayer(_player, _map);
		}
	}
	void playerUpdate()
	{

		if (tiks % _player.GetSpeed() == 0)
		{
			if (key)
			{
				Print::erasePlayer(_player, _map);
				switch (key)
				{
				case RIGHTKEY:
					if (_player.GetRotate() != RIGHT)
						_player.Turn(RIGHT);
					else if (_player.GetX() + 1 != 39 && Collision::PlayerOnBlock(_map, _player, RIGHT) && Collision::enterPlayerOnEnemyes(_player, _enemy) == 0)
						_player.MoveRight();
					break;
				case LEFTKEY:
					if (_player.GetRotate() != LEFT)
						_player.Turn(LEFT);
					else if (_player.GetX() - 1 >= 0 && Collision::PlayerOnBlock(_map, _player, LEFT) && Collision::enterPlayerOnEnemyes(_player, _enemy) == 0)
						_player.MoveLeft();
					break;
				case DOWNKEY:
					if (_player.GetRotate() != DOWN)
						_player.Turn(DOWN);
					else if (_player.GetY() + 1 != 39 && Collision::PlayerOnBlock(_map, _player, DOWN) && Collision::enterPlayerOnEnemyes(_player, _enemy) == 0)
						_player.MoveDown();
					break;
				case UPKEY:
					if (_player.GetRotate() != UP)
						_player.Turn(UP);
					else if (_player.GetY() - 1 >= 0 && Collision::PlayerOnBlock(_map, _player, UP) && Collision::enterPlayerOnEnemyes(_player, _enemy) == 0)
						_player.MoveUp();
					break;

				case ' ':
					_player.Turn((Rotation)_player.GetRotate());
					if (_playerBul.getCount() == 0 || _player.getLvl() > 2 && _playerBul.getCount() == 1)
					{
						if (_player.GetRotate() == UP)
						{
							if (_player.GetY() > 1)
								if (_map.destroy(_player.GetX(), _player.GetY() - 1, _player.GetRotate(), _player.isPunchWall()) == 0)
									_playerBul.add(_player.Shoot());

						}
						else if (_player.GetRotate() == DOWN)
						{

							if (_player.GetY() < 38)
								if (_map.destroy(_player.GetX(), _player.GetY() + 1, _player.GetRotate(), _player.isPunchWall()) == 0)
									_playerBul.add(_player.Shoot());
						}
						else if (_player.GetRotate() == LEFT)
						{
							if (_player.GetX() - 1 > 1)
								if (_map.destroy(_player.GetX() - 1, _player.GetY(), _player.GetRotate(), _player.isPunchWall()) == 0)
									_playerBul.add(_player.Shoot());
						}
						else if (_player.GetRotate() == RIGHT)
						{
							if (_player.GetX() + 1 < 38)
								if (_map.destroy(_player.GetX() + 1, _player.GetY(), _player.GetRotate(), _player.isPunchWall()) == 0)
									_playerBul.add(_player.Shoot());
						}


					}
					break;
				default:
					break;
				}
				Print::printPlayer(_player, _map);
				key = 0;
			}
		}

		playerBonusUpdate();
	}
	bool playerBulletsUpdate()
	{
		if (_playerBul.getCount() > 0)
		{

			for (int i = 0; i < _playerBul.getCount(); i++)
			{
				if (tiks % _playerBul[i]->GetSpeed() == 0)
				{
					if (_map(_playerBul[i]->getX(), _playerBul[i]->getY())->getColor() != LightGreen)
						_playerBul[i]->erase((Color)_map(_playerBul[i]->getX(), _playerBul[i]->getY())->getColor());

					if (Collision::isNotGoAway(_playerBul[i]) == 1)
					{

						_playerBul[i]->destroy();
						_playerBul.removeOnIndex(i);
						continue;
					}
					if (Collision::BulletOnBlock(_map, _playerBul[i]) == 1)
					{

						_playerBul[i]->go();
						/*if (Collision::destroyFacility(_playerBul[i]))
						{
							_playerBul[i]->erase();
							_playerBul.removeOnIndex(i);
							fac.printD();
							return 0;
						}*/
						int tmp = Collision::indexTankDestroy(_playerBul[i], _enemy);
						if (tmp >= 0)
						{
							if (_enemy[tmp]->isBonusTank())
							{
								createBonus();
								_enemy[tmp]->ofBonus();
							}
							_playerBul[i]->destroy();
							_playerBul.removeOnIndex(i);
							if (_enemy[tmp]->getLive() == 1)
							{
								Print::eraseTank(_enemy[tmp], _map);
								_enemy[tmp]->destroy();
								_enemy.removeOnIndex(tmp);
							}
							else
							{
								_enemy[tmp]->downLive();
							}

							continue;
						}

						tmp = Collision::indexBulletOnArrBull(_playerBul[i], _enemyBul);
						if (tmp >= 0)
						{
							if (_map(_playerBul[i]->getX(), _playerBul[i]->getY())->getColor() != LightGreen)
								_playerBul[i]->erase((Color)_map(_playerBul[i]->getX(), _playerBul[i]->getY())->getColor());
							_playerBul[i]->destroy();
							_playerBul.removeOnIndex(i);
							_enemyBul[tmp]->destroy();
							_enemyBul.removeOnIndex(tmp);

							continue;
						}

						if (_map(_playerBul[i]->getX(), _playerBul[i]->getY())->getColor() != LightGreen)
							_playerBul[i]->print((Color)_map(_playerBul[i]->getX(), _playerBul[i]->getY())->getColor());



						if (_bonus != nullptr && _bonus->getX() == _playerBul[i]->getX() && _bonus->getY() == _playerBul[i]->getY())
							_bonus->print();

					}
					else
					{
						_playerBul[i]->go();
						if (_map.destroy(_playerBul[i]->getX(), _playerBul[i]->getY(), _playerBul[i]->getRotation(), _playerBul[i]->IsPunchWall()) == -1)
						{
							Print::facilityPrintD();
							_playerBul[i]->destroy();
							_playerBul.removeOnIndex(i);
							return 0;
						}
						_playerBul[i]->destroy();
						_playerBul.removeOnIndex(i);
					}


				}
			}

		}
		return 1;
	}

	int update()
	{
		if (enemyLive == 0 && _enemy.getCount() == 0)
			return 1;
		playerUpdate();
		enemyUpdate();


		if (enemyBulletsUpdate() == 0 || playerBulletsUpdate() == 0)
			return -1;


		nextStep();
		return 0;

	}


	void enemyUpdate()
	{
		if (_enemy.getCount() < 3 && tiks % 75000 == 0 && enemyLive)
		{
			int tmp = rand() % 4;
			if (enemyLive == 3 || enemyLive == 9 || enemyLive == 17)
			{
				if (tmp == 0)
					_enemy.add(new EazyTank(spawnPosition, 1));
				else if (tmp == 1)
					_enemy.add(new SpeedTank(spawnPosition, 1));
				else if (tmp == 2)
					_enemy.add(new ShooterTank(spawnPosition, 1));
				else if (tmp == 3)
					_enemy.add(new ArmorTank(spawnPosition, 1));
			}
			else
			{
				if (tmp == 0)
					_enemy.add(new EazyTank(spawnPosition));
				else if (tmp == 1)
					_enemy.add(new SpeedTank(spawnPosition));
				else if (tmp == 2)
					_enemy.add(new ShooterTank(spawnPosition));
				else if (tmp == 3)
					_enemy.add(new ArmorTank(spawnPosition));
			}
			enemyLive--;
			printInterface();
			_enemy[_enemy.getCount() - 1]->Draw();

			if (spawnPosition == TypeCreate::RIGHT)
				spawnPosition = TypeCreate::LEFT;
			else if (spawnPosition == TypeCreate::LEFT)
				spawnPosition = TypeCreate::MID;
			else if (spawnPosition == TypeCreate::MID)
				spawnPosition = TypeCreate::RIGHT;
		}


		if (BonusTime == 0)
		{
			for (int i = 0; i < _enemy.getCount(); i++)
			{
				if (tiks % _enemy[i]->GetSpeed() == 0)
				{
					Print::eraseTank(_enemy[i], _map);
					int tmp = rand() % 13;
					if (tmp % 5 == 0 && _enemy[i]->getBulletLive() == 0)
					{

						if (_enemy[i]->getRotation() == UP)
						{
							if (_enemy[i]->getY() > 1)
								if (_map.destroy(_enemy[i]->getX(), _enemy[i]->getY() - 1, _enemy[i]->getRotation(), _enemy[i]->isPunchWall()) == 0)
									_enemyBul.add(_enemy[i]->Shoot());

						}
						else if (_enemy[i]->getRotation() == DOWN)
						{

							if (_enemy[i]->getY() < 38)
								if (_map.destroy(_enemy[i]->getX(), _enemy[i]->getY() + 1, _enemy[i]->getRotation(), _enemy[i]->isPunchWall()) == 0)
									_enemyBul.add(_enemy[i]->Shoot());
						}
						else if (_enemy[i]->getRotation() == LEFT)
						{
							if (_enemy[i]->getX() - 1 > 1)
								if (_map.destroy(_enemy[i]->getX() - 1, _enemy[i]->getY(), _enemy[i]->getRotation(), _enemy[i]->isPunchWall()) == 0)
									_enemyBul.add(_enemy[i]->Shoot());
						}
						else if (_enemy[i]->getRotation() == RIGHT)
						{
							if (_enemy[i]->getX() + 1 < 38)
								if (_map.destroy(_enemy[i]->getX() + 1, _enemy[i]->getY(), _enemy[i]->getRotation(), _enemy[i]->isPunchWall()) == 0)
									_enemyBul.add(_enemy[i]->Shoot());
						}

					}
					else
						if (tmp == 6)
						{
							tmp = rand() % 4;
							_enemy[i]->Turn((Rotation)tmp);
						}
						else
						{
							if (Collision::TankGoAway(_enemy[i]) == 0 || Collision::TankOnBlock(_map, _enemy[i]) == 0
								|| Collision::enterTankOnPlayer(_enemy[i], _player) == 1 || (_enemy.getCount() > 1 && Collision::enterTankOnArrTank(_enemy[i], i, _enemy) == 1))
							{

								tmp = rand() % 4;

								while (tmp == _enemy[i]->getRotation())
									tmp = rand() % 4;


								_enemy[i]->Turn((Rotation)tmp);


							}
							else
							{
								switch (_enemy[i]->getRotation())
								{
								case UP:
									_enemy[i]->MoveUp();
									break;
								case DOWN:
									_enemy[i]->MoveDown();
									break;
								case LEFT:
									_enemy[i]->MoveLeft();
									break;
								case RIGHT:
									_enemy[i]->MoveRight();
									break;
								default:
									break;
								}
							}
						}

					Print::printTank(_enemy[i], _map);
					if (_bonus != nullptr)
						_bonus->print();
				}

			}

		}
	}
	bool enemyBulletsUpdate()
	{
		if (_enemyBul.getCount() > 0)
		{

			for (int i = 0; i < _enemyBul.getCount(); i++)
			{
				if (tiks % _enemyBul[i]->GetSpeed() == 0)
				{
					if (_map(_enemyBul[i]->getX(), _enemyBul[i]->getY())->getColor() != LightGreen)
						_enemyBul[i]->erase((Color)_map(_enemyBul[i]->getX(), _enemyBul[i]->getY())->getColor());

					if (Collision::isNotGoAway(_enemyBul[i]) == 1)
					{

						_enemyBul[i]->destroy();
						_enemyBul.removeOnIndex(i);
						continue;
					}
					if (Collision::BulletOnBlock(_map, _enemyBul[i]) == 1)
					{

						_enemyBul[i]->go();

						int tmp = Collision::indexBulletOnArrBull(_enemyBul[i], _playerBul);
						if (tmp >= 0)
						{
							if (_map(_enemyBul[i]->getX(), _enemyBul[i]->getY())->getColor() != LightGreen)
								_enemyBul[i]->erase((Color)_map(_enemyBul[i]->getX(), _enemyBul[i]->getY())->getColor());
							_enemyBul[i]->destroy();
							_enemyBul.removeOnIndex(i);
							_playerBul[tmp]->destroy();
							_playerBul.removeOnIndex(tmp);
							continue;
						}

						tmp = Collision::indexBulletOnArrBull(_enemyBul, i);
						if (tmp >= 0)
						{
							if (_map(_enemyBul[i]->getX(), _enemyBul[i]->getY())->getColor() != LightGreen)
								_enemyBul[i]->erase((Color)_map(_enemyBul[i]->getX(), _enemyBul[i]->getY())->getColor());
							if (i > tmp)
							{
								_enemyBul[i]->destroy();
								_enemyBul.removeOnIndex(i);
								_enemyBul[tmp]->destroy();
								_enemyBul.removeOnIndex(tmp);
							}
							else
							{
								_enemyBul[tmp]->destroy();
								_enemyBul.removeOnIndex(tmp);
								_enemyBul[i]->destroy();
								_enemyBul.removeOnIndex(i);
							}
							continue;
						}

						if (Collision::indexTankDestroy(_enemyBul[i], _enemy) != -1)
						{
							_enemyBul[i]->destroy();
							_enemyBul.removeOnIndex(i);
							continue;
						}

						if (Collision::enterBulletOnPlayer(_enemyBul[i], _player))
						{
							_enemyBul[i]->destroy();
							_enemyBul.removeOnIndex(i);
							if (_player.GetBonusArmor() == 0)
							{
								Print::erasePlayer(_player, _map);
								_player.Destroy();
								printInterface();
								_player.Spawn();

								if (_player.GetLive() == 0)
									return 0;
#ifdef FAST
								startArm = tiks + 150000;
#else
								startArm = tiks + 90000;
#endif 

								
								_player.ArmorOn();
								Print::printPlayer(_player, _map);

							}
							continue;
						}

						if (_map(_enemyBul[i]->getX(), _enemyBul[i]->getY())->getColor() != LightGreen)
							_enemyBul[i]->print((Color)_map(_enemyBul[i]->getX(), _enemyBul[i]->getY())->getColor());



						if (_bonus != nullptr && _bonus->getX() == _enemyBul[i]->getX() && _bonus->getY() == _enemyBul[i]->getY())
							_bonus->print();

					}
					else
					{
						_enemyBul[i]->go();
						if (_map.destroy(_enemyBul[i]->getX(), _enemyBul[i]->getY(), _enemyBul[i]->getRotation(), _enemyBul[i]->IsPunchWall()) == -1)
						{
							Print::facilityPrintD();
							_enemyBul[i]->destroy();
							_enemyBul.removeOnIndex(i);
							return 0;
						}
						_enemyBul[i]->destroy();
						_enemyBul.removeOnIndex(i);
					}

				}
			}

		}
		return 1;
	}


	void printInterface()
	{
		Cursor(41, 23);
		SetColor(Red, 8);
		cout << char(3);
		SetColor(0, 8);
		cout << _player.GetLive();

		Cursor(40, 30);
		cout << char(222);
		SetColor(Red, 8);
		cout << char(16);
		SetColor(0, 8);
		Cursor(40, 31);
		cout << char(222);


		for (int i = 0; i < 20; i++)
		{
			Cursor(41 + (i % 2 == 0), 3 + i / 2);
			if (i <= enemyLive - 1)
				cout << "T";
			else cout << ' ';
		}

	}

	void clear()
	{

		int tmp = _enemy.getCount();
		for (int i = 0; i < tmp; i++)
		{
			_enemy.removeOnIndex(0);
		}
		tmp = _enemyBul.getCount();
		for (int i = 0; i < tmp; i++)
		{
			_enemyBul.removeOnIndex(0);
		}
		tmp = _playerBul.getCount();
		for (int i = 0; i < tmp; i++)
		{
			_playerBul.removeOnIndex(0);
		}

		if (_bonus != nullptr)
		{
			delete _bonus;
			_bonus = nullptr;
		}
		tiks = 0;
		key = 0;

		BonusDefens = 0;
		BonusTime = 0;
		BonusArmor = 0;
		enemyLive = 20;
		spawnPosition = TypeCreate::MID;
	}

	void game()
	{
		system("color 80");
		system("cls");
		_player.Start();
		tiks = 0;
		int size = 4;

		while (_construction.getConstrucrion() == 0)
		{
			Cursor(20, 20);
			cout << tiks + 1;
			key = _getch();
			if (key == 224)
				key = _getch();

			if (key == UPKEY)
			{
				tiks++;
				if (tiks == size)
					tiks = 0;
			}
			else if (key == DOWNKEY)
			{
				tiks--;
				if (tiks == -1)
					tiks = size - 1;
			}
			else if (key == 13)
			{
				break;
			}
		}

		for (int i = tiks; i < size; i++)
		{
			if (_construction.getConstrucrion() == 1)
				i--;

			system("color 80");
			system("cls");
			Cursor(20, 20);
			cout << i + 1;
			Sleep(2000);


			clear();
			_player.GoToStart();
#ifdef FAST
			startArm = tiks + 145000;
#else
			startArm = tiks + 870000;
#endif 
			
			if (_construction.getConstrucrion() == 0)
				_map.create(maps[i]);
			else
				_map.copy(_construction);

			_map.print();
			Print::facilityPrint();
			_player.ArmorOn();
			_player.Draw();
			printInterface();
			Cursor(42, 31);
			cout << i + 1;



			int _update;
			while (1)
			{
				tiks++;
				if (_kbhit())
				{
					key = _getch();
					if (key == 224)
						key = _getch();
				}
				_update = update();
				if (_update == 1)
				{
					break;
				}
				if (_update == -1)
				{
					Sleep(2500);

					_map.create(the_end);
					SetColor(Black, Black);
					system("cls");
					_map.print();
					Sleep(2500);
					return;
				}
				_update = 0;

			}
			Sleep(2500);

		}
		SetColor(0, 0);
		system("cls");
	}


public:

	Game() = default;

	void start()
	{
		system("mode con cols=45 lines=40");

		menu();
		
	}

};