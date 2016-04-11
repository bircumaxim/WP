//
// Created by bircumaxim on 3/20/2016.
//

#ifndef LAB3_BEZIER_H
#define LAB3_BEZIER_H


#include "../../Tools/Pen/include/Pen.h"

class Bezier : public Pen {
    private:
        POINT points[4];
        virtual void MouseButtonDown(LPARAM,WPARAM) override ;
        virtual void MouseMove(LPARAM,WPARAM) override ;
        virtual void MouseButtonUp(LPARAM,WPARAM) override ;
        void DrawBezier (HDC, POINT[]);
    public:
        Bezier(HWND hwnd):Pen(hwnd){
            RECT windowRect;
            GetWindowRect(hwnd,&windowRect);
            int cxClient = windowRect.right - windowRect.left ;
            int cyClient = windowRect.bottom - windowRect.top  ;
            points[0].x = cxClient / 4 ;
            points[0].y = cyClient / 2 ;
            points[1].x = cxClient / 2 ;
            points[1].y = cyClient / 4 ;
            points[2].x = cxClient / 2 ;
            points[2].y = 3 * cyClient / 4 ;
            points[3].x = 3 * cxClient / 4 ;
            points[3].y = cyClient / 2 ;
        };

};


#endif //LAB3_BEZIER_H
