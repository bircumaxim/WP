//
// Created by max on 2/17/2016.
//

#ifndef TESTPROJECT_CONFIG_H
#define TESTPROJECT_CONFIG_H

#include <windows.h>

char szClassName[ ] = "ClionWindowsApplication";
WNDCLASSEX wincl;

void windowSetups(HINSTANCE hThisInstance, HINSTANCE hPrevInstance,  LPSTR lpszArgument, int nCmdShow,WNDCLASSEX wincl, WNDPROC WindowProcedure){
    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */

    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    if (!RegisterClassEx (&wincl))
        exit;
}

#endif //TESTPROJECT_CONFIG_H
