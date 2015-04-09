#include "circle.h"

Circle::Circle()
{
   int r = 25; Point P = Point(50,50);
   center = P; radius = r;
   color = Color(255,255,255);

   int x = -r, y = 0, err = 2-2*r; /* II. Quadrant */ 
   do {
      arrPoint.push_back( Point(P.x-x, P.y+y) ); /*   I. Quadrant */
      arrPoint.push_back( Point(P.x-y, P.y-x) ); /*  II. Quadrant */
      arrPoint.push_back( Point(P.x+x, P.y-y) ); /* III. Quadrant */
      arrPoint.push_back( Point(P.x+y, P.y+x) ); /*  IV. Quadrant */
      r = err;
      if (r <= y) err += ++y*2+1;           /* e_xy+e_y < 0 */
      if (r > x || err > y) err += ++x*2+1; /* e_xy+e_x > 0 or no 2nd y-step */
   } while (x < 0);
}

Circle::Circle(Point P, int r)
{
   center = P; radius = r;
   color = Color(255,255,255);

   int x = -r, y = 0, err = 2-2*r; /* II. Quadrant */ 
   do {
      arrPoint.push_back( Point(P.x-x, P.y+y) ); /*   I. Quadrant */
      arrPoint.push_back( Point(P.x-y, P.y-x) ); /*  II. Quadrant */
      arrPoint.push_back( Point(P.x+x, P.y-y) ); /* III. Quadrant */
      arrPoint.push_back( Point(P.x+y, P.y+x) ); /*  IV. Quadrant */
      r = err;
      if (r <= y) err += ++y*2+1;           /* e_xy+e_y < 0 */
      if (r > x || err > y) err += ++x*2+1; /* e_xy+e_x > 0 or no 2nd y-step */
   } while (x < 0);
}

Circle::Circle(Point P, int r, Color c)
{
   center = P; radius = r;
   color = c;
   
   int x = -r, y = 0, err = 2-2*r; /* II. Quadrant */ 
   do {
      arrPoint.push_back( Point(P.x-x, P.y+y) ); /*   I. Quadrant */
      arrPoint.push_back( Point(P.x-y, P.y-x) ); /*  II. Quadrant */
      arrPoint.push_back( Point(P.x+x, P.y-y) ); /* III. Quadrant */
      arrPoint.push_back( Point(P.x+y, P.y+x) ); /*  IV. Quadrant */
      r = err;
      if (r <= y) err += ++y*2+1;           /* e_xy+e_y < 0 */
      if (r > x || err > y) err += ++x*2+1; /* e_xy+e_x > 0 or no 2nd y-step */
   } while (x < 0);
}

void Circle::Draw(FrameBuffer& fb){
   for(int i = 0 ; i < arrPoint.size() ; i++)
      fb.setPixel(arrPoint[i].x, arrPoint[i].y, color);
      
   }
  

