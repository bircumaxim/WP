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
    TextBox(LPCSTR text,HWND parent, int id, Dimensions *dimensions)
            :WindowObject("Edit",text,parent,id,dimensions){

    }

    LPCSTR getText();
    void setText(TCHAR*);
    void superTextBox();
};


#endif //LAB1_TEXTBOX_H
