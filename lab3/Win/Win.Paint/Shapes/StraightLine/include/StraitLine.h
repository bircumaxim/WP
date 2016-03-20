//
// Created by bircumaxim on 3/20/2016.
//

#ifndef LAB3_STRAITLINE_H
#define LAB3_STRAITLINE_H


#include "../../../Core/include/Pen.h"

class StraitLine : public Pen {
    private:
        bool vertical = false;
        bool horizontal = false;
        bool conected = false;
        virtual void MouseButtonDown(LPARAM, WPARAM) override;
        virtual void MouseButtonUp(LPARAM, WPARAM) override;
        virtual void MouseMove(LPARAM, WPARAM) override;


    public:
        StraitLine(HWND hwnd) : Pen(hwnd){}
        void ExitDrawing();

    bool isVertical() const {
        return vertical;
    }

    void setVertical(bool vertical) {
        StraitLine::vertical = vertical;
    }

    bool isHorizontal() const {
        return horizontal;
    }

    void setHorizontal(bool horizontal) {
        StraitLine::horizontal = horizontal;
    }

    bool isConected() const {
        return conected;
    }

    void setConected(bool conected) {
        StraitLine::conected = conected;
    }
};


#endif //LAB3_STRAITLINE_H
