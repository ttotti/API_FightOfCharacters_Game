#pragma once

#include <Windows.h>
#include "Rect_point.h"

class tilePoint
{
private:
	Rect_Point tile_No_1;
	Rect_Point tile_No_2;
	Rect_Point tile_No_3;
	Rect_Point tile_No_4;
	Rect_Point tile_No_5;

	Rect_Point tile_No_6;
	Rect_Point tile_No_7;
	Rect_Point tile_No_8;
	Rect_Point tile_No_9;
	Rect_Point tile_No_10;

	Rect_Point tile_No_11;
	Rect_Point tile_No_12;
	Rect_Point tile_No_13;
	Rect_Point tile_No_14;
	Rect_Point tile_No_15;

	Rect_Point tile_No_16;
	Rect_Point tile_No_17;
	Rect_Point tile_No_18;
	Rect_Point tile_No_19;
	Rect_Point tile_No_20;

	Rect_Point tile_No_21;
	Rect_Point tile_No_22;
	Rect_Point tile_No_23;
	Rect_Point tile_No_24;
	Rect_Point tile_No_25;

public:
	tilePoint();
	~tilePoint();

	void setPoint(int x, int y);
	void setPointX(int x);
	void setPointY(int y);

	int getPointX();
	int getPointY();

};