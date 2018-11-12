#pragma once

class Point
{
public:
	int left, right, top, bottom;

public:
	Point();
	~Point();

	void setPoint(int left, int top, int right, int bottom);

	void setLeft(int left);
	void setRight(int right);
	void setTop(int top);
	void setBottom(int bottom);
};