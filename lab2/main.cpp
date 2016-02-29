#include <windows.h>
#include <commctrl.h>
#include <crtdbg.h>
#include "MainWindow.h"
#include "config.h"
#include "Button.h"
#include "ScrollBar.h"
#include "Resource.h"
#include "ListBox.h"
#include "TextBox.h"
#include "TextLabel.h"

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

MainWindow *mainWindow;
Button *addElement;
Button *removeElement;
Button *showElement;
ListBox *listBox;
ScrollBar *windowSizeScrollV;
ScrollBar *windowSizeScrollH;
ScrollBar *windowScrollV;
ScrollBar *windowScrollH;
TextBox *textBox;
TextLabel *displayLabel;

int WINAPI WinMain (HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow){
    MSG messages;

    windowSetups(hThisInstance,hPrevInstance,lpszArgument,nCmdShow,wincl,WindowProcedure);
    mainWindow = new MainWindow(szClassName, "Main Window", WS_OVERLAPPEDWINDOW, new Dimensions(screenWidth/2,screenHeight/2,screenWidth/2,screenHeight/2), HWND_DESKTOP, 0, hThisInstance, NULL);

    RegisterHotKey(mainWindow->getInstance(),CTRL_C_HOOT_KEY,MOD_CONTROL,0x43);
    RegisterHotKey(mainWindow->getInstance(),CTRL_V_HOOT_KEY,MOD_CONTROL,0x56);


    ShowWindow (mainWindow->getInstance(), nCmdShow);

    while (GetMessage (&messages, NULL, 0, 0)){
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}

void onCreate(HWND hwnd){
    textBox = new TextBox("",hwnd,TEXT_BOX,new Dimensions(50,30,260,20));

    HDC hdc;

    displayLabel = new TextLabel("Not selected");


    removeElement = new Button("remove",hwnd,REMOVE_BUTTON, new Dimensions(210,55,100,50));
    addElement = new Button("add",hwnd,ADD_BUTTON, new Dimensions(210,110,100,50));
    showElement = new Button("show",hwnd,SHOW_BUTTON, new Dimensions(210,165,100,50));

    listBox = new ListBox("",new Dimensions(50,55,150,170),hwnd,105);

    windowSizeScrollH = new ScrollBar(WS_VISIBLE | WS_CHILD | SBS_HORZ,new Dimensions(0,0,screenWidth/4,20),hwnd,WINDOW_SIZE_SCROLL_H,hInstance);
    windowSizeScrollH->setRange(0,screenWidth/2);
    windowSizeScrollH->setThumbPosition(0);

    windowSizeScrollV = new ScrollBar(WS_VISIBLE | WS_CHILD | SBS_VERT,new Dimensions(0,20,20,screenHeight/4),hwnd,WINDOW_SIZE_SCROLL_V,hInstance);
    windowSizeScrollV->setRange(0,screenHeight/2);
    windowSizeScrollV->setThumbPosition(0);

//Window Scroll Bars
    windowScrollH = new ScrollBar((WS_VISIBLE | WS_CHILD | SBS_HORZ),new Dimensions(0,0,0,0),hwnd,WINDOW_SCROLL_H,hInstance);
    windowScrollH->setThumbPosition(0);

}

void render(HWND hwnd){
    RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASE);
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);
    SetBkMode(hdc,TRANSPARENT);
    GetWindowPlacement(hwnd,&wp);
    displayLabel->drawLabel(hdc, wp.rcNormalPosition.left+(xResized) + 500, 150);
    EndPaint(hwnd, &ps);
}

void changeColorRandom(HWND hwnd){
    static int i = 0;
    HBRUSH hbrush;
    i++;
    if(i == 4)
        i = 0;
    switch( i){
        case 1:
            hbrush = CreateSolidBrush(RGB(255,0,0));
            break;
        case 2:
            hbrush = CreateSolidBrush(RGB(0,255,0));
            break;
        case 3:
            hbrush = CreateSolidBrush(RGB(0,0,255));
            break;
        default:
            hbrush = CreateSolidBrush(RGB(100,155,100));
            break;
    }
    SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG) hbrush);
    RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASE);
}

void createSystemMenu(HWND hwnd){
    HMENU hMenu, hFileMenu;
    hMenu = CreateMenu();
    hFileMenu = CreatePopupMenu();
    AppendMenu(hFileMenu,MF_STRING,MENU_POSITION_RAND_SIZE,"Set random size");
    AppendMenu(hFileMenu,MF_STRING,MENU_POSITION_RAND_POSITION,"Set random position");
    AppendMenu(hMenu,MF_STRING | MF_POPUP, (UINT_PTR) hFileMenu, "Position");
    AppendMenu(hMenu,MF_STRING,MENU_CHANGE_WINDOW_COLOR,"Color");
    SetMenu(hwnd,hMenu);
}

void systemMenuAction( HWND hwnd,WPARAM wParam){
    switch(wParam){
        case MENU_CHANGE_WINDOW_COLOR:
            changeColorRandom(hwnd);
            break;
        case MENU_POSITION_RAND_SIZE:
            GetWindowPlacement(hwnd,&wp);
            SetWindowPos(hwnd,NULL,wp.rcNormalPosition.left,wp.rcNormalPosition.top,rand()%300+500,rand()%300+500,0);
            break;
        case MENU_POSITION_RAND_POSITION:
            SetWindowPos(hwnd,NULL,rand()%500,rand()&500,600,600,0);
            break;
    }
}

void WindowSizeScrollActions(HWND hwnd, WPARAM wparam, UINT message){
    static int rang = 8;
    switch(message){
        case WM_VSCROLL:
        {
            switch(LOWORD(wparam))
            {
                case SB_PAGELEFT:
                    GetWindowRect(hwnd,&rc);
                    GetWindowPlacement(hwnd,&wp);
                    SetWindowPos(hwnd, NULL, wp.rcNormalPosition.left, wp.rcNormalPosition.top, rc.right-rc.left, rc.bottom-rc.top - rang, 0);
                    windowSizeScrollV->setThumbPosition(windowSizeScrollV->getThumbPosition() - rang);
                    break;
                case SB_LINELEFT:
                    GetWindowRect(hwnd,&rc);
                    GetWindowPlacement(hwnd,&wp);
                    SetWindowPos(hwnd, NULL, wp.rcNormalPosition.left, wp.rcNormalPosition.top, rc.right-rc.left, rc.bottom-rc.top - rang, 0);
                    windowSizeScrollV->setThumbPosition(windowSizeScrollV->getThumbPosition() - rang);
                    break;
                case SB_PAGERIGHT:
                    GetWindowRect(hwnd,&rc);
                    GetWindowPlacement(hwnd,&wp);
                    SetWindowPos(hwnd, NULL, wp.rcNormalPosition.left, wp.rcNormalPosition.top, rc.right-rc.left, rc.bottom-rc.top + rang, 0);
                    windowSizeScrollV->setThumbPosition(windowSizeScrollV->getThumbPosition() + rang);
                    break;
                case SB_LINERIGHT:
                    GetWindowRect(hwnd,&rc);
                    GetWindowPlacement(hwnd,&wp);
                    SetWindowPos(hwnd, NULL, wp.rcNormalPosition.left, wp.rcNormalPosition.top, rc.right-rc.left, rc.bottom-rc.top + rang, 0);
                    windowSizeScrollV->setThumbPosition(windowSizeScrollV->getThumbPosition() + rang);
                    break;
                case SB_THUMBPOSITION:
                    GetWindowRect(hwnd,&rc);
                    GetWindowPlacement(hwnd,&wp);
                    SetWindowPos(hwnd, NULL, wp.rcNormalPosition.left, wp.rcNormalPosition.top, rc.right-rc.left, screenHeight/2 + HIWORD(wparam), 0);
                    windowSizeScrollV->setThumbPosition(HIWORD(wparam));
                    break;
                default: break;
            }
        }
        break;

        case WM_HSCROLL:
        {
            switch(LOWORD(wparam))
            {
                case SB_PAGELEFT:
                    GetWindowRect(hwnd,&rc);
                    GetWindowPlacement(hwnd,&wp);
                    SetWindowPos(hwnd, NULL, wp.rcNormalPosition.left, wp.rcNormalPosition.top, rc.right-rc.left - rang, rc.bottom-rc.top, 0);
                    windowSizeScrollH->setThumbPosition(windowSizeScrollH->getThumbPosition() - rang);
                    break;
                case SB_LINELEFT:
                    GetWindowRect(hwnd,&rc);
                    GetWindowPlacement(hwnd,&wp);
                    SetWindowPos(hwnd, NULL, wp.rcNormalPosition.left, wp.rcNormalPosition.top, rc.right-rc.left - rang, rc.bottom-rc.top, 0);
                    windowSizeScrollH->setThumbPosition(windowSizeScrollH->getThumbPosition() - rang);
                    break;
                case SB_PAGERIGHT:
                    GetWindowRect(hwnd,&rc);
                    GetWindowPlacement(hwnd,&wp);
                    SetWindowPos(hwnd, NULL, wp.rcNormalPosition.left, wp.rcNormalPosition.top, rc.right-rc.left + rang, rc.bottom-rc.top, 0);
                    windowSizeScrollH->setThumbPosition(windowSizeScrollH->getThumbPosition() + rang);
                    break;
                case SB_LINERIGHT:
                    GetWindowRect(hwnd,&rc);
                    GetWindowPlacement(hwnd,&wp);
                    SetWindowPos(hwnd, NULL, wp.rcNormalPosition.left, wp.rcNormalPosition.top, rc.right-rc.left + rang, rc.bottom-rc.top, 0);
                    windowSizeScrollH->setThumbPosition(windowSizeScrollH->getThumbPosition() + rang);
                    break;
                case SB_THUMBPOSITION:
                    GetWindowRect(hwnd,&rc);
                    GetWindowPlacement(hwnd,&wp);
                    SetWindowPos(hwnd, NULL, wp.rcNormalPosition.left, wp.rcNormalPosition.top, screenWidth/2 + HIWORD(wparam), rc.bottom-rc.top, 0);
                    windowSizeScrollH->setThumbPosition(HIWORD(wparam));
                    break;
                default: break;
            }
        }
        break;
    }
}

void WindowScrollActions(HWND hwnd, WPARAM wparam, UINT message){
    static int rang = 5;
    switch(message){
        case WM_HSCROLL:
        {
            switch(LOWORD(wparam))
            {
                case SB_LINELEFT:
                    if(windowScrollH->getThumbPosition() != 0){
                        GetWindowRect(windowScrollH->getInstance(),&rc);
                        GetWindowPlacement(windowScrollH->getInstance(),&wp);
                        SetWindowPos(windowScrollH->getInstance(), NULL, wp.rcNormalPosition.left-rang, wp.rcNormalPosition.top, rc.right-rc.left, rc.bottom-rc.top, 0);
                        windowScrollH->setThumbPosition(windowScrollH->getThumbPosition()-1);
                        UpdateWindow(hwnd);
                        ScrollWindow(hwnd,+rang,0,NULL,NULL);
                        xResized += rang;
                    }
                    break;

                case SB_LINERIGHT:
                    GetWindowRect(hwnd,&rc);
                    if(windowScrollH->getThumbPosition() < windowScrollH->getMaxRange()){
                        GetWindowRect(windowScrollH->getInstance(),&rc);
                        GetWindowPlacement(windowScrollH->getInstance(),&wp);
                        SetWindowPos(windowScrollH->getInstance(), NULL, wp.rcNormalPosition.left+rang, wp.rcNormalPosition.top, rc.right-rc.left, rc.bottom-rc.top, 0);
                        windowScrollH->setThumbPosition(windowScrollH->getThumbPosition()+1);
                        UpdateWindow(hwnd);
                        ScrollWindow(hwnd,-rang,0,NULL,NULL);
                        xResized -= rang;
                    }
                    break;
                default: break;
            }
        }
        break;
    }
}


LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
    switch (message){                  /* handle the messages */
        case WM_CREATE:{
            onCreate(hwnd);
            createSystemMenu(hwnd);
            break;
        }
        case WM_COMMAND:{
            systemMenuAction(hwnd,wParam);
            if(LOWORD(wParam) == listBox->getId()){
                switch (HIWORD(wParam)){
                    case LBN_DBLCLK:{
                        if(MessageBox(NULL, (LPCSTR)(listBox->get()), ("Sset Window title ?"), MB_YESNO) == 6){
                                SetWindowText(hwnd,(LPCSTR)listBox->get());
                        };
                        break;
                    }
                    case LBN_SELCHANGE:{
                        delete displayLabel;
                        displayLabel = new TextLabel((LPCSTR)listBox->get());
                        RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASE);
                        break;
                    }
                }
            }
            switch(LOWORD(wParam)) {
                case REMOVE_BUTTON:
                    listBox->remove();
                    break;
                case ADD_BUTTON:
                    listBox->add((LPARAM)textBox->getText());
                    break;
                case SHOW_BUTTON:
                    MessageBox(NULL, (LPCSTR) listBox->get(), ("Selected Text:"), MB_OK);
                    break;
            }
            break;
        }


        case WM_PAINT:{
            render(hwnd);
            break;
        }


        case WM_HSCROLL:{
            if (lParam != 0) {
                int id = GetDlgCtrlID((HWND)lParam);
                switch(id){
                    case WINDOW_SIZE_SCROLL_H:
                        WindowSizeScrollActions(hwnd,wParam,message);
                        break;
                    case WINDOW_SCROLL_H:
                        WindowScrollActions(hwnd,wParam,message);
                        break;
                }
            }
            break;
        }

        case WM_VSCROLL:{
            if (lParam != 0) {
                int id = GetDlgCtrlID((HWND)lParam);
                switch(id){
                    case WINDOW_SIZE_SCROLL_H:
                        WindowSizeScrollActions(hwnd,wParam,message);
                        break;
                    case WINDOW_SCROLL_H:
                        WindowScrollActions(hwnd,wParam,message);
                        break;
                }
            }
            break;
        }

        case WM_SIZE:{

            int xNewSize;
            int yNewSize;

            xNewSize = LOWORD(lParam);
            yNewSize = HIWORD(lParam);

            GetWindowRect(hwnd,&rc);
            windowSizeScrollH->setThumbPosition(xNewSize - screenWidth/2);
            windowSizeScrollV->setThumbPosition(yNewSize - screenHeight/2);
            windowScrollH->setRange(0,normalWidth - xNewSize);


            if(xNewSize >= normalWidth){
                ScrollWindow(hwnd,(-1*xResized),0,NULL,NULL);
                xResized = 0;
            }

            if(xNewSize < normalWidth){
                ShowWindow(windowSizeScrollH->getInstance(),SW_HIDE);
                ShowWindow(windowScrollH->getInstance(),SW_SHOW);
                SetWindowPos(windowScrollH->getInstance(),NULL,0,0,xNewSize,20,NULL);
            }
            else{
                ShowWindow(windowSizeScrollH->getInstance(),SW_SHOW);
                ShowWindow(windowScrollH->getInstance(),SW_HIDE);
            }
            if(yNewSize < normalHeight){
                ShowWindow(windowSizeScrollV->getInstance(),SW_HIDE);
            }
            else{
                ShowWindow(windowSizeScrollV->getInstance(),SW_SHOW);

            }
            break;
         }

        case WM_HOTKEY: {
            switch(wParam){
                case CTRL_C_HOOT_KEY:
                    changeColorRandom(hwnd);
                    break;
                case CTRL_V_HOOT_KEY:
                    DestroyWindow(hwnd);
                    changeColorRandom(hwnd);
                    break;
            }
            break;
        }

        case WM_GETMINMAXINFO:{
            MINMAXINFO* mi = (MINMAXINFO*)lParam;
            mi->ptMinTrackSize.x = (mi->ptMaxSize.x-16)/5;
            mi->ptMinTrackSize.y = (mi->ptMaxSize.x-16)/4;
            normalWidth = (mi->ptMaxSize.x-16)/2-145;
            normalHeight = (mi->ptMaxSize.y-16)/2;
            mi->ptMaxTrackSize.x = mi->ptMaxSize.x-16;
            mi->ptMaxTrackSize.y = mi->ptMaxSize.y-16;
            screenWidth = mi->ptMaxSize.x-16;
            screenHeight = mi->ptMaxSize.y-16;
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


