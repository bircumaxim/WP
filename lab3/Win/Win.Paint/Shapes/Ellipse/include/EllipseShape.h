//
// Created by bircumaxim on 3/20/2016.
//

#ifndef LAB3_ELIPSE_H
#define LAB3_ELIPSE_H

#include "../../../Tools/Pen/include/Pen.h"

class EllipseShape : public Pen {
    private:
        int length;
        bool regular = false;
    protected:

        virtual void MouseButtonDown(LPARAM,WPARAM) override ;
        virtual void MouseMove(LPARAM,WPARAM) override ;
        virtual void MouseButtonUp(LPARAM,WPARAM) override ;

    public:
        EllipseShape(HWND hwnd):Pen(hwnd){}

        void setRegular(bool regular) {
            EllipseShape::regular = regular;
        }


        bool isRegular() const {
            return regular;
        }
};


#endif //LAB3_ELIPSE_H
