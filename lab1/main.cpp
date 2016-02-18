#include <windows.h>
#include <commctrl.h>
#include "MainWindow.h"
#include "config.h"
#include "Button.h"
#include "TextLabel.h"
#include "TextBox.h"

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

//Celan
TextLabel *questionLabel;
TextLabel *resultLabel;
TextBox *resultTextBox;
TextBox *monitorBox;
Button  *hintButton;
Button  *submitButton;
Button *exitButton;

MainWindow *mainWindow;
TextLabel *copyRight;


RECT windowRect;

#define IDC_EXIT_BUTTON 101;
#define IDC_PUSHLIKE_BUTTON 102;

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

    hintButton = new Button("hint",hwnd,0,new Dimensions(200,0,100,40));
    submitButton = new Button("submit",hwnd,1,new Dimensions(0,0,100,40));

    copyRight = new TextLabel("Done with Pride an Prejudice by Bircu Maxim");
    resultLabel = new TextLabel("Input the result here: ");
    questionLabel = new TextLabel("Which is the best university in Moldova ?");

    monitorBox = new TextBox("",hwnd,2,new Dimensions(20,110,250,20));
    resultTextBox = new TextBox("",hwnd,2,new Dimensions(160,79,33,20));
}



void render(HWND hwnd){
    RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASE);
    GetClientRect(hwnd,&windowRect);

    ///ButtonsDrowing
    hintButton->setPosition(windowRect.right/2+50,windowRect.bottom/1.5);
    submitButton->setPosition(windowRect.right/2+50,windowRect.bottom/1.5);
    if(exitButton){
        exitButton->setPosition(windowRect.right/2-150,windowRect.bottom/2+50);
    }
    ///LabelsDrowing
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);
    SetBkMode(hdc,TRANSPARENT);
    resultLabel->drawLabel(hdc, 100, 80);
    questionLabel->drawLabel(hdc, windowRect.right/2,50);
    copyRight->drawLabel(hdc, windowRect.right/2, windowRect.bottom/2);
    monitorBox->superTextBox();
    EndPaint(hwnd, &ps);
}

void checkAnswere(string ans,HWND hwnd){
    if(ans == "UTM" || ans == "utm"){
        exitButton = new Button("EXIT",hwnd,4,new Dimensions(0,0,300,100));
        monitorBox->setText("The best universiti is UTM indead");
    }
    else{
        HBRUSH brush = CreateSolidBrush(RGB( 255,0,0));
        SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG)brush);
        RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASE);
        MessageBox(hwnd, "Your answere is wrong !!!","Wrong", MB_ICONINFORMATION);
        brush = CreateSolidBrush(RGB( 0,255,255));
        SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG)brush);
        RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASE);
        resultTextBox->setText("");
    }
}

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){

    switch (message){                  /* handle the messages */
        case WM_CREATE: {
            onCreate(hwnd);
            break;
        }

        case WM_COMMAND:{
            if(LOWORD(wParam) == hintButton->getId()){
                MessageBox(hwnd,TEXT("USM , ASEM , ULIM"),TEXT("Variante posibile"),MB_ICONINFORMATION);
            }
            if(LOWORD(wParam) == submitButton->getId()){
                if(MessageBox(hwnd,TEXT(resultTextBox->getText()),TEXT("Variante dumneavoastra"),MB_ICONINFORMATION))
                {
                    checkAnswere(resultTextBox->getText(),hwnd);
                }
            }
            if(exitButton){
                DestroyWindow(hintButton->getInstance());
                DestroyWindow(submitButton->getInstance());

                HBRUSH brush = CreateSolidBrush(RGB( 0,255,0));
                SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG)brush);
                RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASE);

                if(LOWORD(wParam) == exitButton->getId()){
                    DestroyWindow(hwnd);
                }
            }

            break;
        }
        case WM_E
        case WM_PAINT:
            render(hwnd);
            break;

        case WM_SIZE:{
            GetClientRect(hwnd,&windowRect);
            render(hwnd);
            HBRUSH brush = CreateSolidBrush(RGB( rand()%20 + 230,windowRect.right,windowRect.bottom));
            SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG)brush);
            RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASE);
            break;
        }

        case WM_MOVE:{
            HBRUSH brush = CreateSolidBrush(RGB( 0,155,255));
            SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG)brush);
            RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASE);
            break;
        }

        case WM_GETMINMAXINFO:{
            MINMAXINFO *min = (MINMAXINFO*)lParam;
            min->ptMinTrackSize.x = 350;
            min->ptMinTrackSize.y = 350;
            break;
        }
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        case WM_CLOSE:{
            if(!exitButton) {
                HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
                SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG) brush);
                RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASE);
                MessageBox(hwnd, "You should solve the problem from the screen to find the EXIT button !!!",
                           "Can't exit !!!", MB_ICONINFORMATION);
            }else
                MessageBox(hwnd,"Press EXIT button to close","Can't exit !!!",MB_ICONINFORMATION);;
            break;
        }
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }
    return 0;
}

