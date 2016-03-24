//
// Created by bircumaxim on 3/20/2016.
//

#include "../include/Tetragon.h"

void Tetragon::MouseButtonDown(LPARAM lParam,WPARAM wparam) {
    hdc = GetDC(hwnd);
    StartX = LOWORD(lParam);
    StartY = HIWORD(lParam);

    EndX = LOWORD(lParam);
    EndY = HIWORD(lParam);

    SetROP2(hdc, R2_XORPEN);
    setupPaintingTools(hdc);
    Rectangle(hdc,StartX,StartY,EndX,EndY);

    IsDrawing = true;
    ReleaseDC(hwnd, hdc);
}

void Tetragon::MouseButtonUp(LPARAM lParam,WPARAM wparam) {
    hdc = GetDC(hwnd);
    EndX = LOWORD(lParam);
    EndY = HIWORD(lParam);

    SetROP2(hdc, R2_XORPEN);
    setupPaintingTools(hdc);

    IsDrawing = FALSE;
    length = 0;
    ReleaseDC(hwnd, hdc);
}

void Tetragon::MouseMove(LPARAM lParam,WPARAM wparam) {
    hdc = GetDC(hwnd);

    if( IsDrawing == true )
    {
        if(regular){
            SetROP2(hdc, R2_NOTXORPEN);
            setupPaintingTools(hdc);
            Rectangle(hdc,StartX,StartY,StartX + length,StartY + length);

            EndX = LOWORD(lParam);
            EndY = HIWORD(lParam);
            if(EndX > EndY)
                length = EndX - StartX;
            else
                length = EndY - StartY;


            Rectangle(hdc,StartX,StartY,StartX + length,StartY + length);
        }else{
            SetROP2(hdc, R2_NOTXORPEN);
            setupPaintingTools(hdc);
            Rectangle(hdc,StartX,StartY,EndX,EndY);

            EndX = LOWORD(lParam);
            EndY = HIWORD(lParam);

            Rectangle(hdc,StartX,StartY,EndX,EndY);
        }
    }
    ReleaseDC(hwnd, hdc);
}



