#pragma once
#include "Shape.h"

class Square: virtual public Shape
{

public:
	Square() {
		isCircle = false;
	}


	virtual void render(HDC hdc) override {

		SelectObject(hdc, CreateSolidBrush(color));

		int left = x - size;
		int top = y - size;
		int right = x + size;
		int bottom = y + size;

		RECT square = { left, top, right, bottom };
		FillRect(hdc, &square, (HBRUSH)(color));
	}
};

