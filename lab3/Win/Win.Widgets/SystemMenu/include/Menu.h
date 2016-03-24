//
// Created by bircumaxim on 3/19/2016.
//

#ifndef LAB3_MENU_H
#define LAB3_MENU_H


#include <windows.h>
#include <c++/vector>
#include "../../../Win.Core/include/Config.h"

class Menu {
    protected:
        HMENU hmenu;
        vector<int> itemsId;
    public:
        HMENU getHmenu();
        void AppendMenuItem(LPCSTR);
        UINT getItemId(int);
};


#endif //LAB3_MENU_H
