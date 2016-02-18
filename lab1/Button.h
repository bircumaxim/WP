//
// Created by max on 2/18/2016.
//

#ifndef LAB1_BUTTON_H
#define LAB1_BUTTON_H
#include "WindowObject.h"
#include <iostream>
using namespace std;


class Button:public WindowObject {
public:
    Button(LPCSTR title,HWND parentInstace,int id,Dimensions *dimensions)
            :WindowObject("BUTTON",title,parentInstace,id,dimensions){
    }

};


#endif //LAB1_BUTTON_H
