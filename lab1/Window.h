//
// Created by max on 2/17/2016.
//

#ifndef TESTPROJECT_WINDOW_H
#define TESTPROJECT_WINDOW_H
#include <iostream>
#include <windows.h>

using namespace std;

class Window {

private:
    LPCSTR windowTitle;
    int width;
    int height;
    HWND hwnd;
public:

    Window(const LPCSTR &windowTitle, int width, int height, char *szClassName, const HINSTANCE hThisInstance) {
        this->windowTitle = windowTitle;
        this->width = width;
        this->height = height;
        hwnd = CreateWindowEx (
                0,                   /* Extended possibilites for variation */
                szClassName,         /* Classname */
                windowTitle,  /* Title Text */
                WS_OVERLAPPEDWINDOW, /* default window */
                CW_USEDEFAULT,       /* Windows decides the position */
                CW_USEDEFAULT,       /* where the window ends up on the screen */
                width,                 /* The programs width */
                height,                 /* and height in pixels */
                HWND_DESKTOP,        /* The window is a child-window to desktop */
                NULL,                /* No menu */
                hThisInstance,       /* Program Instance handler */
                NULL                 /* No Window Creation data */
        );
    }

    HWND getHwnd(){
        return this->hwnd;
    }

    int getWindoWidth(){
        return this->width;
    }

    int getWindoHeight(){
        return this->height;
    }

    LPCSTR getWindowTitle(){
        return this->windowTitle;
    }
};


#endif //TESTPROJECT_WINDOW_H
