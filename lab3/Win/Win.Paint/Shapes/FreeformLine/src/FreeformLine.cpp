//
// Created by bircumaxim on 3/20/2016.
//

#include "../include/FreeformLine.h"
#include <iostream>

using namespace std;

void FreeformLine::MouseButtonDown(LPARAM lparam, WPARAM wparam){
    hdc = GetDC(hwnd);

    StartX = LOWORD(lparam);
    StartY = HIWORD(lparam);

    EndX = LOWORD(lparam);
    EndY = HIWORD(lparam);

    StartX = LOWORD(lparam);
    StartY = HIWORD(lparam);
    IsDrawing = TRUE;

    ReleaseDC(hwnd, hdc);
};

void FreeformLine::MouseMove(LPARAM lparam, WPARAM wparam){
    hdc = GetDC(hwnd);
    if (IsDrawing == true) {

        SetROP2(hdc, R2_NOTXORPEN);

       static HPEN hPen = CreatePen(PS_DOT, 1, RGB(0, 0, 255));

                SelectObject(hdc, hPen);

//                //SelectObject(hdc,GetStockObject(BLACK_PEN));
//                SelectObject(hdc,GetStockObject(DC_PEN));
//                SelectObject(hdc,GetStockObject(DC_BRUSH));
                SetDCBrushColor(hdc, RGB(0,255,0));



        MoveToEx(hdc, EndX, EndY, NULL);
        EndX = LOWORD(lParam);
        EndY = HIWORD(lParam);
        LineTo(hdc, EndX, EndY);
    };
    ReleaseDC(hwnd, hdc);
};

void FreeformLine::MouseButtonUp(LPARAM lparam, WPARAM wparam) {
    hdc = GetDC(hwnd);

    EndX = LOWORD(lparam);
    EndY = HIWORD(lparam);

    SetROP2(hdc, R2_XORPEN);

    MoveToEx(hdc, StartX, StartY, NULL);
    LineTo(hdc, EndX, EndY);

    IsDrawing = FALSE;

    ReleaseDC(hwnd, hdc);
}
