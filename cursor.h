#include "polygon.h"

class Cursor{
public:
	Polygon p;
	static int xed ;
	static int yed ;
	static int centerx ;
	static int centery ;


	Cursor();
	Cursor(int x, int y);
	void Update(int x,int y);	
	void Draw(FrameBuffer fb);
};
