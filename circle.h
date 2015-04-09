#ifndef CIRCLE_H
#define CIRCLE_H

#include "base.h"
#include "Drawable.h"
using namespace std;

class Circle : public Drawable
{
	public:
		vector<Point> arrPoint;
		int radius;
		Point center;
		Color color;
		Circle();
		Circle(Point center, int r);
		Circle(Point center, int r, Color c);
		virtual void Draw(FrameBuffer& fb);
		
	
};

#endif