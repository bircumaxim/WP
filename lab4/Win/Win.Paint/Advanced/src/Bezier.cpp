//
// Created by bircumaxim on 3/20/2016.
//

#include "../include/Bezier.h"


void Bezier::MouseButtonDown(LPARAM lparam, WPARAM wparam) {

    if (wparam & MK_LBUTTON || wparam & MK_RBUTTON) {
        hdc = GetDC(hwnd);
        setupPaintingTools(hdc);
        SelectObject(hdc, GetStockObject(WHITE_PEN));
        DrawBezier(hdc, points);
        if (wparam & MK_LBUTTON) {
            points[1].x = LOWORD (lparam);
            points[1].y = HIWORD (lparam);
        }
        if (wparam & MK_RBUTTON) {
            points[2].x = LOWORD (lparam);
            points[2].y = HIWORD (lparam);
        }
        SelectObject(hdc, GetStockObject(BLACK_PEN));
        DrawBezier(hdc, points);
        ReleaseDC(hwnd, hdc);
    }
}

void Bezier::MouseMove(LPARAM lparam, WPARAM wparam) {
    if (wparam & MK_LBUTTON || wparam & MK_RBUTTON) {
        hdc = GetDC(hwnd);
        setupPaintingTools(hdc);
        SelectObject(hdc, GetStockObject(WHITE_PEN));

        DrawBezier(hdc, points);
        if (wparam & MK_LBUTTON) {
            points[1].x = LOWORD (lparam);
            points[1].y = HIWORD (lparam);
        }
        if (wparam & MK_RBUTTON) {
            points[2].x = LOWORD (lparam);
            points[2].y = HIWORD (lparam);
        }
        SelectObject(hdc, GetStockObject(BLACK_PEN));
        DrawBezier(hdc, points);
        ReleaseDC(hwnd, hdc);
    }
}

void Bezier::MouseButtonUp(LPARAM lparam, WPARAM wparam) {
    if (wparam & MK_LBUTTON || wparam & MK_RBUTTON) {
        hdc = GetDC(hwnd);
        setupPaintingTools(hdc);
        SelectObject(hdc, GetStockObject(WHITE_PEN));
        DrawBezier(hdc, points);
        if (wparam & MK_LBUTTON) {
            points[1].x = LOWORD (lparam);
            points[1].y = HIWORD (lparam);
        }
        if (wparam & MK_RBUTTON) {
            points[2].x = LOWORD (lparam);
            points[2].y = HIWORD (lparam);
        }
        SelectObject(hdc, GetStockObject(BLACK_PEN));
        DrawBezier(hdc, points);
        ReleaseDC(hwnd, hdc);
    }
}

void Bezier::DrawBezier (HDC hdc, POINT points[]) {
    PolyBezier (hdc, points, 4) ;
    MoveToEx (hdc, points[0].x, points[0].y, NULL) ;
    LineTo (hdc, points[1].x, points[1].y) ;
    MoveToEx (hdc, points[2].x, points[2].y, NULL) ;
    LineTo (hdc, points[3].x, points[3].y) ;
}
