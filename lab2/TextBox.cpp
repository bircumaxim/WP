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

void TextBox::superTextBox(){
    NONCLIENTMETRICS ncb;
    ncb.cbSize = sizeof(ncb);
    SystemParametersInfo(SPI_GETNONCLIENTMETRICS,sizeof(ncb),&ncb,0);
    HFONT hfon = CreateFontIndirectA(&ncb.lfMessageFont);
    SendMessage(this->mainInstance,WM_SETFONT,(WPARAM)hfon,0);
}