#include <windows.h>

#include "Win/Win.Widgets/MainWindow/include/MainWindow.h"
#include "Win/settups.h"
#include "Win/Win.Widgets/SystemMenu/include/SystemMenu.h"
#include "Win/Win.Widgets/SystemMenu/include/PopupMenu.h"

#include "Win/Win.Paint/Shapes/Tetragon/include/Tetragon.h"
#include "Win/Win.Paint/Shapes/FreeformLine/include/FreeformLine.h"


LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

MainWindow *mainWindow;

int WINAPI WinMain (HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow){
    MSG messages;

    windowSetups(hThisInstance,hPrevInstance,lpszArgument,nCmdShow,wincl,WindowProcedure);
    mainWindow = new MainWindow(szClassName, "Main Window", WS_OVERLAPPEDWINDOW, new Dimensions(1376/2 - 500,768/2 - 300,1000,600), HWND_DESKTOP, hThisInstance, NULL);
    ::SetWindowLong(mainWindow->getInstance(), GWL_STYLE, GetWindowLong(mainWindow->getInstance(), GWL_STYLE)&~WS_SIZEBOX);

    RegisterHotKey(mainWindow->getInstance(),CTRL_C_HOOT_KEY,MOD_CONTROL,0x43);
    RegisterHotKey(mainWindow->getInstance(),CTRL_V_HOOT_KEY,MOD_CONTROL,0x56);



    ShowWindow (mainWindow->getInstance(), nCmdShow);

    while (GetMessage (&messages, NULL, 0, 0)){
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}

void createSystemMenu(HWND hwnd){
    SystemMenu mainMenu;
    PopupMenu popupMenuFile;
    PopupMenu popupMneuAdvanced;

    popupMenuFile.AppendMenuItem("Save");
    popupMenuFile.AppendMenuItem("Open");

    mainMenu.AppendPopup(popupMenuFile.getHmenu(),"File");

    popupMneuAdvanced.AppendMenuItem("Bezier curves");
    mainMenu.AppendPopup(popupMneuAdvanced.getHmenu(),"Advanced");

    mainMenu.AppendMenuItem("Help");

    SetMenu(hwnd,mainMenu.getHmenu());
}

FreeformLine *fl = NULL;

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
    HDC hDC;
    PAINTSTRUCT ps;
    HPEN hPen;

    if(fl != NULL)
        fl->SwitchMouseMessages(message, lParam,wParam);

    switch (message){                  /* handle the messages */
        case WM_CREATE:{
            createSystemMenu(hwnd);
            fl = new FreeformLine(hwnd);

            break;
        }

        case WM_COMMAND:
            break;


        case WM_MOUSEACTIVATE:
            break;
//        case WM_LBUTTONDOWN:
//            hdc = GetDC(hwnd);
//            startX = LOWORD(lParam);
//            startY = HIWORD(lParam);
//
//            endX = LOWORD(lParam);
//            endY = HIWORD(lParam);
//
//            SetROP2(hdc, R2_XORPEN);
//
//            MoveToEx(hdc, startX, startY, NULL);
//            LineTo(hdc, endX, endY);
//            isDrowning = true;
//            ReleaseDC(hwnd, hdc);
//            cout << "START" << startX << " : " << startY << endl;
//            break;
//
//        case WM_MOUSEMOVE:
//            hdc = GetDC(hwnd);
//
//            startX = LOWORD(lParam);
//            startY = HIWORD(lParam);
//
//            endX = LOWORD(lParam);
//            endY = HIWORD(lParam);
//            if( isDrowning == true )
//            {
//                SetROP2(hdc, R2_NOTXORPEN);
//
//
                hPen = CreatePen(PS_DASHDOTDOT, 3, RGB(0, 0, 255));

//                SelectObject(hdc, hPen);
//
////                SelectObject(hdc,GetStockObject(BLACK_PEN));
////                SelectObject(hdc,GetStockObject(DC_PEN));
////                SelectObject(hdc,GetStockObject(DC_BRUSH));
//                //SetDCBrushColor(hdc, RGB(0,255,0));
//                //EllipseShape(hdc,startX,startY,endX,endY);
//
//                MoveToEx(hdc, startX, startY, NULL);
//                LineTo(hdc, endX, endY);
//
//                endX = LOWORD(lParam);
//                endY = HIWORD(lParam);
//
//                //EllipseShape(hdc,startX,startY,endX,endY);
////
////                //if(abs(endX - startX) > abs(endY - startY))
////
//
//                startX = LOWORD(lParam);
//                startY = HIWORD(lParam);
//                //MoveToEx(hdc, startX, startY, NULL);
//                //LineTo(hdc, endX, endY);
//            }
//
//            ReleaseDC(hwnd, hdc);
//            break;
//
//        case WM_LBUTTONUP:
//
//            hdc = GetDC(hwnd);
//
//            endX = LOWORD(lParam);
//            endY = HIWORD(lParam);
//
//            SetROP2(hdc, R2_XORPEN);
//
//            MoveToEx(hdc, startX, startY, NULL);
//            LineTo(hdc, endX, endY);
//
//            isDrowning = FALSE;
//
//            ReleaseDC(hwnd, hdc);
//
//            break;


        case WM_PAINT:

            break;

        case WM_GETMINMAXINFO:{
            MINMAXINFO* mi = (MINMAXINFO*)lParam;
            screenWidth = mi->ptMaxSize.x-16;
            screenHeight = mi->ptMaxSize.y-16;
            break;
        }

        case WM_SIZE:

            break;

        case WM_HOTKEY: {
            switch(wParam){
                case CTRL_C_HOOT_KEY:
                    fl->setStatus(true);
                    break;
                case CTRL_V_HOOT_KEY:
                    //fl->ExitDrawing();
                    //DestroyWindow(hwnd);
                    break;
            }
            break;
        }

        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;

        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;

        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);

    }

    return 0;
}




