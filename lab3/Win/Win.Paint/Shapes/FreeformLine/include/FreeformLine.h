//
// Created by bircumaxim on 3/20/2016.
//

#ifndef LAB3_FREEFROMLINE_H
#define LAB3_FREEFROMLINE_H

#include "../../../Tools/Pen/include/Pen.h"

class FreeformLine : public Pen {
    private:
        virtual void MouseButtonDown(LPARAM,WPARAM) override;
        virtual void MouseButtonUp(LPARAM,WPARAM) override;
        virtual void MouseMove(LPARAM,WPARAM) override;

    public:

        FreeformLine(HWND hwnd) : Pen(hwnd){}

};


#endif //LAB3_FREEFROMLINE_H
