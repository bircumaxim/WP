#pragma once
#include <math.h>

class Shape
{
protected:
	bool isCircle = false;
	int x,y;   //Position
	int vX,vY; //Velocity
	int playSpeed = 2;
	int initialSize = 0;
	int size;
	COLORREF color;

public:

	bool collision(Shape* second) {
		int xDistance = abs(second->x - x);
		int yDistance = abs(second->y - y);

		if (xDistance > (second->getSize() + size))
			return false;
		if (yDistance > (second->getSize() + size))
			return false;

		if (xDistance <= second->getSize()) {
			x = x - playSpeed;
			this->changeDirection();
			second->changeDirection();
			return true;
		}

		if (yDistance <= second->getSize()) {
			this->changeDirection();
			second->changeDirection();
			return true;
		}
		return false;
	}

	//Collision
	int checkForCollide(HWND hwnd) {
		RECT rect;
		GetClientRect(hwnd, &rect);
		int right = rect.right - rect.left;
		int bottom = rect.bottom - rect.top;

		if (LeftCollide() || RightCollide(right)) {
			return 1;
		}
		
		if (TopCollide() || BottomCollide(bottom)) {
			return 2;
		}
	}

	bool LeftCollide() {
		if (x - size + playSpeed <= 0) {
			vX *= -1;
			update();
			return true;
		}
		return false;
	}

	bool TopCollide() {
		if (y - size + playSpeed <= 0) {
			vY *= -1;
			update();
			return true;
		}
		return false;
	}

	bool RightCollide(int right) {
		if (x + size >= right) {
			vX *= -1;
			update();
			return true;
		}
		return false;
	}

	bool BottomCollide(int bottom) {
		if (y + size >= bottom) {
			vY *= -1;
			return true;
		}
		return false;
	}

	virtual void render(HDC hdc) = 0;

	virtual void update() {
		x += vX * playSpeed;
		y += vY * playSpeed;
	}

	int getX() {
		return x;
	}
	
	int getY() {
		return y;
	}

	void setPlaySpeed(int speed) {
		this->playSpeed = speed;
	}

	int getPlaySpeed() {
		return playSpeed;
	}

	void setSize(int size) {
		this->initialSize = this->initialSize == 0 ? size : this->initialSize;
		this->size = size;
	}


	int getSize() {
		return this->size;
	}

	int getInitialSize() {
		return this->initialSize;
	}

	void setColor(COLORREF color) {
		this->color = color;
	}

	void setPosition(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void setVelocity(int vX, int vY) {
		this->vX = vX;
		this->vY = vY;
	}

	bool IsCircle() {
		return this->isCircle;
	}

	COLORREF getColor() {
		return color;
	}

	int getvX() {
		return vX;
	}

	int getvY() {
		return vY;
	}

	void changeDirection() {
		vX *= -1;
		vY *= -1;
	}

	void IncreaseVelocity() {
		if(abs(vX) < 8)
			vX *= 2;
		if(abs(vY) < 8)
			vY *= 2;
	}


	///Random..........................

	void setRandomPosition(HWND hwnd) {
		RECT rect;
		GetClientRect(hwnd, &rect);
		x = (rand() % (rect.right - rect.left)) / 2 + size + 10;
		y = (rand() % (rect.bottom - rect.top)) / 2 + size + 10;
	}

	void setRandomSize() {
		size = (rand() % 15) + 10;
	}

	void setRandomColor() {
		color = RGB(rand() % 255, rand() % 255, rand() % 255);
	}

	void setRandomVelocity() {
		vX = rand() % 1 ? ((rand() % 5) + 1) + sin(((rand() % 5) + 1) * 2)  : ((rand() % 5) + 1) + sin(((rand() % 5) + 1) * 2) * -1;
		vY = rand() % 1 ? ((rand() % 5) + 1) + cos(((rand() % 5) + 1) * 2) : ((rand() % 5) + 1) + cos(((rand() % 5) + 1) * 2) * -1;
	}
};

