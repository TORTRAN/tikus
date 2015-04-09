#include <iostream>
#include "Mouse.h"
#include "base.h"
#include "cursor.h"


int main()
{
	Mouse m;
	Cursor c(m.getX(), m.getY());

	FrameBuffer fb;

	while(1)
	{
		while(m.eventAvailable())
		{
			MouseEvent me = m.getMouseEvent();

			switch(me.getButton())
			{
				case MouseEvent::Button::Left:
					std::cout << "Tombol kiri ditekan bro! Posisi: " << me.getX() << " " << me.getY() << "\n";
					break;
				case MouseEvent::Button::Right:
					std::cout << "Tombol kanan ditekan bro! Posisi: " << me.getX() << " " << me.getY() << "\n";
					break;
				case MouseEvent::Button::Middle:
					std::cout << "Tombol tengah ditekan bro! Posisi: " << me.getX() << " " << me.getY() << "\n";
					break;
			}
		}

		c.Update(m.getX(), m.getY()); 
		system("clear"); 
		c.Draw(fb);

	}
	return 0;
}