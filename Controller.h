#ifndef CONTROLLER_H
#define	CONTROLLER_H
#include <vector>

#include "base.h"
#include "Drawable.h"
#include "Mouse.h"
#include "cursor.h"
#include "KeyboardController.h"
#include "Rectangle.h"
#include "circle.h"
#include "polygon1.h"


class Controller
{
public:
	void controllerMain();

private:
	std::vector <Point> points;
	std::vector <Rectangle> rectangles;
	std::vector <Circle> circles;
	std::vector <Polygon1> polygons;
	std::vector <Line> lines;
	//std::vector <Poly> circles;
	FrameBuffer fb;
	Mouse mouse;
	Cursor cursor;
	KeyboardController keyboardController;

};

#endif