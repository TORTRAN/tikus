#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "base.h"
#include "line.h"
#include "Drawable.h"

using namespace std;

class Rectangle: public Drawable
{
public:
	Line RectLine[4];
	Color c;
	vector<Point> arrPoint;

	Rectangle();
	Rectangle(Point a, Point b, Point c, Point d);

	void setColor(Color color);
	virtual void Draw(FrameBuffer &fb);
	void Update();
};

#endif
