//
// Created by bircumaxim on 3/20/2016.
//

#ifndef LAB3_STRAITLINE_H
#define LAB3_STRAITLINE_H

#include "../../../Tools/Pen/include/Pen.h"

class StraightLine : public Pen {
    private:
        bool vertical = false;
        bool horizontal = false;
        bool conected = true;
        virtual void MouseButtonDown(LPARAM, WPARAM) override;
        virtual void MouseButtonUp(LPARAM, WPARAM) override;
        virtual void MouseMove(LPARAM, WPARAM) override;


    public:
        StraightLine(HWND hwnd) : Pen(hwnd){}
        void ExitDrawing();

    bool isVertical() const {
        return vertical;
    }

    void setVertical(bool vertical) {
        StraightLine::vertical = vertical;
    }

    bool isHorizontal() const {
        return horizontal;
    }

    void setHorizontal(bool horizontal) {
        StraightLine::horizontal = horizontal;
    }

    bool isConected() const {
        return conected;
    }

    void setConected(bool conected) {
        StraightLine::conected = conected;
    }
};


#endif //LAB3_STRAITLINE_H
