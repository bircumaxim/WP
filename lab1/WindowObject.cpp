//
// Created by max on 2/18/2016.
//

#include "WindowObject.h"
#include <iostream>
using namespace std;

WindowObject::WindowObject(LPCSTR objectType, LPCSTR objectTitle, HWND parentInstance, int ID_OBJECT, Dimensions *dimensions){
    this->dimensions = dimensions;
    this->parrentInstnce = parentInstance;
    this->objectTitle = objectTitle;
    this->objectType = objectType;
    this->ID_OBJECT = ID_OBJECT;
    this->hThisHinstance = hThisHinstance;
    this->mainInstance = CreateWindowEx(
            NULL,
            this->objectType,
            this->objectTitle,
            WS_VISIBLE | WS_CHILD,
            dimensions->getPosX(),
            dimensions->getPosY(),
            dimensions->getWidth(),
            dimensions->getHeight(),
            parentInstance,
            (HMENU) ID_OBJECT,
            (HINSTANCE)GetWindowLong(parentInstance,GWL_HINSTANCE),
            NULL
    );
}

HWND WindowObject::getInstance(){
    return mainInstance;
}

int WindowObject::getId(){
    return this->ID_OBJECT;
}

int WindowObject::getWidh(){
    RECT r;
    GetWindowRect(this->mainInstance,&r);
    return r.right - r.left;
}

int WindowObject::getHeight(){
    RECT r;
    GetWindowRect(this->mainInstance,&r);
    return r.bottom - r.top;
}

void WindowObject::setPosition(int x, int y) {
    if(x-dimensions->getPosX() >= 0 && y-dimensions->getPosY() >= 0)
        SetWindowPos(mainInstance,HWND_TOP,x-dimensions->getPosX(),y-dimensions->getPosY(),getWidh(),getHeight(),SWP_FRAMECHANGED);
}
