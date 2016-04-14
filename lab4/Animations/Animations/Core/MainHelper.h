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
		SQUARE,
		TRIANGLE,
		ARROW,
		ELLIPSE
	};

	void setupShape(Shape* shape, int x, int y, int size, COLORREF color, int vX, int vY) {
		shape->setSize(size);
		shape->setColor(color);
		shape->setPosition(x, y);
		shape->setVelocity(vX,vY);
	}

	void setupRandomShape(Shape* shape) {
		shape->setRandomSize();
		shape->setRandomColor();
		shape->setRandomPosition(hwnd);
		shape->setRandomVelocity();
	}

	int circlesToCreate = 0;
	int squaresToCreate = 0;
	void changeColorAndMultiply(Shape* first, Shape *second) {
		if (first->IsCircle() && second->IsCircle()) {
			first->setRandomColor();
			second->setColor(first->getColor());
			circlesToCreate++;
		}
		if (!first->IsCircle() && !second->IsCircle()) {
			squaresToCreate++;
			first->setRandomColor();
			second->setColor(first->getColor());
		}
	}

	void switchShape(Shape **shape) {
		Shape *temp;

		int x = (*shape)->getX();
		int y = (*shape)->getY();
		int size = (*shape)->getSize();
		int vX = (*shape)->getvX();
		int vY = (*shape)->getvY();
		int color = (*shape)->getColor();
		int playSpeed = (*shape)->getPlaySpeed();

		if ((*shape)->IsCircle()) {
			(*shape) = new Square();
			setupShape((*shape),x,y,size,color,vX,vY);

		}
		else {
			(*shape) = new Circle();
			setupShape((*shape), x, y, size, color, vX, vY);
		}
		(*shape)->setPlaySpeed(playSpeed);
	}

	

public:
	MainHelper() {}
	MainHelper(HWND hwnd) {
		this->hwnd = hwnd;
	}

	void setPlaySpeed(int speed) {
		for (std::vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); ++it) {
			Shape *shape = *it;
			shape->setPlaySpeed(speed);
		}
		animationPlaySpeed = speed;
	}

	void createRandomShape(int ShapeType) {
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
		setupRandomShape(newShape);
		shapes.push_back(newShape);
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
			if (first != second) {
				if(first->collision(second))
					changeColorAndMultiply(first,second);
			}
				
		}
	}


	void update(HWND hwnd) {

		RECT rect;
		GetClientRect(hwnd, &rect);

		for (std::vector<Shape*>::iterator shape = shapes.begin(); shape != shapes.end(); ++shape) {
			(*shape)->update();
			switch ((*shape)->checkForCollide(hwnd)) {
			case 1:
				switchShape(&(*shape));
				break;
			case 2:
				(*shape)->IncreaseVelocity();
				break;
			}
			checkCollision((Shape*)(*shape));
		}

	/*	for (int i = circlesToCreate; i > 0; i--) {
			createRandomShape(0);
		}
		for (int i = squaresToCreate; i > 0; i--) {
			createRandomShape(1);
		}*/
		circlesToCreate = 0;
		squaresToCreate = 0;

		InvalidateRect(hwnd, &rect, false);
	}






	void updateSize(HWND hwnd) {
		RECT rect;
		GetClientRect(hwnd, &rect);

		for (std::vector<Shape*>::iterator shape = shapes.begin(); shape != shapes.end(); ++shape) {
			RECT rt;
			GetWindowRect(hwnd, &rt);
			if ((*shape)->getSize() > 25) {
				(*shape)->setSize((*shape)->getSize() - animationPlaySpeed);
			}
			else {
				(*shape)->setSize((*shape)->getInitialSize());
			}
		}
		InvalidateRect(hwnd, &rect, false);
	}

};

