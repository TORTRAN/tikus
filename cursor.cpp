#include "cursor.h"

Cursor::Cursor():p(Point(0,0),Point(xed,0),Point(centerx,centery),Point(0,yed)){
	
}

Cursor::Cursor(int x, int y):p(Point(x,y),Point(x+xed,y+yed),Point(x+centerx,y+centery),Point(x+yed,y+xed)){
	
}

void Cursor::Update(int x,int y){
	p.arrPoint[0].x = x;
	p.arrPoint[0].y = y;

	p.arrPoint[1].x = x+xed;
	p.arrPoint[1].y = y+yed;

	p.arrPoint[2].x = x+centerx;
	p.arrPoint[2].y = y+centery;

	p.arrPoint[3].x = x+yed;
	p.arrPoint[3].y = y+xed;

	p.Update();

}

void Cursor::Draw(FrameBuffer fb){
	p.Draw(fb);
}

int Cursor::xed = 15;
int Cursor::yed = 5;
int Cursor::centerx = 5;
int Cursor::centery = 5;
