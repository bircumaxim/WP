#pragma once
#include "Shape.h"

class Circle : virtual public Shape
{
public:
	Circle(){ }

	virtual void render(HDC hdc) override {
		
		SelectObject(hdc, CreateSolidBrush(color));

		int left = x - size;
		int top = y - size;
		int right = x + size;
		int bottom = y + size;

		Ellipse(hdc, left, top, right, bottom);
	}
};

