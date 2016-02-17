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

    int getWidth() const {
        return width;
    }

    void setWidth(int width) {
        Window::width = width;
    }

    int getHeight() const {
        return height;
    }

    void setHeight(int height) {
        Window::height = height;
    }

    ~Window();
};


#endif //TESTPROJECT_WINDOW_H
