#pragma once
#include "Shape.h"

class Arrow : virtual public Shape
{
public:
	Arrow() {}
	virtual void render(HDC hdc) override {

		SelectObject(hdc, CreateSolidBrush(color));

		POINT Pt[7];
		Pt[0].x = x;
		Pt[0].y = y;
		Pt[1].x = x + size;
		Pt[1].y = y;
		Pt[2].x = x + size;
		Pt[2].y = y - (size - 80);
		Pt[3].x = x + size + 80;
		Pt[3].y = y + size - 70;
		Pt[4].x = x + size;
		Pt[4].y = y + size - 20;
		Pt[5].x = x + size;
		Pt[5].y = y + size - 40;
		Pt[6].x = x;
		Pt[6].y = y + size - 40;

		Polygon(hdc, Pt, 7);
	}
};

