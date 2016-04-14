#pragma once
#include "MainHelper.h"

class StaticAnimation
{
private:
	bool isRunning = false;
	MainHelper *mainHelper;
	
	void createShapes() {
		mainHelper->createShape(100, 300, 50, 0, RGB(255, 0, 0), 1, 1);
		mainHelper->createShape(250, 300, 80, 1, RGB(0, 0, 255), 1, 1);
		mainHelper->createShape(100, 70, 60, 2, RGB(0, 255, 0), 1, 1);
		mainHelper->createShape(250, 70, 120, 3, RGB(255, 0, 0), 1, 1);
		mainHelper->createShape(700, 150, 250, 4, RGB(255, 0, 255), 1, 1);
	}

public:
	void start() {
		isRunning = true;
	}

	void stop() {
		isRunning = false;
	}

	StaticAnimation() {
		mainHelper = new MainHelper();
		createShapes();
	};
	
	void playSpeed(int speed) {
		mainHelper->setPlaySpeed(speed);
	}

	void render(HDC hdc) {
		if(isRunning) mainHelper->render(hdc);
	}

	void update(HWND hwnd) {
		if (isRunning) mainHelper->updateSize(hwnd);
	}
	
};

