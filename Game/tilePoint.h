#pragma once

#include <Windows.h>
#include "point.h"

class tilePoint
{
private:
	Point tile_No_1;
	Point tile_No_2;
	Point tile_No_3;
	Point tile_No_4;
	Point tile_No_5;

	Point tile_No_6;
	Point tile_No_7;
	Point tile_No_8;
	Point tile_No_9;
	Point tile_No_10;

	Point tile_No_11;
	Point tile_No_12;
	Point tile_No_13;
	Point tile_No_14;
	Point tile_No_15;

	Point tile_No_16;
	Point tile_No_17;
	Point tile_No_18;
	Point tile_No_19;
	Point tile_No_20;

	Point tile_No_21;
	Point tile_No_22;
	Point tile_No_23;
	Point tile_No_24;
	Point tile_No_25;

public:
	tilePoint();
	~tilePoint();

	void setPoint(int x, int y);
	void setPointX(int x);
	void setPointY(int y);

	int getPointX();
	int getPointY();

};