//
// Created by bircumaxim on 3/21/2016.
//

#ifndef LAB3_ERASER_H
#define LAB3_ERASER_H


#include "../../Pen/include/Pen.h"

class Eraser : public Pen {

    virtual void MouseButtonDown(LPARAM lparam, WPARAM wparam) override;

    virtual void MouseMove(LPARAM lparam, WPARAM wparam) override;

    virtual void MouseButtonUp(LPARAM lparam, WPARAM wparam) override;

public:
    Eraser(const HWND hwnd) : Pen(hwnd){
        this->setPenColor(RGB(255,255,255));
        this->setBrushColor(RGB(255,255,255));
    }
};


#endif //LAB3_ERASER_H
