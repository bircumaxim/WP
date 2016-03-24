#include <windows.h>
#include "resource.h"
#include "Win/Win.Widgets/MainWindow/include/MainWindow.h"
#include "Win/settups.h"
#include "main.h"
#include <string>
#include <sstream>
#include <cmath>

int WINAPI WinMain (HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow){
    MSG messages;

    windowSetups(hThisInstance,hPrevInstance,lpszArgument,nCmdShow,wincl,WindowProcedure);
    mainWindow = new MainWindow(szClassName, "Main Window", WS_OVERLAPPEDWINDOW, new Dimensions(1376/2 - 500,768/2 - 300,1010,600), HWND_DESKTOP, hThisInstance, NULL);
    ::SetWindowLong(mainWindow->getInstance(), GWL_STYLE, GetWindowLong(mainWindow->getInstance(), GWL_STYLE)&~WS_SIZEBOX);

    ctrl_R = new ShortKey(mainWindow->getInstance(),0x52);
    ctrl_E = new ShortKey(mainWindow->getInstance(),0x45);

    toolBarInit();

    hWndToolbar = CreateToolbarEx(mainWindow->getInstance(),
                                  WS_VISIBLE | WS_CHILD | WS_EX_OVERLAPPEDWINDOW,
                                  IDB_STANDARD,
                                  NUMBUTTONS,
                                  hThisInstance,
                                  IDB_STANDARD,
                                  tbrButtons,
                                  NUMBUTTONS,
                                  32, 32, 32, 32,
                                  sizeof(TBBUTTON));

    ShowWindow (mainWindow->getInstance(), nCmdShow);

    while (GetMessage (&messages, NULL, 0, 0)){
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}

void updateColor(HWND hwnd){
    HDC hdc = GetDC(hwnd);
    RECT rt;
    RECT wrt;
    GetClientRect(hwnd,&wrt);
    rt.left = wrt.left+270;
    rt.bottom = wrt.top+140;
    rt.right = wrt.left+300;
    rt.top = wrt.top+80;

    FillRect(hdc, &rt, CreateSolidBrush(RGB(colorScrollbarR->getThumbPosition(), colorScrollbarG->getThumbPosition(), colorScrollbarB->getThumbPosition())));

    int a = eraserScrollBar->getThumbPosition();
    stringstream ss;
    ss << a;
    string str = ss.str();

    thicknesBox->setText((TCHAR*)str.c_str());

    freeformLine->setPenColor(RGB(colorScrollbarR->getThumbPosition(),colorScrollbarG->getThumbPosition(),colorScrollbarB->getThumbPosition()));
    straightLine->setPenColor(RGB(colorScrollbarR->getThumbPosition(),colorScrollbarG->getThumbPosition(),colorScrollbarB->getThumbPosition()));
    elipse->setPenColor(RGB(colorScrollbarR->getThumbPosition(),colorScrollbarG->getThumbPosition(),colorScrollbarB->getThumbPosition()));
    tetragon->setPenColor(RGB(colorScrollbarR->getThumbPosition(),colorScrollbarG->getThumbPosition(),colorScrollbarB->getThumbPosition()));
    bezier->setPenColor(RGB(colorScrollbarR->getThumbPosition(),colorScrollbarG->getThumbPosition(),colorScrollbarB->getThumbPosition()));

    freeformLine->setThickenss(eraserScrollBar->getThumbPosition());
    straightLine->setThickenss(eraserScrollBar->getThumbPosition());
    elipse->setThickenss(eraserScrollBar->getThumbPosition());
    tetragon->setThickenss(eraserScrollBar->getThumbPosition());
    bezier->setThickenss(eraserScrollBar->getThumbPosition());
    eraser2->setThickenss(eraserScrollBar->getThumbPosition());

    elipse->setBrushColor(RGB(colorScrollbarR->getThumbPosition(),colorScrollbarG->getThumbPosition(),colorScrollbarB->getThumbPosition()));
    tetragon->setBrushColor(RGB(colorScrollbarR->getThumbPosition(),colorScrollbarG->getThumbPosition(),colorScrollbarB->getThumbPosition()));

}

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
    if(created){
        freeformLine->SwitchMouseMessages(message, lParam,wParam);
        straightLine->SwitchMouseMessages(message, lParam,wParam);
        elipse->SwitchMouseMessages(message, lParam,wParam);
        tetragon->SwitchMouseMessages(message, lParam,wParam);
        bezier->SwitchMouseMessages(message, lParam,wParam);
        eraser->SwitchMouseMessages(message, lParam,wParam);
        eraser2->SwitchMouseMessages(message,lParam,wParam);
    }

    switch (message){                  /* handle the messages */
        case WM_CREATE:
            createDrawingTools(hwnd);
            createScrollBars(hwnd);
            updateColor(hwnd);
            break;

        case WM_COMMAND:
            toolBarSwitch(wParam,hwnd);
            break;

        case WM_HOTKEY:
            if(wParam == ctrl_R->getId()) {
                elipse->setRegular(!elipse->isRegular());
                tetragon->setRegular(!tetragon->isRegular());
            }
            if(wParam == ctrl_E->getId()){
                straightLine->ExitDrawing();
            }
            break;


        case WM_HSCROLL:
            updateColor(hwnd);
            if (lParam != 0) {
                int id = GetDlgCtrlID((HWND) lParam);
                if (id == eraserScrollBar->getId())
                    eraserScrollBar->update(wParam);
                if (id == colorScrollbarR->getId())
                    colorScrollbarR->update(wParam);
                if (id == colorScrollbarG->getId())
                    colorScrollbarG->update(wParam);
                if (id == colorScrollbarB->getId())
                    colorScrollbarB->update(wParam);
            }
        break;

        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        case WM_ERASEBKGND:

            break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;

        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }
    return 0;
}

void toolBarSwitch(WPARAM wParam, HWND hwnd){
    switch(wParam){
        case IDM_CURSOR:
            unselectAllTools();
            break;
        case IDM_PEN:
            unselectAllTools();
            freeformLine->setStatus(true);
            break;
        case IDM_BRUSH:
            feelColor = !feelColor;
            if(!feelColor)
                resetBrush();
            else
                setBrush();
            break;

        case IDM_LINE:
            unselectAllTools();
            straightLine->setStatus(true);
            break;
        case IDM_VERT_LINE:
            unselectAllTools();
            straightLine->setStatus(true);
            straightLine->setVertical(true);
            break;
        case IDM_HORIZ_LINE:
            unselectAllTools();
            straightLine->setStatus(true);
            straightLine->setHorizontal(true);
            break;

        case IDM_ELLIPSE:
            unselectAllTools();
            elipse->setStatus(true);
            break;
        case IDM_TETTRA:
            unselectAllTools();
            tetragon->setStatus(true);
            break;
        case IDM_CONECTED_LINE:
            unselectAllTools();
            straightLine->setStatus(true);
            straightLine->setConected(true);
            break;

        case IDM_BEZIER:
            unselectAllTools();
            bezier->setStatus(true);
            break;
        case IDM_GRADIENT:
            OnEraseBkGnd(hwnd);
            break;
        case IDM_ERASER_1:
            unselectAllTools();
            eraser->setThickenss(8);
            eraser->setStatus(true);
            break;
        case IDM_ERASER_2:
            unselectAllTools();
            eraser->setThickenss(16);
            eraser->setStatus(true);
            break;
        case IDM_ERASER_3:
            unselectAllTools();
            eraser->setThickenss(32);
            eraser->setStatus(true);
            break;
        case IDM_ERASER_4:
            unselectAllTools();
            eraser2->setStatus(true);
            break;
    }
}

void createDrawingTools(HWND hwnd){
    freeformLine = new FreeformLine(hwnd);
    straightLine = new StraightLine(hwnd);
    elipse = new EllipseShape(hwnd);
    tetragon = new Tetragon(hwnd);
    bezier = new Bezier(hwnd);
    eraser = new Eraser(hwnd);
    eraser2 = new Eraser(hwnd);
    created = true;
}

void createScrollBars(HWND hwnd){
    //TextBoxThicknes

    thicknesBox = new TextBox("",hwnd,new Dimensions(270,49,30,30));

    //Eraser Scroll
    eraserScrollBar = new ScrollBar(WS_VISIBLE | WS_CHILD | SBS_HORZ ,new Dimensions(5,50,255,20),hwnd,hInstance);
    eraserScrollBar->setRange(0,255);
    eraserScrollBar->setThumbPosition(rand() % 100 +1);

    //Colors Scrolls
    colorScrollbarR = new ScrollBar(WS_VISIBLE | WS_CHILD | SBS_HORZ ,new Dimensions(5,80,255,20),hwnd,hInstance);
    colorScrollbarR->setRange(0,255);
    colorScrollbarR->setThumbPosition(rand() % 100 +1);

    colorScrollbarG = new ScrollBar(WS_VISIBLE | WS_CHILD | SBS_HORZ ,new Dimensions(5,100,255,20),hwnd,hInstance);
    colorScrollbarG->setRange(0,255);
    colorScrollbarG->setThumbPosition(rand() % 100 +1);

    colorScrollbarB = new ScrollBar(WS_VISIBLE | WS_CHILD | SBS_HORZ ,new Dimensions(5,120,255,20),hwnd,hInstance);
    colorScrollbarB->setRange(0,255);
    colorScrollbarB->setThumbPosition(rand() % 100 +1);
    updateColor(hwnd);
}

void unselectAllTools(){
    freeformLine->setStatus(false);

    straightLine->setStatus(false);
    straightLine->setHorizontal(false);
    straightLine->setVertical(false);
    straightLine->setConected(false);

    elipse->setStatus(false);
    tetragon->setStatus(false);
    bezier->setStatus(false);
    eraser->setStatus(false);
    eraser2->setStatus(false);
}

void setBrush(){
    elipse->setBrushColor(RGB(colorScrollbarR->getThumbPosition(),colorScrollbarG->getThumbPosition(),colorScrollbarB->getThumbPosition()));
    tetragon->setBrushColor(RGB(colorScrollbarR->getThumbPosition(),colorScrollbarG->getThumbPosition(),colorScrollbarB->getThumbPosition()));
}

void resetBrush(){
    elipse->setBrushColor(RGB(255,255,255));
    tetragon->setBrushColor(RGB(255,255,255));
}

void OnEraseBkGnd(HWND hwnd) {
    HDC dc;
    RECT rect, temp;
    HBRUSH color;
    dc = GetDC(hwnd);
    GetClientRect(hwnd, &rect);
    int r1 = 255, g1 = 0, b1 = 0;

    int r2 = 255, g2 = 255, b2 = 0;

    for(int i=0;i<rect.right;i++)
    {
        int r,g,b;
        r = r1 + (i * (r2-r1) / rect.right);
        g = g1 + (i * (g2-g1) / rect.right);
        b = b1 + (i * (b2-b1) / rect.right);

        temp.left = i;

        temp.top = 150;
        temp.right = i + 1;
        temp.bottom = rect.bottom;

        color = CreateSolidBrush(RGB(r, g, b));

        FillRect(dc, &temp, color);
    }
}
