#include "point.h"

Rect_Point::Rect_Point()
{
	left = right = top = bottom = 0;
}

Rect_Point::~Rect_Point()
{
}

void Rect_Point::setPoint(int left, int top, int right, int bottom)
{
	this->left = left;
	this->right = right;
	this->top = top;
	this->bottom = bottom;
}

void Rect_Point::setLeft(int left)
{
	this->left = left;
}

void Rect_Point::setRight(int right)
{
	this->right = right;
}

void Rect_Point::setTop(int top)
{
	this->top = top;
}

void Rect_Point::setBottom(int bottom)
{
	this->bottom = bottom;
}
