#include "line.h"
#include "base.h"

Line::Line():c(255,0,0){
	P1.x = 0;
	P1.y = 0;
	P2.x = 0;
	P2.y = 0;
}
Line::Line(int x1, int y1, int x2, int y2):c(255,0,0){
	P1.x = x1;
	P1.y = y1;
	P2.x = x2;
	P2.y = y2;
	
}

void Line::line(int x1, int y1, int x2, int y2){
	P1.x = x1;
	P1.y = y1;
	P2.x = x2;
	P2.y = y2;
}

void Line::setColor(Color color){
	c=color;
}

void Line::draw(FrameBuffer fb){
	int x = P1.x;
	int y = P1.y;
	int dx = abs (P2.x-x), sx = x<P2.x	 ? 1 : -1;
	int dy = - abs (P2.y-y), sy = y<P2.y ? 1 : -1;
	int error = dx + dy, e2;

	for (;;){
		fb.setPixel(x,y,c);
		if (x==P2.x && y==P2.y) break;
		e2 = 2 * error;
		if (e2 >= dy) {error += dy; x += sx;}
		if (e2 <= dx) {error += dx; y += sy;}
	}
}

int Line::getX(int y){
	int x;
	if(P1.y != P2.y){
		x = (y * (P1.x - P2.x) - P1.x * P2.y + P2.x * P1.y) / (P1.y - P2.y);	
	}
	else{
		x = P1.x;
	}
	return x;
}

int Line::getY(int x){
	int y;
	if (P1.x != P2.x){
		y = (x * (P1.y - P2.y) + P1.x * P2.y - P2.x * P1.y) / (P1.x - P2.x);
	}
	else{
		y = P1.y;
	}
	return y;
}
