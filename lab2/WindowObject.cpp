//
// Created by max on 2/18/2016.
//

#include "WindowObject.h"
#include <iostream>
using namespace std;

WindowObject::WindowObject(DWORD exStyle,LPCTSTR objectType, LPCSTR objectTitle, DWORD dwStyle, Dimensions *dimensions,HWND parentInstance, int ID_OBJECT,HINSTANCE hInstance, LPVOID IpParam){
    this->exStyle = exStyle;
    this->objectType = objectType;
    this->objectTitle = objectTitle;
    this->dwStyle = dwStyle;
    this->dimensions = dimensions;
    this->parrentInstnce = parentInstance;
    this->ID_OBJECT = ID_OBJECT;
    this->hInstance = hInstance;
    this->IpParam = IpParam;

    this->mainInstance = CreateWindowEx(
            this->exStyle,
            this->objectType,
            this->objectTitle,
            this->dwStyle,
            this->dimensions->getPosX(),
            this->dimensions->getPosY(),
            this->dimensions->getWidth(),
            this->dimensions->getHeight(),
            parentInstance,
            (HMENU) this->ID_OBJECT,
            (HINSTANCE)this->hInstance,
            this->IpParam
    );
}

HWND WindowObject::getInstance(){
    return this->mainInstance;
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
