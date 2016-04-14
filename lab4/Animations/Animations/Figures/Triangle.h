#pragma once
#include "Shape.h"
class Triangle : virtual public Shape
{
public:
	Triangle() { }
	
	virtual void render(HDC hdc) override {

		SelectObject(hdc, CreateSolidBrush(color));

		POINT Pt[3];
		Pt[0].x = x;
		Pt[0].y = y + size;
		Pt[1].x = x + size;
		Pt[1].y = y - size;
		Pt[2].x = x - size;
		Pt[2].y = y - size;
		
		Polygon(hdc, Pt, 3);
	}
	
};

