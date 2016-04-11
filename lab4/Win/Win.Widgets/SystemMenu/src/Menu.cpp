//
// Created by bircumaxim on 3/19/2016.
//

#include "../include/Menu.h"

HMENU Menu::getHmenu(){
    return this->hmenu;
}

void Menu::AppendMenuItem(LPCSTR label){
    UINT id = Config::instance().idGen();
     itemsId.push_back(id);
    AppendMenu(this->hmenu,MF_STRING,id,label);
}

UINT Menu::getItemId(int index) {
    return itemsId[index];
}