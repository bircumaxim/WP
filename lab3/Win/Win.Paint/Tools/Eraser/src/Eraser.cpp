//
// Created by bircumaxim on 3/21/2016.
//

#include "../include/Eraser.h"

//
// Created by bircumaxim on 3/20/2016.
//

void Eraser::MouseButtonDown(LPARAM lparam, WPARAM wparam){
    hdc = GetDC(hwnd);
    setupPaintingTools(hdc);
    StartX = LOWORD(lparam);
    StartY = HIWORD(lparam);

    EndX = LOWORD(lparam);
    EndY = HIWORD(lparam);

    StartX = LOWORD(lparam);
    StartY = HIWORD(lparam);
    IsDrawing = TRUE;

    ReleaseDC(hwnd, hdc);
};

void Eraser::MouseMove(LPARAM lparam, WPARAM wparam){
    hdc = GetDC(hwnd);

    if (IsDrawing == true) {

        //SetROP2(hdc, R2_XORPEN);

        MoveToEx(hdc, EndX, EndY, NULL);
        EndX = LOWORD(lparam);
        EndY = HIWORD(lparam);
        setupPaintingTools(hdc);
        setPenColor(RGB(255,255,255));
        LineTo(hdc, EndX, EndY);

    };
    ReleaseDC(hwnd, hdc);
};

void Eraser::MouseButtonUp(LPARAM lparam, WPARAM wparam) {
    hdc = GetDC(hwnd);

    EndX = LOWORD(lparam);
    EndY = HIWORD(lparam);

    IsDrawing = FALSE;

    ReleaseDC(hwnd, hdc);
}
