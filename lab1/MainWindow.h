//
// Created by max on 2/17/2016.
//

#ifndef TESTPROJECT_WINDOW_H
#define TESTPROJECT_WINDOW_H
#include <iostream>
#include <windows.h>
#include "WindowObject.h"

using namespace std;

class MainWindow{

private:
    LPCSTR windowTitle;
    HWND mainInstance;
    HWND parentInstance;
    Dimensions *dimensions;
public:

    MainWindow(const LPCSTR &windowTitle,Dimensions *dimens, char *szClassName, const HINSTANCE hThisInstance,HWND parentInstace) {
        this->windowTitle = windowTitle;
        this->mainInstance = CreateWindowEx (
                0,                   /* Extended possibilites for variation */
                szClassName,         /* Classname */
                windowTitle,  /* Title Text */
                WS_OVERLAPPEDWINDOW, /* default window */
                dimens->getPosX(),       /* Windows decides the position */
                dimens->getPosY(),       /* where the window ends up on the screen */
                dimens->getWidth(),                 /* The programs width */
                dimens->getHeight(),                 /* and height in pixels */
                parentInstace,        /* The window is a child-window to desktop */
                NULL,                /* No menu */
                hThisInstance,       /* Program Instance handler */
                NULL                 /* No Window Creation data */
        );
    }

    HWND getInstace(){
        return this->mainInstance;
    }

    Dimensions* getDimensions(){
        return this->dimensions;
    }

};


#endif //TESTPROJECT_WINDOW_H
