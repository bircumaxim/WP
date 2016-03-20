//
// Created by bircumaxim on 3/20/2016.
//

#ifndef LAB3_PEN_H
#define LAB3_PEN_H
#include <windows.h>

class Pen {
    protected:
        int StartX;
        int StartY;
        int EndX;
        int EndY;

        HDC hdc;
        HWND hwnd;
        bool status;
        bool IsDrawing;

        int thickness;
        COLORREF penColor;
        COLORREF brushColor;


        virtual void MouseButtonDown(LPARAM,WPARAM) = 0;
        virtual void MouseMove(LPARAM,WPARAM) = 0;
        virtual void MouseButtonUp(LPARAM,WPARAM) = 0;

        void setThickenss(int);
        void setPenColor(COLORREF);
        void setBrushColor(COLORREF);

        void setupPaintingTools(HDC hdc);
    public:
        Pen(HWND);
        void SwitchMouseMessages(UINT, LPARAM, WPARAM);
        void setStatus(bool);
        void setColor(COLORREF);
        void setThickness(int);

};


#endif //LAB3_PEN_H
