all:
	g++ --std=c++11 -g -pthread Mouse.cpp MouseEvent.cpp main.cpp cursor.cpp base.cpp line.cpp Rectangle.cpp Controller.cpp KeyboardController.cpp circle.cpp polygon1.cpp
