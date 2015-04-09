#ifndef POLYGON1_H
#define POLYGON1_H
#include "base.h"
#include "line.h"
#include <vector>

class Polygon1{
public:
	vector <Point> vecPoint;
	int n;

	Polygon1();
	Polygon1(int no);
	
	void draw(FrameBuffer fb);
	void addPoint(Point p1);
};

#endif
