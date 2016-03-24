//
// Created by bircumaxim on 3/23/2016.
//

#ifndef LAB3_MAIN_H
#define LAB3_MAIN_H

#include "Win/Win.Paint/Shapes/FreeformLine/include/FreeformLine.h"
#include "Win/Win.Paint/Shapes/StraightLine/include/StraightLine.h"
#include "Win/Win.Paint/Shapes/Tetragon/include/Tetragon.h"
#include "Win/Win.Paint/Advanced/include/Bezier.h"
#include "Win/Win.Paint/Shapes/Ellipse/include/EllipseShape.h"
#include "Win/Win.Widgets/MainWindow/include/MainWindow.h"
#include "Win/Win.Core/include/ShortKey.h"
#include "Win/Win.Paint/Tools/Eraser/include/Eraser.h"
#include "Win/Win.Widgets/ScrollBar/include/ScrollBar.h"
#include "Win/Win.Widgets/TextBox/include/TextBox.h"

FreeformLine *freeformLine;
StraightLine *straightLine;
EllipseShape *elipse;
Tetragon *tetragon;
Bezier *bezier;
Eraser *eraser;
Eraser *eraser2;
static HINSTANCE hInstance;

static bool created = false;
static bool feelColor = false;
MainWindow *mainWindow;
ShortKey *ctrl_R;
ShortKey *ctrl_E;

ScrollBar *eraserScrollBar;
ScrollBar *colorScrollbarR;
ScrollBar *colorScrollbarG;
ScrollBar *colorScrollbarB;

TextBox *thicknesBox;

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

void createDrawingTools(HWND hwnd);

void unselectAllTools();

void setBrush();

void resetBrush();

void OnEraseBkGnd(HWND hwnd);

void toolBarSwitch(WPARAM,HWND);

void createScrollBars(HWND);

#endif //LAB3_MAIN_H
