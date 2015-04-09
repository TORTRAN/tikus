#include "polygon.h"

Polygon::Polygon():c(255,0,0){
	RectLine[0]=Line(10,10,20,20);
	RectLine[1]=Line(20,20,40,20);
	RectLine[2]=Line(40,20,30,10);
	RectLine[3]=Line(30,10,10,10);
	arrPoint.push_back(RectLine[0].P1);
	arrPoint.push_back(RectLine[1].P1);
	arrPoint.push_back(RectLine[2].P1);
	arrPoint.push_back(RectLine[3].P1);
}

Polygon::Polygon(Point a, Point b, Point c, Point d):c(255,0,0){
	RectLine[0]=Line(a.x, a.y, b.x, b.y);
	RectLine[1]=Line(b.x, b.y, c.x, c.y);
	RectLine[2]=Line(c.x, c.y, d.x, d.y);
	RectLine[3]=Line(d.x, d.y, a.x, a.y);
	arrPoint.push_back(RectLine[0].P1);
	arrPoint.push_back(RectLine[1].P1);
	arrPoint.push_back(RectLine[2].P1);
	arrPoint.push_back(RectLine[3].P1);
}

void Polygon::setColor(Color color){
	c=color;
	for(int i = 0; i<4 ; i++){
		RectLine[i].c=c;
	}
}

void Polygon::Draw(FrameBuffer fb){
	for(int i=0;i<4;i++){
		RectLine[i].draw(fb);
	}
}

void Polygon::Update(){
	RectLine[0]=Line(arrPoint[0].x, arrPoint[0].y, arrPoint[1].x, arrPoint[1].y);
	RectLine[1]=Line(arrPoint[1].x, arrPoint[1].y, arrPoint[2].x, arrPoint[2].y);
	RectLine[2]=Line(arrPoint[2].x, arrPoint[2].y, arrPoint[3].x, arrPoint[3].y);
	RectLine[3]=Line(arrPoint[3].x, arrPoint[3].y, arrPoint[0].x, arrPoint[0].y);
}