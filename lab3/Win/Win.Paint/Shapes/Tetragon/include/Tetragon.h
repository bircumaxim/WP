//
// Created by bircumaxim on 3/20/2016.
//

#ifndef LAB3_TETRAGON_H
#define LAB3_TETRAGON_H


#include "../../../Core/include/Pen.h"

class Tetragon : public Pen {
    virtual void MouseButtonDown(LPARAM,WPARAM) override;
    virtual void MouseButtonUp(LPARAM,WPARAM) override;
    virtual void MouseMove(LPARAM,WPARAM) override;
public:
    Tetragon(HWND hwnd) : Pen(hwnd){}
};


#endif //LAB3_TETRAGON_H
