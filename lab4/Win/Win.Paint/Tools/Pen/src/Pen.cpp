//
// Created by bircumaxim on 3/20/2016.
//

#include "../include/Pen.h"

#include <iostream>

using namespace std;

Pen::Pen(HWND hwnd){
    hdc  = GetDC(hwnd);
    this->hwnd = hwnd;
    this->penColor = RGB(255,0,0);
    this->brushColor = RGB(255,255,255);
    this->thickness = 2;
    this->status = false;
    this->IsDrawing = false;
}

void Pen::setStatus(bool status){
    this->status = status;
}

void Pen::SwitchMouseMessages(UINT message, LPARAM lParam , WPARAM wparam){
    if(!status)
        return;
    int x = LOWORD(lParam);
    int y = HIWORD(lParam);
    WINDOWPLACEMENT wp;
    GetWindowPlacement(hwnd,&wp);
    if(y-wp.rcNormalPosition.top  > 60 + this->thickness/2){
        switch (message){
            case WM_LBUTTONDOWN:
                this->MouseButtonDown(lParam,wparam);
                break;
            case WM_MOUSEMOVE:
                this->MouseMove(lParam,wparam);
                break;
            case WM_LBUTTONUP:
                this->MouseButtonUp(lParam,wparam);
                break;
        }
    }

}


void Pen::setupPaintingTools(HDC hdc) {
    HPEN hpen = CreatePen(PS_DASHDOTDOT, this->thickness, this->penColor);
    HBRUSH hbrush = CreateSolidBrush(this->brushColor);

    SelectObject(this->hdc, hpen);
    SelectObject(hdc, hbrush);
}


void Pen::setThickenss(int thickness) {
    this->thickness = thickness;
}

void Pen::setPenColor(COLORREF color) {
    this->penColor = color;
}

void Pen::setBrushColor(COLORREF color) {
    this->brushColor = color;
}

