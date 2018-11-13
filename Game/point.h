#pragma once

class Rect_Point
{
public:
	int left, right, top, bottom;

public:
	Rect_Point();
	~Rect_Point();

	void setPoint(int left, int top, int right, int bottom);

	void setLeft(int left);
	void setRight(int right);
	void setTop(int top);
	void setBottom(int bottom);
};