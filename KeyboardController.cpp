#include "KeyboardController.h"
#include "base.h"

KeyboardController::KeyboardController(): nbTitik(0), mode(KeyboardController::Mode::Rectangle), modeHasChanged(true), waitForInput(false)
{
	t = std::thread(&KeyboardController::inputThread, this);
}

void KeyboardController::inputThread()
{

	while (1)
	{
		char input = getch();

		switch(input)
		{
			case 'r':
				mode = Mode::Rectangle;
				modeHasChanged = true;
				break;

			case 'c':
				mode = Mode::Circle;
				modeHasChanged = true;
				break;

			case 'p':
				mode = Mode::Polygon;
				modeHasChanged = true;

				waitForInput = true;
				input = getch();
				waitForInput = false;

				if (input >= '3')
				{
					nbTitik = (int) (input - '0');
				} else {
					nbTitik = 3;
				}

				
				break;
			case 'l':
				mode = Mode::Line;
				modeHasChanged = true;
				break;

			default:
				break;
		}
	}
}

KeyboardController::Mode KeyboardController::getMode()
{
	modeHasChanged = false;
	return mode;
}

int KeyboardController::getNbTitik()
{
	return nbTitik;
}

bool KeyboardController::isModeHasChanged()
{
	return modeHasChanged;
}