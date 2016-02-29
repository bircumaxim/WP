//
// Created by max on 2/18/2016.
//

#ifndef LAB1_TEXTBOX_H
#define LAB1_TEXTBOX_H
#include <windows.h>
#include "WindowObject.h"
#include <iostream>
using namespace std;

class TextBox:public WindowObject  {
private:
    LPCSTR text;
public:
    TextBox(LPCSTR text,HWND parentInstance, int id, Dimensions *dimensions) :WindowObject(
            NULL,
            "Edit",
            text,WS_CHILD | WS_VISIBLE | WS_BORDER,
            dimensions,
            parentInstance,
            id,(HINSTANCE)GetWindowLong(parentInstance,GWL_HINSTANCE),
            NULL){}

    LPCSTR getText();
    void setText(TCHAR*);

    void superTextBox();
};


#endif //LAB1_TEXTBOX_H
