//
// Created by bircumaxim on 3/20/2016.
//

#include "../include/EllipseShape.h"


void EllipseShape::MouseButtonDown(LPARAM lParam,WPARAM wparam) {
    hdc = GetDC(hwnd);
    StartX = LOWORD(lParam);
    StartY = HIWORD(lParam);

    EndX = LOWORD(lParam);
    EndY = HIWORD(lParam);

    SetROP2(hdc, R2_XORPEN);

    Ellipse(hdc,StartX,StartY,EndX,EndY);

    IsDrawing = true;
    ReleaseDC(hwnd, hdc);
}

void EllipseShape::MouseButtonUp(LPARAM lParam,WPARAM wparam) {
    hdc = GetDC(hwnd);

    EndX = LOWORD(lParam);
    EndY = HIWORD(lParam);

    SetROP2(hdc, R2_XORPEN);

    MoveToEx(hdc, StartX, StartY, NULL);
    LineTo(hdc, EndX, EndY);

    IsDrawing = FALSE;

    ReleaseDC(hwnd, hdc);
}

void EllipseShape::MouseMove(LPARAM lParam,WPARAM wparam) {
    hdc = GetDC(hwnd);
    if( IsDrawing == true )
    {
        SetROP2(hdc, R2_NOTXORPEN);

        Ellipse(hdc,StartX,StartY,EndX,EndY);

        EndX = LOWORD(lParam);
        EndY = HIWORD(lParam);

        Ellipse(hdc,StartX,StartY,EndX,EndY);
    }
    ReleaseDC(hwnd, hdc);
}



