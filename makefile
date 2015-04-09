all:
	g++ --std=c++11 -pthread Mouse.cpp MouseEvent.cpp main.cpp cursor.cpp base.cpp line.cpp polygon.cpp
