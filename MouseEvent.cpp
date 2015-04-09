#include "MouseEvent.h"

MouseEvent::MouseEvent() : btn(Button::Left), x(0), y(0)
{

}

MouseEvent::MouseEvent(Button button, int x, int y) : btn(button), x(x), y(y)
{

}

int MouseEvent::getX()
{
	return x;
}

int MouseEvent::getY()
{
	return y;
}

void MouseEvent::setX(int x)
{
	this->x = x;
}

void MouseEvent::setY(int y)
{
	this->y = y;
}

MouseEvent::Button MouseEvent::getButton()
{
	return btn;
}

void MouseEvent::setButton(Button btn)
{
	this->btn = btn;
}

MouseEvent& MouseEvent::operator=(MouseEvent &e)
{
	this->btn = e.btn;
	this->x = e.x;
	this->y = e.y;

	return (*this);
}