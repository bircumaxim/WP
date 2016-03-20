//
// Created by max on 2/18/2016.
//

#include "../include/WindowObject.h"
#include <iostream>
#include <commctrl.h>

using namespace std;

WindowObject::WindowObject(DWORD exStyle,
                           LPCTSTR objectType,
                           LPCSTR objectTitle,
                           DWORD dwStyle,
                           Dimensions *dimensions,
                           HWND parentInstance,
                           HINSTANCE hInstance,
                           LPVOID IpParam){
    this->exStyle = exStyle;
    this->objectType = objectType;
    this->objectTitle = objectTitle;
    this->dwStyle = dwStyle;
    this->dimensions = dimensions;
    this->parrentInstnce = parentInstance;
    this->hInstance = hInstance;
    this->IpParam = IpParam;
    this->objectId = Config::instance().idGen();
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
            (HMENU) objectId,
            (HINSTANCE)this->hInstance,
            this->IpParam
    );
}

HWND WindowObject::getInstance(){
    return this->mainInstance;
}

int WindowObject::getId(){
    return this->objectId;
}

Dimensions* WindowObject::getDimensions() {
    RECT r;
    GetWindowRect(this->mainInstance,&r);

    this->dimensions->setWidth(r.right - r.left);
    this->dimensions->setHeight(r.bottom - r.top);
    this->dimensions->setPosX(r.left);
    this->dimensions->setPosY(r.top);
    return this->dimensions;
}

void WindowObject::setDimensions(Dimensions d) {
    SetWindowPos(this->mainInstance,
                 HWND_TOP,
                 d.getPosX(),
                 d.getPosY(),
                 d.getWidth(),
                 d.getHeight(),
                 SWP_FRAMECHANGED);
}
