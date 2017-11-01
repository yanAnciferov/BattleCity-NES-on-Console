#pragma once
#include "Header.h"


class Map
{
	Block* blocks[39][39];
	const int h = 39;
	const int w = 39;
	bool construction = 0;

	void printCursor(char block,int x,int y, bool BigMode)
	{
		if (BigMode == 0)
		{
			if (block == 'R')
			{
				SetColor(DarkGray, 0);
				Cursor(x, y);
				cout << (char)176;
			}
			else if (block == 'B')
			{
				SetColor(LightGray, Red);
				Cursor(x, y);
				cout << (char)176;
			}
			else if (block == 'W')
			{
				SetColor(White, LightGray);
				Cursor(x, y);
				cout << (char)178;
			}
			else if (block == 'F')
			{
				SetColor(LightGray, LightGreen);
				Cursor(x, y);
				cout << (char)177;

			}
			else if (block == 'S')
			{
				SetColor(0, Blue);
				Cursor(x, y);
				cout << ' ';
			}
		}
		else if (BigMode == 1)
		{
			if (block == 'R')
			{
				SetColor(DarkGray, 0);
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						Cursor(x + i, y + j);
						cout << (char)176;
					}
				}
				
			}
			else if (block == 'B')
			{
				SetColor(LightGray, Red);
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						Cursor(x + i, y + j);
						cout << (char)176;
					}
				}
			}
			else if (block == 'W')
			{
				SetColor(White, LightGray);
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						Cursor(x + i, y + j);
						cout << (char)178;
					}
				}
				
			}
			else if (block == 'F')
			{
				SetColor(LightGray, LightGreen);
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						Cursor(x + i, y + j);
						cout << (char)177;
					}
				}
				

			}
			else if (block == 'S')
			{
				SetColor(0, Blue);
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						Cursor(x + i, y + j);
						cout << ' ';
					}
				}
			
			}
		}
	}

	void printBlocks(int x, int y, bool BigMode)
	{
		if (BigMode)
		{
			for (int i = 0; i < 3; i++)
			{
				for (int k = 0; k < 3; k++)
				{
					blocks[x + i][y + k]->print();
				}
			}
		}else blocks[x][y]->print();
	}

	void preSpawn()
	{
		int x = 0, y = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				delete blocks[x + i][y + j];
				blocks[x + i][y + j] = new Road(x + i, y + j);
			}
		}
		x = 0, y = 18;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				delete blocks[x + i][y + j];
				blocks[x + i][y + j] = new Road(y + i, x + j);
			}
		}
		x = 0, y = 36;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				delete blocks[x + i][y + j];
				blocks[x + i][y + j] = new Road(y + i, x + j);
			}
		}


		x = 36, y = 12;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				delete blocks[x + i][y + j];
				blocks[x + i][y + j] = new  Road(y + i, x + j);
			}
		}


		x = 36, y = 18;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				delete blocks[x + i][y + j];
				blocks[x + i][y + j] = new Facility(y + i, x + j);
			}
		}
	}

public:
	
	Map() = default;
	Map(char map[39][39]);
	

	void create(char map[39][39]);

	void print();
	Block* operator() (int i, int j);

	int destroy(int y, int x, int rotation, bool isPunchWall);

	void onDefensBonus();

	void printShelter();

	void ofDefensBonus();

	bool getConstrucrion()
	{
		return construction;
	}

	void constructionMode()
	{
		int x = 0, y = 0;
		char block = 'R';
		int key;
		bool BigMode = 0;
		if (construction == 0)
		{
			construction = 1;
			for (int i = 0; i < h; i++)
				for (int j = 0; j < w; j++)
						blocks[i][j] = new Road(j, i);
			ofDefensBonus();
				
		}
		print();
		while (1)
		{
			key = _getch();
			switch (key)
			{
			case UPKEY:
				printBlocks(x,y,BigMode);
				if(x - 1 != -1)
					x--;
				printCursor(block, y, x, BigMode);
				break;
			case DOWNKEY:
				printBlocks(x, y, BigMode);
				if (x + 1 != 39 && BigMode == 0 || x + 1 != 37 && BigMode == 1)
					x++;
				printCursor(block, y, x, BigMode);
				break;
			case LEFTKEY:
				printBlocks(x, y, BigMode);
				if (y - 1 != -1)
					y--;
				printCursor(block, y, x, BigMode);
				break;
			case RIGHTKEY:
				printBlocks(x, y, BigMode);
				if (y + 1 != 39 && BigMode == 0 || y + 1 != 37 && BigMode == 1)
					y++;
				printCursor(block, y, x,BigMode);
				break;
			case 13:
				if (BigMode == 0)
				{
					BigMode = 1;
					if (x > 36)
						x = 36;
					if (y > 36)
						y = 36;
				}
				else
				{
					if (block == 'R')
					{

						block = 'B';
						BigMode = 0;
						printBlocks(x, y, 1);

					}
					else if (block == 'B')
					{

						BigMode = 0;
						block = 'W';
						printBlocks(x, y, 1);
					}
					else if (block == 'W')
					{

						BigMode = 0;
						block = 'F';
						printBlocks(x, y, 1);

					}
					else if (block == 'F')
					{

						BigMode = 0;
						block = 'S';
						printBlocks(x, y, 1);

					}
					else if (block == 'S')
					{

						BigMode = 0;
						block = 'R';
						printBlocks(x, y, 1);

					}
				}
				printCursor(block, y, x, BigMode);
				break;
			case ' ':
				if(BigMode)
					for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						delete blocks[x + i][y + j];
					}
				}
				else 
					delete blocks[x][y];

				if (block == 'R')
					if(BigMode)
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							blocks[x + j][y + i] = new Road(y + i, x + j);
						}
					}
					else blocks[x][y] = new Road(y, x);
					
				else if (block == 'B')
					if (BigMode)
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							blocks[x + j][y + i] = new Brick(y + i, x + j);
						}
					}
					else blocks[x][y] = new Brick(y, x);


				else if (block == 'W')
					if (BigMode)
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							blocks[x + j][y + i] = new Wall(y + i, x + j);
						}
					}
					else blocks[x][y] = new Wall(y, x);


				else if (block == 'F')
					if (BigMode)
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							blocks[x + j][y + i] = new Forest(y + i, x + j);
						}
					}
					else blocks[x][y] = new Forest(y, x);


				else if (block == 'S')
					if (BigMode)
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							blocks[x + j][y + i] = new Water(y + i, x + j);
						}
					}
					else blocks[x][y] = new Water(y, x);


				printBlocks(x, y, BigMode);
				
				break;
			case 27:
				preSpawn();
				return;
				break;
			default:
				break;
			}
		}
	}

	void copy(Map& m)
	{

		for (int i = 0; i < 39; i++)
		{
			for (int j = 0; j < 39; j++)
			{
				delete blocks[i][j];
				blocks[i][j] = m.blocks[i][j];
				m.blocks[i][j] = nullptr;
			}
		}
		m.construction = 0;
	}
};