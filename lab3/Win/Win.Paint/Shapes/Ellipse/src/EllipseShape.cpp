//
// Created by bircumaxim on 3/20/2016.
//

#include "../include/EllipseShape.h"
#include <iostream>
using namespace std;

void EllipseShape::MouseButtonDown(LPARAM lParam,WPARAM wparam) {
    hdc = GetDC(hwnd);
    StartX = LOWORD(lParam);
    StartY = HIWORD(lParam);

    EndX = LOWORD(lParam);
    EndY = HIWORD(lParam);

    SetROP2(hdc, R2_XORPEN);
    setupPaintingTools(hdc);
    Ellipse(hdc,StartX,StartY,EndX,EndY);

    IsDrawing = true;
    ReleaseDC(hwnd, hdc);
}

void EllipseShape::MouseButtonUp(LPARAM lParam,WPARAM wparam) {
    hdc = GetDC(hwnd);

    EndX = LOWORD(lParam);
    EndY = HIWORD(lParam);

    SetROP2(hdc, R2_XORPEN);
    setupPaintingTools(hdc);
//    Ellipse(hdc,StartX,StartY,EndX,EndY);

    IsDrawing = FALSE;
    length = 0;
    ReleaseDC(hwnd, hdc);
}
void EllipseShape::MouseMove(LPARAM lParam,WPARAM wparam) {
    hdc = GetDC(hwnd);
    if( IsDrawing == true )
    {
        if(regular){
<<<<<<< HEAD

=======
>>>>>>> lab4Dev
            SetROP2(hdc, R2_NOTXORPEN);
            setupPaintingTools(hdc);
            Ellipse(hdc,StartX,StartY,StartX + length,StartY + length);

            EndX = LOWORD(lParam);
            EndY = HIWORD(lParam);
            if(EndY < EndX)
                length = EndY - StartY;
            else;
                length = EndX - StartX;

            Ellipse(hdc,StartX,StartY,StartX+length,StartY + length);
        }else{
            SetROP2(hdc, R2_NOTXORPEN);
            setupPaintingTools(hdc);
            Ellipse(hdc,StartX,StartY,EndX,EndY);

            EndX = LOWORD(lParam);
            EndY = HIWORD(lParam);

            Ellipse(hdc,StartX,StartY,EndX,EndY);
        }

    }
    ReleaseDC(hwnd, hdc);
}



