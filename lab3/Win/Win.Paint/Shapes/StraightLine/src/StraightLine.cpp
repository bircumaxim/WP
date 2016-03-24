//
// Created by bircumaxim on 3/20/2016.
//

#include "../include/StraightLine.h"

void StraightLine::MouseButtonDown(LPARAM lParam, WPARAM wparam) {
    hdc = GetDC(hwnd);

    StartX = LOWORD(lParam);
    StartY = HIWORD(lParam);

    EndX = LOWORD(lParam);
    EndY = HIWORD(lParam);

    setupPaintingTools(hdc);

    MoveToEx(hdc, StartX, StartY, NULL);
    LineTo(hdc, EndX, EndY);
    IsDrawing = true;
    ReleaseDC(hwnd, hdc);

}

void StraightLine::MouseButtonUp(LPARAM lParam, WPARAM wparam) {

        hdc = GetDC(hwnd);

        setupPaintingTools(hdc);

        MoveToEx(hdc, StartX, StartY, NULL);
        LineTo(hdc, EndX, EndY);

    if(!conected)
        IsDrawing = false;

        ReleaseDC(hwnd, hdc);
}

void StraightLine::MouseMove(LPARAM lParam, WPARAM wparam) {
    hdc = GetDC(hwnd);
    setupPaintingTools(hdc);
    if( IsDrawing == true )
    {
        SetROP2(hdc, R2_NOTXORPEN);
        if(horizontal){
            MoveToEx(hdc, StartX, StartY, NULL);
            LineTo(hdc, EndX, StartY);

            EndX = LOWORD(lParam);
            EndY = StartY;

            MoveToEx(hdc, StartX, StartY, NULL);
            LineTo(hdc, EndX, StartY);
        }else if(vertical){
            MoveToEx(hdc, StartX, StartY, NULL);
            LineTo(hdc, StartX, EndY);

            EndX = StartX;
            EndY = HIWORD(lParam);

            MoveToEx(hdc, StartX, StartY, NULL);
            LineTo(hdc, StartX, EndY);
        }else{
            MoveToEx(hdc, StartX, StartY, NULL);
            LineTo(hdc, EndX, EndY);

            EndX = LOWORD(lParam);
            EndY = HIWORD(lParam);

            MoveToEx(hdc, StartX, StartY, NULL);
            LineTo(hdc, EndX, EndY);
        }
    }
    ReleaseDC(hwnd, hdc);
}

void StraightLine::ExitDrawing() {
    IsDrawing = false;
}





