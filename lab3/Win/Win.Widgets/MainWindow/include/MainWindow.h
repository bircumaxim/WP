//
// Created by max on 2/17/2016.
//

#ifndef LAB3_MAIN_WINDOW_H
#define LAB3_MAIN_WINDOW_H
#include <iostream>
#include <windows.h>
#include "../../../Win.Core/include/WindowObject.h"

using namespace std;

class MainWindow: public WindowObject{

public:
    MainWindow(LPCSTR objType, LPCTSTR windowTitle, DWORD styles, Dimensions* dimensions,HWND parentInstance,HINSTANCE hInstance,LPVOID ip) :
            WindowObject(0, objType, windowTitle, styles, dimensions, parentInstance, hInstance, ip){}
};


#endif //TESTPROJECT_WINDOW_H
