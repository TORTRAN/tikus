#include "Mouse.h"

#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>	/* for input_event and input constants */
#include <linux/fb.h>		/* for frame buffer properties */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Mouse::Mouse(): xres(1368), yres(768)
{
	int event_id[31];		// event identifiers for mice devices

	// reset all event_id with -1
	memset(event_id, 255, sizeof(event_id));


	// detect event number which handle mouse
	FILE *fdevices = fopen("/proc/bus/input/devices", "r");
	if (fdevices == NULL) {
		printf("Error reading input devices\n");
		exit(1);
	}

	char line[999];
	while (!feof(fdevices)) {

		fgets(line, 999, fdevices);
		char info[999];
		int temp_mouse_id = -1;
		int temp_event_id = -1;

		// looking for handler
		if (sscanf(line, "H: Handlers=%[^\n]s", info) == 1) {
			char *part = strtok(info, " ");

			while (part != NULL) {
				int temp;
				if (sscanf(part, "mouse%d", &temp) == 1) {
					temp_mouse_id = temp;
				} else if (sscanf(part, "event%d", &temp) == 1) {
					temp_event_id = temp;
				}

			part = strtok(NULL, " ");
			}
		}

		if (temp_mouse_id != -1) {
			threads.push_back(std::thread(&Mouse::mouseController, this, temp_event_id));
		}
	}

	fclose(fdevices);
}

Mouse::Mouse(int xres, int yres): xres(1368), yres(768)
{
	int event_id[31];		// event identifiers for mice devices

	// reset all event_id with -1
	memset(event_id, 255, sizeof(event_id));
	// detect event number which handle mouse
	FILE *fdevices = fopen("/proc/bus/input/devices", "r");
	if (fdevices == NULL) {
		printf("Error reading input devices\n");
		exit(1);
	}

	char line[999];
	while (!feof(fdevices)) {

		fgets(line, 999, fdevices);
		char info[999];
		int temp_mouse_id = -1;
		int temp_event_id = -1;

		// looking for handler
		if (sscanf(line, "H: Handlers=%[^\n]s", info) == 1) {
			char *part = strtok(info, " ");

			while (part != NULL) {
				int temp;
				if (sscanf(part, "mouse%d", &temp) == 1) {
					temp_mouse_id = temp;
				} else if (sscanf(part, "event%d", &temp) == 1) {
					temp_event_id = temp;
				}

			part = strtok(NULL, " ");
			}
		}

		if (temp_mouse_id != -1) {
			threads.push_back(std::thread(&Mouse::mouseController, this, temp_event_id));
		}
	}

	fclose(fdevices);
}

void Mouse::mouseController(int eventId)
{
	int fd;
	struct input_event event;
	char event_filename[20];

	sprintf(event_filename, "/dev/input/event%d", eventId);
	
	// access the device file
	fd = open(event_filename, O_RDONLY);
	if (fd == -1) {
		printf("Error opening device information (%s)\n", event_filename);
		exit(1);
	} else {
		// printf("mfd[%d] = %d, event%d\n", i, mfd[i], event_id[i]);
	}

	int ret;
	while (ret = read(fd, &event, sizeof(event)) != -1) {
		MouseEvent currentEvent;
		switch (event.type) {
			// nothing happened
			case EV_SYN:
				break;

			// key press
			case EV_KEY:
				currentEvent.setX(this->x);
				currentEvent.setY(this->y);

				switch (event.code) {
					// left key
					case BTN_LEFT:
						//left = event.value;
						if (event.value == 0)
						{
							currentEvent.setButton(MouseEvent::Button::Left);
							addEvent(currentEvent);
						}

						break;

					// right key
					case BTN_RIGHT:
						//right = event.value;
						if (event.value == 0)
						{
							currentEvent.setButton(MouseEvent::Button::Right);
							addEvent(currentEvent);
						}
						break;

					// middle key
					case BTN_MIDDLE:
						//middle = event.value;
						if (event.value == 0)
						{
							currentEvent.setButton(MouseEvent::Button::Middle);
							addEvent(currentEvent);
						}
						break;
				}
			break;

			// relative movement
			case EV_REL:
				switch (event.code) {
					// x axis
					case REL_X:
						x += event.value;
						if (x < 0) x = 0;
						if (x >= xres) x = xres - 1;
						break;

					// y axis
					case REL_Y:
						y += event.value;
						if (y < 0) y = 0;
						if (y >= yres) y = yres - 1;
						break;

					// wheel
					case REL_WHEEL:
						//wheel += event.value;
						break;
				}
			break;
		}
	}
}

void Mouse::addEvent(MouseEvent e)
{
	std::lock_guard <std::mutex> lock(m);
	eventQueue.push(e);
}

MouseEvent Mouse::getMouseEvent()
{
	std::lock_guard <std::mutex> lock(m);
	MouseEvent out = eventQueue.front();
	eventQueue.pop();
	return out;
}

bool Mouse::eventAvailable()
{
	return !eventQueue.empty();
}

int Mouse::getX()
{
	return x;
}

int Mouse::getY()
{
	return y;
}