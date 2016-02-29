//
// Created by max on 2/27/2016.
//
#include <iostream>
using namespace std;
#include "ScrollBar.h"
void ScrollBar::setRange(int min,int max){
    this->maxRange = max;
    this->minRange = min;
    SetScrollRange(this->getInstance(),SB_CTL,min,max,FALSE);
}

int ScrollBar::getMinRange(){
    return this->minRange;
}

int ScrollBar::getMaxRange(){
    return this->maxRange;
}

void ScrollBar::setThumbPosition(int position) {
    this->thumbPosition = position;
    SetScrollPos(this->getInstance(),SB_CTL,position,TRUE);
}

int ScrollBar::getThumbPosition() {
    return this->thumbPosition;
}
