#pragma once
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Arrow.h"
#include "EllipseFigure.h"

#include <vector>

using namespace std;

class MainHelper
{
private:
	HWND hwnd;
	int animationPlaySpeed = 2;
	vector<Shape*> shapes;
	enum ShapeType {
		CIRCLE,
		TRIANGLE,
		SQUARE,
		ARROW,
		ELLIPSE
	};

	void setupShape(Shape* shape, int x, int y, int size, COLORREF color, int vX, int vY) {
		shape->setSize(size);
		shape->setColor(color);
		shape->setPosition(x, y);
		shape->setVelocity(vX,vY);
}

public:
	MainHelper() {}
	
	void setPlaySpeed(int speed) {
		for (std::vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); ++it) {
			Shape *shape = *it;
			shape->setPlaySpeed(speed);
		}
		animationPlaySpeed = speed;
	}

	void createShape(int x, int y, int size, int ShapeType, COLORREF color, int vX, int vY) {
		Shape *newShape = NULL;
		switch (ShapeType)
		{
		case CIRCLE:
			newShape = new Circle();
			break;
		case TRIANGLE:
			newShape = new Triangle();
			break;
		case SQUARE:
			newShape = new Square();
			break;
		case ARROW:
			newShape = new Arrow();
			break;
		case ELLIPSE:
			newShape = new EllipseFigure();
			break;
		}
		setupShape(newShape, x, y, size, color, vX, vY);
		shapes.push_back(newShape);
	}

	void render(HDC hdc) {

		for (std::vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); ++it) {
			Shape *shape = *it;
			shape->render(hdc);
		}
	}

	void checkCollision(Shape *first) {
		for (std::vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); ++it) {
			Shape *second = *it;
			if(first != second)
				first->collision(second);
		}
	}

	void update(HWND hwnd) {
		
		RECT rect;
		GetClientRect(hwnd, &rect);

		for (std::vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); ++it) {
			Shape *shape = *it;
			shape->update();
			shape->checkForCollide(hwnd);	
			checkCollision(shape);
		}

		InvalidateRect(hwnd, &rect, false);
	}

	void updateSize(HWND hwnd) {
		RECT rect;
		GetClientRect(hwnd, &rect);

		for (std::vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); ++it) {
			Shape *shape = *it;
			RECT rt;
			GetWindowRect(hwnd, &rt);
			if (shape->getSize() > 25) {
				shape->setSize(shape->getSize() - animationPlaySpeed);
			}
			else {
				shape->setSize(shape->getInitialSize());
			}
		}
		InvalidateRect(hwnd, &rect, false);
	}

};

