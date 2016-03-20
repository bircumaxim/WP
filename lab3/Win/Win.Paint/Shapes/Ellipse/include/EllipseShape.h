//
// Created by bircumaxim on 3/20/2016.
//

#ifndef LAB3_ELIPSE_H
#define LAB3_ELIPSE_H


#include "../../../Core/include/Pen.h"

class EllipseShape : public Pen {
    protected:
        virtual void MouseButtonDown(LPARAM,WPARAM) override ;
        virtual void MouseMove(LPARAM,WPARAM) override ;
        virtual void MouseButtonUp(LPARAM,WPARAM) override ;

    public:
        EllipseShape(HWND hwnd):Pen(hwnd){}
};


#endif //LAB3_ELIPSE_H
