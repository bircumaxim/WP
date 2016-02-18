#include <windows.h>
#include "MainWindow.h"
#include "config.h"
#include "Button.h"
#include "TextLabel.h"
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

MainWindow *mainWindow;
Button  *defaultButton;
Button  *customButton;
TextLabel *textLabel;
RECT windowRect;
RECT container;

int WINAPI WinMain (HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow){
    MSG messages;

    //WidowCreation
    windowSetups(hThisInstance,hPrevInstance,lpszArgument,nCmdShow,wincl,WindowProcedure);
    mainWindow = new MainWindow("MainWindow",new Dimensions(100,40,900,600),szClassName,hThisInstance,HWND_DESKTOP);

    //WindowShow
    ShowWindow (mainWindow->getInstace(), nCmdShow);

    //MainRender
    while (GetMessage (&messages, NULL, 0, 0)){
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}

void onCreate(HWND hwnd){

    //TODO ACtionons for default and customButton
    //TODO Customizing of te customButton.
    
    defaultButton = new Button("default",hwnd,0,new Dimensions(200,0,100,40));
    customButton = new Button("customize",hwnd,1,new Dimensions(0,0,100,40));
    textLabel = new TextLabel("Done with Pride an Prejudice by Bircu Maxim");
}

void render(HWND hwnd){
    RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASE);
    GetClientRect(hwnd,&windowRect);
    defaultButton->setPosition(windowRect.right/2+50,windowRect.bottom/1.5);
    customButton->setPosition(windowRect.right/2+50,windowRect.bottom/1.5);
    textLabel->render(hwnd,windowRect);
}

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
    switch (message){                  /* handle the messages */
        case WM_CREATE:
            onCreate(hwnd);
            break;
        case WM_COMMAND:{
            if(LOWORD(wParam) == defaultButton->getId()){
                MessageBox(hwnd,"Default Button","Alert from default button",MB_ICONINFORMATION);
            }
            if(LOWORD(wParam) == customButton->getId()){
                MessageBox(hwnd,"Custom Button","Alert from custom button",MB_ICONINFORMATION);
            }

            break;
        }
        case WM_PAINT:
            render(hwnd);
            break;
        case WM_SIZE:
            render(hwnd);
            break;
        case WM_GETMINMAXINFO:{
            MINMAXINFO *min = (MINMAXINFO*)lParam;
            min->ptMinTrackSize.x = 350;
            min->ptMinTrackSize.y = 350;
            break;
        }
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;

        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }
    return 0;
}






//#include <windows.h>
//#include "MainWindow.h"
//#include "config.h"
//#include "Button.h"
//#include "TextLabel.h"
//LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
//
//MainWindow *mainWindow;
//TextLabel *textLabel;
//Button *button;
//
//int WINAPI WinMain (HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow){
//    MSG messages;
//    cout << "" << endl;
//    //WidowCreation
//    windowSetups(hThisInstance,hPrevInstance,lpszArgument,nCmdShow,wincl,WindowProcedure);
//
//    mainWindow = new MainWindow("MainWindow",new Dimensions(0,0,600,600),szClassName,hThisInstance,HWND_DESKTOP);
//
//    //WindowShow
//
//    ShowWindow(mainWindow->getInstace(), nCmdShow);
//
//    //MainRender
//    while (GetMessage (&messages, NULL, 0, 0)){
//        TranslateMessage(&messages);
//        DispatchMessage(&messages);
//    }
//    return messages.wParam;
//}
//
//
//
//void onCreate(HWND hwnd){
//    button = new Button("OK",hwnd,0,new Dimensions(80,80,100,40));
//    textLabel = new TextLabel("TextLabel");
//}
//
//void render(HWND hwnd){
//    RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASE);
//
//    PAINTSTRUCT ps;
//    HDC hdc = BeginPaint(hwnd, &ps);
//    SetBkMode(hDC,TRANSPARENT);
//
//    textLabel->renderLabel(hdc,);
//}
//
//LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
//    HDC hdc;
//    PAINTSTRUCT ps;
//    RECT rect;
//    switch (message){                  /* handle the messages */
//        case WM_PAINT:{
//            hdc = BeginPaint(hwnd,&ps);
//
//
//            GetClientRect(hwnd,&rect);
//
//            SelectObject(hdc,GetStockObject(DEFAULT_GUI_FONT));
//            SetBkMode(hdc,TRANSPARENT);
//            SetTextColor(hdc,RGB(255,0,0));
//
//            DrawText(hdc,TEXT("Text"),-1,&rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);
//
//
//            EndPaint(hwnd,&ps);
//            break;
//        }
//        case WM_CREATE:{
//            onCreate(hwnd);
//            break;
//        }
//        case WM_COMMAND:{
//            if(LOWORD(wParam) == button->getId()){
//                MessageBox(hwnd,"privet","privet",MB_ICONINFORMATION);
//            }
//            break;
//        }
//        case WM_DESTROY:
//            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
//            break;
//        default:                      /* for messages that we don't deal with */
//            return DefWindowProc (hwnd, message, wParam, lParam);
//    }
//    return 0;
//}
//
//
//
