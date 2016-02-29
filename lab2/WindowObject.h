//
// Created by max on 2/18/2016.
//

#ifndef LAB1_WINDOWOBJECT_H
#define LAB1_WINDOWOBJECT_H
#include <windows.h>
#include "Dimensions.h"

class WindowObject {
protected:
    WindowObject(DWORD,LPCTSTR,LPCSTR,
                 DWORD,Dimensions*,
                 HWND,int,HINSTANCE,LPVOID);
    HWND mainInstance;
    DWORD exStyle;
    LPCTSTR objectType;
    LPCSTR objectTitle;
    DWORD dwStyle;
    Dimensions *dimensions;
    HWND parrentInstnce;
    int ID_OBJECT;
    HINSTANCE hInstance;
    LPVOID IpParam;



public:
    HWND getInstance();
    int getId();
    int getWidh();
    int getHeight();
    void setPosition(int,int);

};


#endif //LAB1_WINDOWOBJECT_H
