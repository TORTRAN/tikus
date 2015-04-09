#ifndef POLYGON_H
#define POLYGON_H
#include "base.h"
#include "line.h"

using namespace std;

class Polygon{
public:
	Line RectLine[4];
	Color c;
	vector<Point> arrPoint;

	Polygon();
	Polygon(Point a, Point b, Point c, Point d);

	void setColor(Color color);
	void Draw(FrameBuffer fb);
	void Update();
};

#endif
