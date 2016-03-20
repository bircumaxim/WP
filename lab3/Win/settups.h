//
// Created by bircumaxim on 3/19/2016.
//

#ifndef LAB3_SETTUPS_H
#define LAB3_SETTUPS_H

#include <windows.h>


char szClassName[ ] = "ClionWindowsApplication";
WNDCLASSEX wincl;

///OBJECTS ID

static int screenWidth;
static int screenHeight;

#define CTRL_C_HOOT_KEY 201
#define CTRL_V_HOOT_KEY 202


void windowSetups(HINSTANCE hThisInstance, HINSTANCE hPrevInstance,  LPSTR lpszArgument, int nCmdShow,WNDCLASSEX wincl, WNDPROC WindowProcedure){
    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */

    wincl.hbrBackground = (HBRUSH) RGB(0,0,0);

    if (!RegisterClassEx (&wincl))
        exit;
}

#endif //LAB3_SETTUPS_H
