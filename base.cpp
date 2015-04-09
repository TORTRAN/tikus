#include "base.h"

using namespace std;
//TERMIOS
static struct termios old, New;

//input without enter
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  New = old; /* make new settings same as old settings */
  New.c_lflag &= ~ICANON; /* disable buffered i/o */
  New.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &New); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) 
{
  return getch_(1);
}



// COLOR
Color::Color(){
		Red=255;
		Green=255;
		Blue=255;
	}
	
Color::Color(int red, int green, int blue){
	if(red<=255 && red>=0 && green<=255 && green>=0 && blue>=0&& blue<=255){
		
		Red=red;
		Green=green;
		Blue=blue;
	}
	else{
		Red=0;
		Green=0;
		Blue=0;
	}
}
	
void Color::setRed(int r){
	if(r>=0&&r<=255)Red=r;
}

void Color::setGreen(int g){
	if(g>=0&&g<=255)Green=g;
}

void Color::setBlue(int b){
	if(b>=0&&b<=255)Blue=b;
}


// FRAMEBUFFER
FrameBuffer::FrameBuffer(){
	
	/* open the file for reading and writing */
	fbfd = open("/dev/fb0",O_RDWR);
	if (!fbfd) {
		printf("Error: cannot open framebuffer device.\n");
		exit(1);
	}
	//printf ("The framebuffer device was opened successfully.\n");

	/* get the fixed screen information */
	if (ioctl (fbfd, FBIOGET_FSCREENINFO, &finfo)) {
		printf("Error reading fixed information.\n");
		exit(2);
	}

	/* get variable screen information */
	if (ioctl (fbfd, FBIOGET_VSCREENINFO, &vinfo)) {
		printf("Error reading variable information.\n");
		exit(3);
	}
	/* map the device to memory */
	fbp = (char*)mmap(0, finfo.smem_len, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
	screensize = 0;

	if (fbp == (char *)-1) {
		printf ("Error: failed to map framebuffer device to memory.\n");
		exit(4);
	}

	
	//printf ("Framebuffer device was mapped to memory successfully.\n");
}

void FrameBuffer::pickColor(){
	int location;
	 char* tempfbp = (char*) malloc (finfo.smem_len);
	int x, y; /* x and y location */
	int blue = 0;
  int green = 170;
  int red = 170;
  int grade = -85;
  int bluep, greenp, redp;
  for(y = 0; y < 170; y++) {
      for(x = 0; x < 510; x++) { 
          location = x * (vinfo.bits_per_pixel/8) + y * finfo.line_length;
      
      // blue
      if(0 <= x && x <= 254) {
        blue++;
      }
      else if(255 <= x && x <= 510) {
        blue--;
      }
      if(blue + grade < 0) {
        bluep = 0;
      }
      else if(blue + grade > 255) {
        bluep = 255;
      }
      else {
        bluep = blue + grade;
      }
      
      // green
      if(0 <= x && x <= 169) {
        green--;
      }
      else if(170 <= x && x <= 424) {
        green++;
      }
      else if(425 <= x && x <= 510) {
        green--;
      }
      if(green + grade < 0) {
        greenp = 0;
      }
      else if(green + grade > 255) {
        greenp = 255;
      }
      else {
        greenp = green + grade;
      }
      
      // red
      if(0 <= x && x <= 84) {
        red ++;
      }
      else if(85 <= x && x <= 339) {
        red--;
      }
      else if(340 <= x && x <= 510) {
        red++;
      }
      if(red + grade < 0) {
        redp = 0;
      }
      else if(red + grade > 255) {
        redp = 255;
      }
      else {
        
        redp = red + grade;
      }
      *(fbp + location) = bluep; // Some blue 
      *(fbp + location + 1) = greenp; // A little green 
      *(fbp + location + 2) = redp; // A lot of red
      *(fbp + location + 3) = 0; // No transparency
      }
      grade++;
  }
  munmap(fbp, screensize);
  
  // Baca dari input
  for(int i = 0; i < finfo.smem_len; i++) {
      tempfbp[i] = fbp[i];
  }
  int inputx, inputy;
  
  printf("Masukkan nilai untuk x: ");
  scanf("%d", &inputx);
  system("clear");
  for(y = 0; y < 170; y++) {
      for(x = 0; x < 510; x++) { 
          location = x * (vinfo.bits_per_pixel/8) + y * finfo.line_length;
      
      // blue
      if(0 <= x && x <= 254) {
        blue++;
      }
      else if(255 <= x && x <= 510) {
        blue--;
      }
      if(blue + grade < 0) {
        bluep = 0;
      }
      else if(blue + grade > 255) {
        bluep = 255;
      }
      else {
        bluep = blue + grade;
      }
      
      // green
      if(0 <= x && x <= 169) {
        green--;
      }
      else if(170 <= x && x <= 424) {
        green++;
      }
      else if(425 <= x && x <= 510) {
        green--;
      }
      if(green + grade < 0) {
        greenp = 0;
      }
      else if(green + grade > 255) {
        greenp = 255;
      }
      else {
        greenp = green + grade;
      }
      
      // red
      if(0 <= x && x <= 84) {
        red ++;
      }
      else if(85 <= x && x <= 339) {
        red--;
      }
      else if(340 <= x && x <= 510) {
        red++;
      }
      if(red + grade < 0) {
        redp = 0;
      }
      else if(red + grade > 255) {
        redp = 255;
      }
      else {
        
        redp = red + grade;
      }
      *(fbp + location) = bluep; // Some blue 
      *(fbp + location + 1) = greenp; // A little green 
      *(fbp + location + 2) = redp; // A lot of red
      *(fbp + location + 3) = 0; // No transparency
      }
      grade++;
  }
  munmap(fbp, screensize);
  printf("Masukkan nilai untuk y: ");
  scanf("%d", &inputy);
  int new_location = new_location = inputx * (vinfo.bits_per_pixel/8) + inputy * finfo.line_length;
  
  
  new_blue = *(tempfbp + new_location);
  new_green = *(tempfbp + new_location + 1);
  new_red = *(tempfbp + new_location + 2);

  printf("R = %d, G = %d, B = %d\n", new_red, new_green, new_blue);
	for(int y = 0; y < 170; y++) {
		for(int x = 0; x < 510; x++) { 
			location = x * (vinfo.bits_per_pixel/8) + y * finfo.line_length;
			if(vinfo.bits_per_pixel == 32) {
				*(fbp + location) = new_blue;
				*(fbp + location + 1) = new_green;
				*(fbp + location + 2) = new_red;
				*(fbp + location + 3) = 0;
			} else { // asumsi 16 bits_per_pixel
				int temp_blue = 10;
				int temp_green = (x-100)/6; // A little green
				int temp_red = 31-(y-100)/16; // A lot of red
				unsigned short int t = temp_red << 11 | temp_green << 5 | temp_blue;
				*((unsigned short int*) (fbp + location)) = t;
			}
		}
	}
  getchar();
  getchar();

}

void FrameBuffer::setPixel(int x, int y,Color color){
    if ((x < vinfo.xres) && (y < vinfo.yres))
    {
      int location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset) * finfo.line_length;
      *(fbp + location) = color.Blue; // Some blue 
      *(fbp + location + 1) = color.Green; // A little green 
      *(fbp + location + 2) = color.Red; // A lot of red
      *(fbp + location + 3) = 0; // No transparency 
    }
}

void FrameBuffer::deletePixel(int x, int y){
	int location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset) * finfo.line_length;
    *(fbp + location) = 0; // Some blue 
    *(fbp + location + 1) = 0; // A little green 
    *(fbp + location + 2) = 0; // A lot of red
    *(fbp + location + 3) = 0; // No transparency 
}

// POINT
Point::Point(){
	x = 0;
	y = 0;
}

Point::Point(int x1, int y1){
	x = x1;
	y = y1;
}

int Point::getIndex(Point P1,Point P2){
	int ret = 0;
	if(y<P1.y){
		ret = ret | 8;
	}
	if(y>P2.y){
		ret = ret | 4;
	}
	if(x>P2.x){
		ret = ret | 2;
	}
	if(x<P1.x){
		ret = ret | 1;
	}
	return ret;
}


// GLOBAL VOID
void drawLine(int x0, int y0, int x1, int y1,FrameBuffer fb){
	int dx = abs (x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = - abs (y1-y0), sy = y0<y1 ? 1 : -1;
	int error = dx + dy, e2;
	Color c(255,255,0);
	if (x0==x1 && y0==y1){
		
	}
	else{
		for (;;){
		fb.setPixel(x0,y0,c);
		if (x0==x1 && y0==y1) break;
		e2 = 2 * error;
		if (e2 >= dy) {error += dy; x0 += sx;}
		if (e2 <= dx) {error += dx; y0 += sy;}
		}
	}
}

void deleteLine(int x0, int y0, int x1, int y1,FrameBuffer fb){
	int dx = abs (x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = - abs (y1-y0), sy = y0<y1 ? 1 : -1;
	int error = dx + dy, e2;
	Color c(255,255,0);

	for (;;){
		fb.deletePixel(x0,y0);
		if (x0==x1 && y0==y1) break;
		e2 = 2 * error;
		if (e2 >= dy) {error += dy; x0 += sx;}
		if (e2 <= dx) {error += dx; y0 += sy;}
	}
}

