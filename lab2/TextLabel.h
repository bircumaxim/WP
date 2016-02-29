//
// Created by max on 2/18/2016.
//

#ifndef LAB1_TEXTLABEL_H
#define LAB1_TEXTLABEL_H
#include <windows.h>
#include <iostream>
#include "Dimensions.h"
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


#endif //LAB1_TEXTLABEL_H
