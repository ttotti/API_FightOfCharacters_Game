#include "tilePoint.h"

tilePoint::tilePoint()
{
	tile_No_1.setPoint(84, 205, 300, 311);
	tile_No_2.setPoint(300, 205, 497, 311);
	tile_No_3.setPoint(499, 205, 697, 311);
	tile_No_4.setPoint(698, 205, 933, 311);
	tile_No_5.setPoint(937, 205, 1181, 311);

	tile_No_6.setPoint(84, 314, 300, 404);
	tile_No_7.setPoint(300, 314, 496, 404);
	tile_No_8.setPoint(499, 314, 696, 404);
	tile_No_9.setPoint(697, 314, 934, 404);
	tile_No_10.setPoint(937, 314, 1180, 404);

	tile_No_11.setPoint(84, 408, 298, 500);
	tile_No_12.setPoint(302, 408, 495, 500);
	tile_No_13.setPoint(499, 408, 696, 500);
	tile_No_14.setPoint(699, 408, 933, 500);
	tile_No_15.setPoint(937, 408, 1180, 500);

	tile_No_16.setPoint(84, 506, 298, 608);
	tile_No_17.setPoint(301, 506, 495, 608);
	tile_No_18.setPoint(499, 506, 696, 608);
	tile_No_19.setPoint(699, 506, 931, 608);
	tile_No_20.setPoint(936, 506, 1180, 608);

	tile_No_21.setPoint(84, 612, 298, 734);
	tile_No_22.setPoint(302, 612, 495, 734);
	tile_No_23.setPoint(500, 612, 696, 734);
	tile_No_24.setPoint(701, 612, 931, 734);
	tile_No_25.setPoint(936, 612, 1180, 734);
}

tilePoint::~tilePoint()
{
}

void tilePoint::setPoint(int x, int y)
{
}

void tilePoint::setPointX(int x)
{
}

void tilePoint::setPointY(int y)
{
}

int tilePoint::getPointX()
{
	return 0;
}

int tilePoint::getPointY()
{
	return 0;
}
