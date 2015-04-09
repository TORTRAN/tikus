#include "polygon1.h"

Polygon1::Polygon1(){
	n=0;
}

Polygon1::Polygon1(int no){
	n=no;
}

void Polygon1::draw(FrameBuffer fb){
	int m=0;
	if (vecPoint.size() != 0)
	{
		while(m<vecPoint.size()-1){
			Line l;
			if(m==n-1){
				l.P1 = vecPoint[m];
				l.P2 = vecPoint[0];
			}
			else{
				l.P1 = vecPoint[m];
				l.P2 = vecPoint[m+1];
			}
			l.draw(fb);
			m++;
		}
	}
}

void Polygon1::addPoint(Point p1){
	if(vecPoint.size()<=n){
		vecPoint.push_back(p1);
	}
	
}
