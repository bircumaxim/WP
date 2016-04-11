//
// Created by bircumaxim on 3/22/2016.
//

#ifndef LAB3_RESOURCES_H
#define LAB3_RESOURCES_H
#include <windows.h>
#include <commctrl.h>

#define IDB_STANDARD        1000

#define IDM_CURSOR          1001
#define IDM_PEN             1002
#define IDM_BRUSH           1003

#define IDM_LINE            1004
#define IDM_VERT_LINE       1005
#define IDM_HORIZ_LINE      1006

#define IDM_ELLIPSE         1007
#define IDM_TETTRA          1008
#define IDM_CONECTED_LINE   1009

#define IDM_BEZIER          1010
#define IDM_GRADIENT        1011

#define IDM_ERASER_1        1012
#define IDM_ERASER_2        1013
#define IDM_ERASER_3        1014
#define IDM_ERASER_4        1015

HWND hWndToolbar;
const int NUMBUTTONS = 20;
TBBUTTON tbrButtons[20];

void toolBarInit(){
    tbrButtons[0].iBitmap   = 0;
    tbrButtons[0].idCommand = IDM_CURSOR;
    tbrButtons[0].fsState   = TBSTATE_ENABLED;
    tbrButtons[0].fsStyle   = TBSTYLE_BUTTON;
    tbrButtons[0].dwData    = 0L;
    tbrButtons[0].iString   = 0;

    tbrButtons[1].iBitmap   = 1;
    tbrButtons[1].idCommand = IDM_PEN;
    tbrButtons[1].fsState   = TBSTATE_ENABLED;
    tbrButtons[1].fsStyle   = TBSTYLE_BUTTON;
    tbrButtons[1].dwData    = 0L;
    tbrButtons[1].iString   = 0;


    tbrButtons[2].iBitmap   = 2;
    tbrButtons[2].idCommand = IDM_BRUSH;
    tbrButtons[2].fsState   = TBSTATE_ENABLED;
    tbrButtons[2].fsStyle   = TBSTYLE_CHECK;
    tbrButtons[2].dwData    = 0L;
    tbrButtons[2].iString   = 0;

    tbrButtons[3].iBitmap   = 0;
    tbrButtons[3].idCommand = 0;
    tbrButtons[3].fsState   = TBSTATE_ENABLED;
    tbrButtons[3].fsStyle   = TBSTYLE_SEP;
    tbrButtons[3].dwData    = 0L;
    tbrButtons[3].iString   = 0;

    tbrButtons[4].iBitmap   = 3;
    tbrButtons[4].idCommand = IDM_LINE;
    tbrButtons[4].fsState   = TBSTATE_ENABLED;
    tbrButtons[4].fsStyle   = TBSTYLE_BUTTON;
    tbrButtons[4].dwData    = 0L;
    tbrButtons[4].iString   = 0;

    tbrButtons[5].iBitmap   = 4;
    tbrButtons[5].idCommand = IDM_VERT_LINE;
    tbrButtons[5].fsState   = TBSTATE_ENABLED;
    tbrButtons[5].fsStyle   = TBSTYLE_BUTTON;
    tbrButtons[5].dwData    = 0L;
    tbrButtons[5].iString   = 0;

    tbrButtons[6].iBitmap   = 5;
    tbrButtons[6].idCommand = IDM_HORIZ_LINE;
    tbrButtons[6].fsState   = TBSTATE_ENABLED;
    tbrButtons[6].fsStyle   = TBSTYLE_BUTTON;
    tbrButtons[6].dwData    = 0L;
    tbrButtons[6].iString   = 0;

    tbrButtons[7].iBitmap   = 0;
    tbrButtons[7].idCommand = 0;
    tbrButtons[7].fsState   = TBSTATE_ENABLED;
    tbrButtons[7].fsStyle   = TBSTYLE_SEP;
    tbrButtons[7].dwData    = 0L;
    tbrButtons[7].iString   = 0;

    tbrButtons[8].iBitmap   = 6;
    tbrButtons[8].idCommand = IDM_ELLIPSE;
    tbrButtons[8].fsState   = TBSTATE_ENABLED;
    tbrButtons[8].fsStyle   = TBSTYLE_BUTTON;
    tbrButtons[8].dwData    = 0L;
    tbrButtons[8].iString   = 0;

    tbrButtons[9].iBitmap   = 7;
    tbrButtons[9].idCommand = IDM_TETTRA;
    tbrButtons[9].fsState   = TBSTATE_ENABLED;
    tbrButtons[9].fsStyle   = TBSTYLE_BUTTON;
    tbrButtons[9].dwData    = 0L;
    tbrButtons[9].iString   = 0;

    tbrButtons[10].iBitmap   = 8;
    tbrButtons[10].idCommand = IDM_CONECTED_LINE;
    tbrButtons[10].fsState   = TBSTATE_ENABLED;
    tbrButtons[10].fsStyle   = TBSTYLE_BUTTON;
    tbrButtons[10].dwData    = 0L;
    tbrButtons[10].iString   = 0;

    tbrButtons[11].iBitmap   = 0;
    tbrButtons[11].idCommand = 0;
    tbrButtons[11].fsState   = TBSTATE_ENABLED;
    tbrButtons[11].fsStyle   = TBSTYLE_SEP;
    tbrButtons[11].dwData    = 0L;
    tbrButtons[11].iString   = 0;


    tbrButtons[12].iBitmap   = 9;
    tbrButtons[12].idCommand = IDM_BEZIER;
    tbrButtons[12].fsState   = TBSTATE_ENABLED;
    tbrButtons[12].fsStyle   = TBSTYLE_BUTTON;
    tbrButtons[12].dwData    = 0L;
    tbrButtons[12].iString   = 0;

    tbrButtons[13].iBitmap   = 10;
    tbrButtons[13].idCommand = IDM_GRADIENT;
    tbrButtons[13].fsState   = TBSTATE_ENABLED;
    tbrButtons[13].fsStyle   = TBSTYLE_BUTTON;
    tbrButtons[13].dwData    = 0L;
    tbrButtons[13].iString   = 0;

    tbrButtons[14].iBitmap   = 0;
    tbrButtons[14].idCommand = 0;
    tbrButtons[14].fsState   = TBSTATE_ENABLED;
    tbrButtons[14].fsStyle   = TBSTYLE_SEP;
    tbrButtons[14].dwData    = 0L;
    tbrButtons[14].iString   = 0;

    tbrButtons[15].iBitmap   = 11;
    tbrButtons[15].idCommand = IDM_ERASER_1;
    tbrButtons[15].fsState   = TBSTATE_ENABLED;
    tbrButtons[15].fsStyle   = TBSTYLE_BUTTON;
    tbrButtons[15].dwData    = 0L;
    tbrButtons[15].iString   = 0;

    tbrButtons[16].iBitmap   = 12;
    tbrButtons[16].idCommand = IDM_ERASER_2;
    tbrButtons[16].fsState   = TBSTATE_ENABLED;
    tbrButtons[16].fsStyle   = TBSTYLE_BUTTON;
    tbrButtons[16].dwData    = 0L;
    tbrButtons[16].iString   = 0;

    tbrButtons[17].iBitmap   = 13;
    tbrButtons[17].idCommand = IDM_ERASER_3;
    tbrButtons[17].fsState   = TBSTATE_ENABLED;
    tbrButtons[17].fsStyle   = TBSTYLE_BUTTON;
    tbrButtons[17].dwData    = 0L;
    tbrButtons[17].iString   = 0;

    tbrButtons[18].iBitmap   = 0;
    tbrButtons[18].idCommand = 0;
    tbrButtons[18].fsState   = TBSTATE_ENABLED;
    tbrButtons[18].fsStyle   = TBSTYLE_SEP;
    tbrButtons[18].dwData    = 0L;
    tbrButtons[18].iString   = 0;

    tbrButtons[19].iBitmap   = 14;
    tbrButtons[19].idCommand = IDM_ERASER_4;
    tbrButtons[19].fsState   = TBSTATE_ENABLED;
    tbrButtons[19].fsStyle   = TBSTYLE_BUTTON;
    tbrButtons[19].dwData    = 0L;
    tbrButtons[19].iString   = 0;
}


#endif //LAB3_RESOURCES_H
