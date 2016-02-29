//
// Created by max on 2/17/2016.
//

#ifndef TESTPROJECT_CONFIG_H
#define TESTPROJECT_CONFIG_H

#include <windows.h>
#include "Resource.h"

char szClassName[ ] = "ClionWindowsApplication";
WNDCLASSEX wincl;

///OBJECTS ID

static HINSTANCE hInstance;
static WINDOWPLACEMENT wp;
static RECT rc;
static int screenWidth;
static int screenHeight;
static int normalWidth;
static int normalHeight;
int xResized = 0;
int yResized = 0;

#define ADD_BUTTON 100
#define REMOVE_BUTTON 101
#define SHOW_BUTTON 102
#define CTRL_C_HOOT_KEY 201
#define CTRL_V_HOOT_KEY 202
#define MENU_POSITION_RAND_POSITION  303
#define MENU_POSITION_RAND_SIZE  304
#define MENU_CHANGE_WINDOW_COLOR 305
#define WINDOW_SIZE_SCROLL_V 400
#define WINDOW_SIZE_SCROLL_H 401
#define WINDOW_SCROLL_V 402
#define WINDOW_SCROLL_H 403
#define TEXT_BOX 500
#define DISPLAY_LABEL 600
#define IDC_TARGET 1000

void windowSetups(HINSTANCE hThisInstance, HINSTANCE hPrevInstance,  LPSTR lpszArgument, int nCmdShow,WNDCLASSEX wincl, WNDPROC WindowProcedure){
    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (hThisInstance, MAKEINTRESOURCE(IDE_TARGET));
    wincl.hCursor = LoadCursor (hThisInstance,MAKEINTRESOURCE(IDC_TARGET) );
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */

    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    if (!RegisterClassEx (&wincl))
        exit;
}

#endif //TESTPROJECT_CONFIG_H
