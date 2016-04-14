#pragma once
#include "MainHelper.h"
#include <math.h>
#define PI 3.14159265
class DynamicAnimation
{
private:
	bool isRunning = false;
	MainHelper *mainHelper;
	void createShapes(HWND hwnd) {
		mainHelper = new MainHelper(hwnd);

		for (int i = 0; i < 5; i++) {
			mainHelper->createRandomShape(rand()%2);
		}
		
	}
public:
	void start() {
		isRunning = true;
	}

	void stop() {
		isRunning = false;
	}

	DynamicAnimation(HWND hwnd) {
		mainHelper = new MainHelper();
		createShapes(hwnd);
	};


	void playSpeed(int speed) {
		mainHelper->setPlaySpeed(speed);
	}

	void render(HDC hdc) {
		if (isRunning) mainHelper->render(hdc);
	}

	void update(HWND hwnd) {
		if (isRunning) mainHelper->update(hwnd);
	}


	void addShape(int x, int y,int type) {
		mainHelper->createShape(x, y, 10, type, RGB(rand() % 255, rand() % 255, rand() % 255), rand() % 1 ? ((rand() % 5) + 1) + sin(((rand() % 5) + 1) * 2) : ((rand() % 5) + 1) + sin(((rand() % 5) + 1) * 2) * -1 , rand() % 1 ? ((rand() % 5) + 1) + sin(((rand() % 5) + 1) * 2) : ((rand() % 5) + 1) + sin(((rand() % 5) + 1) * 2) * -1);
	}
};

