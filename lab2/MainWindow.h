//
// Created by max on 2/17/2016.
//

#ifndef TESTPROJECT_WINDOW_H
#define TESTPROJECT_WINDOW_H
#include <iostream>
#include <windows.h>
#include "WindowObject.h"

using namespace std;

class MainWindow: public WindowObject{

public:
    MainWindow(LPCSTR objType, LPCTSTR windowTitle, DWORD styles, Dimensions* dimensions,HWND parentInstance,int hMenu,HINSTANCE hInstance,LPVOID ip):WindowObject(
            0,
            objType,
            windowTitle,
            WS_OVERLAPPEDWINDOW,
            dimensions,
            parentInstance,
            hMenu,
            hInstance,
            ip){}
};


#endif //TESTPROJECT_WINDOW_H
