//
// Created by bircumaxim on 3/19/2016.
//

#ifndef LAB3_BSICMENU_H
#define LAB3_BSICMENU_H

#include <windows.h>
#include "Menu.h"

class SystemMenu : public Menu {
    public:
        SystemMenu();
        void AppendPopup(HMENU,LPCSTR);
};


#endif //LAB3_BSICMENU_H
