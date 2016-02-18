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
    void updateLabel(HDC hdc, int x, int y){
        this->hdc = hdc;
        this->posX = x;
        this->posY = y;

    }

public:
    TextLabel(string text){
        this->text = text;
    }

    void renderLabel(HDC hdc,int x ,int y ){
        this->updateLabel(hdc,x,y);
        TextOut(this->hdc,this->posX - text.length()*3.4,this->posY-1.7,text.c_str(),text.length());
    }


};


#endif //LAB1_TEXTLABEL_H
