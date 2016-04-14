#pragma once
#include "MainHelper.h"
#include <math.h>
#define PI 3.14159265
class DynamicAnimation
{
private:
	MainHelper *mainHelper;
	void createShapes() {
		mainHelper = new MainHelper;

		for (int i = 0; i < 10; i++) {
			mainHelper->createShape(rand() % 400, rand() % 400, 25, rand()%3, RGB(rand() & 255, rand() & 255, rand() & 255), ((rand() % 5) + 1) + sin(((rand() % 5) + 1)*2), ((rand() % 5) + 1) + cos(((rand() % 5)+ 1))*2);
		}
		/*mainHelper->createShape(150, 150, 50, 0, RGB(255,0,0), 1, -1);
		mainHelper->createShape(260, 150, 50, 0, RGB(0,255,0), -1, 1);*/
		

	}
public:
	DynamicAnimation() {
		mainHelper = new MainHelper();
		createShapes();
	};


	void playSpeed(int speed) {
		mainHelper->setPlaySpeed(speed);
	}

	void render(HDC hdc) {
		mainHelper->render(hdc);
	}

	void update(HWND hwnd) {
		mainHelper->update(hwnd);
	}

};

