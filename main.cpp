#include <windows.h>
#include "Window.h"
#include "config.h"
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

Window *window;

int WINAPI WinMain (HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow){
    MSG messages;

    //WidowCreation
    windowSetups(hThisInstance,hPrevInstance,lpszArgument,nCmdShow,wincl,WindowProcedure);
    window = new Window("Privet",300,300,szClassName,hThisInstance);

    //WindowShow
    ShowWindow (window->getHwnd(), nCmdShow);

    //MainRender
    while (GetMessage (&messages, NULL, 0, 0)){
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
    switch (message){                  /* handle the messages */
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }
    return 0;
}



