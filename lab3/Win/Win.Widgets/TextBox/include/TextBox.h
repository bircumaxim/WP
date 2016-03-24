//
// Created by bircumaxim on 3/23/2016.
//

#ifndef LAB3_TEXTBOX_H
#define LAB3_TEXTBOX_H


#include <windows.h>
#include <iostream>
#include "../../../Win.Core/include/WindowObject.h"

using namespace std;

class TextBox:public WindowObject  {
private:
    LPCSTR text;
public:
    TextBox(LPCSTR text,HWND parentInstance, Dimensions *dimensions) :WindowObject(
            NULL,
            "Edit",
            text,WS_CHILD | WS_VISIBLE | WS_BORDER,
            dimensions,
            parentInstance,
            (HINSTANCE)GetWindowLong(parentInstance,GWL_HINSTANCE),
            NULL){}

    LPCSTR getText();
    void setText(TCHAR*);

    void superTextBox();
};


#endif //LAB3_TEXTBOX_H
