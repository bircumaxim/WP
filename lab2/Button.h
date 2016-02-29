//
// Created by max on 2/18/2016.
//

#ifndef LAB1_BUTTON_H
#define LAB1_BUTTON_H
#include "WindowObject.h"
#include <iostream>
using namespace std;

class Button:public WindowObject {
public:
    DWORD btStyle = WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON;
    Button(LPCSTR buttonTitle,HWND parentInstance,int id,Dimensions *dimensions)
            :WindowObject(0,
                          "BUTTON",
                          buttonTitle,
                          WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                          dimensions,
                          parentInstance,
                          id,
                          (HINSTANCE) GetWindowLong(parentInstance, GWL_HINSTANCE),
                          NULL){
    }

};


#endif //LAB1_BUTTON_H
