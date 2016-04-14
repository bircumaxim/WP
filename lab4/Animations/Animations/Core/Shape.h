#pragma once
#include <math.h>

class Shape
{
protected:
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

		if (xDistance <= second->getSize())
			return true;
		if (yDistance <= second->getSize())
			return true;

	}

	//Collision
	void checkForCollide(HWND hwnd) {
		RECT rect;
		GetClientRect(hwnd, &rect);
		int right = rect.right - rect.left;
		int bottom = rect.bottom - rect.top;

		LeftCollide();
		RightCollide(right);
		TopCollide();
		BottomCollide(bottom);
	}

	bool LeftCollide() {
		if (x - size <= 0) {
			vX *= -1;
			return true;
		}
		return false;
	}

	bool TopCollide() {
		if (y - size <= 0) {
			vY *= -1;
			return true;
		}
		return false;
	}

	bool RightCollide(int right) {
		if (x + size >= right) {
			vX *= -1;
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
};

