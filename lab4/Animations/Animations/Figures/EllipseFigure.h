#pragma once
#include "Shape.h"
class EllipseFigure : virtual public Shape
{

public:
	EllipseFigure() {}


	virtual void render(HDC hdc) override {

		SelectObject(hdc, CreateSolidBrush(color));

		int left = x - size;
		int top = y - size / 2;
		int right = x + size;
		int bottom = y + size;

		Ellipse(hdc, left, top, right, bottom);
	}
};

