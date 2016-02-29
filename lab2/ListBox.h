//
// Created by max on 2/29/2016.
//

#ifndef LAB2_LISTBOX_H
#define LAB2_LISTBOX_H


#include "WindowObject.h"

class ListBox: public WindowObject {
private:
    HWND parentInstance;
public:
    ListBox(LPCSTR title,Dimensions* dimensions, HWND parentInstance,int id):WindowObject(
            WS_EX_CLIENTEDGE,
            "listbox",
            title,
            WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_AUTOVSCROLL | LBS_NOTIFY,
            dimensions,
            parentInstance,
            id,
            NULL,
            NULL
    ){
        this->parentInstance = parentInstance;
    }

    void add(LPARAM element);
    void remove();
    LPARAM get();
};


#endif //LAB2_LISTBOX_H
