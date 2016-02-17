//
// Created by max on 2/17/2016.
//

#ifndef WP_BUTTON_H
#define WP_BUTTON_H
#include <iostream>
#include <windows.h>
using namespace std;

class Button {

private:
    int ID_BUTTON;
    HWND hwnd;
    LPCSTR buttonTitle;
    int x;
    int y;
    int width;
    int height;
public:
    Button(LPCSTR buttonTitle, int x, int y, int width, int height, HWND parent,int id){
        this->ID_BUTTON = id;
        this->buttonTitle = buttonTitle;
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        hwnd = CreateWindowEx(NULL,
                                      "BUTTON",
                                      this->buttonTitle,
                                      WS_TABSTOP|WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,
                                      this->x,
                                      this->y,
                                      this->width,
                                      this->height,
                                      parent,
                                      (HMENU)ID_BUTTON ,
                                      (HINSTANCE)GetWindowLong(parent, GWL_HINSTANCE),
                                      NULL);

    }

    HWND getHwnd(){
        return hwnd;
    }

    WORD getButtonId(){
        return ID_BUTTON;
    }
};


#endif //WP_BUTTON_H
