//
// Created by max on 2/18/2016.
//

#include "WindowObject.h"
WindowObject::WindowObject(LPCSTR objectType, LPCSTR objectTitle, HWND parentInstance, int ID_OBJECT, Dimensions *dimensions){
    this->parrentInstnce = parentInstance;
    this->objectTitle = objectTitle;
    this->objectType = objectType;
    this->ID_OBJECT = ID_OBJECT;
    this->hThisHinstance = hThisHinstance;
    this->mainInstance = CreateWindowEx(
            (DWORD)NULL,
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