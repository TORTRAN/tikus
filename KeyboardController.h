#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H
#include <thread>

class KeyboardController
{
public:
	enum Mode {Rectangle, Polygon, Circle, Line};
	KeyboardController();

	Mode getMode();
	bool isModeHasChanged();

	int getNbTitik();

	volatile bool waitForInput;

private:
	Mode mode;
	int nbTitik; //Digunakan kalau menggambar polygon
	std::thread t;

	bool modeHasChanged;
	void inputThread();
};

#endif