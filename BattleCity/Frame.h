#pragma once

#include "Header.h"


class frame
{
	int _downWall;
	int _leftWall;
	int _upWall;
	int _rightWall;

public:
	frame(int DW, int RW)
	{
		_downWall = DW;
		_rightWall = RW;
		_upWall = 0;
		_leftWall = 0;
	}
	frame(int DW, int RW, int UW, int LW)
	{
		_downWall = DW;
		_leftWall = LW;
		_upWall = UW;
		_rightWall = RW;
	}
	frame()
	{
	}
	int getDW()
	{
		return _downWall;
	}
	int getUW()
	{
		return _upWall;
	}
	int getLW()
	{
		return _leftWall;
	}
	int getRW()
	{
		return _rightWall;
	}
	void printFrame()
	{
		for (int i = 0; i <= _rightWall - _leftWall; i++)
		{
			Cursor(i + _leftWall, _upWall);
			cout << (char)BLOK;
		}
		for (int i = 0; i <= _downWall - _upWall; i++)
		{
			Cursor(_leftWall, i + _upWall);
			cout << (char)BLOK;
			Cursor(_rightWall, i + _upWall);
			cout << (char)BLOK;
		}
		for (int i = 0; i <= _rightWall - _leftWall; i++)
		{
			Cursor(i + _leftWall, _downWall);
			cout << (char)BLOK;
		}

	}
};