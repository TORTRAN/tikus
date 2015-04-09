#ifndef MOUSE_H
#define MOUSE_H
#include "MouseEvent.h"
#include <mutex>
#include <thread>
#include <queue>
#include <vector>

class Mouse
{
public:
	Mouse();
	Mouse(int xres, int yres);

	bool eventAvailable();
	MouseEvent getMouseEvent();
	void draw();

	int getX();
	int getY();
private:
	int x, y;
	int xres, yres;
	std::mutex m;
	std::vector <std::thread> threads;
	std::queue <MouseEvent> eventQueue;

	void mouseController(int eventId);
	void addEvent(MouseEvent event);

};


#endif

