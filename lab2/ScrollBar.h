//
// Created by max on 2/27/2016.
//

#ifndef LAB2_SCROLLBAR_H
#define LAB2_SCROLLBAR_H


#include "WindowObject.h"

class ScrollBar: public WindowObject {
    private:
        int thumbPosition;
        int minRange;
        int maxRange;
    public:
        ScrollBar(DWORD style,Dimensions* dimension,HWND parentInstance,int id,HINSTANCE hinstance):WindowObject(
                0,
                "scrollbar",
                "",
                style,
                dimension,
                parentInstance,
                id,
                hInstance,
                NULL){}
    void setRange(int mint, int max);
    int getMinRange();
    int getMaxRange();
    void setThumbPosition(int position);
    int getThumbPosition();
};


#endif //LAB2_SCROLLBAR_H
