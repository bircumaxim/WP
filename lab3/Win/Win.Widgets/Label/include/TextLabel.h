//
// Created by bircumaxim on 3/23/2016.
//

#ifndef LAB3_TEXTLABEL_H
#define LAB3_TEXTLABEL_H

#include <iostream>
#include <windows.h>
using namespace std;

class TextLabel{
private:
    string text;
    HDC hdc;
    int posX;
    int posY;
    void updateLabel(HDC hdc, int x, int y);

public:

    TextLabel(string text);

    void drawLabel(HDC hdc,int x ,int y );

    void render(HWND,RECT);

    HDC getHdc();

    void renderAtPosition(HWND,int,int);
};


#endif //LAB3_TEXTLABEL_H
