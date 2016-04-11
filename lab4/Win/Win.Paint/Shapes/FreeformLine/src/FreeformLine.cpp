//
// Created by bircumaxim on 3/20/2016.
//

#include "../include/FreeformLine.h"
#include <iostream>

using namespace std;

void FreeformLine::MouseButtonDown(LPARAM lparam, WPARAM wparam){
    hdc = GetDC(hwnd);
    setupPaintingTools(hdc);
    StartX = LOWORD(lparam);
    StartY = HIWORD(lparam);

    EndX = LOWORD(lparam);
    EndY = HIWORD(lparam);

    StartX = LOWORD(lparam);
    StartY = HIWORD(lparam);
    IsDrawing = TRUE;

//    ReleaseDC(hwnd, hdc);
};

void FreeformLine::MouseMove(LPARAM lparam, WPARAM wparam){
    //hdc = GetDC(hwnd);

    if (IsDrawing == true) {

        //SetROP2(hdc, R2_NOTXORPEN);

        MoveToEx(hdc, EndX, EndY, NULL);
        EndX = LOWORD(lparam);
        EndY = HIWORD(lparam);
//        setupPaintingTools(hdc);
        LineTo(hdc, EndX, EndY);

    };
//    ReleaseDC(hwnd, hdc);
};

void FreeformLine::MouseButtonUp(LPARAM lparam, WPARAM wparam) {
    hdc = GetDC(hwnd);

    EndX = LOWORD(lparam);
    EndY = HIWORD(lparam);



    IsDrawing = FALSE;

    ReleaseDC(hwnd, hdc);
}
