//
// Created by max on 2/18/2016.
//

#include "TextLabel.h"
TextLabel::TextLabel(string text){
this->text = text;
}

void TextLabel::drawLabel(HDC hdc,int x ,int y ){
    this->updateLabel(hdc,x,y);
    TextOut(this->hdc,this->posX - text.length()*3.4,this->posY-1.7,text.c_str(),text.length());
}

void TextLabel::updateLabel(HDC hdc, int x, int y){
    this->hdc = hdc;
    this->posX = x;
    this->posY = y;
}

void TextLabel::render(HWND hwnd,RECT windowRect){

    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);
    SetBkMode(hdc,TRANSPARENT);
    GetClientRect(hwnd, &windowRect);

    //TODO Position settor
    this->drawLabel(hdc, windowRect.right/2, windowRect.bottom/2);

    EndPaint(hwnd, &ps);
}