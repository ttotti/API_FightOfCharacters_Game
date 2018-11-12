#include "point.h"

Point::Point()
{
	left = right = top = bottom = 0;
}

Point::~Point()
{
}

void Point::setPoint(int left, int top, int right, int bottom)
{
	this->left = left;
	this->right = right;
	this->top = top;
	this->bottom = bottom;
}

void Point::setLeft(int left)
{
	this->left = left;
}

void Point::setRight(int right)
{
	this->right = right;
}

void Point::setTop(int top)
{
	this->top = top;
}

void Point::setBottom(int bottom)
{
	this->bottom = bottom;
}
