#include "Controller.h"
#include "circle.h"

void Controller::controllerMain()
{
	KeyboardController::Mode currMode;
	while(1)
	{
		if (keyboardController.isModeHasChanged())
		{
			points = std::vector <Point>();
			currMode = keyboardController.getMode();

			if (currMode == KeyboardController::Mode::Polygon)
			{
				while (keyboardController.waitForInput);
				polygons.push_back(Polygon1(keyboardController.getNbTitik()));
			}
		}

		//proses semua event input dari mouse
		while(mouse.eventAvailable())
		{
			MouseEvent event = mouse.getMouseEvent();

			//TODO: Tambahain firepoint disin
			
			if (keyboardController.getMode() != KeyboardController::Mode::Polygon)
			{
				points.push_back(Point(event.getX(), event.getY()));
			} else {
				polygons.at(polygons.size() - 1).addPoint(Point(event.getX(), event.getY()));
			}
		}
		cursor.Update(mouse.getX(), mouse.getY());

		//Kalo semua titik udah lengkap, masukkan ke dalam drawable
		switch(currMode)
		{
			case KeyboardController::Mode::Rectangle:
				if (points.size() == 4)
				{
					rectangles.push_back(Rectangle(points.at(0), points.at(1), points.at(2), points.at(3)));
					points = std::vector<Point>();
				}
				break;
			case KeyboardController::Mode::Circle:
				if (points.size() == 1)
				{
					circles.push_back(Circle(points.at(0), 100));
					points = std::vector<Point>();
				}
				break;
			case KeyboardController::Mode::Line:
				if (points.size() == 2)
				{
					lines.push_back(Line(points.at(0).x, points.at(0).y, points.at(1).x, points.at(1).y));
					points = std::vector<Point>();
				}
				break;
		}

		//Draw :)
		int i;
		for (i=0; i<rectangles.size(); i++)
		{
			rectangles.at(i).Draw(fb);
		}
		for (i=0; i<circles.size(); i++)
		{
			circles.at(i).Draw(fb);
		}
		for (i=0; i<polygons.size(); i++)
		{
			polygons.at(i).draw(fb);
		}
		for (i=0; i<lines.size(); i++)
		{
			lines.at(i).draw(fb);
		}

		cursor.Draw(fb);

		system("clear");
	}
}