//
// Created by max on 2/18/2016.
//

#ifndef LAB1_WINDOWOBJECT_H
#define LAB1_WINDOWOBJECT_H
#include <windows.h>
#include "Dimensions.h"
#include "Config.h"

class WindowObject {
protected:
    WindowObject(DWORD,LPCTSTR,LPCSTR,
                 DWORD,Dimensions*,
                 HWND,HINSTANCE,LPVOID);
    HWND mainInstance;
    DWORD exStyle;
    LPCTSTR objectType;
    LPCSTR objectTitle;
    DWORD dwStyle;
    Dimensions *dimensions;
    HWND parrentInstnce;
    int objectId;
    HINSTANCE hInstance;
    LPVOID IpParam;



public:
    HWND getInstance();
    int getId();
    void setDimensions(Dimensions);
    Dimensions *getDimensions();

};


#endif //LAB1_WINDOWOBJECT_H
