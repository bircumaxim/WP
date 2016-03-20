//
// Created by bircumaxim on 3/20/2016.
//

#include "../include/StraitLine.h"

void StraitLine::MouseButtonDown(LPARAM lParam, WPARAM wparam) {
    hdc = GetDC(hwnd);
    StartX = LOWORD(lParam);
    StartY = HIWORD(lParam);

    EndX = LOWORD(lParam);
    EndY = HIWORD(lParam);

    SetROP2(hdc, R2_XORPEN);

    MoveToEx(hdc, StartX, StartY, NULL);
    LineTo(hdc, EndX, EndY);
    IsDrawing = true;
    ReleaseDC(hwnd, hdc);

}

void StraitLine::MouseButtonUp(LPARAM lParam, WPARAM wparam) {
    if(!conected)
    {
        hdc = GetDC(hwnd);

        EndX = LOWORD(lParam);
        EndY = HIWORD(lParam);

        SetROP2(hdc, R2_XORPEN);

        MoveToEx(hdc, StartX, StartY, NULL);
        LineTo(hdc, EndX, EndY);

        IsDrawing = false;

        ReleaseDC(hwnd, hdc);
    }
}

void StraitLine::MouseMove(LPARAM lParam, WPARAM wparam) {
    hdc = GetDC(hwnd);
    if( IsDrawing == true )
    {
        SetROP2(hdc, R2_NOTXORPEN);

        if(horizontal){
            MoveToEx(hdc, StartX, StartY, NULL);
            LineTo(hdc, EndX, StartY);

            EndX = LOWORD(lParam);
            EndY = HIWORD(lParam);

            MoveToEx(hdc, StartX, StartY, NULL);
            LineTo(hdc, EndX, StartY);
        }else if(vertical){
            MoveToEx(hdc, StartX, StartY, NULL);
            LineTo(hdc, StartX, EndY);

            EndX = LOWORD(lParam);
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

void StraitLine::ExitDrawing() {
    IsDrawing = false;
}





