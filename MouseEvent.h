#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H
class MouseEvent
{
public:
	enum Button {Left, Middle, Right};
	MouseEvent();
	MouseEvent(Button button, int x, int y);

	int getX();
	int getY();
	void setX(int x);
	void setY(int y);

	Button getButton();
	void setButton(Button btn);

	MouseEvent& operator=(MouseEvent &e);

private:
	Button btn;
	int x;
	int y;
};

#endif