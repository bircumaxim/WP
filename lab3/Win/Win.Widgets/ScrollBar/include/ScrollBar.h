//
// Created by bircumaxim on 3/23/2016.
//

#ifndef LAB3_SCROLLBAR_H
#define LAB3_SCROLLBAR_H


#include "../../../Win.Core/include/WindowObject.h"

class ScrollBar: public WindowObject {
private:
    int thumbPosition;
    int minRange;
    int maxRange;
public:
    ScrollBar(DWORD style,Dimensions* dimension,HWND parentInstance,HINSTANCE hinstance):WindowObject(
            0,
            "scrollbar",
            "",
            style,
            dimension,
            parentInstance,
            hInstance,
            NULL){}
    void setRange(int mint, int max);
    int getMinRange();
    int getMaxRange();
    void setThumbPosition(int position);
    int getThumbPosition();
    void update(WPARAM wparam);
};


#endif //LAB3_SCROLLBAR_H
