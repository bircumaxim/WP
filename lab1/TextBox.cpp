//
// Created by max on 2/18/2016.
//


#include "TextBox.h"

LPCSTR TextBox::getText() {
    char buff[1024];
    GetWindowText(this->mainInstance,buff,2014);
    LPCSTR result = buff;
    return result;
}

void TextBox::setText(TCHAR *newText) {
    SetWindowText(this->mainInstance,newText);
}

