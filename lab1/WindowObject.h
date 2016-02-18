//
// Created by max on 2/18/2016.
//

#ifndef LAB1_WINDOWOBJECT_H
#define LAB1_WINDOWOBJECT_H
#include <windows.h>
#include "Dimensions.h"

class WindowObject {
protected:
    HWND mainInstance;
    HWND parrentInstnce;
    LPCSTR objectTitle;
    LPCTSTR objectType;
    int ID_OBJECT;
    HINSTANCE hThisHinstance;
    Dimensions *dimensions;
public:
    WindowObject(LPCSTR,LPCSTR,HWND,int,Dimensions*);
    HWND getInstance();
    int getId();
    void setPosition(int,int);

    int getWidh();

    int getHeight();
};


#endif //LAB1_WINDOWOBJECT_H
