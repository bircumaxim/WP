//
// Created by bircumaxim on 3/23/2016.
//

#include "../include/ScrollBar.h"
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


void ScrollBar::update(WPARAM wparam) {
    switch(LOWORD(wparam)) {
        case SB_PAGELEFT:
            if (this->getThumbPosition() > 0 && this->getThumbPosition() < 255)
                this->setThumbPosition(this->getThumbPosition() - 15);
            break;
        case SB_LINELEFT:
            if (this->getThumbPosition() > 0 && this->getThumbPosition() < 255)
                this->setThumbPosition(this->getThumbPosition() - 1);
            break;
        case SB_PAGERIGHT:
            if (this->getThumbPosition() > 0 && this->getThumbPosition() < 255)
                this->setThumbPosition(this->getThumbPosition() + 15);
            break;
        case SB_LINERIGHT:
            if (this->getThumbPosition() > 0 && this->getThumbPosition() < 255)
                this->setThumbPosition(this->getThumbPosition() + 1);
            break;
        case SB_THUMBPOSITION:
            if (this->getThumbPosition() >= 0 && this->getThumbPosition() <= 255)
                this->setThumbPosition(HIWORD(wparam));
            break;
        default:
            break;
    }
}


